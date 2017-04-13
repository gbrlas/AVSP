#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <stdio.h>

using namespace std;




int length(int x);
int permute(int x, int n);


int main(int argc, char *argv[])
{

    FILE * handler = fopen ("C-small-attempt0.in","r");

    if(!handler){
        cout<<"can't read the file"<<endl;
        return 1;
    }


    char v[150];
    fscanf(handler,"%s",v);
    int input_count = atoi(v);

     FILE * outputFile = fopen("output","w+");

    //cout<<input_count<<endl;
    for(int w=0;w<input_count;w++) {

        char tab[2000000] = {0};
        char tab2[2000000] = {0};

        int A;
        int B;

        char buff1[20];
        char buff2[20];
        fscanf(handler,"%s %s",buff1, buff2);
        A = atoi(buff1);
        B = atoi(buff2);


        for(int i=A; i<=B; i++) {
            int l = length(i);
            int buff[4] = {0};
            for(int j=1; j<l; j++) {
                int v = permute(i,j);
                bool add;
                if(v>=A && v<=B && v > i ) {
                    add= true;
                    for(int u=0;u<l;u++) {
                        if(buff[u]==v)
                            add=false;
                    }
                    if(add) {
                        buff[j]=v;
                        tab[i]++;
                        //cout/*<<i<<" : "*/<<v<<endl;
                        tab2[v]++;
                    }
                }
            }
        }

        int count=0;
        for(int i=0; i<2000000; i++) {
            if(tab[i]!=0) {
                count+=tab[i];
                //cout<<i<<" : "<<(int)tab[i]<<endl;
            }
        }





       fprintf(outputFile,"Case #%i: %d\n",w+1 ,count);

    }



    //cout<<"count : "<<count<<endl;

    return 0;
}

int length(int x) {
    char buf[25];
    sprintf(buf, "%i", x);
    return strlen(buf);
}

int permute(int x, int n) {
    int l = pow(10,n);
    int nx = x/l;
    int moving_part = x-(nx*l);
    int reversed = (moving_part*pow(10,length(nx))) + nx;
    return reversed;
}



