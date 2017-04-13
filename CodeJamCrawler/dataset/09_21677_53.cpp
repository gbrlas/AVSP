#include<iostream>
#include<string>
using namespace std;

int main()
{
	bool flagB=false, flagF=false;
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
					flagB=true;
				else
					flagB=false;
					
				flagF=false;
				if(flagB==false)
				{
					if(b.at(k)==a[j][p])
					{
						p++;
						flagF=true;
					}
					else
					{
						flagF=false;
						break;
					}
				}
				else
				{
					while(b.at(k)!=')' && k<length)
					{
						if(b.at(k)==a[j][p])
						{
							if(flagF!=true)
								p++;
							flagF=true;
						}
						k++;
					}
				}
				if(flagF!=true)
					break;
				
			}
			if(flagF==true)
				count++;

		}
		printf("Case #%d: %d\n",i+1,count);
	}
	
}
