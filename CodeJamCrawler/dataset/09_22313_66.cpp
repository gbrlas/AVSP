//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <io.h>
#include <vector>

using namespace std;

#define M 20
#define L 500
#define N 100
#define ALPHA 128
int a[M];
char s[L];
char ptn[M] = {"welcome to code jam"};
const int pl = strlen(ptn);
vector <int>vec[ALPHA];
int n;

int mod (int a)
{	
	return a%10000; 
}
int main() {
	//ifstream fin("in.txt");
	//streambuf *inbuf = cin.rdbuf(in.rdbuf());
	//ofstream fout("out.txt");
	//streambuf *outbuf = cout.rdbuf(out.rdbuf());

	freopen( "C-large.in.txt","r",stdin);
	freopen( "C-large.out.txt","w",stdout);

	for (int j = 0; j < pl; j++)
		vec[ptn[j]].push_back(j);
	//cin>>n;
	scanf("%d",&n);getchar();
	
	for (int i = 0; i < n; i++) {
		memset(a, 0, sizeof a);
		int j = 0; char ch;
		//while (fin.get(ch,'\n') 
		while( (ch = getchar()) != '\n')
			s[j++] = ch;
			s[j] = 0;
		int p;
		for (j = 0; j < strlen(s); j++)
			for (int i = 0; i < vec[s[j]].size(); i++) {
				p = vec[s[j]][i];
				if (p == 0) a[p]++, a[p]=mod(a[p]);
				else  a[p]+=a[p-1], a[p]=mod(a[p]);
			}
		//	cout<<"Case #"<<i+1<<": "<<
		printf("Case #%d: %04d\n",i+1,a[pl-1]);
	}

	//fin.close();
	//cin.rdbuf(inbuf);
	//fout.close();
	//cout.rdbuf(outbuf);
	return 0;
}