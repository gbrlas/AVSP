#include <iostream>
#include <iomanip>

using namespace std;

string casestr;
int select_arr[500];
int Size = 0;
string stdStr = "welcome to code jam";
int caseResCnt = 0;

void dfs (int level, int choice, int nextChIdx) {
	//select_arr[level] = choice;

	if (choice == 1 && nextChIdx == 18) {
		if (casestr[level] == stdStr[nextChIdx]) {
			caseResCnt++;
			if (caseResCnt == 10000)
				caseResCnt = 0;	
		}
		return;
	}

	if (level >= (Size-1) || nextChIdx >= 19)
		return;
	else {
		if (choice == 1) {
			if (casestr[level] == stdStr[nextChIdx]) {
				dfs(level+1,1,nextChIdx+1);
				dfs(level+1,0,nextChIdx+1);
			}
		} else if (choice == 0) {
			dfs(level+1,1,nextChIdx);
			dfs(level+1,0,nextChIdx);
		}
	}
}


int main() {
	int N;
	cin >> N;
	getline(cin,casestr);
	
	for (int i = 0; i < N; ++i) {
		getline(cin,casestr);
		//cout << "begin:" << casestr << endl;
		Size = casestr.length();
		caseResCnt = 0;
		
		int idx = casestr.find("w",0,1);
		
		if(idx != -1) {

		dfs(idx,1,0);
		dfs(idx,0,0);
		}

		cout << "Case #" << i+1 << ": " << setw(4) << setfill('0') << caseResCnt << endl;

	}

	return 0;
}
