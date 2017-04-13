#include<stdio.h>
#include<algorithm>

using namespace std;

bool comp(const char &a, const char &b){
    return a>b;   
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        char kata[100];
        scanf("%s",kata);
        char temp[100];
        strcpy(temp,kata);
        sort(temp,temp+strlen(temp),comp);
        //printf("%s\n",temp);
        if(strcmp(kata,temp)==0){
            sort(temp,temp+strlen(temp));
            int x=strlen(temp);

            int hitung=0;
            for(int i=0;i<x;i++){
                if(temp[i]=='0') hitung++;
                if(temp[i]!='0') break;
            }
            
            char temp2[100]="";
            temp2[0]=temp[hitung];
            for(int i=0;i<=hitung;i++){
                temp2[i+1]='0';   
            }
            for(int i=hitung+1;i<=x;i++){
                temp2[i+1]=temp[i];   
            }
            temp2[x+1]='\0';
            /*for(int i=hitung;i<x;i++){
                temp2[i-hitung]=temp[i];
            }
            int sisa=x-hitung;
            for(int i=0;i<=hitung;i++){
                temp2[sisa+i]='0';
            }
            temp2[sisa+hitung+1]='\0';*/
            
            //printf("%s\n",temp2);
            strcpy(kata,temp2);
        }
        else{
            next_permutation(kata,kata+strlen(kata));
        }
        printf("Case #%d: %s\n",i,kata); 
    }
    
    return 0;   
}
