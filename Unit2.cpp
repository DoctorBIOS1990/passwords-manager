//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDB *DB;
//---------------------------------------------------------------------------
__fastcall TDB::TDB(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDB::queryDatosBeforeInsert(TDataSet *DataSet)
{
    mainForm->inputURL->SetFocus();
}
//---------------------------------------------------------------------------

