#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int t;
    cin>>t;
    for(int kase = 1; kase <= t; kase++) {
        int a, b;
        int first[4][4], second[4][4];
        cin>>a;
        a--;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin>>first[i][j];
        cin>>b;
        b--;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin>>second[i][j];
        int ans = -1, count = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if (first[a][i] == second[b][j]) {
                    ans = first[a][i];
                    count++;
                }
            }
        }
        cout<<"Case #"<<kase<<": ";
        if (ans == -1)
            cout<<"Volunteer cheated!"<<endl;
        else if (count > 1)
            cout<<"Bad magician!"<<endl;
        else
            cout<<ans<<endl;
    }
    
    return 0;
}
