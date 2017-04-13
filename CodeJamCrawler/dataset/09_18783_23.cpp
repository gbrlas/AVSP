#include<stdio.h>
#include<mem.h>

int main(){
    char data[100];
    bool flag[50];
    int change[50];
    
    int t;
    scanf("%d\n",&t);
    for(int nT=1;nT<=t;nT++){
        memset(flag,false,sizeof(flag));
        memset(change,-1,sizeof(change));
        gets(data);
        
        int base=0;
        int length = strlen(data);
        for(int i=0;i<length;i++){
            if(data[i]>='a' && data[i]<='z'){
                flag[data[i]-'a'+10]=true;   
            }
            else{
                flag[data[i]-'0']=true;   
            }
        }
        
        for(int i=0;i<36;i++){
            if(flag[i]==true){
                base++;   
            }   
        }
        if(base==1) base=2;
        
        if(data[0]>='a'&&data[0]<='z')
            change[data[0]-'a'+10]=1;
        else
            change[data[0]-'0']=1;
        int count=1;
        for(int i=1;i<length;i++){
            int c;
            if(data[i]>='a'&&data[i]<='z')
                c='a'-10;
            else
                c='0';
            if(change[data[i]-c]==-1){
                if(count==1){
                    if(data[i]>='a'&&data[i]<='z')
                        change[data[i]-'a'+10]=0;   
                    else
                        change[data[i]-'0']=0;
                }   
                else{
                    if(data[i]>='a'&&data[i]<='z')
                        change[data[i]-'a'+10]=count;  
                    else
                        change[data[i]-'0']=count;
                }
                count++;
            }
        }
        
        /*for(int i=0;i<length;i++){
            if(data[i]>='a'&&data[i]<='z')
                printf("%d ",change[data[i]-'a'+10]);
            else
                printf("%d ",change[data[i]-'0']);  
        }
        printf("\n");
        for(int i=0;i<36;i++){
            printf("%d ",flag[i]);   
        }
        printf("\n");
        printf("Base: %d\n",base);*/
        
        __int64 hasil=0;
        __int64 temp=1;
        for(int i=length-1;i>=0;i--){
            if(data[i]>='a'&&data[i]<='z')
                hasil+=((__int64)change[data[i]-'a'+10])*temp;
            else
                hasil+=((__int64)change[data[i]-'0'])*temp;
            temp*=base;
        }
     
        printf("Case #%d: %I64d\n",nT,hasil);   
    }
    return 0;   
}
