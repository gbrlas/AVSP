#include<iostream>
#include<cstdio>
#include<deque>

using namespace std;

int t,n,num;
char car;
struct nodo{
    char car;int num;
    nodo(char Car,int Num){
        car=Car;num=Num;
    }
    nodo(){}
};

int doit(){
    scanf("%d",&n);
    deque<int>O,B;
    deque<nodo>Orden;
    for(int i=0;i<n;++i){
        cin>>car;cin>>num;
        //cout<<car<<num<<endl;
        if(car=='O'){
            O.push_back(num);
        }
        else{
            B.push_back(num);
        }
        Orden.push_back(nodo(car,num));
    }
    int posO=1,posB=1;
    int tiempo=0;
    while(!Orden.empty()){
        //printf("posO: %d, posB: %d, O: %d, B: %d\n",posO,posB,O.front(),B.front());
        //cout<<Orden.front().car<<" "<<Orden.front().num<<endl;
        if(posO==O.front()&&posO==Orden.front().num&&Orden.front().car=='O'){
            //cout<<"Push O"<<endl;
            Orden.pop_front();
            O.pop_front();
            if(posB!=B.front()){
                //cout<<"Move B"<<endl;
                if(B.front()>posB)posB++;
                else posB--;
            }
            tiempo++;
            continue;
        }
        if(posB==B.front()&&posB==Orden.front().num&&Orden.front().car=='B'){
            //cout<<"Push B"<<endl;
            Orden.pop_front();
            B.pop_front();
            if(posO!=O.front()){
                //cout<<"Move O"<<endl;
                if(O.front()>posO)posO++;
                else posO--;
            }
            tiempo++;
            continue;
        }
        //cout<<"Pase"<<endl;
        if(posO!=O.front()){
            //cout<<"O"<<endl;
            if(O.front()>posO)posO++;
            else posO--;
        }
        if(posB!=B.front()){
            //cout<<"B"<<endl;
            if(B.front()>posB)posB++;
            else posB--;
        }
        tiempo++;
    }
    return tiempo;
}

int main(){
    scanf("%d",&t);
    //cout<<t<<endl;
    for(int i=1;i<=t;++i){
        printf("Case #%d: %d\n",i,doit());
    }
}
