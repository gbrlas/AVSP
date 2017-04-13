#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

/*struct eqstr
{
  bool operator()(const string s1, const string s2) const
  {
    return s1 == s2;
  }
};*/

string del2Base(int base, int num)
{
	int temp = num;
	ostringstream os;
	while (temp >= base) {
		os << temp % base;
		temp = temp / base;
	}
	os << temp;
	string tempStr = os.str();
	os.str("");
	int i;
	for (i = tempStr.size() - 1; i >= 0; i--) {
		os << tempStr.at(i);
	}
	return os.str();
}

bool isHappyNum(int base, const string &num)
{
	string temp = num;
	int tempNum;
	set<string> done;
	done.insert(num);
	//cout << num << endl;
	while (true) {
		tempNum = 0;
		for (int i = 0; i < temp.size(); i++) {
			tempNum += (temp.at(i) - '0') * (temp.at(i) - '0');
		}
		temp = del2Base(base, tempNum);
		//cout << temp << endl;
		if (temp.size() == 1 && temp.at(0) == '1') break;
		if (done.find(temp) != done.end()) break;
		done.insert(temp);
		//cout << done.size() << endl;
	}
	if (temp.size() == 1 && temp.at(0) == '1') {
		return true;
	} else {
		return false;
	}
}

int main()
{
	/*if (isHappyNum(2, del2Base(2, 3))) {
		cout << "No!" << endl;
		return 0;
	}*/
	ifstream in("A-small.in");
	ofstream out("A-small.out");
	int T;
	int i, j, k;
	in >> T;
	string ignore;
	getline(in, ignore);
	string line;
	for (i = 0; i < T; i++) {
		//cout << "Case #" << i+1 << endl;
		getline(in, line);
		istringstream is(line);
		int base;
		bool flag;
		vector<int> baseList;
		is >> base;
		while (is) {
			baseList.push_back(base);
			is >> base;
		}
		k = 2;
		flag = false;
		while (!flag) {
			flag = true;
			for (j = 0; j < baseList.size(); j++) {
				//cout << k << '\t' << j << endl;
				if (!isHappyNum(baseList.at(j), del2Base(baseList.at(j), k))) {
					flag = false;
					break;
				}
			}
			if (!flag) k++;
		}
		out << "Case #" << i + 1 << ": " << k << endl;
	}
	in.close();
	out.close();
}
