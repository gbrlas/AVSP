#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

typedef list<double> vd;

bool delete_first_greater(vd &v, double val){
	vd::iterator it;
	for(it = v.begin(); it != v.end(); ++it){
		if(*it > val){
			v.erase(it);
			return true;
		}
	}
	return false;
}

class DeceitfulWar{
public:
	vd naomi;
	vd ken;

	DeceitfulWar(vd v1, vd v2){
		naomi = v1;
		ken = v2;
		naomi.sort();
		ken.sort();
		
	}

	int war_score(){
		vd naomi2 = naomi;
		vd ken2 = ken;
		int points = 0;

		while(naomi2.size() > 0){
			double val = naomi2.front();
			naomi2.pop_front();
			
			bool res = delete_first_greater(ken2,val);
			if(!res){
				ken2.pop_front();
				points++;
			}
		}
		return points;
	}

	int deceitful_war_score(){
		vd naomi2 = naomi;
		vd ken2 = ken;

		int points = 0;
		while(naomi2.size() > 0){
			double val1 = naomi2.front();
			naomi2.pop_front();
			double val2 = ken2.front();
			if(val1 > val2){
				ken2.pop_front();
				points++;
			}
			else
				ken2.pop_back();
		}
		return points;
	}


};

int main(){
	int casos, cant_bloques;
	double num;

	vd naomi;
	vd ken;

	cin >> casos;

	for(int caso = 1; caso <= casos; caso++){
		naomi.clear();
		ken.clear();
		cin >> cant_bloques;
		//leer naomi
		for(int i = 0; i < cant_bloques ; i++){
			cin >> num;
			naomi.push_back(num);
		}
		//leer ken
		for(int i = 0; i < cant_bloques ; i++){
			cin >> num;
			ken.push_back(num);
		}

		DeceitfulWar war(naomi,ken);
		cout << "Case #" << caso << ": " << war.deceitful_war_score() << " " << war.war_score() << endl;

	}

	return 0;
}
