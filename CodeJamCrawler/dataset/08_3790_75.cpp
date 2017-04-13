#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;


ofstream cout("A-large.out");
ifstream cin ("A-large.in");



int main()
{

    int count = 0;
    cin >> count;
    for (int t = 1; t <= count; ++t)
    {
        int s = 0;
        cin >> s;
        string name;
        map<string, int> names;
        for (int i = 0; i < s; ++i)
        {
            getline(cin, name);
            if (name.empty())
            {
                --i;
                continue;
            }
            names[name] = i;
        }

        int q = 0;
        cin >> q;
        vector<int> v(q);
        for (int i = 0; i < q; ++i)
        {
            getline(cin, name);
            if (name.empty())
            {
                --i;
                continue;
            }
            v[i] = names[name];
        }

        vector<int> minSwith1(s), minSwith2(s);

        for (int i = q - 1; i >= 0; --i)
        {
            for (int j = 0; j < s; ++j)
            {
                if(v[i] == j)
                {
                    int minE = 1000000;
                    for (unsigned k = 0; k < minSwith1.size(); ++k)
                    {
                        if (k != j && minSwith1[k] < minE)
                        {
                            minE = minSwith1[k];
                        }
                    }
                    
                    minSwith2[j] = minE + 1;
                }
                else
                    minSwith2[j] = minSwith1[j];
            }
            minSwith1.swap(minSwith2);
        }

        int minE = * min_element(minSwith1.begin(), minSwith1.end());
        cout<< "Case #"<<t<<": " << minE << endl; 
    }
    return 0;
} 
