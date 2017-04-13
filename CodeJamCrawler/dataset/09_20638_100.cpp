#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long gogogo(vector<int> v , int base)
{
    long long ret = 0;
    int i;
    long long k = 1;
    for (i = v.size() - 1; i >= 0; i--)
    {
        ret += k * v[i];
        k *= base;
    }

    return ret;
}

int b[1000] , u[1000] , nom;

int main()
{
    freopen("d:/input.txt" , "r" , stdin);
    freopen("d:/output.txt" , "w" , stdout);

	int t;
    cin>>t;
	int i;
    for (int tt = 1; tt <= t; tt++)
    {
        string s;
        cin>>s;
		nom = 0;

        for (i = 0; i < 300; i++)
            u[i] = 0;

        int sum = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (u[s[i]] == 0)
            {
                u[s[i]] = 1;
                sum++;
            }
        }

		int j;
		long long ans;
		if (sum < 2)  sum = 2;
        for (i = sum; i <= sum; i++)
        {
            string s1 = s;
            for (j = 0; j < 300; j++)
                b[j] = -1;

            nom = 0;
			b[s1[0]] = 1;
            for(j = 0; j < s1.size();j++)
            {
                if (b[s1[j]] == -1)
                {
					if (nom == 1) nom++;
                    b[s1[j]] = nom++;
                }
            }

            vector<int> v;
            for (j = 0; j < s1.size(); j++)
            {
                v.push_back(b[s1[j]]);
            }

            ans = gogogo(v , i);

        }




        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }

    return 0;
}