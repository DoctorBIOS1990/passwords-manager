//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
//---------------------------------------------------------------------------
class TDB : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *conexion;
	TDataSource *DAO_User;
	TFDQuery *queryUser;
	TDataSource *DAO_Pass;
	TFDQuery *queryPass;
	TDataSource *DAO_Datos;
	TFDQuery *queryDatos;
	void __fastcall queryDatosBeforeInsert(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TDB(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDB *DB;
//---------------------------------------------------------------------------
#endif
