#include <iostream>
#include <stdio.h>

using namespace std;

class Simulation{
public:
	double F,X,C;
	
	Simulation(double Cp, double Fp, double Xp){
		F = Fp;
		C = Cp;
		X = Xp;
		t = 0;
		G = 0;
		last_time = 99999999999;

	}

	double best_time(){
		while(1){
			double this_time = end_time();
			//printf("Time: %.7f\n", this_time);
			if(last_time < this_time)
				return last_time;
			last_time = this_time;
			do_step();
		}

	}




private:
	double t, G; 
	double last_time;

	double farm_time(){
		return C/inc_rate();
	}

	double end_time(){
		return t + X/inc_rate();
	}

	double inc_rate(){
		return G*F+2;
	}

	void do_step(){
		t += farm_time();
		G++;
	}
};

int main(){
  int casos;
  double C, F, X;

  cin >> casos;

  for(int caso = 1; caso <= casos; caso++){
  	cin >> C >> F >> X;
  	Simulation s(C,F,X);
  	printf("Case #%d: %.7f\n",caso, s.best_time());
  }
  return 0;
}
