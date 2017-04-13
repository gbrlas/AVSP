#include <iostream>

#include<map>

#include<algorithm>

#include<cstdio>

using namespace std;
 

int main() {

	int T, x, y, chosen=0, p;

	int m[4][4];

	scanf("%d", &T);

 
	
	map<int, bool> mymap;

	map<int, bool>::iterator it;

 
	
		for(int i=0; i<T; i++) {

		int count = 0;

		scanf("%d", &x);

		for(int j=0; j<4; j++) {
					
		for(int k=0; k<4; k++) {
					
		scanf("%d", &m[j][k]);

			}

		}

		for(p=0; p<4; p++) {

			mymap.insert( pair<int, bool>(m[x-1][p], true) );

		}

		scanf("%d", &y);

		for(int j=0; j<4; j++) {

			for(int k=0; k<4; k++) {

				scanf("%d", &m[j][k]);

			}

		}

		for(p=0; p<4; p++) {

			if(mymap.find(m[y-1][p]) != mymap.end()) {

				it = mymap.find(m[y-1][p]);

				chosen= it->first;

				count+=1;

			}

		}

		if(count == 1) {

			printf("Case #%d: %d\n", i+1, chosen);

		}

		else if(count > 1) {

			printf("Case #%d: Bad magician!\n", i+1);

		}

		else if(count == 0) {

			printf("Case #%d: Volunteer cheated!\n", i+1);

		}

		mymap.clear();

	}

	return 0;

}
