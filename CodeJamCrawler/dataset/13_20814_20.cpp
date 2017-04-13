#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	int T;
	ifstream cin ("input.txt");
	 ofstream cout("Output.txt");
	cin>>T;
	for (int Number=0;Number<T;Number++)
	{
		vector< string> V;
		string temp;
		string S[4];
		bool Draw=true;
		bool typed=false;
		for (int i=0;i<4;i++)
		{
			cin>>temp;
			for (int k=0;k<4;k++)
			if (temp[k] == '.' )
				Draw=false;
			S[i]=temp;

		}
		
			for (int i=0;i<4;i++)
			{
				char C=S[i][i] ;// el 4 diagonals , we 2 bel warb
				int x=0,y=0,z=0,a=0;
				
				
				for (int k=0;k<4;k++)
				{
					
				
					if ((S[i][k]== C || S[i][k]== 'T' )&& C!='.')
						x++;

					if ((S[k][i]== C ||S[i][k]== 'T') && C!='.')
						y++;

					if ((S[k][k] ==C ||S[k][k]=='T') && C!='.')
						z++;

					C=S[0][3];
					
					if ((S[k][3-k] ==C ||S[k][3-k]=='T') && C !='.')
						a++;
					C=S[i][i];
				}
						if (a==4 ) 
						{
							C=S[0][3];
							cout<<"Case #"<<Number+1<<": "<<C<<" won"<<endl;
							typed=true;
						break;
						}
						if (x==4 || y == 4 ||z==4  )
					{
						cout<<"Case #"<<Number+1<<": "<<C<<" won"<<endl;
						typed=true;
						break;
					}
				else 
					{
						x=0;
						y=0;	
							
					}
								
			}
			if (typed==false)
			{
			if (Draw == true)
			{cout<<"Case #"<<Number+1<<": "<<"Draw"<<endl;}//break;}
						else cout<<"Case #"<<Number+1<<": "<<"Game has not completed"<<endl;
						//break;	
			}
				
		}
	return 0;
}
