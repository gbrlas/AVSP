#include <iostream>
#include <fstream>

using namespace std;


int main() {
    int num = 0;
    ifstream in;
    in.open("in1.txt");    
    string line = "";
    getline(in, line);  
    num = atoi(line.c_str());
    char grid[4][4];
    int x = 0;
    int o = 0;
    int t = 0;
    bool won = false;
    ofstream out ("out1.txt");    
    for(int i = 0; i < num; i++) {
        won = false;            
        cerr << i << endl;
        for(int a = 0; a < 4; a++){
            getline(in,line);
            while(line == "") {
                    getline(in, line);
            }
            grid[a][0] = line.at(0);
            grid[a][1] = line.at(1);
            grid[a][2] = line.at(2);
            grid[a][3] = line.at(3);
        }   
               
        for(int j = 0; j < 4; j++) {
            x = 0;
            o = 0;
            t = 0;
            for(int k = 0; k < 4; k++) {
               if(grid[j][k] == 'X') {
                   x++;            
               } else if (grid[j][k] == 'O') {
                    o++;
               } else if (grid[j][k] == 'T') {
                    t++;       
               }
            }
            if((x == 3 && t == 1) || x == 4) {
                 out << "Case #" << i + 1 << ": X won" << endl; 
                 won = true;
                 break;
            } else if ((o == 3 && t == 1) || o == 4) {
                 out << "Case #" << i + 1 << ": O won" << endl; 
                 won = true;
                 break;
            }
        }
        if(won) {
        continue;
        }
        for(int l = 0; l < 4; l++) {
            x = 0;
            o = 0;
            t = 0;
            for(int m = 0; m < 4; m++) {
               if(grid[m][l] == 'X') {
                   x++;            
               } else if (grid[m][l] == 'O') {
                    o++;
               } else if (grid[m][l] == 'T') {
                    t++;       
               }
            }
            if((x == 3 && t == 1) || x == 4) {
                 out << "Case #" << i + 1 << ": X won" << endl; 
                 won = true;    
                 break;
            } else if ((o == 3 && t == 1) || o == 4) {
                 out << "Case #" << i + 1 << ": O won" << endl; 
                 won = true;
                 break;
            }
        }        
        x = 0;
        o = 0;
        t = 0;
        if(won) {
        continue;
        }
        for(int n = 0; n < 4; n++) {
              if(grid[n][n] == 'X') {
                   x++;            
               } else if (grid[n][n] == 'O') {
                    o++;
               } else if (grid[n][n] == 'T') {
                    t++;       
               }        
        }
        if((x == 3 && t == 1) || x == 4) {
                 out << "Case #" << i + 1 << ": X won" << endl; 
                 won = true;             
        } else if ((o == 3 && t == 1) || o == 4) {
                 out << "Case #" << i + 1 << ": O won" << endl; 
                 won = true;
        }
        x = 0;
        o = 0;
        t = 0;
        if(won) {
        continue;
        }
        for(int j = 0; j < 4; j++) {
              if(grid[j][3 - j] == 'X') {
                   x++;            
               } else if (grid[j][3 - j] == 'O') {
                    o++;
               } else if (grid[j][3 - j] == 'T') {
                    t++;       
               }        
        }
        if((x == 3 && t == 1) || x == 4) {
                 out << "Case #" << i + 1 << ": X won" << endl; 
                 won = true;
        } else if ((o == 3 && t == 1) || o == 4) {
                 out << "Case #" << i + 1 << ": O won" << endl; 
                 won = true;
        }
        if(won) {
        continue;
        }
        if(!won) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                        if(grid[j][k] == '.') {
                            out << "Case #" << i + 1 << ": Game has not completed" << endl; 
                            won = true;
                            break;     
                        }        
                }          
                if(won) {
                        break;
                }
            }
        }
        if(!won) {
                out << "Case #" << i + 1 << ": Draw" << endl; 
        }
        won = false;
        
    }
    
    cin >> num;
}
