#include<stdio.h>

int n,a,b,i,j,k,l,t,counta,countb,q;
int tmp1,tmp2,tmp3,tmp4;
int tafrom[200],tato[200],tat[200];
int flag,what;
 
int route(int index) {
    int m;
    if(flag == 0) {
        flag = 1;
        what = tat[index];
    }
    if(tat[index] == 0) {
        for(m=0; m<a+b; m++) {
            if((tat[m] == 1)&&(tafrom[m] >= tato[index])) {
                tat[index] = -1;
                route(m);
                break;
            }
        }  
    } else
    if(tat[index] == 1) {
        for(m=0; m<a+b; m++) {
            if((tat[m] == 0)&&(tafrom[m] >= tato[index])) {
                tat[index] = -1;
                route(m);
                break;
            }
        }  
    }
    tat[index] = -1;
    return what;
}






   
int main() {
    scanf("%d",&n);
    for(l=0;l<n;l++) {
        scanf("%d",&t);
        scanf("%d %d",&a,&b);
        for(j=0; j<a; j++) {
            scanf("%d:%d %d:%d",&tmp1,&tmp2,&tmp3,&tmp4);
            tafrom[j] = (tmp1*60)+tmp2;
            tato[j] = (tmp3*60)+tmp4+t;
            tat[j] = 0;
        }
        for(; j<b+a; j++) {
            scanf("%d:%d %d:%d",&tmp1,&tmp2,&tmp3,&tmp4);
            tafrom[j] = (tmp1*60)+tmp2;
            tato[j] = (tmp3*60)+tmp4+t;
            tat[j] = 1;
        }
    
// Sort
    for(i=0;i<a+b-1;i++)
        for(j=0;j<a+b-1;j++)
            if(tafrom[j] > tafrom[j+1]) {
                tmp1 = tafrom[j];
                tafrom[j] = tafrom[j+1];
                tafrom[j+1] = tmp1;
                tmp1 = tato[j];
                tato[j] = tato[j+1];
                tato[j+1] = tmp1;
                tmp1 = tat[j];
                tat[j] = tat[j+1];
                tat[j+1] = tmp1;
            }
    for(i=0; i<a+b; i++) {

      
        q = route(i);
        if(q == 0) {
            counta++;
            flag = 0;
        }
        if(q == 1) {
            countb++;
            flag = 0;
        }
        if(q == -1)
            flag = 0;
    }

    printf("Case #%d: %d %d\n",l+1,counta,countb);


    for(i=0; i<a+b; i++) {
        tafrom[i] = 0;
        tato[i] = 0;
        tat[i] = 0;
    }
    counta = 0;
    countb = 0;
    flag = 0;

    }

return 0;
}
