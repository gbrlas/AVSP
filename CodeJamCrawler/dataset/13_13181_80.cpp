/*ShivamDixit [Pandit]*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <fstream>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main()
{
	int i, j, k, p_r, q_r, x, y, z, t, r_r, q_c, p_c, r_c, l, p_i, q_i, r_i, q_v, p_v, r_v;
	
	ifstream rf;
	ofstream sf;

	rf.open ("B.txt");
	sf.open ("A.txt");

	//scanf ("%d", &t);
	rf >> t;
	//cout << "t = " << t << endl;
	//char ch;
	//ch = getchar();
	//rf >> ch;
	//cout << "First ch =";

	for (l = 1; l <= t; l++) {
	//	ch = getchar();
		char a[5][5];
		
		z = 16;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				//scanf ("%c", &a[i][j]);
				rf >> a[i][j];
				if (a[i][j] == '.') {
					z--;
				}
			}
			//ch = getchar();
			//rf >> ch;
		}
		/*cout << "Given matrix: " << endl;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "wait" << endl;
		int fg;
		cin >> fg;*/
		bool g_x = false, g_o = false;
		p_i = 0, q_i = 0, r_i = 0, q_v = 0, p_v = 0, r_v = 0;
		for (j = 0; j < 4; j++) {
			//bool X = false, Y = false, m = false, n = false;
			p_c = 0, q_c = 0, r_c = 0, p_r = 0, q_r = 0, r_r = 0;
			for (i = 0; i < 4; i++) {
				//cout << "i = " << i << " j = " << j << endl;
				if (i == j) {
					if (p_i != -1) {
						if (a[j][i] == 'T' && !p_i) {
							p_i++;
						}
						else if (a[j][i] == 'T' && p_i) {
							p_i = -1;
						}
						if (r_i && a[j][i] == 'X') {
							p_i = -1;
						}
						if (q_i && a[i][j] == 'O') {
							p_i = -1;
						}
						if (a[j][i] == 'O') {
							r_i++;
						}
						if (a[j][i] == 'X') {
							q_i++;
						}
					}
				}
				if (i + j == 3) {
					if (p_v != -1) {
						if (a[j][i] == 'T' && !p_v) {
							p_v++;
						}
						else if (a[j][i] == 'T' && p_v) {
							p_v = -1;
						}
						if (r_v && a[j][i] == 'X') {
							p_v = -1;
						}
						if (q_v && a[i][j] == 'O') {
							p_v = -1;
						}
						if (a[j][i] == 'O') {
							r_v++;
						}
						if (a[j][i] == 'X') {
							q_v++;
						}
					}
				}
				if (p_r != -1) {
					if (a[j][i] == 'T' && !p_r) {
						p_r++;
			//			cout << "Enters p_r = " << p_r << endl;
					}
					else if (a[j][i] == 'T' && p_r) {
						p_r = -1;
					}
					if (r_r && a[j][i] == 'X') {
						p_r = -1;
					}
					if (q_r && a[j][i] == 'O') {
						p_r = -1;
					}
					if (a[j][i] == 'O') {
						r_r++;
					}
					if (a[j][i] == 'X') {
						q_r++;
			//			cout << "Enters q_r = " << q_r << endl;
					}
				}
				if (p_c != -1) {
					if (a[i][j] == 'T' && !p_c) {
						p_c++;
					}
					else if (a[i][j] == 'T' && p_c) {
						p_c = -1;
					}
					if (r_c && a[i][j] == 'X') {
						p_c = -1;
					}
					if (q_c && a[i][j] == 'O') {
						p_c = -1;
			//			cout << "Enters p_c = " << p_c << endl;
					}
					if (a[i][j] == 'O') {
						r_c++;
					}
					if (a[i][j] == 'X') {
						q_c++;
			//			cout << "Enters q_c = " << q_c << endl;
					}
				}
			}
			//cout << "\nValue of q_r, p_r = " << q_r << " " << p_r << endl;
			if ((r_v == 3 && p_v == 1) || (r_v == 4)) {
				g_o = true;
			}
			if ((q_v == 3 && p_v == 1) || (q_v == 4)) {
				g_x = true;
			}
			if ((r_i == 3 && p_i == 1) || (r_i == 4)) {
				g_o = true;
				break;
			}
			if ((q_i == 3 && p_i == 1) || (q_i == 4)) {
				g_x = true;
				break;
			}
			if ((r_r == 3 && p_r == 1) || (r_r == 4)) {
				//printf ("O won\n");
				g_o = true;
				break;
			}
			if ((q_r == 3 && p_r == 1) || (q_r == 4)) {
				//printf ("X won\n");
				//cout << "Enters q_o" << endl;
				g_x = true;
				break;
			}
			if ((r_c == 3 && p_c == 1) || (r_c == 4)) {
				//printf ("O won\n");
				g_o = true;
				break;
			}
			if ((q_c == 3 && p_c == 1) || (q_c == 4)) {
				//printf ("X won\n");
				g_x = true;
				break;
			}
		}
		if (g_x == true) {
			sf << "Case #";
			sf << l;
			sf << ": X won\n";
			//cout << "X won" << endl;
		}
		else if (g_o) {
			sf << "Case #";
			sf << l;
			sf << ": O won\n";
			//cout << "O won" << endl;
		}
		else if (z != 16) {
			sf << "Case #";
			sf << l;
			sf << ": Game has not completed\n";
			//cout << "Game has not completed" << endl;
		}
		else {
			sf << "Case #";
			sf << l;
			sf << ": Draw\n";
			//cout << "Draw" << endl;
		}
	}
	
	return 0;
}

