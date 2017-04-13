#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MaxN=111;
const int MaxLen=22;
string str[MaxN],ordr;
int ans,mark,cnt,N,M,tmp,lft,head,flag;
int len[MaxN],Q[MaxLen],nxt[MaxN],fnt[MaxN],v[MaxLen];


void kick(int x)
{
	--lft;
	if (head==x)
	{
		head=nxt[x];
		return;
	}
	if (nxt[x]==0)
	{
		nxt[fnt[x]]=0;
		return;
	}
	nxt[fnt[x]]=nxt[x];
	fnt[nxt[x]]=fnt[x];
}

void printt()
{
	for (int p=head; p; p=nxt[p])
		cout<<str[p]<<endl;
}

int calcu(int x)
{
//	cout<<"guess:"<<str[x]<<endl;
	head=1;
	for (int i=1; i<N; ++i) nxt[i]=i+1;
	nxt[N]=0;
	fnt[1]=0;
	for (int i=2; i<=N; ++i) fnt[i]=i-1;
	nxt[0]=0;
	fnt[0]=0;
	
	lft=N;
	for (int p=head; p; p=nxt[p])
		if (len[p]!=len[x]) kick(p); 
	if (lft==1) return 0;
//	printt();
	
	tmp=0;
	for (int i=0; i<26; ++i)
	{
		flag=0;
		for (int p=head; p; p=nxt[p])
		{
			if (flag) break;
			for (int j=0; j<len[p]; ++j)
				if (str[p][j]==ordr[i])
				{
					flag=1;
					break;
				}
		}
		if (!flag) continue;
		flag=0;
		for (int j=0; j<len[x]; ++j) 
			if (str[x][j]==ordr[i]) 
			{
				v[j]=1;
				flag=1;
			}
			else v[j]=0;
//		cout<<ordr[i]<<endl;
		if (!flag)
		{
			++tmp;
			for (int p=head; p; p=nxt[p])
			{
				for (int j=0; j<len[p]; ++j)
					if (str[p][j]==ordr[i])
					{
						kick(p);
						break;
					}
			}
//			printt();
			continue;
		}
		for (int p=head; p; p=nxt[p])
		{
			for (int j=0; j<len[x]; ++j)
			{
				if (((v[j])&&(str[p][j]!=ordr[i]))||((!v[j])&&(str[p][j]==ordr[i])))
				{
					kick(p);
					break;
				}
			}
		}
//		printt();
		if (lft==1) return tmp;
	}
	return tmp;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	int Testnum;
	cin>>Testnum;
	for (int Test=1; Test<=Testnum; ++Test)
	{
		printf("Case #%d: ",Test);
		cin>>N>>M;
		for (int i=1; i<=N; ++i) cin>>str[i];
		for (int i=1; i<=N; ++i) len[i]=str[i].length();
		for (int i=1; i<=M; ++i)
		{
			cin>>ordr;
			ans=-1;
			for (int j=1; j<=N; ++j)
			{
				cnt=calcu(j);
//				cout<<j<<":"<<cnt<<endl;
				if (cnt>ans)
				{
					ans=cnt;
					mark=j;
//					cout<<mark<<endl;
				}
			}
			if (i>1) cout<<" ";
			cout<<str[mark];
		}
		cout<<endl;
	}
	return 0;
}
/*
Case #5: vrmc dy kkax w owhn eaqo iraq izhin gcic
Case #6: cqwswobfwf ajozvpvfun soclacgque ewmewwfrvk mojqqmnhbc ncocfrfgmx umyoougmii ijcawjzcaz zyypvnzbkc vdgdvothqd
Case #7: ppx hxx ypj fff fff fff jhj jhj fff ypj
Case #8: bbbccc kkkjjb kkcclc bbbccc llklkk llklkk jjllll bbbccc bbbjbl llklkk
Case #9: rurrurruuu uuuuuuuuu rurrurruuu uuuuuuuuu uuuuuuuuu rurrurruuu uuuuuuuuu rurrurruuu rurrurruuu uuuuuuuuu
Case #10: xxooxxi oooioio xddxxxd xddxxxd oooioio dodoxoo oooioio oooxxxx diiiddd oooxxxx
*/