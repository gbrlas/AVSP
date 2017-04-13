#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
int n_src;
string src;
const int n_ptrn = 19;
const string ptrn = "welcome to code jam";
 
int tbl[500][19];
 
int dfs(const int s_src, const int s_ptrn)
{
   // if(s_src==src.length() )return tbl[s_src][s_ptrn];
 	//if(s_src==s_ptrn)return total;

	if (tbl[s_src][s_ptrn] != -1)
	{
		return tbl[s_src][s_ptrn];
	}
	if (n_src - s_src < n_ptrn - s_ptrn)
	{
		tbl[s_src][s_ptrn] = 0;
		return 0;
	}
	if(src.substr(s_src,n_src)==ptrn.substr(s_ptrn,n_ptrn))
	{
	   	tbl[s_src][s_ptrn]=1;
		return tbl[s_src][s_ptrn];
	}
	else {
		 tbl[s_src][s_ptrn]=0;
		 //return tbl[s_src][s_ptrn];
	}
/*	if (n_src - s_src == n_ptrn - s_ptrn)
	{
		string sub_src = src.substr(s_src, n_src );
		string sub_ptrn = ptrn.substr(s_ptrn, n_ptrn );
		tbl[s_src][s_ptrn] = (sub_src == sub_ptrn) ? 1 : 0;
	//	cout<<sub_src<<" "<<sub_ptrn<<endl;

		return tbl[s_src][s_ptrn];
	}
&*/
	int total = 0;
	total += dfs(s_src+1, s_ptrn);
	total %= 10000;
	if (src[s_src] == ptrn[s_ptrn])
	{
		total += dfs(s_src+1, s_ptrn+1);
		total %= 10000;
	}
	tbl[s_src][s_ptrn] = total;
	return total;
}
 
int main()
{
	int N;
	scanf("%d",&N);
	string temp;
	getline(cin, temp);

	for (int n = 0; n < N; ++n)
	{
		getline(cin, src);
		
		memset(tbl, -1, 500 * 19);
		n_src = src.length();
		int cnt = dfs(0, 0);
		printf("Case #%d: %04d\n", n+1, cnt);
	}
	return 0;
}
