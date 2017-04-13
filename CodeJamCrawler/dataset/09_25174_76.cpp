#include<iostream>
#include<string>
using namespace std;
#define Inf 40

char cc[Inf];
string str;
char stt[20] = "welcome to code jam" ;
int z = 19;
int ans = 0;
int len;

void dfs(int mark1 , int mark2)
{
	int i;
	if( mark2 == 19)
	{
		ans ++;
		return ;
	}
	if( len - mark1 < z - mark2) return ;
	for( i = mark1 ; i < len ; ++i)
	{
		if(str[i] == stt[mark2])
		{
			dfs( i + 1 , mark2 + 1);
		}
	}
}
void date_in()
{
	ans = 0;
	getline( cin , str);
	len = str.length();
	dfs( 0 , 0);
	ans %= 10000;
	printf("%04d\n",ans);
}
int main()
{
	int cases;
	//freopen("date.in","r",stdin);
	scanf("%d\n",&cases);
	int t = 1;
	while( cases --)
	{
		printf("Case #%d: ",t);
		t ++;
		date_in();
	}
	return 0;
}
