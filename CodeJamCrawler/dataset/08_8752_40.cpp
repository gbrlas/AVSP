// UglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "vector"
#include "string"
#include "iostream"
#include "sstream"
#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "fstream"
using namespace std;
long long  g;
int isugly(long long  n)
{
	if(n<0) n=-n;
	if(n%2==0) return 1;
	if(n%3==0) return 1;
	if(n%5==0) return 1;
	if(n%7==0) return 1;
	return 0;
}
void dfs(string &num, long long pos, long long  cur,long long  com, long long  positive)
{
	if(pos>=num.size()) 
	{
		if(isugly(cur+com*positive)) g++;
		return;
	}
	long long  n=num[pos]-'0';
	dfs(num,pos+1,cur,com*10+n,positive);
	dfs(num,pos+1,cur+com*positive,n,1);
	dfs(num,pos+1,cur+com*positive,n,-1);
}
int main()
{
	int N;
	ifstream fin("c:\\B-small-attempt1.in");
	ofstream fout("c:\\UglyNumber.txt");
	fin>>N;
	for(int i=0;i<N;i++)
	{
		string num;
		fin>>num;
		int start=num[0]-'0';
		g=0;
		dfs(num,1,0,start,1);
		int ans=g;
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}

