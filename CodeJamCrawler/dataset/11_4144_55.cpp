#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


int main(void){
    int t;
    cin >> t;
    for (int i=1; i<=t; i++){

        map<vector<char>, char> combine;
        map<vector<char>, bool> oppose;
        // create combine mapping
        int c;
        cin >> c;
        for (int x=0; x<c; x++){
            string comb;
            cin >> comb;
            vector<char> tmp;
            tmp.push_back(comb[0]);
            tmp.push_back(comb[1]);
            combine[tmp] = comb[2];
            vector<char> tmp2;
            tmp2.push_back(comb[1]);
            tmp2.push_back(comb[0]);
            combine[tmp2] = comb[2];
        }
        // create oppose mapping
        int d;
        cin >> d;
        for(int x=0; x<d; x++){
            string comb;
            cin >> comb;
            vector<char> tmp;
            tmp.push_back(comb[0]);
            tmp.push_back(comb[1]);
            oppose[tmp] = true;
            vector<char> tmp2;
            tmp2.push_back(comb[1]);
            tmp2.push_back(comb[0]);
            oppose[tmp2] = true;
        }
        // read chars and create list
        vector<char> output;
        int n;
        cin >> n;
        string line;
        cin >> line;
        for(int x=0; x<n; x++){
            if (output.size() == 0){
                output.push_back(line[x]);
            }
            else {
                // check to combine
                vector<char> tmp;
                tmp.push_back(output.back());
                tmp.push_back(line[x]);
                if (combine.find(tmp) != combine.end()){
                    output.pop_back();
                    output.push_back(combine[tmp]);
                } else {
                    output.push_back(line[x]);
                }

                //check for elimination
                char top = output.back();
                vector<char> tmp2;
                tmp2.push_back(top);
                for(int z=0; z<output.size(); z++){
                    tmp2.push_back(output[z]);
                    if (oppose[tmp2] == true){
                        output.clear();
                    }
                    tmp2.pop_back();
                }
            }
        }
        cout << "Case #" << i << ": " << "[";
        if (output.size() > 0){
            for (int x=0; x<output.size()-1; x++){
                cout << output[x] << ", ";
            }
            for(int x=output.size()-1; x<output.size(); x++){
                cout << output[x];
            }
        }
        cout << "]" << endl;
        output.clear();
    }


}
