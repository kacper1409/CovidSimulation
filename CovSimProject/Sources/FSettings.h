//---------------------------------------------------------------------------

#ifndef FSettingsH
#define FSettingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFmSettings : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtnOk;
	TBitBtn *BitBtnCancel;
	TEdit *EditAreaWidth;
	TLabel *LabelAreaHeight;
	TEdit *EditAreaHeight;
	TLabel *LabelBoxLen;
	TEdit *EditBoxLen;
	TLabel *LabelPopulation;
	TEdit *EditPopulation;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EditInfectionDuration;
	TEdit *EditRiskOfInfection;
	TEdit *EditInitInfectedPeople;
	TLabel *Label4;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFmSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFmSettings *FmSettings;
//---------------------------------------------------------------------------
#endif
