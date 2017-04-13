#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int main()
{
	int T,R,k,N,temp;
	cin>>T;
	for(int caso=1;caso<=T;++caso)
	{
		cin>>R>>k>>N;
		//R numero de veces
		//k numero de personas
		queue<int> Q;
		for(int i=0;i<N;++i)
		{
			cin>>temp;
			Q.push(temp);
		}
		int cant=0;
		for(int i=0;i<R;++i)
		{
			int suma=0;
			int u=0;
			while(suma+Q.front()<=k && u<Q.size())
			{
				int h=Q.front();
				Q.pop();
				suma+=h;
				Q.push(h);
				u++;
			}
			cant+=suma;
		}
		cout<<"Case #"<<caso<<": "<<cant<<endl;
	}
}


