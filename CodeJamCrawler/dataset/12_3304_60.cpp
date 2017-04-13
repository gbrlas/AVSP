/* Google Code Jam 2012 - Qualification Round
 * Problema: C - Recycled Numbers
 * Categoria: Brute force
 * 
 * Israel Leiva - 14-04-2012
 */
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

void num_to_str(int n, char str[8]){
	int i=6;
	while(n>0){
		str[i]='0'+(n%10);
		n=n/10;
		i--;
	}
	while(i>=0){
		str[i]='0';
		i--;
	}
	str[7]='\0';
}

int process(int n, char A[8], char B[8]){
	int i, sz, corr, init, tmp_init, j, res=0;
	char tmp_str[8], recycled[8];
	vector<string> gen;
	bool found;
	
	num_to_str(n, tmp_str);
	
	for(i=0;i<7;i++){
		if(tmp_str[i]!='0'){
			sz=7-i;
			break;
		}
	}
	
	init=7-sz;	
	for(i=0;i<init;i++)
		recycled[i]='0';
	
	
	for(corr=1;corr<sz;corr++){
		tmp_init=7-corr;
		j=0;
		for(i=tmp_init;i<7;i++){
			recycled[init+j]=tmp_str[i]; 
			j++;
		}
		for(i=init;i<tmp_init;i++){
			recycled[init+j]=tmp_str[i];
			j++;
		}
		recycled[7]='\0';
		
		
		if( (strcmp(A, recycled) <= 0) && (strcmp(recycled, B) <= 0) && (strcmp(tmp_str, recycled)) < 0 ){
			found=false;
			for(i=0;i<res;i++){
				if(strcmp(gen[i].c_str(), recycled)==0){
					found=true;
					break;
				}
			}
			if(!found){
				gen.push_back(recycled);
				res++;
			}
		}
	}
	gen.clear();
	return res;
}

int main(){
	int T, i=0, j, A, B, res;
	char A_str[8], B_str[8], tmp_str[8];
	
	scanf("%d\n", &T);
	while(T>0){
		res=0;
		i++;
		printf("Case #%d: ", i);
		scanf("%d %d\n", &A, &B);
		
		num_to_str(A, A_str);
		num_to_str(B, B_str);
		
		for(j=A;j<=B;j++)
			res+=process(j, A_str, B_str);

		printf("%d\n", res);
		T--;
	}
}
