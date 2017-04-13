#include <iostream>
using namespace std;
char P[4][4];
int main()
{
	ios_base::sync_with_stdio(0);
	int zest;
	cin>>zest;
	for(int aa=1; aa<=zest; aa++)
	{
		int koniec=1;
		for(int n=0; n<4; n++)
		{
				cin>>P[n];
		}

		for(int n=0; n<4; n++)
		{
			for(int a=0; a<4; a++)
			{
				if(P[a][n]=='.') koniec=0;
			}
		}
		char znak;
		bool czy=1;
		bool czykoniec=0;
		for(int n=0; n<4; n++)
		{
			czy=1;
			znak=P[n][0];
			if(znak=='.') continue;
			for(int a=0; a<4; a++)
			{
				if(P[n][a]!=znak && P[n][a]!='T')
				{czy=0;
				break;}
			}
			if(czy==1)
			{
				cout<<"Case #"<<aa<<": "<<znak<<" won"<<endl;
				czykoniec=1;
				break;	
			}
		}
		if(czykoniec==0)
		{
			for(int n=0; n<4; n++)
			{
				czy=1;
				znak=P[0][n];
				if(znak=='.') continue;
				for(int a=0; a<4; a++)
				{
					if(P[a][n]!=znak && P[a][n]!='T')
					{czy=0;
					break;}
				}
				if(czy==1)
				{
					cout<<"Case #"<<aa<<": "<<znak<<" won"<<endl;
					czykoniec=1;
					break;	
				}
			}
		}
		if(czykoniec==0)
		{
			czy=1;
			znak=P[0][0];
			if(znak=='.') znak='$';
			for(int a=0; a<4; a++)
			{
				if(P[a][a]!=znak && P[a][a]!='T')
				{
					czy=0;
					break;
				}
			}
			if(czy)
			{
				cout<<"Case #"<<aa<<": "<<znak<<" won"<<endl;
				czykoniec=1;
				
			}
		}
		
		if(czykoniec==0)
		{
			czy=1;
			znak=P[0][3];
			if(znak=='.') znak='$';
			for(int a=0; a<4; a++)
			{
				if(P[a][3-a]!=znak && P[a][3-a]!='T')
				{
					czy=0;
					break;
				}
			}
			if(czy)
			{
				cout<<"Case #"<<aa<<": "<<znak<<" won"<<endl;
				czykoniec=1;
					
			} 
		}
		if(czykoniec==0)
		{
			if(koniec==0)
			{
				cout<<"Case #"<<aa<<": Game has not completed"<<endl;
			}
			else
			{
				cout<<"Case #"<<aa<<": Draw"<<endl;
			}
		}
	}
}
