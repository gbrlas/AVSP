#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct node{
    bool onoffstate;
    bool powerstate;
};

int main()
{
    int casenumber,N,K;
    int i,j,m,n;

    FILE *f;
    f = fopen("input.txt","r");

    fscanf(f,"%d",&casenumber);

    for(i=0;i<casenumber;i++)
    {
        vector<struct node> gogo;
        gogo.clear();

        fscanf(f,"%d",&N);
        fscanf(f,"%d",&K);

        struct node root;
        root.onoffstate = false;
        root.powerstate = true;
        gogo.push_back(root);

        for(j=0;j<N-1;j++)
        {
            struct node temp;

            temp.onoffstate = false;
            temp.powerstate = false;

            gogo.push_back(temp);
        }


        for(j=0;j<K;j++)
        {
            for(m=0;m<gogo.size();m++)
            {
                if(gogo.at(m).powerstate)
                {
                    if(gogo.at(m).onoffstate) gogo.at(m).onoffstate = false;
                    else gogo.at(m).onoffstate = true;
                }
            }

            for(m=0;m<gogo.size();m++)
            {
                if(gogo.at(m).onoffstate == false)
                {
                    for(n=m+1;n<gogo.size();n++)
                    {
                        gogo.at(n).powerstate = false;
                    }
                    break;
                }
                if((m+1) < gogo.size())gogo.at(m+1).powerstate = true;
            }

        }


        cout<<"Case #"<<i+1<<": ";
        if(gogo.at(gogo.size()-1).powerstate && gogo.at(gogo.size()-1).onoffstate)cout<<"ON";
        else cout<<"OFF";
        
        if(i != casenumber-1)cout<<endl;

    }

}