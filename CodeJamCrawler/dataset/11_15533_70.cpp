#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

long NT,t,N;
string A[107],B[107],s;
char st[107];
long sp,na,nb;

bool magic()
{
	long i;
	for(i=1;i<=na;i++)
		if(A[i][0]==st[sp] && A[i][1]==st[sp-1] ||
		   A[i][1]==st[sp] && A[i][0]==st[sp-1])
		{
			sp--;
			st[sp] = A[i][2];
			return true;
		}
	return false;
}

bool checkopos(char c1,char c2)
{
	for(long i=1;i<=nb;i++)
		if(B[i][0]==c1 && B[i][1]==c2 ||
		   B[i][0]==c2 && B[i][1]==c1) return true;
	return false;
}

void Add(char c)
{
	long i;
	sp++; st[sp] = c;
	while(sp>=2 && magic());
	for(i=1;i<sp;i++)
		if(checkopos(st[i],st[sp])) { sp=0; return; }
}

int main()
{
	long i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>NT;
	for(t=1;t<=NT;t++)
	{
		cout<<"Case #"<<t<<": ";
		cin>>na;
		for(i=1;i<=na;i++) cin>>A[i];
		cin>>nb;
		for(i=1;i<=nb;i++) cin>>B[i];
		cin>>N;
		cin>>s;
		sp = 0;
		for(i=0;i<N;i++) Add(s[i]);
		cout<<"[";
		if(sp>0) cout<<st[1];
		for(i=2;i<=sp;i++) cout<<", "<<st[i];
		cout<<"]"<<endl;
	}
	
	return 0;
}
