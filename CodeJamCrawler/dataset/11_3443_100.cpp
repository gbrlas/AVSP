#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char trans[1<<10][1<<10];
int cnt[1<<8];
vector<char> opposed[1<<10];

int main(){
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		vector<char> elem;
		memset(trans,-1,sizeof(trans));
		memset(cnt,0,sizeof(cnt));
		for (int i = 0; i < 250; i++)
			opposed[i].clear();
		int c; cin >> c;
		for (int i = 0; i < c; i++){
			char x, y, z; cin >> x >> y >> z;
			trans[x][y] = z;
			trans[y][x] = z;	
		}
		cin >> c;
		for (int i = 0; i < c; i++){
			char x, y; cin >> x >> y;
			opposed[x].push_back(y);
			opposed[y].push_back(x);
			//cout << "x = " << x << ", y = " << y << endl;
		}
		int n; cin >> n;
		for (int i = 0; i < n; i++){
/*			for (int j = 0; j < elem.size(); j++){
			if(j) cout << ", ";
			cout << elem[j];	
		}
		cout << "]" << endl;*/
			char x; cin >> x;
			if (elem.empty()){
				elem.push_back(x);
				cnt[x]++;
				continue;	
			}
			char y = trans[elem.back()][x];
			//cout << "elem.back() = " << elem.back() << ", y = " << y << endl;
			if(y!=-1){
				cnt[elem.back()]--;
				elem[elem.size()-1] = y;
				cnt[y]++;
				continue;
			}
			bool okay = true;
			for (int j = 0; j < opposed[x].size(); j++){
				if(cnt[opposed[x][j]] > 0){
					okay = false;
					break;
				}
			}
			if (okay){
				elem.push_back(x);
				cnt[x]++;
				continue;
			}
			elem.clear();
			memset(cnt,0,sizeof(cnt));
		}
		cout << "Case #" << zzz << ": [";
		for (int i = 0; i < elem.size(); i++){
			if(i) cout << ", ";
			cout << elem[i];	
		}
		cout << "]" << endl;
	}
	
	return 0;
}
