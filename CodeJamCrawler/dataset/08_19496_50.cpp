#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
	int tests,lines,se,licznik,sw;
	cin >> tests;
	vector<string> s;
	map<string,bool> M;
	map<string,bool>::iterator it;
	string str;
	bool b[1200]={0};
	
	for(int t=1; t<=tests; t++){
		cin >> se;
		for(int i=0; i<se; i++)
			b[i]=0;
		sw=0;
		getline(cin,str);
		for(int i=0; i<se; i++){
			getline(cin,str);
			M[str]=false;
			s.push_back(str);
		}

		cin >> lines;
		getline(cin,str);
		licznik=0;
		for(int i=0; i<lines; i++){
			getline(cin,str);
			if(M[str]==false){
				M[str]=true;
				licznik++;
				if (licznik==se){
					licznik=1;
					sw++;
					for(it=M.begin(); it!=M.end(); it++)
							(*it).second=0;
					}
				M[str]=true;
			}
		}

		cout << "Case #" <<  t << ": " << sw << endl;
		M.clear();
		
		
		
	}
	
	
	
	return 0;
}
