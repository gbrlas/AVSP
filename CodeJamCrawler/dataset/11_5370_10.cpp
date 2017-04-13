#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    fstream inputfile;
    fstream outfile;
    
    inputfile.open("input.txt", fstream::in );
    outfile.open("magickaoutput.txt", (fstream::out|fstream::trunc) );
    
    int T;
    inputfile >> T;
    for(int trial=0;trial<T;trial++){
        char cast[100];
        bool conflict[256][256]; for(int i=0;i<256;i++){ for(int j=0;j<256;j++){ conflict[i][j]=0; } }
        char combo[256][256]; for(int i=0;i<256;i++){ for(int j=0;j<256;j++){ combo[i][j]=0; } }
        string output = "";
        int C, D, N;
        
        inputfile >> C;
        for(int i=0;i<C;i++){
            char temp[3];
            inputfile >> temp;
            combo[(temp[0])][(temp[1])]=temp[2];
            combo[(temp[1])][(temp[0])]=temp[2];
        }
        
        inputfile >> D;
        for(int i=0;i<D;i++){
            char temp[2];
            inputfile >> temp;
            conflict[temp[0]][temp[1]]=1;
            conflict[temp[1]][temp[0]]=1;
            cout << "Conflict of" << temp[0] << temp[1] << endl;
        }
        
        inputfile >> N;
        inputfile >> cast;
        cout << "Let's roll, " << cast << endl;
                
        output+=cast[0];
        for(int i=1;i<N;i++){
            output+=cast[i];
            if(combo[ output[output.size()-1] ][ output[output.size()-2] ]){
                cout << "Found combo on " << i << ": " << output[output.size()-1] << output[output.size()-2] << combo[output[output.size()-1]][output[output.size()-2]] << endl;
                output.replace(output.size()-2, 2, &combo[ output[output.size()-1] ][ output[output.size()-2] ]);
            }else{
                bool conflicted=0;
                for(int jayzee=1;( jayzee<output.size() )&& ( !conflicted );jayzee++){
                    if(conflict[output[output.size()-1]][output[output.size()-1-jayzee]]){
                        output.clear();
                        conflicted=1;
                        cout << "Found conflict on " << i << ": " << output[output.size()-1] << output[output.size()-1-jayzee] << jayzee << endl;
                    }
                }
            }
            cout << "String is" << output << endl;
        }
        outfile << "Case #" << trial+1 << ": [";
        for(int i=0;i<output.size();i++){
            outfile << output[i];
            if(i!=output.size()-1) outfile << ", ";
        }
        outfile << "]" << endl;
        cout << "trial" << trial << "/" << T << "\nC: " << C << "\nD: " << D << endl;
        cout << output << endl << endl;
    }
    outfile.close();
    inputfile.close();
    
    system("PAUSE");
    return 0;
}
