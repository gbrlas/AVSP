#include <stdio.h>
#include <math.h>
#define T 10000

int dap[T+1];
int n;
int s,e;

bool is_pal(int num){
    int m[30]={0,};
    int cnt=0,i;

    while(1){
        m[cnt]=num%10;
        num/=10;
        cnt++;
        if(num == 0)
            break;
    }
    for(i=0;i<=cnt/2;i++){
        if(m[i] != m[cnt-i-1])
            return false;
    }
    return true;
}

int chk(){
    int i,j;
    int cnt=0;

    for(i=s;i<=e;i++){
        if(sqrt(i)*sqrt(i) == i){
            if(is_pal(i) == true && is_pal((int)sqrt(i)) == true){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int i;
    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");

    fscanf(in,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(in,"%d%d",&s,&e);
        dap[i]=chk();
    }
    fclose(in);

    for(i=0;i<n;i++){
        fprintf(out,"Case #%d: %d\n",i+1,dap[i]);
    }
    fclose(out);
    return 0;
}
