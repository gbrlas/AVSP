//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#include<iostream.h>
#include<fstream.h>
#include <stdexcept>
#include<map.h>
#include<string.h>
#include<stdio.h>


int main()
{
    char cString[256];
    char bString[256];
    int i;
    int y;
    int a;
    char op [1];
    int iZeilen;
    ifstream file;
    file.open("A-small-attempt6.in", ios::in);

    if (!file)
    {
     cout<<"File dosn't exist!!"<<endl;
    }
    else
    {

        file.getline(cString, sizeof(cString));
        ofstream outfile("output.out", ios::out | ios::app);
        iZeilen= atoi(cString);
        for  (i=1; i<=iZeilen && i<31; i++)
        {
        outfile<<"Case #";
        outfile<<i<<": ";


        file.getline(bString,256);

                                  for(y=0; bString[y]!='\0'; y++)
                                  {
                                   switch (bString[y])
                                   {
                                   case 'y':
                                   outfile<<"a";
                                   break;
                                   case 'n':
                                   outfile<<"b";
                                   break;

                                   case 'f':
                                   outfile<<"c";
                                   break;
                                   case 'i':
                                   outfile<<"d";
                                   break;

                                   case 'c':
                                   outfile<<"e";
                                   break;
                                   case 'w':
                                   outfile<<"f";
                                   break;

                                   case 'l':
                                   outfile<<"g";
                                   break;
                                   case 'b':
                                   outfile<<"h";
                                   break;

                                   case 'k':
                                   outfile<<"i";
                                   break;
                                   case 'u':
                                   outfile<<"j";
                                   break;

                                   case 'o':
                                   outfile<<"k";
                                   break;
                                   case 'm':
                                   outfile<<"l";
                                   break;

                                   case 'x':
                                   outfile<<"m";
                                   break;
                                   case 's':
                                   outfile<<"n";
                                   break;

                                   case 'e':
                                   outfile<<"o";
                                   break;
                                   case 'v':
                                   outfile<<"p";
                                   break;

                                   case 'z':
                                   outfile<<"q";
                                   break;
                                   case 'p':
                                   outfile<<"r";
                                   break;

                                   case 'd':
                                   outfile<<"s";
                                   break;
                                   case 'r':
                                   outfile<<"t";
                                   break;

                                   case 'j':
                                   outfile<<"u";
                                   break;
                                   case 'g':
                                   outfile<<"v";
                                   break;

                                   case 't':
                                  outfile<<"w";
                                   break;
                                   case 'h':
                                   outfile<<"x";
                                   break;

                                   case 'a':
                                   outfile<<"y";
                                   break;
                                   case 'q':
                                   outfile<<"z";
                                   break;


                                   case ' ':
                                   outfile<<" ";
                                   break;
                                   }



                                  }

         outfile<<endl;

        }
    }





     system("pause");
     return 0;

}


