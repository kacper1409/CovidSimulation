//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FSettings.h"
#include "Parameters.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFmSettings *FmSettings;
//---------------------------------------------------------------------------
__fastcall TFmSettings::TFmSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFmSettings::FormShow(TObject *Sender)
{
	EditPopulation->Text 				= Parameters::population;
	EditAreaWidth->Text 				= Parameters::width;
	EditAreaHeight->Text 				= Parameters::height;
	EditBoxLen->Text 					= Parameters::boxLen;
	EditInitInfectedPeople->Text 		= Parameters::initInfectedPeople;
	EditInfectionDuration->Text 		= Parameters::infectionDuration;
	EditRiskOfInfection->Text	 		= Parameters::riskOfInfection;
}
//---------------------------------------------------------------------------

void __fastcall TFmSettings::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ModalResult == mrOk)
	{
		Parameters::population				= EditPopulation->Text.ToInt();
		Parameters::width					= EditAreaWidth->Text.ToInt();
		Parameters::height					= EditAreaHeight->Text.ToInt();
		Parameters::boxLen					= EditBoxLen->Text.ToInt();
		Parameters::initInfectedPeople		= EditInitInfectedPeople->Text.ToInt();
		Parameters::infectionDuration		= EditInfectionDuration->Text.ToInt();
		Parameters::riskOfInfection			= EditRiskOfInfection->Text.ToInt();
	}
}
//---------------------------------------------------------------------------







