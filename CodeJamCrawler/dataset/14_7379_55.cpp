#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( (*(double*)a > *(double*)b)? 1 : -1 );
}


//a,b sorted
 int dw(double *a,double *b,int n)
 {
    int i=0,j=0,re=0;
    while(i<n){
        if(*(a+i)>*(b+j)){
            i++;j++;re++;
        }
        else{
            i++;
        }
    }
    return re;
 }

int d(double *a,double *b,int n)
{
    return(n-dw(b,a,n));
}

int main()
{
    int n,i,t,T;
    double temp;
 //   double a[NN],b[NN];
    freopen("data4.in","r",stdin);
    freopen("data4.out","w",stdout);
    cin>>T;
    for(t=0;t<T;t++){
        cin>>n;
        double *a=new double[n];
        double *b=new double[n];
        for(i=0;i<n;i++) {
            cin>>*(a+i);
        }
        for(i=0;i<n;i++){
             cin>>*(b+i);
        }
        qsort(a,n,sizeof(double),compare);
        qsort(b,n,sizeof(double),compare);


        cout<<"Case #"<<t+1<<": "<<dw(a,b,n)<<" "<<d(a,b,n)<<endl;
        delete [] a;
        delete [] b;
    }

    fclose(stdin);
    fclose(stdout);
}
