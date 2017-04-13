#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    int N;
    cin>>N;
    for (int k=1; k<=N; k++){

        vector<int> IX(4,0);
        vector<int> JX(4,0);
        vector<int> DX(4,0);

        vector<int> IO(4,0);
        vector<int> JO(4,0);
        vector<int> DO(4,0);

        bool swX = false, swO = false, swG = false;
        char mat[4][4];
        bool sw = false;
        for ( int i=0; i<4; i++ ){
            for (int j=0; j<4; j++){
                    cin>>mat[i][j];

                        if (mat[i][j]=='.'){
                            sw = true;
                        }

                        if (!swG){
                            if (mat[i][j]=='X' || mat[i][j]=='T'){
                                IX[j]+=1;
                                JX[i]+=1;
                                if (i==j){
                                    DX[0]+=1;
                                }

                                if ((i==0 && j==3)||(i==1&&j==2)||(i==2&&j==1)||(i==3&&j==0)){
                                    DX[1]+=1;
                                }

                                if (IX[j]==4 || JX[i]==4 || DX[0]==4 || DX[1]==4){
                                    swX=true;
                                    swG=true;
                                }
                            }
                            if(mat[i][j]=='O' || mat[i][j]=='T'){
                                IO[j]+=1;
                                JO[i]+=1;
                                if (i==j){
                                    DO[0]+=1;
                                }
                                if ((i==0 && j==3)||(i==1&&j==2)||(i==2&&j==1)||(i==3&&j==0)){
                                    DO[1]+=1;
                                }
                                if (IO[j]==4 || JO[i]==4 || DO[1]==4 || DO[0]==4){
                                    swO=true;
                                    swG=true;
                                }
                            }
                        }


            }
        }
        cout<<"Case #"<<k<<": ";
        if (swX){
            cout<<"X won"<<endl;
            continue;
        }
        if (swO){
            cout<<"O won"<<endl;
            continue;
        }
        if (sw){
            cout<<"Game has not completed"<<endl;
            continue;
        }
        cout<<"Draw"<<endl;

    }
    return 0;
}
