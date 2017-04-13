#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

typedef struct _coords{
	int i;
	int j;
} coords;

typedef struct{
	int num;
	vector<coords> others;
} value;

vector<value> tree;
bool enables[100][100];
int M,N;

bool possible(coords c){
	int k;
	bool flag = true;
	for(k=0;k<N;k++){
		if(!enables[k][c.j]){
			flag = false;
			break;
		}
	}
	if(flag) return true;
	flag = true;
	for(k=0;k<M;k++){
		if(!enables[c.i][k]){
			flag = false;
			break;
		}
	}
	if(flag) return true;
	return false;
}

vector<value>::iterator find(int n){
	vector<value>::iterator it = tree.begin();
	while(it != tree.end()){
		if(it->num == n)
			return it;
		it ++;
	}
	return tree.end();
}

int main(){
	list<int> values;
	vector<coords> tt;
	int t,temp;
	int cas;
	bool flag;
	vector<value>::iterator it;
	coords co;
	cin >> t;
	for(cas=1;cas<=t;cas++){
		values.clear();
		tree.clear();
		cin >> N;
		cin >> M;
		for(int i=0; i < N; i++){
			for(int j=0; j < M; j++){
				enables[i][j] = true;
				cin >> temp;
				values.push_back(temp);
				co.i = i; co.j = j;
				if(tree.empty()){
					value x;
					x.num = temp;
					x.others.push_back(co);
					tree.push_back(x);
				}else{
					it = find(temp);
					if(it == tree.end() && tree.back().num != temp){
						value x;
						x.num = temp;
						x.others.push_back(co);
						tree.push_back(x);
					}else{
						it->others.push_back(co);
					}
				}
			}
		}
		values.sort();
		values.unique();
		flag = true;
		while(!values.empty() && flag){
			temp = values.back(); values.pop_back();
			it = find(temp);
			while(!it->others.empty()){
				co = it->others.back(); it->others.pop_back();
				tt.push_back(co);
				if(!possible(co)){
					flag = false;
					break;
				}
			}
			while(!tt.empty()){
				co = tt.back(); tt.pop_back();
				enables[co.i][co.j] = false;
			}
		}
		if(flag)
			cout << "Case #"<< cas << ": YES" << endl;
		else
			cout << "Case #"<< cas << ": NO" << endl;
	}
	return 0;
}