//Needed libraries
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <conio.h>
using namespace std;

//Loops
#define Loop(Start,End) for (int i = Start ; i < End ; i++) //Loop On Defined Variable "i"
#define VLoop(VarName,Start,End) for (int VarName = Start ; VarName < End ; VarName++) //Loop On User Defined Variable Name

//Sorting
#define AscOrder(Object,Size) sort(Object,Object+Size);
#define DesOrder(Object,Size) sort(Object,Object+Size); for (int i = 0 ; i < Size/2 ; i++) swap(Object[i],Object[Size-1-i]);
#define VAscOrder(Vector) sort(Vector.begin(),Vector.end());
#define VDesOrder(Vector) sort(Vector.begin(),Vector.end()); for (int i = 0 ; i < (Vector.size())/2 ; i++) swap(Vector[i],Vector[Vector.size()-1-i]);


//Data Types & Structures Declarations
#define BigInt long long //Long Long DataType 
#define A(Name,Type,Size) Type* Name = new type[Size]; //Create Array
#define DA(Name) delete Name; //Destroy Array
#define Stop _getch(); //Wait For User Char entry

//Filenames
#define InFile "A.in" //Name of Input File
#define OutFile "Output.txt"  //Name of Output File

//Main Program Starts Here
int main()
{
	ifstream In;
	In.open(InFile);

	ofstream Out;
	Out.open(OutFile);

	if (In.fail() || Out.fail())
		cout<<"Failed to Open Files!"<<endl;

	int Cases = 0;
	int Current_Case = 1;
	string Result = "";

	In>>Cases; //Get Number of Cases from file

	while (Cases--)
	{
		//Code Logic Starts Here (Save Result to "Result" variable)
		int P,K,L,Temp,Sum =0;
		In>>P>>K>>L;
		if (P*K >= L)
		{
			int* A = new int[L];
			Loop(0,L) {In>>Temp; A[i] = Temp;}
			DesOrder(A,L);
			
			
			Loop(0,L) Sum+=(A[i]*((i+K)/(K)));
			cout<<Sum<<endl;
			
		}
		else Result = "Impossible";
		
		//Code Logic Ends Here ("Result" variable content is written to Output File)
		if (Result == "Impossible")
		{
			Out<<"Case #"<<Current_Case++<<": "<<Result<<endl; //Output Result of Current Case to File
			Result = "";
		}
		else
			Out<<"Case #"<<Current_Case++<<": "<<Sum<<endl;
	}

	cout<<"End Of Code Execution...Press Any Key to Exit! (Output File = "<<OutFile<<")";
	Stop;
	return 0;
}
//Main Program Ends Here
