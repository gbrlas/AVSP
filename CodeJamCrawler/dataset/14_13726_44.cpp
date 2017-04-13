using namespace std;
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
vector<double> naomi;
vector<double> ken;
int n;
double v;

void read(){
	naomi.clear();
	ken.clear();
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>v;
		naomi.push_back(v);
	}
	for (int i = 0; i < n; ++i){
		cin>>v;
		ken.push_back(v);
	}
	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());
}

int warScore(){
	int score=0;
	int ks=0,ke=n-1,found;
	vector<int> mask(n,1);
	for (int i = n-1; i >= 0; i--){
		found=0;
		for (int j = 0; j <= n-1; j++){
			if(naomi[i]<ken[j] && mask[j]){
				found=1;
				mask[j]=0;
				break;
			}
		}
		if(!found){
			score++;
			mask[ks++] = 0;
		}
	}
	return score;
}

int deceitWarScore(){
	int score=0;
	vector<int> mask(n,1);
	int ks=0,kn=n-1;;
	for (int i = 0; i < n; ++i){
		if(naomi[i] > ken[ks] && mask[ks]){
			score++;
			mask[ks]=0;
			ks++;
		}
		else{
			mask[kn]=0;
			kn--;
		}
	}
	return score;
}

int main(){
	int ite;
	cin>>ite;
	for (int i = 1; i <= ite; ++i){
		read();	
		int ws = warScore();
		int dws = deceitWarScore();
		cout<<"Case #"<<i<<": "<<dws<<" "<<ws<<endl;
	}
}