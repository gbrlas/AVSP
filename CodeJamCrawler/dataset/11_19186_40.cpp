#include<iostream>
using namespace std;
int main(){
    int t,r;
    cin>>t;
    r=t;
    while(t--){
        int c,d,n,j=0;
        cin>>c;
        char cc[3],dd[2];
        if(c==1){
            cin>>cc[0]>>cc[1]>>cc[2];
        }
        cin>>d;
        if(d==1){
            cin>>dd[0]>>dd[1];
        }
        cin>>n;
        char b[n],a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<n;i++){//cout<<j;
            int m=0;
            if(i==0||j==0)
            b[j++]=a[i];
            else{
                if(c==1&&(((a[i]==cc[1])&&(b[j-1]==cc[0]))||((a[i]==cc[0])&&(b[j-1]==cc[1])))){
                    b[j-1]=cc[2];m=2;
                }
                else if(d==1&&(a[i]==dd[0]||a[i]==dd[1])){
                    m=1;
                    if(a[i]==dd[0])
                    {
                        for(int k=0;k<j;k++){
                            if(b[k]==dd[1]){//cout<<i;
                                j=0;m=2;
                                break;
                            }
                        }
                    }
                    else{
                        for(int k=0;k<j;k++){
                        if(b[k]==dd[0]){//cout<<b[k];
                            j=0;m=2;
                            break;
                        }
                        }
                    }
                }
                if(m!=2){
                    b[j++]=a[i];
                }
            }
        }
        printf("Case #%d: [",r-t);
        for(int i=0;i<j-1;i++)
        cout<<b[i]<<", ";
        if(j!=0)
        cout<<b[j-1];
        cout<<"]"<<endl;
    }
    return 0;
}



