#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int follow(vector <int> start,vector <int> arrive);

void main()
{
	ifstream in("B-small-attempt1.in");
	ofstream out("B-small.out");
	int n,t,na,nb,hour,minute,temp,k=0,l=0;
	char ch;
	in>>n;
		for (int c=0;c<n;c++)
		{
			in>>t>>na>>nb;
	vector <int> starta;
	vector <int> arrivea;
	vector <int> startb;
	vector <int> arriveb;

	for (int i=0;i<na;i++)
	{
		in>>hour>>ch>>minute;
		starta.push_back(minute+hour*60);
		in>>hour>>ch>>minute;
		arrivea.push_back(minute+hour*60+t);
	}
	for (int j=0;j<nb;j++)
	{
		in>>hour>>ch>>minute;
		startb.push_back(minute+hour*60);
		in>>hour>>ch>>minute;
		arriveb.push_back(minute+hour*60+t);
	}
	if (na==0 || nb==0) {out<<"Case #"<<c+1<<": "<<na<<" "<<nb<<endl;continue;}

	for (k=0;k<na-1;k++)
		for (l=0;l<na-1-k;l++)
			if (starta[l]>starta[l+1])
			{temp=starta[l];starta[l]=starta[l+1];starta[l+1]=temp;}
	for (k=0;k<na-1;k++)
		for (l=0;l<na-1-k;l++)
			if (arrivea[l]>arrivea[l+1])
			{temp=arrivea[l];arrivea[l]=arrivea[l+1];arrivea[l+1]=temp;}
	for (k=0;k<nb-1;k++)
		for (l=0;l<nb-1-k;l++)
			if (startb[l]>startb[l+1])
			{temp=startb[l];startb[l]=startb[l+1];startb[l+1]=temp;}
	for (k=0;k<nb-1;k++)
		for (l=0;l<nb-1-k;l++)
			if (arriveb[l]>arriveb[l+1])
			{temp=arriveb[l];arriveb[l]=arriveb[l+1];arriveb[l+1]=temp;}
	int anum=na-follow(starta,arriveb);
	int bnum=nb-follow(startb,arrivea);
	out<<"Case #"<<c+1<<": "<<anum<<" "<<bnum<<endl;
		}

}


int follow(vector <int> start,vector <int> arrive)
{
	int number=0;
	int i=0,j=0,k=0;
	do
	{
		for (i=k;i<start.size();i++)
		{
			if (start[i]>=arrive[j]) {k=i+1;number++;break;}
		}
		j++;
	}
	while (j<arrive.size() && k<start.size());
	return number;
}
