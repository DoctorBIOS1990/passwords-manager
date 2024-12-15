//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include <Windows.h>
#include <Vcl.Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TmainForm *mainForm;

bool estado;

//---------------------------------------------------------------------------
__fastcall TmainForm::TmainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void abrirDB()
{
	DB->conexion->Params->Values["Database"] = ExtractFilePath(Application->ExeName) + "\Security.dll";
	DB->conexion->Params->Values["Password"] = "b_NjwOi@";

	DB->conexion->Open();
	DB->queryPass->Open();
	DB->queryDatos->Open();
	DB->queryUser->Open();
}
//---------------------------------------------------------------------------
String CrearContrasena(int longitud)
{
    String caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%{}_-[]";
	String resultado = "";

	Randomize();
	for (int i = 0; i < longitud; ++i) {
        int posicionAleatoria = Random(caracteres.Length()) + 1;
        resultado += caracteres[posicionAleatoria];
    }
    return resultado;
}

//---------------------------------------------------------------------------
void generateKey()
{
	DB->DAO_Datos->Edit();
	mainForm->inputPass->Text = CrearContrasena(mainForm->spinFuerza->Value);
}

//---------------------------------------------------------------------------
void __fastcall TmainForm::makePassClick(TObject *Sender)
{

	if (inputPass->Text == "") {
		generateKey();
	}else {
		if (Application->MessageBox(L"Se va a cambiar la clave.\n\n¿Estás de acuerdo?",
		L"Advertencia", MB_OKCANCEL | MB_ICONWARNING) == 1){
			mainForm->inputPass->Clear();
			generateKey();
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TmainForm::inputURLClick(TObject *Sender)
{
	inputURL->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::btnLoginClick(TObject *Sender)
{
	String clave = DB->queryPass->FieldByName("password")->AsString;

	if (estado == false)
		{
			if (inputLogin->Text == clave )
				{
					pageControl->Pages[1]->TabVisible  = True;
					pageControl->Pages[2]->TabVisible  = True;
					mainForm->Height = 500;
					inputLogin->Clear();
					pageControl->TabIndex = 1;
					estado = true;
					btnLogin->Caption = "Cerrar";
					inputLogin->Hide();
					lblIngrese->Caption = "En linea.";
				}

			else Application->MessageBox(TEXT("Contraseña Incorrecta.\nIntente nuevamente."),TEXT("ERROR"), MB_OK | MB_ICONERROR);
		}

	else {
			 pageControl->Pages[1]->TabVisible  = false;
			 pageControl->Pages[2]->TabVisible  = false;
			 inputLogin->Show();
			 lblIngrese->Caption = "Ingrese su clave.";
			 btnLogin->Caption = "Iniciar";
			 estado = false;
		 }
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::btnChangeClick(TObject *Sender)
{

String clave = DB->queryPass->FieldByName("password")->AsString;

	if (oldPass->Text == clave)
		{
			if (newPass->Text == confirmPass->Text)
				{
					DB->DAO_Pass->Edit();
					editPass->Text = confirmPass->Text;
					DB->queryPass->Post();
					Application->MessageBox(L"Se ha cambiado con EXITO.",L"Notificación", MB_OK | MB_ICONINFORMATION);
					oldPass->Clear();
				}
			else Application->MessageBox(L"Se ha EQUIVOCADO en la contraseña.",L"ERROR", MB_OK | MB_ICONERROR);
		}
	else Application->MessageBox(L"La contraseña antigua es INCORRECTA.",L"ERROR", MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::FormShow(TObject *Sender)
{
	try{
		abrirDB();
	}
	catch(Exception &Exception){
		Application->MessageBox(L"ERROR de Base de Datos.",L"Ha ocurrido un error", MB_OK | MB_ICONERROR);
		Application->Terminate();
	}
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::pageControlChange(TObject *Sender)
{
	if (pageControl->TabIndex == 1) {
		mainForm->Height = 500;
	} else mainForm->Height = 293;
}
//---------------------------------------------------------------------------


void __fastcall TmainForm::btnCopyClick(TObject *Sender)
{
	Clipboard()->AsText = inputPass->Text;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::btnCopyUrlClick(TObject *Sender)
{
	Clipboard()->AsText = inputURL->Text;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::Image3Click(TObject *Sender)
{
    ShellExecute(mainForm->Handle, TEXT("open"),
        TEXT("https://github.com/DoctorBIOS1990"), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

