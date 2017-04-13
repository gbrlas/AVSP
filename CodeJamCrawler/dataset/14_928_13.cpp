#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        int sz,t;
        _if >> t >> sz;
        int files[t];
        for(int j=0;j<t;j++)
            _if >> files[j];

        vector<int> myvector (files, files+t);
        sort(myvector.begin(),myvector.begin()+t);
        int taken = 0;
        int cds = 0;
        int last = t-1;
        int first = 0;
        while(taken < t){
            if(last == first){
                taken++;
                cds++;
                break;
            }
            if(myvector[last] + myvector[first] <= sz){
                taken += 2;
                last--;
                first++;
                cds++;
            }
            else{
                last--;
                taken++;
                cds++;
            }
        }


        _of << "Case #" << i+1 << ": " << cds << endl;
    }
}
