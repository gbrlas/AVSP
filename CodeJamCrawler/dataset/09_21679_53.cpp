#include<iostream>
#include<string>
using namespace std;

int main()
{
	bool fl1=false, fl2=false;
	int i,L,D,N;
	char a[5000][15];
	string b;
	scanf("%d%d%d",&L,&D,&N);
	for(i=0; i<D; i++)
		scanf("%s",a[i]);
	for(i=0; i<N; i++)
	{
		cin>>b;
		int count=0, length = b.length();
		for(int j=0; j<D; j++)
		{
			int p=0;
			for(int k=0;k<length; k++)
			{
				if(b.at(k)=='(')
					fl1=true;
				else
					fl1=false;
					
				fl2=false;
				if(fl1==false)
				{
					if(b.at(k)==a[j][p])
					{
						p++;
						fl2=true;
					}
					else
					{
						fl2=false;
						break;
					}
				}
				else
				{
					while(b.at(k)!=')' && k<length)
					{
						if(b.at(k)==a[j][p])
						{
							if(fl2!=true)
								p++;
							fl2=true;
						}
						k++;
					}
				}
				if(fl2!=true)
					break;
				
			}
			if(fl2==true)
				count++;

		}
		printf("Case #%d: %d\n",i+1,count);
	}	
}
