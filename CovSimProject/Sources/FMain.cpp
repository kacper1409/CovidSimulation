//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <list>
#include <fstream>
#include <DateUtils.hpp>
#pragma hdrstop

#include "FMain.h"
#include "Engine.h"
#include "Person.h"
#include "Vector2d.h"
#include "Parameters.h"
#include "Status.h"
#include "FSettings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

Engine engine;


TFmMain *FmMain;
//---------------------------------------------------------------------------
__fastcall TFmMain::TFmMain(TComponent* Owner)
	: TForm(Owner)
{
	Bitmap = NULL;
	Timer->Enabled = false;
}
//---------------------------------------------------------------------------

__fastcall TFmMain::~TFmMain()
{
	delete Bitmap;					  	// free the bitmap object
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::FormShow(TObject *Sender)
{
	engine.init();
	InitVisual();
	Visualize(Image->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::InitVisual()
{
	Caption = 	(AnsiString)"Wizualizacja rozwoju pandemii - populacja: " + Parameters::population +
				(AnsiString)", rozm. mapy: " +
				Parameters::width + " x " + Parameters::height;

	if (Bitmap != NULL) delete Bitmap;

	Bitmap = new Graphics::TBitmap();
	Bitmap->Width = Parameters::width * Parameters::boxLen;
	Bitmap->Height = Parameters::height * Parameters::boxLen;

	Image->Picture->Graphic = Bitmap;	// assign the bitmap to the image control

	// wart. pocz. timera ustawiam na 1 sek. i init kontrolki trackbar (jest w jedn. 0.1 sek.)

	Timer->Interval = 1000;
	TrackBarFreq->Position = Timer->Interval / 100;

	// pocz. aktualizacja innych elementów górnego paska

	UpdateButtonsState();
	UpdateTrackBarFreqLabel();
	UpdateStepLabels();
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::Visualize(TCanvas* Canvas)
{
	Canvas->Brush->Style = bsSolid;
	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(Canvas->ClipRect);

	vector<Person>::iterator p = engine.people.begin();
	while (p != engine.people.end())
	{
		int x0 = p->getPosition().getX() * Parameters::boxLen;
		int y0 = p->getPosition().getY() * Parameters::boxLen;

		int x1 = x0 + Parameters::boxLen;
		int y1 = y0 + Parameters::boxLen;

		if 		(p->getStatus() == Healthy)   Canvas->Brush->Color = clLime;
		else if (p->getStatus() == Infected)  Canvas->Brush->Color = clRed;
		else if (p->getStatus() == Recovered) Canvas->Brush->Color = clBlue;
		else                        		  Canvas->Brush->Color = clYellow;

		Canvas->FillRect(Rect(x0, y0, x1, y1));

		p++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::TimerTimer(TObject *Sender)
{
	engine.step();

	Visualize(Image->Canvas);

	UpdateStepLabels();
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::ToolButtonStartClick(TObject *Sender)
{
	Timer->Enabled = true;
	UpdateButtonsState();
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::ToolButtonStopClick(TObject *Sender)
{
	Timer->Enabled = false;
	UpdateButtonsState();
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::ToolButtonStepClick(TObject *Sender)
{
	TimerTimer(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::TrackBarFreqChange(TObject *Sender)
{
	Timer->Interval = TrackBarFreq->Position * 50;
	UpdateTrackBarFreqLabel();
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::UpdateButtonsState()
{
	ToolButtonStart->Enabled	= !Timer->Enabled;
	ToolButtonStop->Enabled		=  Timer->Enabled;
	ToolButtonStep->Enabled     = !Timer->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::UpdateTrackBarFreqLabel()
{
	LabelFreq->Caption = " Czêst.: " + AnsiString().sprintf("%0.2lf s", TrackBarFreq->Position / 20.0);
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::UpdateStepLabels()
{
	int totMins = engine.getStepNo() * Parameters::stepLen;
	int days = totMins / MinsPerDay;
	int hours = (totMins - days * MinsPerDay) / MinsPerHour;
	int mins = totMins - days * MinsPerDay - hours * MinsPerHour;

	LabelNotInfected->Caption = (AnsiString)"Nie zainfekowani: " + engine.getNotInfected();
	LabelInfected->Caption = (AnsiString)"Zainfekowani: " + engine.getInfected();
	LabelRecovered->Caption = (AnsiString)"Ozdrowieñcy: " + engine.getRecovered();

	LabelStepNo->Caption = AnsiString().sprintf("Krok sym.: %d", engine.getStepNo());
	LabelTime->Caption = AnsiString().sprintf("Czas: %dd %02dh %02dm", days, hours, mins);
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::ToolButtonExitClick(TObject *Sender)
{
	ToolButtonStopClick(NULL);

	ofstream myfile ("../../data.txt");

	if (myfile.is_open())
	{
		list<int>::iterator notInfectedIt = engine.notInfectedList.begin();
		list<int>::iterator infectedIt = engine.infectedList.begin();
		list<int>::iterator recoveredIt = engine.recoveredList.begin();


		while (notInfectedIt != engine.notInfectedList.end())
		{
			myfile << *notInfectedIt;
			myfile << " ";

			myfile << *infectedIt;
			myfile << " ";

			myfile << *recoveredIt;
			myfile << endl;

			notInfectedIt++;
			infectedIt++;
			recoveredIt++;
		}
	}

	myfile.close();

    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFmMain::ToolButtonSettingsClick(TObject *Sender)
{
	ToolButtonStopClick(NULL);

	if (FmSettings->ShowModal() == mrCancel)
		ToolButtonStartClick(NULL);
	else
	{
		engine.init();
		InitVisual();
		Visualize(Image->Canvas);
	}
}
//---------------------------------------------------------------------------


