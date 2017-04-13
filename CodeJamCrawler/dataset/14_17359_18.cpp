#include<stdio.h>
#include<string.h>
#include<math.h>
#include <iostream>
#include <vector>
using namespace std;

string thin(string str) {
	char ch = '0';
	string thin = "";
	for (unsigned int i = 0; i < str.length(); i++) {
		char c = str.at(i);
		if (ch != c) {
			thin += c;
			ch = c;
		}
	}
	return thin;
}
int cutString(string templ, string test) {
	int size = 0, f1 = 0, f2 = 0, s1 = 0, s2 = 0;
	int thin_size = thin(templ).length();

	for (int i = 0; i < thin_size; i++) {
		s1 = 1;
		s2 = 1;
		for (unsigned int w = f1 + 1; w < templ.length(); w++) {
			if (templ.at(f1) == templ.at(w)) {
				s1++;
			} else {
				f1 = w;
				break;
			}
		}
		for (unsigned int w = f2 + 1; w < test.length(); w++) {
			if (test.at(f2) == test.at(w)) {
				s2++;
			} else {
				f2 = w;
				break;
			}
		}
		if (s1 > s2)
			size += s1 - s2;
		else
			size += s2 - s1;

	}

	return size;
}
int main() {
	int index, cc = 0, num, total_size, tt_size;
	unsigned int temp_size;
	freopen("A-small-attempt0.in", "r", stdin);
    freopen("out","w",stdout);
	vector<string> strs;
	string temp, templ, thinstr;
	bool notpossible;
	scanf("%d", &index);
	while (index--) {
		strs.clear();
		total_size = 0;
		temp_size = 0;
		templ = "";
		notpossible = false;
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			cin >> temp;
			total_size += temp.length();
			if (i == 0)
				thinstr = thin(temp);
			else {
				if (thinstr != thin(temp))
					notpossible = true;
			}
			strs.push_back(temp);
		}
		if (!notpossible) {
			temp_size = total_size / num;

			while (true) {
				for (unsigned int i = 0; i < strs.size(); i++) {
					temp = strs[i];
					if (temp.length() == temp_size) {
						break;
					}
				}
				if (temp != "")
					break;
				else
					temp_size--;

			}
			total_size = 0;
			for (unsigned int i = 0; i < strs.size(); i++) {
				string tt = strs[i];
				//printf("%s to %s  size=%d \n",temp.c_str(),tt.c_str(),cutString(temp,tt));
				total_size += cutString(temp, tt);
			}
			if (total_size > num) {
				tt_size = 0;
				for (unsigned int i = 0; i < strs.size(); i++) {
					string tt = strs[i];
					//printf("%s to %s  size=%d \n",temp.c_str(),tt.c_str(),cutString(temp,tt));
					tt_size += cutString(thin(temp), tt);
				}
				if (tt_size < total_size)
					total_size = tt_size;
			}

		}
		if (notpossible)
			printf("Case #%d: Fegla Won\n", ++cc);
		else
			printf("Case #%d: %d\n", ++cc, total_size);
	}
	return 0;
}
