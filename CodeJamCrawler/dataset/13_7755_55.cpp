#include<iostream>
using namespace std;
struct quad{
  int cnt;
  bool f;
  char p;
  quad(void){
    cnt = 0;
    f = false;
    p = 0;
  }
};

// void reset(){
//   for(int i=0; i<4; i++){
//     col[i].p=0; col[i].cnt=0; col[i].f = true;
//     row[i].p=0; row[i].cnt=0; row[i].f = true;
//   }
//   diag[0].p = diag[1].p = 0;
//   diag[0].cnt = diag[1].cnt = 0;
//   diag[0].f = diag[1].f = true;
// }

int main(void){
    int T;
    cin>>T;
    for(int c=1; c<=T; c++){
        bool fWin = false, fEmp = false;
        int totNf = 8;
        char a, winr;
        quad col[4], row[4], diag[2];
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin>>a;
//                cout<<i<<","<<j<<" a:"<<a<<endl;
                if(fWin || (!totNf && fEmp)){
                    continue;
                }
                if(a == '.'){
                    fEmp = true;
                    col[j].f = true;
                    row[i].f = true;
                    if(i==j)
                        diag[0].f = true;
                    if(i+j == 3)
                        diag[1].f = true;
                }
                else{
                    if(!col[j].f){
                        if(a=='T' || !col[j].p || col[j].p == a){
 //                           cout<<"col"<<j<<": "<<col[j].cnt+1<<endl;
                            if(++col[j].cnt == 4){
                                fWin = true;
                                winr = col[j].p;
                                continue;
                            }
                            if(a != 'T')
                                col[j].p = a;
                        }
                        else{
                            col[j].f = true;
                            totNf--;
                        }
                    }
                    if(!row[i].f){
                        if(a=='T' || !row[i].p || row[i].p == a){
//                            cout<<"row"<<i<<": "<<row[i].cnt+1<<endl;
                            if(++row[i].cnt == 4){
                                fWin = true;
                                winr = row[i].p;
                                continue;
                            }
                            if(a != 'T')
                                row[i].p = a;
                        }
                        else{
                            row[i].f = true;
                            totNf--;
                        }
                    }
                    if(i==j){
                        if(a=='T' || !diag[0].p || diag[0].p == a){
 //                           cout<<"diag0"<<": "<<diag[0].cnt+1<<endl;
                            if(++diag[0].cnt == 4){
                                fWin = true;
                                winr = diag[0].p;
                                continue;
                            }
                            if(a != 'T')
                                diag[0].p = a;
                        }
                        else{
                            diag[0].f = false;
                            totNf--;
                        }
                    }
                    else if(i+j == 3){
                        if(a=='T' || !diag[1].p || diag[1].p == a){
 //                           cout<<"diag1"<<": "<<diag[1].cnt+1<<endl;
                            if(++diag[1].cnt == 4){
                                fWin = true;
                                winr = diag[1].p;
                                continue;
                            }
                            if(a != 'T')
                                diag[1].p = a;
                        }
                        else{
                            diag[1].f = false;
                            totNf--;
                        }
                    }
                }
            }
        }
        if(fWin){
          cout<<"Case #"<<c<<": "<<winr<<" won\n";
        }
        else if(fEmp){
          cout<<"Case #"<<c<<": "<<"Game has not completed\n";
        }
        else{
          cout<<"Case #"<<c<<": "<<"Draw\n";
        }
    }
}
