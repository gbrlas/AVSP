//shivi..coding is adictive!!
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<functional>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<fstream>
using namespace std;
long long int ans=0,a,b;
string arr[40]={"1","4","9","121","484","10201","12321","14641","40804","44944","1002001","1234321","4008004","100020001","102030201","104060401","121242121","123454321","125686521","400080004","404090404","10000200001","10221412201","12102420121","12345654321","40000800004","1000002000001","1002003002001","1004006004001","1020304030201","1022325232201","1024348434201","1210024200121","1212225222121","1214428244121","1232346432321","1234567654321","4000008000004","4004009004004"};

long long int number(string s)
{
	long long int sum=0;
	int l=s.length(),k=l-1;
	for(int i=0;i<l;++i)
	{
		sum+=(s[i]-'0')*(long long int)pow(10.0,k);
		--k;
	}
	return sum;
}
void work()
{
	ans=0;
	for(int i=0;i<40;++i)
	{
		if(number(arr[i])<=b && number(arr[i])>=a)
		++ans;
		else if(number(arr[i])>b)
		break;
	}
	
	
}
int main()
{
	fstream f,m;
	f.open("C:\\Users\\shivendra\\Desktop\\fair_square2.txt",ios::out|ios::binary);
	m.open("C:\\Users\\shivendra\\Desktop\\kkk.txt",ios::in|ios::binary);
	int t,i=1;
	m>>t;
	while(t--)
	{
		m>>a>>b;
		f<<"Case #"<<i++<<": ";
		work();
		f<<ans<<endl;
	}
	f.close();
	m.close();
}
