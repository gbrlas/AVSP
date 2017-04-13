#include <iostream>

using namespace std;

int main()
{

    char a[4][4];
    int ch;
    cin>>ch;
    int k=1;
    while(k<=ch){
            for(int i=0;i<=3;i++){
                for(int j=0;j<=3;j++){
                    cin>>a[i][j];
                }
            }

            int flag=0,f1=0;
            for(int i=0;i<=3;i++){
                switch(a[i][0]){
                case 'X':
                    flag=1;
                    break;
                case 'O':
                    flag=2;
                    break;
                case 'T':
                    flag=3;
                    break;
                case '.':
                    f1=1;
                    break;
                default:
                    break;
                }
                for(int j=1;j<=3;j++){
                    if(a[i][j]=='X'&&(flag==1||flag==3)){
                        if(flag==3){
                            flag=1;
                        }
                         continue;
                    }
                    else if(a[i][j]=='O'&&(flag==2||flag==3)){
                        if(flag==3){
                            flag=2;
                        }
                        continue;
                    }
                    else if(a[i][j]=='T'){
                        continue;
                    }
                    else{
                        if(a[i][j]=='.')
                            f1=1;
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    cout<<"Case #"<<k<<": X won\n";
                    break;
                }
                else if(flag==2){
                    cout<<"Case #"<<k<<": O won\n";
                    break;
                }
            }

            if(flag==0){
                for(int i=0;i<=3;i++){
                    switch(a[0][i]){
                    case 'X':
                        flag=1;
                        break;
                    case 'O':
                        flag=2;
                        break;
                    case 'T':
                        flag=3;
                        break;
                    case '.':
                        f1=1;
                        break;
                    default:
                        break;
                    }
                    for(int j=1;j<=3;j++){
                        if(a[j][i]=='X'&&(flag==1||flag==3)){
                            if(flag==3){
                                flag=1;
                            }
                             continue;
                        }
                        else if(a[j][i]=='O'&&(flag==2||flag==3)){
                            if(flag==3){
                                flag=2;
                            }
                            continue;
                        }
                        else if(a[j][i]=='T'){
                            continue;
                        }
                        else{
                            if(a[i][j]=='.')
                                f1=1;
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1){
                        cout<<"Case #"<<k<<": X won\n";
                        break;
                    }
                    else if(flag==2){

                        cout<<"Case #"<<k<<": O won\n";
                        break;
                    }
                }
            }
            if(flag==0){
                switch(a[0][0]){
                    case 'X':
                        flag=1;
                        break;
                    case 'O':
                        flag=2;
                        break;
                    case 'T':
                        flag=3;
                        break;
                    case '.':
                        f1=1;
                        break;
                    default:
                        break;
                }
                for(int i=1;i<=3;i++){
                    if(a[i][i]=='X'&&(flag==1||flag==3)){
                            if(flag==3){
                                flag=1;
                            }
                             continue;
                        }
                        else if(a[i][i]=='O'&&(flag==2||flag==3)){
                            if(flag==3){
                                flag=2;
                            }
                            continue;
                        }
                        else if(a[i][i]=='T'){
                            continue;
                        }
                        else{
                            if(a[i][i]=='.')
                                f1=1;
                            flag=0;
                            break;
                        }

                }
                if(flag==1){
                        cout<<"Case #"<<k<<": X won\n";

                    }
                    else if(flag==2){

                        cout<<"Case #"<<k<<": O won\n";
                    }
            }
            if(!flag){
                int j=2;

                switch(a[0][3]){
                    case 'X':
                        flag=1;
                        break;
                    case 'O':
                        flag=2;
                        break;
                    case 'T':
                        flag=3;
                        break;
                    case '.':
                        f1=1;
                        break;
                    default:
                        break;
                }
                for(int i=1;i<=3;i++){
                    if(a[i][j]=='X'&&(flag==1||flag==3)){
                            if(flag==3){
                                flag=1;
                            }
                            j--;
                             continue;
                        }
                        else if(a[i][j]=='O'&&(flag==2||flag==3)){
                            if(flag==3){
                                flag=2;
                            }
                            j--;
                            continue;
                        }
                        else if(a[i][j]=='T'){
                                j--;
                            continue;
                        }
                        else{
                            if(a[i][j]=='.')
                                f1=1;
                            flag=0;
                            break;
                        }
                }
                if(flag==1){
                        cout<<"Case #"<<k<<": X won\n";

                    }
                    else if(flag==2){

                        cout<<"Case #"<<k<<": O won\n";
                    }
            }
            if(flag==0 && f1==1){
                cout<<"Case #"<<k<<": Game has not completed\n";
            }
            else if(flag==0 && f1==0){
                cout<<"Case #"<<k<<": Draw\n";
            }
            k++;
    }

    return 0;
}
