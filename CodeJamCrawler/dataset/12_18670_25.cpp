#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char * mapLine(char * input);
int findRow(char c);

int main(int argc, char *argv[])
{
    char  in[]  =  {'a' ,'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z'};
    char out[]  =  {'y' ,'n' ,'f' ,'i' ,'c' ,'w' ,'l' ,'b' ,'k' ,'u' ,'o' ,'m' ,'x' ,'s' ,'e' ,'v' ,'z' ,'p' ,'d' ,'r' ,'j' ,'g' ,'t' ,'h' ,'-a' ,'q'};



    //q

    FILE * handler = fopen ("A-small-attempt2.in","r");

    if(!handler){
        cout<<"can't read the file"<<endl;
        return 1;
    }


    char v[150];
    //fgets(v,250,handler);
    fgets(v,250,handler);
    int count = atoi(v);

    FILE * outputFile = fopen("output","w+");

    //fprintf(outputFile,"Output\n");
    for (int i=0;i<count;i++) {
        fgets(v,250,handler);

        fprintf(outputFile,"Case #%i: %s\n",i+1,mapLine(v));
    }


   /* char * sentence1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    std::cout<<sentence1<<endl;
    std::cout<<mapLine(sentence1)<<endl;
*/
    /*for (int i=0;i<26;i++) {
        char needle = in[i];
        bool found = 0;
        for (int j=0;j<26;j++) {
            if(needle == out[j]) {
                found = 1;
            }

        }
        if(!found) {
            std::cout<<needle <<" was not found";
            break;
        }
    }*/

    return 0;
}

char * mapLine(char * input){
     char out[]  =  {'y' ,'n' ,'f' ,'i' ,'c' ,'w' ,'l' ,'b' ,'k' ,'u' ,'o' ,'m' ,'x' ,'s' ,'e' ,'v' ,'z' ,'p' ,'d' ,'r' ,'j' ,'g' ,'t' ,'h' ,'a' ,'q'};

    int l = strlen(input);
    char * output = new char[l];

    for (int i=0; i<l; i++) {
        char c = tolower(input[i]);

        if(c==' ' || c=='\0') {
            output[i] = c;
            continue;
        }


        output[i] = 97+findRow(c);
        //cout <<c<<" -> "<<output[i]<<endl;
    }
    output[l] = '\0';
    return output;

}

int findRow(char c) {
    char  in[]  =  {'a' ,'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z'};
    char out[]  =  {'y' ,'n' ,'f' ,'i' ,'c' ,'w' ,'l' ,'b' ,'k' ,'u' ,'o' ,'m' ,'x' ,'s' ,'e' ,'v' ,'z' ,'p' ,'d' ,'r' ,'j' ,'g' ,'t' ,'h' ,'a' ,'q'};
    for(int i=0;i<26;i++) {
        if(c==out[i]) {
            return i;
        }
    }
    return -65 ;
}
