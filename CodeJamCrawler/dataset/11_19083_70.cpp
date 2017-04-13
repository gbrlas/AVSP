#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct combine
{
	char one;
	char two;
	char result;
};

struct oppose
{
	char oppone;
	char opptwo;
};

bool isOppose(int,oppose *, const string &, char);
int isCombine(int,combine*, char, char);
char returnCombine(combine*, int );

int main()
{
	ifstream fin("B3.in");
	ofstream fout("B3.out");

	int T,C,D,N;
	combine* comb;
	oppose* opp;
	string elements;char temp; int tempint, templength;
	fin >> T;
	for (int i=1; i<=T;i++)
	{
		if( i == 100)
			i= 100;
		tempint=-1;
		elements="";
		fin >> C;
		comb=new combine[C];
		for(int j=0; j<C; j++)
			fin >> comb[j].one >> comb[j].two >> comb[j].result;
		fin >> D;
		opp=new oppose[D];
		for(int l=0;l<D; l++)
			fin >>opp[l].oppone >> opp[l].opptwo;
		fin >> N;
		for(int k=0;k<N;k++)
		{
			fin>> temp;
			templength= elements.length();
			if( templength == 0)
			{
				elements+=temp;
			}
			else
			{
				if(C>0 && (tempint= isCombine(C,comb,elements[templength-1],temp )) != -1)
				{
					elements[templength-1]=returnCombine(comb,tempint);
				}
				else if( D>0 &&  isOppose(D, opp,elements,temp))
				{
					elements="";
				}
				else
				{
					elements+=temp;
				}

			}
		}
		fout<<"Case #"<<i<<": [";
		templength=elements.length();
		for(int P=0; P<templength; P++)
		{
			if(P != 0 )
				fout<<", ";
			fout<<elements[P];
		}
		fout<<"]\n";
		delete[] comb;
		delete[] opp;


	}
	return 0;
}

bool isOppose(int D, oppose * opp, const string & A, char b)
{
	int temp;
	for(int i=0 ; i<D; i++)
	{
		if(b == opp[i].oppone) 
		{
			temp=A.length();
			for(int j=0; j< temp; j++)
			{
				if( A[j] == opp[i].opptwo)
					return true;
			}
		}
		if ( b== opp[i].opptwo)
		{
			temp=A.length();
			for(int j=0; j< temp; j++)
			{
				if( A[j] == opp[i].oppone)
					return true;
			}
		}
	}
	return false;
}
int isCombine(int C, combine* comb, char a, char b)
{
	for(int i=0; i<C ; i++)
	{
		if( (comb[i].one == a && comb[i].two == b ) || (comb[i].one == b && comb[i].two == a))
			return i;
	}
	return -1;
}
char returnCombine(combine* C, int i)
{
	return C[i].result;
}