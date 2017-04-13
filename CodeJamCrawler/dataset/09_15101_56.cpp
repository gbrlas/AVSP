#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
map<string,int> check;
int main() 
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int T;
	cin>>T;
	int ind=0;
	while(T--)
	{
		ind++;
		int L;
		cin>>L;
		string s[102];
		getline(cin,s[0]);
		for(int i=0;i<L;i++)
			getline(cin,s[i]);
		//cout<<s[1]<<endl;
		int A;
		cout<<"Case #"<<ind<<":"<<endl;
		cin>>A;
		for(int i=0;i<A;i++)
		{
			check.clear();
			int n;
			string ss;
			cin>>ss;
			cin>>n;
			for(int j=0;j<n;j++)
			{
				cin>>ss;
				check[ss]=1;
			}
			int b=0;
			double p=1;
			double pp=0;
			double mno=1;
			int st=0;
			int i=0,j=0;
			int mb=0;
			string slo="";
			while(true)
			{
				if(st==-1)break;
				if(st==0)
				{
					if(s[i][j]=='(')
					{
						st=10;
						b++;
						mb=b;
					}
				}
				else
				{
					
					if(st==10)
					{
						if(s[i][j]=='0' || s[i][j]=='1')
						{
							if(s[i][j]=='1')pp=1;
							st=11;
						}
					}
					else 
					{
						if(st==11)
						{
							if(s[i][j]>='0' && s[i][j]<='9')
							{
								mno*=0.1;
								pp+=mno*(s[i][j]-'0');
							}
							if(s[i][j]==')')
							{
								p*=pp;
								st=-1;
								pp=0;
								mno=1;
							}
							if(s[i][j]==' ')
							{
								p*=pp;
								st=12;
								pp=0;
								mno=1;
							}
						}
						else
						{
							
							if(st==12)
							{
								if(s[i][j]==')')
								{
									st=-1;
								}
								if(s[i][j]>='a' && s[i][j]<='z')
								{
									st=13;
									slo+=s[i][j];
								}
							}
							else
							{
								if(st==13)
								{
									if(s[i][j]>='a' && s[i][j]<='z')
									{
										st=13;
										slo+=s[i][j];
									}
									if(s[i][j]=='(')
									{
										b++;
										if(check.count(slo))
										{
											mb=b;
											st=10;
											slo="";
										}
										else
										{
											st=20;
											slo="";
										}
									}
								}
								else
								{
									if(st==20)
									{
										if(s[i][j]=='(')b++;
										if(s[i][j]==')')
										{
											b--;
											if(b==mb)st=0;
										}
									}
								}
							}
						}
					}
				}
				if(j+1>=s[i].length())
				{
					i++;
					j=0;
				}
				else j++;
			}
			printf("%.7f\n",p);
		}
	}
	return 0;
}