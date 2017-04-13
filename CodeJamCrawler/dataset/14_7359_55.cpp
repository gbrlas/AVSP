#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int unique(int *a,int *b,int len)
{
    int i,j,count=0;
    int res;
    for(i=0;i<len;i++){
        for(j=0;j<len;j++)
            if(*(a+i)==*(b+j)){
                res = *(a+i);
                count++;
            }


    }
    if(count>1)
        return 20;
    else if(count ==0)
        return 0;
    else
        return res;
}

int main()
{
    int row1,row2,k,i,j,t,T,n = 10000;
    int a[4][4],b[4][4];

    freopen("data1.in","r",stdin);
    freopen("data1.out","w",stdout);
    cin>>T;
    for(t=0;t<T;t++){

        cin>>row1;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                cin>>*(a[i]+j);
        }
        cin>>row2;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++)
                cin>>*(b[i]+j);
        }

            k=unique(a[row1-1],b[row2-1],4);



            if(k==0)    cout<<"Case #"<<t+1<<": Volunteer cheated!"<<endl;
            else if(k==20)   cout<<"Case #"<<t+1<<": Bad magician!"<<endl;
            else    cout<<"Case #"<<t+1<<": "<<k<<endl;



    }

    fclose(stdin);
    fclose(stdout);
}
