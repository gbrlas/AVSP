#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
	int t;
	double  c, f, x, rate;
	cin >> t;
	ofstream myfile;
  	myfile.open ("output.txt");
	for(int i = 0; i < t ; i++ ) {
		cin>>c;
		cin>>f; 
		cin>>x;
		
		double last_time = 0;
		double farm_time = 0;
		double new_time = 0;
		double rate = 2;
		last_time = (x/rate);
		farm_time = (c/rate);
		
		if(last_time <= 1){
			cout<<fixed;
			cout<<"Case #"<<i+1<<": "<<setprecision(7)<< last_time<< endl;
			myfile<<"Case #"<<i+1<<": "<<setprecision(7)<< last_time<< endl;
		}
		else{
			while(true){
				rate += f;
				new_time = farm_time+(x/rate);
				if(last_time > new_time){
					last_time = new_time;
					farm_time +=(c/rate);
					continue;
				}else{
					cout<<fixed;
					cout<<"Case #"<<i+1<<": "<<setprecision(7)<<last_time<<endl;
					myfile<<"Case #"<<i+1<<": "<<setprecision(7)<< last_time<< endl;
					break;
				}
			}
		}
	}
	myfile.close();
	return 0;
}
