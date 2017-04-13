#include<iostream>
#include<vector>

using namespace std;

int t,tam,a,b;
string s1[1000],s2[1000];
string s;
vector<char>Q;

void sim(int pos){
    //cout<<"Sim: "<<pos<<endl;
    char u=s[pos];
    //cout<<"u: "<<u<<endl;
    if(Q.size()!=0){
        bool hice=false;
        for(int i=0;i<a;++i){
            char x=s1[i][0],y=s1[i][1];
            char v=Q[Q.size()-1];
            //cout<<"v: "<<v<<endl;
            //cout<<"x: "<<x<<" y: "<<y<<endl;
            if((x==u&&y==v)||(x==v&&y==u)){
                //cout<<"Chamco "<<Q.size()-1<<" "<<s1[i][2]<<endl;
                Q[Q.size()-1]=s1[i][2];
                hice=true;
                break;
            }
        }
        if(!hice){
            //cout<<"Pongo1"<<endl;
            Q.push_back(u);
        }
    }
    else{
        //cout<<"Pongo2"<<endl;
        Q.push_back(u);
    }
    
    if(Q.size()>1){
        for(int i=0;i<b;++i){
            char x=s2[i][0],y=s2[i][1];
            char v=Q[Q.size()-1];
            bool elimin=false;
            if(v==x){
                for(int i=0;i<Q.size()-1;++i){
                    if(Q[i]==y){
                        Q.clear();elimin=true;break;
                    }
                }
            }
            if(v==y){
                for(int i=0;i<Q.size()-1;++i){
                    if(Q[i]==x){
                        Q.clear();elimin=true;break;
                    }
                }
            }
        }
    }
}

void doit(){
    scanf("%d",&a);
    //cout<<"a: "<<a<<endl;
    for(int i=0;i<a;++i){
        cin>>s1[i];
        //cout<<s1[i]<<endl;
    }
    scanf("%d",&b);
    //cout<<b<<endl;
    for(int i=0;i<b;++i){
        cin>>s2[i];
        //cout<<s2[i]<<endl;
    }
    cin>>tam>>s;
    //cout<<tam<<" "<<s<<endl;
    Q.clear();
    for(int i=0;i<tam;++i){
        sim(i);
    }
    printf("[");
    for(int i=0;i<Q.size();++i){
        if(i!=0){
            cout<<", "<<Q[i];
            //pritnf(", %d",);
        }
        else{
            cout<<Q[i];
        }
    }
    printf("]\n");
}

int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        printf("Case #%d: ",i);doit();
    }
}
