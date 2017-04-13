#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>

struct Data{
	int n;
	std::vector<char> data;
};

double calcWP(const Data& input, std::vector<std::vector<bool> >& bd,std::vector<std::vector<int> >& d,int i){
	int w=0,g=0;
	for(int j=0;j<input.n;j++){
		if(bd[i][j]==true){
			g++;
			if(d[i][j]==1) w++;
		}
	}
	if(w!=0) return w/(double)g;
	else return 0;
}

std::string trial(const Data& input){
	std::vector<std::vector<bool> > bd(input.n,std::vector<bool>(input.n,true));
	std::vector<std::vector<int> > d(input.n,std::vector<int>(input.n,-1));
	for(int i=0;i<input.n;i++){
		for(int j=0;j<input.n;j++){
			switch(input.data[i*input.n+j]){
				case '0':
					d[i][j]=0;
					break;
				case '1':
					d[i][j]=1;
					break;
				default:
					bd[i][j]=false;
					break;
			}
			std::cerr << input.data[i*input.n+j] << " ";
		}
		std::cerr << std::endl;
	}

	std::vector<double> wps(input.n,0);
	std::vector<std::vector<double> > wps_t(input.n,std::vector<double>(input.n,0));
	std::vector<double> owps(input.n,0);
	std::vector<double> oowps(input.n,0);
	std::vector<double> rpis(input.n,0);

	for(int i=0;i<input.n;i++){
		wps[i]=calcWP(input,bd,d,i);
		std::cerr << "wp["<< i<< "]=" << std::setprecision(12) << wps[i] << std::endl;
	}

	for(int i=0;i<input.n;i++){
		std::vector<bool> b(input.n);
		for(int j=0;j<input.n;j++){b[j]=bd[j][i];bd[j][i]=false;}

		double temp=0;
		for(int j=0;j<input.n;j++){
			wps_t[i][j]=calcWP(input,bd,d,j);
		}

		for(int j=0;j<input.n;j++){bd[j][i]=b[j];}
	}

	for(int i=0;i<input.n;i++){
		double ow=0.0;
		int g=0;
		for(int j=0;j<input.n;j++){
			if(bd[i][j]==false) continue;
			g++;
			ow+=wps_t[i][j];
		}
		if(g==0) owps[i]=0.0;
		else owps[i]= ow/g;
		std::cerr << "owp[" << i << "]=" << std::setprecision(12) << owps[i] << std::endl;
	}

	for(int i=0;i<input.n;i++){
		double oow=0.0;
		int g=0;
		for(int j=0;j<input.n;j++){
			if(bd[i][j]==false) continue;
			g++;
			oow+=owps[j];
		}
		if(g==0) oowps[i]=0.0;
		else oowps[i]= oow/g;
		std::cerr << "oowp[" << i << "]=" << std::setprecision(12) << oowps[i] << std::endl;
	}

	for(int i=0;i<input.n;i++){
		rpis[i]=0.25*wps[i]+0.5*owps[i]+0.25*oowps[i];
	}

	std::ostringstream oss;
	for(int i=0;i<input.n;i++){
		oss << std::endl << std::setprecision(12) << rpis[i];
	}
	return oss.str();
}

int main(int argc, char **argv){
	std::string str;
	int t;

	std::cin >> t;
	std::vector<Data> query(t);
	for(int i=0;i<t;i++){
		char c;
		std::cin >> query[i].n;
		int size=query[i].n*query[i].n;
		for(int j=0;j<size;j++){
			std::cin >> c;
			query[i].data.push_back(c);
		}
	}

	std::vector<std::string> result(t);
#ifdef _OPENMP
#pragma omp parallel for
#endif
	for(int i=0;i<t;i++){
		result[i]=trial(query[i]);
	}

	for(int i=0;i<t;i++){
		std::cout << "Case #" << i+1 << ":" << result[i] << std::endl;
	}
	return 0;
}
