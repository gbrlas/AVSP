#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int nb_cases;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>nb_cases;
    for(int c=0;c<nb_cases;c++)
    {
        int N;
        in>>N;
        vector <pair<int,int> > orange;
        vector <pair<int,int> > blue;
        for(int c2=0;c2<N;c2++)
        {
            string s;
            in>>s;
            int n2;
            in>>n2;
            if(s=="O")
                orange.push_back(make_pair(c2,n2));
            if(s=="B")
                blue.push_back(make_pair(c2,n2));
        }
        int o=0,b=0;
        int pos_o=1,pos_b=1;
        int nb_etapes=0;
        for(int c2=0;c2<N;c2++)
        {
            if((b>=blue.size())||(o<orange.size()&&orange[o].first<blue[b].first))
            {
                while(pos_o!=orange[o].second)
                {
                    if(b<blue.size())
                    {
                        if(pos_b<blue[b].second)
                            pos_b++;
                        if(pos_b>blue[b].second)
                            pos_b--;
                    }
                    if(pos_o<orange[o].second)
                        pos_o++;
                    else
                        pos_o--;
                    nb_etapes++;
                }
               if(b<blue.size())
                    {
                        if(pos_b<blue[b].second)
                            pos_b++;
                        if(pos_b>blue[b].second)
                            pos_b--;
                    }
                nb_etapes++;
                o++;
            }
            else
            {
                 while(pos_b!=blue[b].second)
                {
                    if(o<orange.size())
                    {
                        if(pos_o<orange[o].second)
                            pos_o++;
                        if(pos_o>orange[o].second)
                            pos_o--;
                    }
                    if(pos_b<blue[b].second)
                        pos_b++;
                    else
                        pos_b--;
                    nb_etapes++;
                }
                if(o<orange.size())
                    {
                        if(pos_o<orange[o].second)
                            pos_o++;
                        if(pos_o>orange[o].second)
                            pos_o--;
                    }
                nb_etapes++;
                b++;
            }
        }
    out<<"Case #"<<c+1<<": "<<nb_etapes<<endl;
    }
}


