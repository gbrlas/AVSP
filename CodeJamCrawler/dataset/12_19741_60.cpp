#include <iostream>
#include <cstring>
using namespace std;

char g[1024];
int T;

int main(){
    
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.out","w",stdout);
    
    cin >> T;
    cin.ignore();
    
    for(int a=0;a<T; a++){
            cout << "Case #" << a+1 << ": ";
            
            cin.getline(g,1024);
            
            for(int b=0; b<strlen(g); b++){
                    char t = g[b];
     
                    if(t=='a') cout << "y";
                    if(t=='b') cout << "h";
                    if(t=='c') cout << "e";
                    if(t=='d') cout << "s";
                    if(t=='e') cout << "o";
                    if(t=='f') cout << "c";
                    if(t=='g') cout << "v";
                    if(t=='h') cout << "x";
                    if(t=='i') cout << "d";
                    if(t=='j') cout << "u";
                    if(t=='k') cout << "i";
                    if(t=='l') cout << "g";
                    if(t=='m') cout << "l";
                    if(t=='n') cout << "b";
                    if(t=='o') cout << "k";
                    if(t=='p') cout << "r";
                    if(t=='q') cout << "z";
                    if(t=='r') cout << "t";
                    if(t=='s') cout << "n";
                    if(t=='t') cout << "w";
                    if(t=='u') cout << "j";
                    if(t=='v') cout << "p";
                    if(t=='w') cout << "f";
                    if(t=='x') cout << "m";
                    if(t=='y') cout << "a";
                    if(t=='z') cout << "q";
                    if(t==' ') cout << " ";      
            }
            
            cout << endl;
    
    }


    //system("PAUSE");
    return 0;
    
}
