//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int L;
    int D;
    int ncase;
    scanf("%d%d%d", &L, &D, &ncase);
	//printf("%d %d %d\n", L, D, ncase);
    getchar();
    set<string> dic;
    set<string>::iterator it;
    for (int i=0; i<D; i++)
    {
        char s[1000];
        scanf("%s", s);
        dic.insert(s);
		//printf("%s\n", s);
    }
    
    
    for (int t=1; t<=ncase; t++)
    {
		vector<string> v(L);
		v.clear();
        char s[1000];
        scanf("%s", s);
        int idx = 0;
        bool flag = false;
        for (int i=0; i<strlen(s); i++)
        {
            if (s[i] == '(') flag = true;
            else if (isalpha(s[i]))
            {
                if (!flag)
                {
                    v[idx] += s[i];
                    idx ++;
                }
                else
                    v[idx] += s[i];
            }
            else if (s[i] == ')')
            {
                flag = false;
                idx++;
            }
        }
		
		//for(int i=0; i<L; i++) cout << v[i] << endl;
        int ret = 0;
        for (it = dic.begin(); it!= dic.end(); it++)
        {
            string temp = (*it);
            bool fflag = true;
            for (int i=0; i<L; i++)
            {
                if (v[i].find(temp[i]) == string::npos)
                {
                    fflag = false;
                    break;
                }
            }
            if (fflag)
                ret ++;
        }
		printf("Case #%d: %d\n", t, ret);
    }

    fclose(stdout);
    fclose(stdin);

    return 0;
}

