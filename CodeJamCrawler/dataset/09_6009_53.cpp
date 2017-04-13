#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <iostream>
#include <fstream>
using namespace std;
int T,H,W;
int altitude[100][100];
int label[100][100];
int glabel;
int fx[4]={0,-1,1,0};
int fy[4]={-1,0,0,1};
const int MaxA=10000;
void mark(int i,int j)
{
	int k,nexti,nextj,nextdir;
	int tempH;
	if (label[i][j]!=-1) 
	{
		return;
	}
	tempH=MaxA;
	for (k=0;k<4;k++) 
	{
		nexti=i+fy[k];nextj=j+fx[k];
		if (nexti>=0&&nexti<H&&nextj>=0&&nextj<W) 
		{
			if (altitude[nexti][nextj]<tempH) 
			{
				tempH=altitude[nexti][nextj];
				nextdir=k;
			}
		}
	}
	if (tempH>=altitude[i][j])
	{
		label[i][j]=glabel;glabel++;
		return;
	}
	else
	{
		nexti=i+fy[nextdir];nextj=j+fx[nextdir];
		if (label[nexti][nextj]==-1) 
		{
			mark(nexti,nextj);
		}
        label[i][j]=label[nexti][nextj];
	}
}
void main()
{
	int i,s,t;
	ifstream fin("BProblem.in");
	ofstream fout("BProblem.out");
	fin>>T;
	for (i=1;i<=T;i++)
	{
		fin>>H>>W;
		for (s=0;s<H;s++) 
		{
			for (t=0;t<W;t++)
			{
				fin>>altitude[s][t];
				label[s][t]=-1;
			}
		}
        glabel=0;
		for (s=0;s<H;s++) 
		{
			for (t=0;t<W;t++)
			{
				mark(s,t);
			}
		}
		fout<<"Case #"<<i<<":"<<endl;
		for (s=0;s<H;s++) 
		{
			for (t=0;t<W;t++)
			{
				fout<<(char)(label[s][t]+'a')<<' ';
			}
			fout<<endl;
		}
	}
	fin.close();
	fout.close();
}