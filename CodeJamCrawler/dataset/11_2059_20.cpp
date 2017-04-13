#include <fstream>
#include <iostream>
#include<cassert>
#include<cmath>
#include<limits>
#include<sstream>
#include<string>
using namespace std;




int main()
{
	ifstream in("A-large.in");
	ofstream out("output.out");
	int N,T,m,i,opc,bpc,num;
	in>>T;
	char sign,psign;
	int step=0;
	int opos,bpos,bstep,ostep;
	for(m=0;m<T;m++)
	{
		in>>N;
		opos=1,bpos=1;
		step=0;
		sign=NULL;
		bstep=ostep=0;
		cout<<"**********************"<<endl;
		for (i=0;i<N;i++)
		{
			in>>sign;
			cout<<sign<<endl;
			

			if(sign=='O')
			{
				
				in>>opc;
				if (opos<=opc)
				{
					num=opc-opos;
					//if(opc<=ostep)
					//	ostep=num;
					if (num>ostep)
					{
						
						
						num-=ostep;
						ostep=0;
						
						step+=(num+1);
						bstep+=num+1;
					}
					else if (num<=ostep)
					{
						ostep=0;
						step+=1;
						bstep+=1;
					}
					opos=opc;
					
					//bpos+=(num+1);
					
				}
				else if (opos>opc)
				{
					num=opos-opc;
					if(num>ostep)
					{
						
						num-=ostep;
						ostep=0;
						
						step+=(num+1);
						bstep+=num+1;

					}
					else if (num<=ostep)
					{
						ostep=0;
						step+=1;
						bstep+=1;

					}
					opos=opc;
					
				}
				
			}
			else if (sign=='B')
			{
				in>>bpc;
				
				if (bpos<=bpc)
				{
					num=bpc-bpos;
					//if(bpc<=bstep)
					//	bstep=num;
					
					if (num>bstep)
					{
						
						
						num-=bstep;
						bstep=0;
						
						step+=(num+1);
						ostep+=num+1;
					}
					else if (num<=bstep)
					{
						//bstep-=num;
						bstep=0;
						step+=1;
						ostep+=1;
					}
					bpos=bpc;
				}
				else if (bpos>bpc)
				{
					num=bpos-bpc;
					if(num>bstep)
					{
						
						num-=bstep;
						bstep=0;
						
						step+=(num+1);
						ostep+=num+1;
						
					}
					else if (num<=bstep)
					{
						bstep=0;
						step+=1;
						ostep+=1;
						
					}
					bpos=bpc;
					
				}
			}
			psign=sign;

		}
		out<<"Case #"<<m+1<<": "<<step<<"\n";

	}
}
