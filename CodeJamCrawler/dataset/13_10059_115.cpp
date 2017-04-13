#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

bool full(vector<string> v) {
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(v[i][j] == '.')
				return false;
	return true;
}

bool win(char c, vector<string> v) {
	for(int i=0;i<4;i++) {
		int j;
		for(j=0;j<4;j++)
			if(v[i][j] != c && v[i][j] != 'T')
				break;
		if(j == 4)
			return true;
	}
	for(int i=0;i<4;i++) {
		int j;
		for(j=0;j<4;j++)
			if(v[j][i] != c && v[j][i] != 'T')
				break;
		if(j == 4)
			return true;
	}
	int j;
	for(j=0;j<4;j++)
		if(v[j][j] != c && v[j][j] != 'T')
			break;
	if(j == 4)
		return true;
	for(j=0;j<4;j++)
		if(v[j][4-j-1] != c && v[j][4-j-1] != 'T')
			break;
	if(j == 4)
		return true;
	return false;
}

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		vector<string> v(4);
		for(int i=0;i<4;i++)
			cin>>v[i];
		cout<<"Case #"<<tt<<": ";
		if(win('X', v))
			cout<<"X won";
		else if(win('O', v))
			cout<<"O won";
		else if(full(v))
			cout<<"Draw";
		else
			cout<<"Game has not completed";
		cout<<endl;
	}

	return 0;
}
