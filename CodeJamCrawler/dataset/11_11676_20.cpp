#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;++t){
		int N;cin >>N;
		vector<vector<int> >win(N,vector<int>(0,0)), loose(N,vector<int>(0,0));
		vector<double> WP(N,0), OWP(N,0), OOWP(N,0), RPI(N,0);

		for(int n=0;n<N;++n){
			string s;cin >> s;

			for(int i=0;i<N;++i){
				if(s[i]=='1') win[n].push_back(i);
				if(s[i]=='0') loose[n].push_back(i);
			}
		}

		for(int n=0;n<N;++n){
			//WP
			WP[n]=win[n].size()/((double)win[n].size()+loose[n].size());
			//cout << n << " " << WP[n] << endl;

			//OWP
			for(int i=0;i<win[n].size();++i){
				double size = win[win[n][i]].size()+loose[win[n][i]].size();
				OWP[n]+=(win[win[n][i]].size())/(size-1);
			}
			for(int i=0;i<loose[n].size();++i){
				double size = win[loose[n][i]].size()+loose[loose[n][i]].size();
				OWP[n]+=(win[loose[n][i]].size()-1)/(size-1);
				//cout << n << " " << loose[n][i] << " " <<(win[loose[n][i]].size()-1)/(size-1) << endl;
			}
			OWP[n]/=(win[n].size()+loose[n].size());
		}


		for(int n=0;n<N;++n){
			//OOWP
			for(int i=0;i<win[n].size();++i)
				OOWP[n]+=OWP[win[n][i]];
			for(int i=0;i<loose[n].size();++i)
				OOWP[n]+=OWP[loose[n][i]];
			OOWP[n] /= win[n].size()+loose[n].size();
		}

		cout  << "Case #" << t << ":" << endl;
		//cout rpi
		for(int n=0;n<N;++n)
			printf("%10.15f\n",0.25*WP[n]+0.5*OWP[n]+0.25*OOWP[n]);

	


	}
	return 0;
}
