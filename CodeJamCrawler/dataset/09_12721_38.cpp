#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, p, q;
    int prisoner[110], release[110];
    cin>>n;
    for(int i = 1; i<= n; i++) {
        cin>>p>>q;
        for(int j = 0; j<q;j++) {
            cin>>release[j];
        }
        sort(release, release+q);
        int min = 0xFFFF;
        do {
            memset(prisoner, 0, sizeof(prisoner));
            int jb=0;
            for(int j = 0; j < q; j++) {
                int tr = release[j];
                prisoner[tr] = 1;
                for(int k = tr+1; k <= p && prisoner[k]==0; k++) {
                    jb++;
                }
                for(int k=tr-1;k>=1 && prisoner[k]==0; k--) {
                    jb++;
                }
            }
            if(jb<min)
                min=jb;
        }while(next_permutation(release, release+q));
        cout<<"Case #"<<i<<": "<<min<<endl;
    }
    return 0;
}
