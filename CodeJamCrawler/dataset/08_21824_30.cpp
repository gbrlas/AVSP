#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("A-large.in",ios_base::in);
ofstream fout("A-large.out",ios_base::out);
int save();
int main()
{
	int no_case;
	fin>>no_case;
	fin.ignore(1,'\n');
	while(no_case--)
		save();
	return 0;
}
int save()
{
	int no_switch=1;
	static int n=1;
	int no_eng,no_query;
	fin>>no_eng;
	fin.ignore(1,'\n');
	int *a=new int[no_eng];
	for(int k=0;k<no_eng;k++)
		a[k]=-1;
	char s[101][110],q[1001][110];
	for(int i=0;i<no_eng;i++)
		{	
			fin.get(s[i],105);
			fin.ignore(1,'\n');
		}
	fin>>no_query;
	fin.ignore(1,'\n');
	for(int i=0;i<no_query;i++)
		{
			fin.get(q[i],105);
			fin.ignore(1,'\n');
		}
	int big=0;
	while(1)
	{
		for(int j=0;j<no_eng;j++)
		for(int i=big;i<no_query;i++)
			if(!strcmp(q[i],s[j]))
				{
					a[j]=i;break;
				}
		for(int k=0;k<no_eng;k++)
			if(a[k]==-1)
			{fout<<"Case #"<<n<<": "<<no_switch-1<<endl;++n;return 0;}
		for(int k=0;k<no_eng;k++)
		if(a[k]>=big)
			big=a[k];
		for(int k=0;k<no_eng;k++)
			if(a[k]<big)
				a[k]=-1;
		++no_switch;
				
	}		
}
