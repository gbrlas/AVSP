#include <iostream>

#include <map>

using namespace std;

int main()
{

    map<char, char> replacemap;

    int i =0;
    while(i<3)
    {
        ++i;
        char s1[101], s2[101];
        cin.getline (s1,101);
        cin.getline (s2, 101);


        int k =0;
        while(s1[k] != '\0')
        {
           if(s1[k] != ' ')
            {
                replacemap[s1[k]] = s2[k];
            }
            ++k;
        }
    }


    /*cout<< replacemap.size() <<endl;

    for(map<char, char>::iterator iter = replacemap.begin(); iter != replacemap.end(); ++iter)
    {
        cout<< iter->first <<"->" << iter->second <<endl;
    }*/
    replacemap['q'] = 'z';
    replacemap['z'] = 'q';

    char no[10];
    int N;
    cin.getline(no,10);
    N = atoi(no);

    int c =0;
    while(c<N)
    {
        cout<<"Case #"<<c+1<<": ";
        char s1[101];
        cin.getline (s1,101);
        int k =0;
        while(s1[k] != '\0')
        {
            char c = s1[k];
            if(s1[k] != ' ')
            {
                c = replacemap[c];
            }
            cout<<c;
            ++k;
        }
        cout<<endl;
        ++c;
    }
}

