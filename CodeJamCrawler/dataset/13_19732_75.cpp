#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int num_problem;
    cin >> num_problem;
    int cnt_problem = 1;
    int l_bound,u_bound;
    int cnt;
    vector<int> fs = {1,4,9,121,484};
    for(int i=0; i<num_problem; ++i){
	cin >> l_bound >> u_bound;
	cnt = 0;
	auto end = fs.end();
	for(auto it = fs.begin(); it<end; ++it){
	    if(*it < l_bound)continue;
	    if(*it <= u_bound)cnt++;
	    else{
		break;
	    }
	}
	cout << "Case #" << cnt_problem++ << ": " << cnt << endl;
    }
       
    return 0;
}
