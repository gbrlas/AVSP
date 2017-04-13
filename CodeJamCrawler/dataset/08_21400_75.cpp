#include<cstdio>
#include<string>
#include<map>
#include<vector>
using namespace std;

bool color[101];

int go(int k, int s, vector<int>&v)
{
    for(int i=0; i<s; i++) color[i]=true;
    int mx=k,licznik=s;
    for(int i=k; i<v.size() && licznik>0 ; i++)
    {
	if(color[v[i]]) {mx=i; licznik--;}
	color[v[i]]=false;
    }
    if(licznik) return v.size();
    return mx;
}

main()
{
    int t,s,q;
    scanf("%d\n",&t);
    map<string,int>M;
    vector<int>v;
    for(int test=1; test<=t; test++)
    {
	M.clear(); v.clear();
	scanf("%d\n",&s);
	for(int i=0; i<s; i++)
	{
	    string str=""; char c=getchar();
	    while(c!='\n' && c!=EOF) {str+=c; c=getchar();}
	    M[str]=i;
	}
	scanf("%d\n",&q);
	for(int i=0; i<q; i++)
	{
	    string str=""; char c=getchar();
	    while(c!='\n' && c!=EOF) {str+=c; c=getchar();}
	    v.push_back(M[str]);
	}
	int k=0,res=-1;
	while(k<v.size())
	{	
	    k=go(k,s,v); res++;
	}
	res= res>0?res:0;
	printf("Case #%d: %d\n",test,res);
    }
    return 0;
}