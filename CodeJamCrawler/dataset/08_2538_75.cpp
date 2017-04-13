#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        string buf;
        int engineNum;
        cin >> engineNum;
        getline(cin, buf); //
        for(int e=0; e<engineNum; e++)
        {
            getline(cin, buf);
        }

        set<string> s;
        int cnt=0;
        int q;
        cin >> q;
        getline(cin, buf); //
        for(int j=0; j<q; j++)
        {
            getline(cin, buf);
            s.insert(buf);
            if(s.size()==engineNum)
            {
                cnt++;
                s.clear();
                s.insert(buf);
            }
        }
        cout << "Case #" << i+1 <<": " << cnt << endl;
    }
    return 0;
}
