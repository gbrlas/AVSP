#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	ofstream out("B.out");
	ifstream in("B.in");
	int T,t;

	char mapTable[193];
	for(t=0;t<192;t++)
		mapTable[t]=0;

	char keyNo[23];
	for(t=0;t<23;t++)
		keyNo[t]=8;
	keyNo['Q'-'A']=0;
	keyNo['W'-'A']=1;
	keyNo['E'-'A']=2;
	keyNo['R'-'A']=3;
	keyNo['A'-'A']=4;
	keyNo['S'-'A']=5;
	keyNo['D'-'A']=6;
	keyNo['F'-'A']=7;

	in>>T;
cout<<T<<endl;
	for(t=1;t<=T;t++)
	{
		char tmp[101];
		int i,I,j,rx;
		unsigned char opp[8], com[8];
		for(i=0;i<8;i++)
		{
			opp[i]=0;
			com[i]=0;
		}

		in>>i;
cout<<t<<':'<<i<<' ';
		if(t==17)
			cout<<'d';
		while(i--)
		{
			in>>tmp;
cout<<tmp<<' ';
			tmp[0]=keyNo[tmp[0]-'A'];
			tmp[1]=keyNo[tmp[1]-'A'];
			com[tmp[0]]|=1<<tmp[1];
			com[tmp[1]]|=1<<tmp[0];
			mapTable[(1<<tmp[0])|(1<<tmp[1])]=tmp[2]-'A';
		}

		in>>i;
cout<<i<<' ';
		while(i--)
		{
			in>>tmp;
cout<<tmp<<' ';
			tmp[0]=keyNo[tmp[0]-'A'];
			tmp[1]=keyNo[tmp[1]-'A'];
			opp[tmp[0]]|=1<<tmp[1];
			opp[tmp[1]]|=1<<tmp[0];
		}

		in>>I;
cout<<I<<' ';
		in>>tmp;
cout<<tmp<<endl;
		for(i=0;i<I;i++)
			tmp[i]-='A';

		j=0;
		rx=0;
		for(i=0;i<I-1;i++)
		{
			if(com[keyNo[tmp[i]]]&(1<<keyNo[tmp[i+1]]))
			{
				tmp[j++]=mapTable[(1<<keyNo[tmp[i]])|(1<<keyNo[tmp[i+1]])];
				i++;
			}
			else
			{
				tmp[j++]=tmp[i];
				rx|=1<<keyNo[tmp[i]];
//				if(rx&opp[keyNo[tmp[i+1]]])
//				{
//					j=0;
//					rx=0;
//					i++;
//				}
			}

			if(rx&opp[keyNo[tmp[i+1]]])
			{
				j=0;
				rx=0;
				i++;
			}
		}
		if(i==I-1)
			tmp[j++]=tmp[i];

		if(j==0)
			out<<"Case #"<<t<<": []"<<endl;
		else
		{
			out<<"Case #"<<t<<": ["<<(char)('A'+tmp[0]);
			for(i=1;i<j;i++)
				out<<", "<<(char)('A'+tmp[i]);
			out<<"]"<<endl;
		}
	}

	in.close();
	out.close();
	cout<<"finished";
	cin>>T;
}

