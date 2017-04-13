#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int t;
    int c, d, n;
    char combine[36][3];
    char opposed[28][2];
    vector<char> gameList;
    ifstream infile("B-large.in");
    ofstream outfile("output-large.txt");
    infile >> t;
    int casenum = 1;
    while(t--) {
        infile >> c;
        for(int i = 0; i < c; ++i)
            for(int j = 0; j < 3; ++j)
                infile >> combine[i][j];
        infile >> d;
        for(int i = 0; i < d; ++i)
            for(int j = 0; j < 2; ++j)
                infile >> opposed[i][j];
        infile >> n;
        gameList.clear();
        for(int i = 0; i < n; ++i) {
            bool isMagic = false;
            char element;
            infile >> element;
            if(!gameList.empty()) {
                char element_t = gameList.back();
                for(int j = 0; j < c; ++j) {
                    if((element == combine[j][0] && element_t == combine[j][1]) || 
                        (element_t == combine[j][0] && element == combine[j][1])) {
                        element = combine[j][2];
                        gameList.pop_back();
                        gameList.push_back(element);
                        isMagic = true;
                        break;
                    }
                }
                for(int j = 0; j < gameList.size(); ++j) {
                    element_t = gameList[j];
                    for(int k = 0; k < d; ++k) {
                        if((element == opposed[k][0] && element_t == opposed[k][1]) ||
                            (element_t == opposed[k][0] && element == opposed[k][1])) {
                            gameList.clear();
                            isMagic = true;
                            break;
                        }
                    }
                }
                if(!isMagic)
                    gameList.push_back(element);    
            }
            else
                gameList.push_back(element);
        }
        
        outfile << "Case #" << casenum << ": [";
        for(int i = 0; i < gameList.size(); ++i) {
            if(i == gameList.size() - 1)
                outfile << gameList[i];
            else
                outfile << gameList[i] << ", ";
        }
        outfile << "]" << endl;
        ++casenum;
    }
    infile.close();
    outfile.close();
    system("pause");
    return 0;
}