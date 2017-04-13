#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	scanf("%d\n",&n);
	vector<char> Number;
	for(int i = 0; i < n; i++){
		char ch;
		Number.clear();
		while(1){
			int r = scanf("%c",&ch);
			if(ch == '\n' || r == -1) 
				break;
			else
				Number.push_back(ch);
		}
		bool tr = next_permutation(Number.begin(),Number.end());
		if(tr)
		{
			printf("Case #%d: ",i+1);
			copy(Number.begin(),Number.end(),ostream_iterator<char>(cout,""));
			printf("\n");
		}
		else
		{
			for(int p = 0; p < Number.size(); p++){
				if(Number[p] != '0'){
					Number[0] = Number[p];
					if(p!=0) Number[p] = '0';
					break;
				}
			}
			printf("Case #%d: %c0",i+1,Number[0]);
			for(int j = 1; j < Number.size(); j++) printf("%c",Number[j]); 
			printf("\n");
		}

	}
	return 0;
}