#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
#include"map"
#include"set"
#include"string.h"
#include"string"
#include"math.h"
#include"queue"
using namespace std;
#define FOR(i,a,b)	for(i=a;i<b;i++)
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL>  VLL;
typedef pair<int,int> PI;
typedef pair<LL,LL> PLL;
LL A[110];
LL powe(LL i)
	{
	LL re=1;
	while(i--)
		re*=10;
	return re;
	}
vector<LL> v;
bool palin(LL num)
	{
	LL num1=num,i,j,len=0,len1;
	while(num1)
		{len++;	num1/=10;}
	num1=num;
	for(i=len-1;i>=0;i--)
		{A[i]=num1%10;	num1/=10;}
	num1=num;
	FOR(i,0,len/2)
		{
		if(A[i]!=A[len-1-i])	return false;
		}
	return true;
	}
void pre()
	{
	LL i,j;
	FOR(i,1,10000010)
		{
		if(palin(i)&&palin(i*i))	v.push_back(i*i);
		}
	}
LL ans(LL a,LL b)
	{
	LL i=0,re=0;
	while(i<v.size() && v[i]<a)	{i++;}
	while(i<v.size() && v[i]<=b)	{re++;	i++;}
	return re;
	}
int main()
	{
	LL te,t,i,j,a,b;
	pre();
	cin>>t;
	FOR(te,1,t+1)
		{
		cin>>a>>b;
		cout<<"Case #"<<te<<": "<<ans(a,b)<<endl;
		}
	return 0;
	}
