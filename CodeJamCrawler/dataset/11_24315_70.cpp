#include<iostream>

using namespace std;
class Magicka
{

    char comb[8][8];
    bool opp[8][8];
    string base;
    int map(char a)
    {
        for(int i=0;i<8;i++)
            if(base[i]==a)
                return i;
        return -1;
    }
public:
    Magicka()
    {
        base="QWERASDF";
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++) {
                comb[i][j]='\0';
                opp[i][j]=false;
            }
    }

    void loadComb(char a, char b, char c)
    {
        int i=map(a);
        int j=map(b);
        comb[i][j]=c;
        comb[j][i]=c;
    }
    void loadOpp(char a, char b)
    {
        int i=map(a);
        int j=map(b);
        opp[i][j]=true;
        opp[j][i]=true;
    }
    char combQ(char a, char b)
    {
        int i=map(a);
        int j=map(b);
        if(i==-1 || j==-1)
            return '\0';
        return comb[i][j];
    }
    bool oppQ(char a, char b)
    {
        int i=map(a);
        int j=map(b);
        if(i==-1 || j==-1)
            return false;
        return opp[i][j];
    }
};

int main()
{
    int T, C, D, N;
    char wstr[100];
    cin>>T;
    for(int k=0;k<T;k++) {
        Magicka m;
        string str;
        cin>>C;
        for(int k1=0;k1<C;k1++) {
            cin>>str;
            m.loadComb(str[0],str[1],str[2]);
        }
        cin>>D;
        for(int k1=0;k1<D;k1++) {
            cin>>str;
            m.loadOpp(str[0],str[1]);
        }
        cin>>N;
        cin>>str;
        wstr[0]=str[0];
        wstr[1]='\0';
        for(int i=1,j=1;i<N;i++,j++) {
            char c;
            wstr[j]=str[i];
            //cout<<"wstr["<<j<<"]: "<<wstr[j]<<"\t";
            wstr[j+1]='\0';
            if(c=m.combQ(wstr[j],wstr[j-1])) {
                wstr[j-1]=c;
                wstr[j]='\0';
                j--;
            }
            else
                for(int k1=j-1;k1>=0;k1--)
                    if(m.oppQ(wstr[j],wstr[k1])) {
                        wstr[0]='\0';
                        j=-1;
                        break;
                    }
            //cout<<"wstr["<<j<<"]: "<<wstr[j]<<endl;
        }
        cout<<"Case #"<<k+1<<": [";
        for(int i=0;wstr[i]!='\0';) {
            cout<<wstr[i];
            if(wstr[++i]!='\0')
                cout<<", ";
            else
                break;
        }
        cout<<"]\n";
    }
}