#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int tests,lines,se,licznik,sw;
	cin >> tests;
	vector<string> s;
	string str;
	bool b[1200]={0};
	
	for(int t=0; t<tests; t++){
		cin >> se;
		for(int i=0; i<se; i++)
			b[i]=0;
		sw=0;
		getline(cin,str);
		for(int i=0; i<se; i++){
			getline(cin,str);
			s.push_back(str);
		}
	//	for(int i=0; i<se; i++)
			//cout << "s[i]: " << s[i] << endl;
		cin >> lines;
		getline(cin,str);
		licznik=0;
		for(int i=0; i<lines; i++){
			getline(cin,str);
			for(int j=0; j<se; j++){
				if(str==s[j]){
				//	cout << "j: " << j << endl;
					if(b[j]==0) {
						//cout << "b[j] - false" << endl;
						licznik++;
						//cout << licznik << endl;
						b[j]=1;
						if (licznik==se){
							licznik=1;
							sw++;
							for(int k=0; k<se; k++)
								b[k]=0;
							b[j]=1;
							//cout << "ost: " << j << endl;
						}
					}
						break;
				}
				
			}
		}
		cout << "Case #" <<  t+1 << ": " << sw << endl;
		s.clear();
		
		
		
	}
	
	
	
	return 0;
}
