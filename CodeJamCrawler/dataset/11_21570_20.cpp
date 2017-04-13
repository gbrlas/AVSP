

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int checkBlock(int r, int c, int R, int C, char a[][50], char mar[][50]){
    if(r==R-1 || c==C-1)
        return 0;
    if(a[r][c]=='#')
        mar[r][c]='/';
    else return 0;
    if(a[r][c+1]=='#')
        mar[r][c+1]='\\';
    else return 0;
    if(a[r+1][c]=='#')
        mar[r+1][c]='\\';
    else return 0;
    if(a[r+1][c+1]=='#')
        mar[r+1][c+1]='/';
    else return 0;    
    return 1;
}
int main(int argc, char** argv) {
    ifstream inFile;
    ofstream outFile;
    int T,R,C;
    
    inFile.open("A-small-attempt1.in", ifstream::in);
    outFile.open("A-small.out", ifstream::out);
    inFile >> T;
    
    for(int i=0;i<T;i++){
        char picture[50][50];
        char mark[50][50];
        int countBlue=0;
        outFile<<"Case #"<<i+1<<":"<<endl;
        //Input
        inFile>>R; 
        inFile>>C;
        for(int j=0;j<R;j++){
            for(int l=0;l<C;l++){
                inFile>>picture[j][l];                
                if(picture[j][l]=='#')
                    countBlue++;                
                mark[j][l]='.';
            }
        }        
        //Process
        if(countBlue==0){
            for(int j=0;j<R;j++){
                for(int l=0;l<C;l++){               
                    outFile<<picture[j][l];                    
                }
                outFile<<endl;
            } 
            continue;
        }else if(countBlue%4!=0){
            outFile<<"Impossible"<<endl;
            continue;
        }else{
            int flag=0;
            for(int j=0;j<R;j++){
                for(int l=0;l<C;l++){
                    if(picture[j][l]=='#' && mark[j][l]=='.'){
                        if(checkBlock(j,l,R,C,picture,mark)==0){
                            j=100;l=100;
                            outFile<<"Impossible"<<endl;
                            flag=1;
                        }
                    }
                }
            }
            if(flag==0){
                for(int j=0;j<R;j++){
                    for(int l=0;l<C;l++){
                        outFile<<mark[j][l];
                    }
                    outFile<<endl;
                }
            }
        }
        //Output        
    }

    inFile.close();
    outFile.close();
    return 0;
}

