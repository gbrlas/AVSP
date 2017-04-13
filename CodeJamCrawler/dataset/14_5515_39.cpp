#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
string get(FILE *);

int main(){
    FILE *nm;
    nm=fopen("A-small-attempt0.in","r+");

    ofstream ofile("output.out");
    int num=0;

    fscanf(nm,"%d",&num);
    for(int i=1;i<=num;i++){
        string out=get(nm);

        ofile<<"Case #"<<i<<": "<<out<<endl;
        cout<<"Case #"<<i<<": "<<out<<endl;
    }
        //fprintf(out,"Case #%d: ",i,get(nm));

    return 0;
}
string get(FILE * nm)
{
    int a=0;
    fscanf(nm,"%d",&a);
    a--;

    int get[4][4]={0};

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        fscanf(nm,"%d",&get[i][j]);

    int b=0;
    fscanf(nm,"%d",&b);
    b--;

    int second[4][4]={0};

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        fscanf(nm,"%d",&second[i][j]);


    int cnt=0,num=0;
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
                if(get[a][i]==second[b][j]){
                    cnt++;
                    num=get[a][i];
                }

        }


    if(cnt==0)
        return "Volunteer cheated!";
    if(cnt>1)
       return "Bad magician!";

        ostringstream out;
        out<<num;

    return out.str();

}
