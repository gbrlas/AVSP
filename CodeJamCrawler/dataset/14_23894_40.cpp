#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, M, N;

string arr[10];
vector<string> vec[5];

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>M>>N;
        for(int i=0; i<M; i++)
        {
            cin>>arr[i];
        }

        int mx = -1, mxnum = 0;
        
        int K = 1;
        for(int i=0; i<M; i++)K *= N;
        for(int i=0; i<K; i++)
        {
            for(int j=0; j<N; j++)
                vec[j].clear();

            int b = i;
            for(int j=0; j<M; j++)
            {
                vec[b%N].push_back(arr[j]);
                b /= N;
            }

            int nm = 0;
            for(int j=0; j<N; j++)
            {
                int kmn = 0;
                int L = vec[j].size();
                if(L==0)continue;
                kmn++;
                for(int k=0; k<L; k++)
                {
                    int maxlcs = 0;
                    for(int l=0; l<k; l++)
                    {
                        int lcs = mismatch(vec[j][k].begin(), vec[j][k].end(), vec[j][l].begin()).first - vec[j][k].begin();
                        maxlcs = max(maxlcs, lcs);
                    }
                    kmn += vec[j][k].size() - maxlcs;
                }

                // cout<<"M "<<j<<endl;
                // for(int i=0; i<L; i++)cout<<vec[j][i]<<" ";cout<<endl;
                // cout<<kmn<<endl;
                nm += kmn;
            }
            if(nm>mx)
            {
                mx = nm;
                mxnum = 0;
            }
            if(nm==mx)
                mxnum++;
        }
        cout<<"Case #"<<t<<": "<<mx<<" "<<mxnum<<endl;
    }

    return 0;
}
