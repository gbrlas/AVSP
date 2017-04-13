#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream fin("C-small.in");
const int MAX = 500;
char s[MAX+1];
char *p="welcome to code jam";
const int m=strlen(p);
int n;
int r[MAX][19];
int N;

int get_r(int i, int j)
{
	if(r[i][j]>0) return r[i][j];

	if(n-i<m-j) r[i][j]=0;
	else if(j==m-1) {
		r[i][j]=get_r(i+1,j);
		if(s[i]==p[j]) r[i][j]++;
	}
	else if(s[i]==p[j]) r[i][j]=get_r(i+1,j+1)+get_r(i+1,j);
	else r[i][j]=get_r(i+1,j);
	if(r[i][j]>=10000) r[i][j]%=10000;
	return r[i][j];
}

int main()
{
	fin>>N;
	fin.getline(s,MAX);
	for(int i=1;i<=N;i++) {
		memset(&r[0][0],-1,sizeof(int)*MAX*19);
		fin.getline(s, MAX);
		n = strlen(s);
		printf("Case #%d: %04d\n", i, get_r(0,0));
	}
	return 0;
}