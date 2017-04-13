#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int T;
        cin >> T;


        int needA[24*60]={0};
        int needB[24*60]={0};
        int a, b;
        cin >> a >> b;

        vector<int> startsA;
        vector<int> startsB;

        for(int j=0; j<a; j++)
        {
            int h, m;
            char coron;
            cin >> h >> coron >> m;

            int startTime=h*60+m;
            cin >> h >> coron >> m;

            int goalTime=h*60+m;

            int t;
            for(t=startTime; t<60*24; t++)
            {
                needA[t]++;
            }
            startsA.push_back(startTime);

            for(t=goalTime+T;t<60*24; t++)
            {
                needB[t]--;
            }
        }
        for(int j=0; j<b; j++)
        {
            int h, m;
            char coron;
            cin >> h >> coron >> m;

            int startTime=h*60+m;
            cin >> h >> coron >> m;

            int goalTime=h*60+m;

            int t;
            for(t=startTime; t<60*24; t++)
            {
                needB[t]++;
            }
//            needB[startTime]++;
            startsB.push_back(startTime);

            for(t=goalTime+T;t<60*24; t++)
            {
                needA[t]--;
            }

        }

        int ansA = *max_element(needA, needA+60*24),
            ansB = *max_element(needB, needB+60*24);
        cout << "Case #"<< i+1 << ": " << ansA << " " << ansB << endl;
    }
    return 0;
}
