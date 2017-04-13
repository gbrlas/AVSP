#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

const int MAXN = 10000;

char str[MAXN];
map<string, int> mp;


int casenum, len, line, N, fn;

void trans(){
	int tmp_len = len;
	len = 0;
	int i;
	for(i = 0 ; i < tmp_len ; i++)
		if(str[i] != ' ') break;
	str[len++] = str[i];
	for( i = i + 1; i < tmp_len; i++){
		if(str[i] == ' ' && str[i-1] == ' ') continue;
		str[len++] = str[i];
	}
	while(str[len-1] == ' ') len--;
	str[len] = 0;
//	printf("M: %s\n", str);
	tmp_len = len;
	len = 0;
	for(int i = 0 ; i < tmp_len ; i++){
		if(i == 0 || i == tmp_len - 1 || str[i] != ' ') {
			str[len++] = str[i];
			continue;
		}
		if(str[i-1] == '(' || str[i-1] == ')' || str[i+1] == '(' || str[i+1] == ')') continue;
		else str[len++] = str[i];
	}
	str[len] = 0;
}

double calc(int st, int end, double ans){
//	printf("st: %d, end: %d, ans: %lf\n", st, end, ans);
//	for(int t = st ; t < end; t++)
//		printf("%c",str[t]);
//	puts("");	puts("*****************************************");
	int i, st1, end1, st2, end2, cnt;
	double score;
	for(i = st; i < end; i++)
		if(str[i] == ' ') break;
	if(i >= end){
		sscanf(str+st+1, "%lf", &score);
		return ans * score;
	}
	string feature = "";
	for(++i ; i < end; i++){
		if(str[i] == '(') break;
		feature += str[i];
	}
	sscanf(str+st+1, "%lf", &score);
	ans *= score;
	st1 = i;
	for( cnt = 0; i < end ; i++){
		if(str[i] == '(') cnt++;
		if(str[i] == ')') cnt--;
		if(cnt == 0) {
			end1 = i;
			break;
		}
	}
	st2 = end1 + 1;
	for( cnt = 0, i = st2 ; i < end; i++){
		if(str[i] == '(') cnt++;
		if(str[i] == ')') cnt--;
		if(cnt == 0) {
			end2 = i;
			break;
		}
	}
	if(mp.find(feature) != mp.end()) {
		return calc(st1, end1+1, ans);
	}
	else {
//		sscanf(str+st2+1, "%lf", &score);
		return calc(st2, end2+1, ans);
	}
	return 0.0;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	string in, ss;
	getline(cin, in);
	sscanf(in.c_str(), "%d", &casenum);
	for(int ca = 1; ca <= casenum; ca++){
		getline(cin, in);
		sscanf(in.c_str(), "%d", &line);
		memset(str, 0, sizeof(str));
		len = 0;
		while(line--){
			getline(cin, in);
			for(int i = 0; i < in.size(); i++){
				if(in[i] == '\n') str[len++] = ' ';
				else str[len++] = in[i];
			}
		}
		str[len] = 0;
//		printf("B: %s\n", str);
		trans();
//		printf("%s\n", str);
		getline(cin, in);
		sscanf(in.c_str(), "%d", &N);
		printf("Case #%d:\n", ca);
		while(N--){
			mp.clear();
			getline(cin, in);
			istringstream CIN(in);
			CIN >> ss;
			CIN >> fn;
			while(fn--) {
				CIN >> ss;
//				cout << ss << endl;
				mp[ss] = 1;
			}
			printf("%.7lf\n", calc(0, len, 1.0));
		}
	}
	return 0;
}
