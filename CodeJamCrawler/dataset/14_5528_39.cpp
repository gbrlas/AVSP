#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
string get(FILE *,FILE *);

int main(){
    FILE *nm,*out;
    nm=fopen("B-large.in","r+");
    out=fopen("output.out","w+");

    int num=0;

    fscanf(nm,"%d",&num);
    for(int i=1;i<=num;i++){
            fprintf(out,"Case #%d: ",i);
            printf("Case #%d: ",i);
    get(nm,out);


    }


    return 0;
}
string get(FILE * nm,FILE *out)
{
    double c=0,f=0,x=0,mintime=0,time=0,r=2;

    fscanf(nm,"%lf%lf%lf",&c,&f,&x);

    time=c/r;
    mintime=x/r;

    while(true){
        if((x/(r+f)+time)<mintime)
           {

               r+=f;

               mintime=time+x/r;
                time+=c/(r);

           }
           else break;
    }

    fprintf(out,"%.7f\n",mintime);
            printf("%.7f\n",mintime);


    return "";
}
