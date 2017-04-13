#include <cstdio>
#include <iostream>
#include <string>
typedef long long int64;
using namespace std;

string s[200];
int len[200],v[200];
int64 t[200];

int calc(string list,string as,int asv,int m)
{
    int ll=as.size(),alp,wa=0,res=0,gua=0;
    string now=as;

	for(int i=0;i<ll;i++) now[i]='_';
    for(int i=0;i<26;i++)
    {
        alp=0;
        for(int j=0;j<m;j++)
            if(len[j]==ll && (wa&(v[j]))==0)
            {
				bool succ=true;
				
				for(int k=0;k<ll && succ;k++)
					if((now[k]=='_' && (gua&(1<<(s[j][k]-'a')))==0 ) || now[k]==s[j][k]) succ=true;
					else succ=false;
					
				if(succ)
                	alp=alp|v[j];
			}
			
        if(!(alp&(1<<(list[i]-'a')))) continue;
        if(asv&(1<<(list[i]-'a')))
        {
            for(int j=0;j<ll;j++)
                if(as[j]==list[i])
					now[j]=list[i];
			gua=gua|(1<<(list[i]-'a'));
        }
        else
        {
            wa=wa|(1<<(list[i]-'a'));
            res++;
        }
    }
    return res;
}

int main()
{
    freopen("B-small-attempt3.in","r",stdin);freopen("B-small-attempt3.out","w",stdout);
    //freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    int test;

    scanf("%d",&test);
    for(int times=1;times<=test;times++)
    {
        int m,n;
        string list;

        cin>>m>>n;
        for(int i=0;i<m;i++)
            cin>>s[i];
        for(int i=0;i<m;i++)
        {
            len[i]=s[i].size();v[i]=0;
            for(int j=len[i]-1;j>=0;j--)
                v[i]=v[i]|(1<<(s[i][j]-'a'));
        }
        cout<<"Case #"<<times<<":";
        for(int i=0;i<n;i++)
        {
            int best=-1;
            string ans;

            cin>>list;
            for(int j=0;j<m;j++)
            {
                int tmp=calc(list,s[j],v[j],m);

                if(tmp>best)
                {
                    best=tmp;
                    ans=s[j];
                }
            }
            cout<<" "<<ans;
        }
        cout<<endl;
    }

    return 0;
}
