#include<iostream>
#include<vector>

using namespace std;

int tot,L,t,N,C;
int val[1000];
int v[1000];

int doit(){
    scanf("%d%d%d%d",&L,&t,&N,&C);
    //cout<<L<<" "<<t<<" "<<N<<" "<<C<<endl;
    for(int i=0;i<C;++i){
        cin>>val[i];
        //cout<<val[i]<<" ";
    }
    //puts("");
    vector<int> vec;
    int dis=0;
    bool ya=false;
    for(int i=0;i<N;++i){
        v[i]=val[i%C];
        //cout<<v[i]<<endl;
        dis+=2*v[i];
        //cout<<dis<<endl;
        if(ya){
            vec.push_back(v[i]);
            //cout<<vec[vec.size()-1]<<endl;
        }
        if(dis>t&&!ya){
            //cout<<"Entre"<<endl;
            vec.push_back((dis-t)/2);
            //cout<<vec[vec.size()-1]<<endl;
            //dis=t;
            ya=true;
        }
        //dis+=v[i];
        //cout<<v[i]<<" ";
    }
    dis=t;
    /*for(int i=0;i<vec.size();++i){
        cout<<vec[i]<<" ";
    }
    puts("");
    sort(vec.begin(),vec.end());*/
    if(vec.size()!=0){
        int tam=vec.size();
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();++i){
            //cout<<vec[i]<<" ";
            if(i<tam-L){
                dis+=vec[i]*2;
            }
            else{
                dis+=vec[i];
            }
        }
        //puts("");
        //cout<<"Usu"<<endl;
    }
    return dis;
    //puts("");
}

int main(){
    scanf("%d",&tot);
    //cout<<tot<<endl;
    for(int i=0;i<tot;++i){
        printf("Case #%d: %d\n",i+1,doit());
    }
}
