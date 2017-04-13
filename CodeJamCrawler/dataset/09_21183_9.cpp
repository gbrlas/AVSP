//2009/09/12 11:11:21
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <sstream>
#include <algorithm>

using namespace std;

bool is(string v, int n)
{
    string temp(v);
    do
    {
        int found = temp.find('0');
        if (found != -1)
            temp.erase(temp.begin() + found);
    }
    while (temp.find('0') != -1);
    stringstream s;
    s << n;
    for (int i=0; i<s.str().size(); i++)
    {
        //cout << "Tci" << endl;
        if (isdigit(s.str().at(i)) && s.str().at(i) != '0')
        {
            //if (v.size() == 0) return false;
            int found = temp.find(s.str().at(i));
            if (found == -1) return false;
            else temp.erase(temp.begin() + found);
        }
    }
    //cout << temp << endl;
    if (temp.empty()) return true;
    return false;
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int T;
    scanf("%d", &T);
    //printf("%d\n", T);
    for (int t=1; t<=T; t++)
    {
        //vector<char> v;
        //v.clear();
        int N;
        scanf("%d", &N);
        stringstream s;
        s << N;
        string str = s.str();
        //for (int j=0; j<str.size(); j++)
        //    if (isdigit(str[j]) && str[j]!='0') v.push_back(str[j]);
        //cout <<"Ticket" << endl;
        for (int j=N+1; ; j++)
        {
            //cout << str.size() << endl;
            if (is(str, j))
            {
                printf("Case #%d: %d\n", t, j);
                break;
            }
        }
    }


    fclose(stdout);
    fclose(stdin);

    return 0;
}
