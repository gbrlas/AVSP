//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        TStringList *fp;

        fp=new TStringList;
        fp->LoadFromFile("A-large.in");

        Memo1->Clear();


        int n=0;
        int game_line=0;

        n=StrToIntDef(fp->Strings[game_line], 0);
        game_line++;

        for (int i=0; i<n; i++)
        {
                TStringList *ndir = new TStringList;
                ndir->Delimiter=' ';
                ndir->DelimitedText=fp->Strings[game_line];
                game_line++;

                int o, b, ocur, bcur, res, ressum;
                o=1; b=1;
                bcur=0;
                ocur=0;
                ressum=0;

                int count=StrToIntDef(ndir->Strings[0],0);
                for (int j=1; j<=count; j++)
                {
                        int resp=0;
                        String code =ndir->Strings[j*2-1];
                        int s=StrToIntDef(ndir->Strings[j*2], 1);

                        if (code == "O")
                        {
                                resp=abs(o-s)-bcur;
                                if (resp < 0)
                                        resp=0;

                                res =  resp+1;//( abs(b - s) +1)-abs(cur-b);
                                o=s;
                                ocur+=res;
                                bcur=0;
                        }
                        else
                        {
                                resp=abs(b-s)-ocur;
                                if (resp < 0)
                                        resp=0;

                                res =  resp+1;//( abs(b - s) +1)-abs(cur-b);
                                b=s;
                                bcur+=res;
                                ocur=0;
                        }


                        ressum+=res;
                }


                ndir->Free();
                String output;
                output.printf("Case #%d: %d", i+1, ressum);
                Memo1->Lines->Append(output);
        }
        Memo1->Lines->SaveToFile("output.txt");

        fp->Free();
}
//---------------------------------------------------------------------------
