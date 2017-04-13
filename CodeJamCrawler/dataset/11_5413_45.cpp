#include<iostream>
#include<algorithm>
#define MAX 1010
using namespace std;

int main()
{
    int N_T,T_C=0,List[MAX],min=0,sum=0;
    cin >> N_T;
    while(T_C<N_T){
        int N_E=0;
        List[0]=0;min=0,sum=0;
        cin >> N_E;
        for(int i=1;i<=N_E;i++){
            cin >> List[i];
            List[0]=List[0]^List[i];
            if(i==1)
                min=List[i];
            else if(min > List[i])
                min=List[i];
            else{}
            sum+=List[i];
        }
        if(List[0]!=0)
            cout<<"Case #"<<T_C+1<<": NO"<<endl;
        else{

            cout<<"Case #"<<T_C+1<<": "<<sum-min<<endl;
        }
        T_C++;
    }
    return 0;
}
