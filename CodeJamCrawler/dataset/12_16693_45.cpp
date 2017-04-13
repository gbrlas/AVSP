#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>

int T;
int A, B;
int cnt;

bool check[5000][5000];

std::string convertInt(int n)
{
   std::stringstream ss;
   ss << n;
   return ss.str();
}

int convertString(std::string s) {
	int n;
	std::istringstream ss(s);
	ss >> n;
	return n;
}

int main () {

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(check, 0, sizeof(check[0][0]) * 5000 * 5000);
		scanf("%d%d", &A, &B);
		cnt = 0;
		for (int i = A; i <= B; i++) {
			std::string s1 = convertInt(i);
			for (int j = 0; j < s1.length(); j++) {
				std::string s2 = s1;
				std::rotate(s2.begin(), s2.begin()+j, s2.end());
				
				int n = convertString(s1);
				int m = convertString(s2);
				
				if (n < m && m <= B && check[n][m] == false && check[n][m] == false) {
					check[n][m] = true;
					check[m][n] = true;
					//std::cout << n << " " << m << std::endl;
					cnt++;
				}
			}
		}
		printf("Case #%d: %d\n", t, cnt);
	}
	
}

