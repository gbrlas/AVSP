#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<iomanip>
using namespace std;

vector<double> WP;
vector<double> OWP;
vector<double> OOWP;

void print(int x)
{
	//cout<<x<<endl;
	//cout<<WP[x]<<"  "<< OWP[x]<<"  "<<OOWP[x]<<endl; 
	double R = (WP[x]/2.0 + OWP[x] + OOWP[x]/2.0 )/2.0;
	//cout<<showpoint<<fixed<<setprecision(R)<<endl;
	cout<<R<<endl;
}

int main()
{
	int T,N;
	string s;
	scanf("%d",&T);
	for(int caso=1;caso<=T;++caso)
	{
		cin>>N;
		vector<string> VS;
		for(int i=0;i<N;++i){cin>>s;VS.push_back(s);}
		
		WP.clear();
		OWP.clear();
		
		
		for(int i=0;i<N;++i)
		{
			int perdidos=0;
			int ganados=0;
			for(int j=0;j<N;++j)
			{
				if(VS[i][j]=='1')ganados++;
				if(VS[i][j]=='0')perdidos++;
			}
			//double WP = (double)ganados/((double)(ganados+perdidos));
			WP.push_back((double)ganados/((double)(ganados+perdidos)));
			
			//OWP
			double suma=0.0;
			int cont=0;
			for(int j=0;j<N;++j)
			{
				if(VS[i][j]!='.')//contra los que jugue
				{
					cont++;
					int gan=0;
					int perd=0;
					for(int k=0;k<N;++k)
					{
						if(k!=i)
						{
							if(VS[j][k]=='1')gan++;
							if(VS[j][k]=='0')perd++;
						}
					}
					suma += (double)gan/(double(gan+perd));
				}
			}
			OWP.push_back(suma/(double)cont);
		}
		OOWP=vector<double>(N,0.0);
		for(int i=0;i<N;++i)
		{	
			int cont=0;
			for(int j=0;j<N;++j)
			{
				if(VS[i][j]!='.')
				{
					cont++;
					OOWP[i]+=OWP[j];
				}
			}
			OOWP[i] /= (double)cont;
		}
		
		cout<<"Case #"<<caso<<":"<<endl;
		for(int i=0;i<N;++i)
		{
			print(i);
		}
	}
}





