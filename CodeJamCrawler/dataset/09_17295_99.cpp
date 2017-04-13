#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using namespace std;

const int R_MAX = 19;
const int C_MAX = 500;
int matrix[R_MAX][C_MAX];
string welcome = "welcome to code jam";

int main()
{
    int N;
    string input;
    cin >> N;
    getline(cin, input); // first newline

    for(int n = 0 ; n < N ; ++n){
        getline(cin, input);

        memset(matrix, 0, sizeof(matrix));

        int R = welcome.size();
        int C = input.size();
        assert(R <= R_MAX);
        assert(C <= C_MAX);
        
        for(int r = 0 ; r < R ; ++r){
            for(int c = 0 ; c < C ; ++c){
                if(input[c] == welcome[r]){
                    if(r == 0){
                        matrix[r][c] = 1;
                    }else{
                        for(int cc = 0 ; cc < c ; ++cc){
                            matrix[r][c] += matrix[r-1][cc];
                            matrix[r][c] %= 10000;
                        }
                    }
                }
            }
        }

        int result = 0;
        for(int c = 0 ; c < C ; ++c){
            result += matrix[R-1][c];
            result %= 10000;
        }

        printf("Case #%d: %04d\n", n + 1, result);
    }

    return 0;
}
            
                        
            
        
               
        
