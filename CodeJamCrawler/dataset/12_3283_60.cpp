#include <cstdio>
int main(){
	int T, i=0;
	char c, mapping[27] = "yhesocvxduiglbkrztnwjpfmaq";
	
	scanf("%d\n", &T);
	while(T>0){
		i++;
		printf("Case #%d: ", i);
		while((c=getchar())!='\n')
			(c==' ') ? printf(" ") : printf("%c", mapping[ c-'a' ]);
		printf("\n");
		T--;
	}
}
