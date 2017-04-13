#include <iostream>
#include <string>
using namespace std;
#define maxn 5005

int len,d,n;
string srr[maxn];
bool brr[20][26];

int main()
{
	int i,j,temp,k;
	int count=1;
	while (scanf("%d%d%d",&len,&d,&n)!=EOF)
	{
		getchar();
		for (i=1;i<=d;++i)
		{
			cin>>srr[i];
		}

		int lens,index=0,start,end;
		string s;
		getchar();
		for (i=1;i<=n;++i)
		{
			
			memset(brr,false,sizeof(brr));
			getline(cin,s);
			//cout<<s<<endl;
			index=0;
            lens=s.length();
			for(j=0;j<lens;j++)
			{
				if(s[j]=='(')
				{
					j++;
					
					start=j;
					while(s[j]!=')') j++;
					end=j-1;
                    for(k=start;k<=end;k++)
						brr[index][s[k]-'a']=true;
                    index++;
				}
				else
				{
					 brr[index][s[j]-'a']=true;
					 index++;
				}
			}
			int sum=0;
			for(j=1;j<=d;j++)
			{
                 for(k=0;k<len;k++)
				 {
					 if(!brr[k][srr[j][k]-'a'])
						 break;
				 }
				 if(k==len)
					 sum++;
			}
			printf("Case #%d: %d\n",i,sum);
		}
	}
	return 0;
}