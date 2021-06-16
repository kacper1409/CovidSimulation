//---------------------------------------------------------------------------

#ifndef FMainH
#define FMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TFmMain : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer;
	TImageList *ImageList;
	TPanel *Panel;
	TLabel *LabelStepNo;
	TLabel *LabelFreq;
	TToolBar *ToolBar;
	TToolButton *ToolButtonStart;
	TToolButton *ToolButtonStop;
	TToolButton *ToolButtonStep;
	TToolButton *ToolButton2;
	TToolButton *ToolButtonSettings;
	TToolButton *ToolButton1;
	TToolButton *ToolButtonExit;
	TToolButton *ToolButton3;
	TTrackBar *TrackBarFreq;
	TScrollBox *ScrollBox;
	TImage *Image;
	TLabel *LabelTime;
	TLabel *LabelNotInfected;
	TLabel *LabelInfected;
	TLabel *LabelRecovered;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall ToolButtonStartClick(TObject *Sender);
	void __fastcall ToolButtonStopClick(TObject *Sender);
	void __fastcall ToolButtonStepClick(TObject *Sender);
	void __fastcall TrackBarFreqChange(TObject *Sender);
	void __fastcall ToolButtonExitClick(TObject *Sender);
	void __fastcall ToolButtonSettingsClick(TObject *Sender);
private:	// User declarations

	Graphics::TBitmap *Bitmap;
	void __fastcall InitVisual();
	void __fastcall Visualize(TCanvas* Canvas);
	void __fastcall UpdateButtonsState();
	void __fastcall UpdateTrackBarFreqLabel();
	void __fastcall UpdateStepLabels();
public:		// User declarations
	__fastcall TFmMain(TComponent* Owner);
	__fastcall ~TFmMain();
};
//---------------------------------------------------------------------------
extern PACKAGE TFmMain *FmMain;
//---------------------------------------------------------------------------
#endif
