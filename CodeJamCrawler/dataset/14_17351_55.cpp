#include<stdio.h>
 #include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {


	int index, cc = 0, n = 0,dwin,warwin;
	float naomi[10];
	float ken[10];
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &index);
	while (index--) {
		scanf("%d", &n);
		dwin=0;warwin=0;
		for (int i = 0; i < n; i++)
			scanf("%f", &naomi[i]);
		for (int i = 0; i < n; i++)
			scanf("%f", &ken[i]);
		std::sort(naomi, naomi+n);
		std::sort(ken, ken+n);
		int nm_i=n-1;
		for (int i = n-1; i >=0; i--)
		{
			while(nm_i>=0){
					if(ken[i]>naomi[nm_i]){
						warwin++;
						nm_i--;
						break;
					}
					nm_i--;
			 }

		}
		warwin=n-warwin;
		  int ken_i=n-1;
		for(int j=n-1;j>=0;j--){
			while(ken_i>=0){
				if(naomi[j]>ken[ken_i])
				{
					dwin++;
					ken_i--;
					break;

				}else{
					ken_i--;
				}

			}
		}
		/*for (int i = 0; i < n; i++)
					printf("%0.3f ", naomi[i]);
		printf("\n");
				for (int i = 0; i < n; i++)
					printf("%0.3f ", ken[i]);
				printf("\n");*/
		printf("Case #%d: %d %d\n", ++cc,dwin,warwin);
	}
	return 0;
}
