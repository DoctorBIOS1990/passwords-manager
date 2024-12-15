//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Mask.hpp>
#include "cspin.h"

//---------------------------------------------------------------------------
class TmainForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pageControl;
	TTabSheet *Login;
	TImage *Image1;
	TEdit *inputLogin;
	TBitBtn *btnLogin;
	TTabSheet *Agenda;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TBitBtn *makePass;
	TTabSheet *Opciones;
	TLabeledEdit *oldPass;
	TLabeledEdit *confirmPass;
	TLabeledEdit *newPass;
	TBitBtn *btnChange;
	TPanel *Panel;
	TLabel *Label1;
	TImage *Image2;
	TLabel *Label2;
	TDBLabeledEdit *inputURL;
	TDBLabeledEdit *inputPass;
	TCSpinEdit *spinFuerza;
	TLabel *lblFuerza;
	TDBEdit *editPass;
	TLabel *lblIngrese;
	TBitBtn *btnCopy;
	TBitBtn *btnCopyUrl;
	TImage *Image3;
	void __fastcall makePassClick(TObject *Sender);
	void __fastcall inputURLClick(TObject *Sender);
	void __fastcall btnLoginClick(TObject *Sender);
	void __fastcall btnChangeClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall pageControlChange(TObject *Sender);
	void __fastcall btnCopyClick(TObject *Sender);
	void __fastcall btnCopyUrlClick(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TmainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainForm *mainForm;
//---------------------------------------------------------------------------
#endif
