#include<stdio.h>
#include<string.h>

char Lan[26]={25,8,5,19,15,3,22,24,4,21,9,7,12,2,11,18,26,20,14,23,10,16,6,13,1,17};

void translate(char a[])
{
  int i;
   int j = strlen(a);
	for(i=0;i<j-1;i++){
                if(a[i]=='\0')break;
		if(a[i]!=' ') a[i]=Lan[(int)a[i]-97]+96;
                
	}
}


main()
{
     int i,k=1;
     char a[102];
    FILE *in ;
    in= fopen("A-small-attempt0.in","r");
    FILE *out;
    out = fopen("A-small-attempt0.out","a+");
    i=atoi(fgets(a, 102, in));
    while(k<=i){
        if(fgets(a, 102, in)!=NULL){
	translate(a);
	fprintf(out,"Case #%d: %s",k,a);
	}
      k++; 
    }
}

