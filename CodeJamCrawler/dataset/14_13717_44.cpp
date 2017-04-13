#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	cout<<fixed;
	cout<<setprecision(7);
	
	int ite;
	cin>>ite;
	double c,f,x;
	for (int i = 1; i <= ite; ++i){
		double rate=2.0;
		double t=0.0,buy_all=0.0,chunk_buy_all=0.0;
		cin>>c>>f>>x;
		if(x<=c)
			cout<<"Case #"<<i<<": "<<x/rate<<endl;
		else{
			//t += c/rate;
			//rate += f;
			while(1){
				buy_all = t + x/rate;
				chunk_buy_all = t + (c/rate) + x/(rate+f);
				if(buy_all - chunk_buy_all <=0.0000001)
					break;
				else{
					t += c/rate;
					rate+=f;
				}
			}
			cout<<"Case #"<<i<<": "<<t+(x/rate)<<endl;
		}
	}
}