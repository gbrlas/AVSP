#include<iostream>
#include<fstream>
using namespace std;

struct robot
{
	char color;
	int pos;
};
int main()
{
	ifstream fin("A.in");
	ofstream fout("A.out");

	int T, N,y;
	char* carr;
	int *O,*B;
	int Rctr, temp,Bctr=0, Octr=0;
	char color;
	fin>>T;
	for(int i =1; i<=T; i++)
	{
		fin>>N;
		Bctr=0, Octr=0;
		carr=new char[N];
		O=new int[N]; B=new int[N];
		for(int j=0; j<N;j++)
		{
			fin>>carr[j]>>temp;
			switch (carr[j])
			{
			case 'B':
				B[Bctr++]=temp;
				break;
			case 'O':
			case 'o':
				O[Octr++]=temp;
				break;
			};
		}
		int Bpos=1, Opos=1, Bnext=0, Onext=0,BCTR=0,OCTR=0, ctr=0;
		bool Bdone=false,Odone=false; y=0;
		while( ctr < N) 
		{
			Bnext=B[BCTR];
			Onext=O[OCTR];

			if( carr[ctr] =='B' && BCTR < Bctr && Bpos == Bnext)
			{BCTR++;}
			else if( carr[ctr] =='O' && OCTR < Octr && Opos == Onext)
			{OCTR++;}

			if( Bpos < Bnext)
			{Bpos++;}
			else if(Bpos == Bnext && carr[ctr]=='B')
			{ctr++; Bdone=true;}
			else if( Bpos >Bnext)
			{Bpos--;}

			if( Opos < Onext)
			{Opos++;}
			else if(Opos == Onext && carr[ctr] == 'O' && !Bdone)
			{ctr++;}
			else if( Opos >Onext)
			{Opos--;}
			
			Bdone=false;

			y++;
		}

		fout<<"Case #"<<i<<": "<<y<<endl;
	}


	return 0;
}