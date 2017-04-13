#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    FILE *f1, *f2;
    int test, c; 
    string line;
    char go[30]={"ynficwlbkuomxsevzpdrjgthaq"};
    ifstream myfile("A-small-attempt0.in");
    f1=fopen("A-small-attempt0.in","r");
    f2=fopen("lang.out","w+");
    if(f1==NULL)
       printf("\nFILE CAN'T BE OPENED");
    else {
        while(test!=EOF){
            fscanf(f1, "%d", &test);
            int c=test;
            if(test==EOF)
              exit(1);
            getline (myfile,line);
            while(test-- > 0){
                getline (myfile,line);
                fprintf(f2, "Case #%d: ", c-test);
                for(int i=0; i<line.length(); i++){
                    if(line[i] == ' ')
                        fprintf(f2, " ");
                    else{
                        int j;
                        for(j=0; j < 26; j++){
                        if(line[i] == go[j]) break;}
                        fprintf(f2, "%c", j+97);
                        }
                }
                fprintf(f2, "\n");
            }        
        }
    }
    fclose(f1);
    fclose(f2);
    return(0);
}
