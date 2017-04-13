#include<iostream>

using namespace std;


int main()
{

    int casos;
    cin>>casos;
    for(int k=0; k<casos; k++)
    {
        int fila, magic[4], x[4], cont=0, pos;
        cin>>fila;
        for(int i=0; i<4; i++)
        {
            cin>>x[0];
            cin>>x[1];
            cin>>x[2];
            cin>>x[3];
            if(fila==i+1)
            {
                magic[0]=x[0];
                magic[1]=x[1];
                magic[2]=x[2];
                magic[3]=x[3];
            }
        }

        cin>>fila;
        for(int i=0; i<4; i++)
        {
            cin>>x[0];
            cin>>x[1];
            cin>>x[2];
            cin>>x[3];
            if(fila==i+1)
            {
                for(int j=0; j<4; j++)
                {
                    if(x[j]==magic[0])
                    {
                        cont ++;
                        pos=0;
                    }
                    if(x[j]==magic[1])
                    {
                        cont ++;
                        pos=1;
                    }
                    if(x[j]==magic[2])
                    {
                        cont ++;
                        pos=2;
                    }
                    if(x[j]==magic[3])
                    {
                        cont ++;
                        pos=3;
                    }

                }
            }
        }

        if(cont==1)
            cout<<"Case #"<<k+1<<": "<<magic[pos]<<endl;
        if(cont>1)
            cout<<"Case #"<<k+1<<": Bad magician!"<<endl;
        if(cont==0)
            cout<<"Case #"<<k+1<<": Volunteer cheated!"<<endl;


        }

    return 0;
}
