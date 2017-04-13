#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int N,i;
    char S[101];
    FILE *x;
    FILE *y;
    x=fopen("input.in","r");
    y=fopen("output.txt","w");
    fscanf(x,"%d",&N);
    fgets(S,101,x);
    for(i=0;i<N+1;i++)
    {
                    int len,j;
                    fprintf(y,"Case #%d: ",i+1);
                        fgets(S,101,x);
                        len=strlen(S);
                        
                        for(j=0;j<len;j++)
                        {
                                          switch(S[j])
                                          {
                                                      case 'a':
                                                           {
                                                               fprintf(y,"y");
                                                               break;
                                                           }
                                                      case 'b':
                                                           {
                                                               fprintf(y,"h");
                                                               break;
                                                           }
                                                      case 'c':
                                                           {
                                                               fprintf(y,"e");
                                                               break;
                                                           }
                                                      case 'd':
                                                           {
                                                               fprintf(y,"s");
                                                               break;
                                                               }
                                                      case 'e':
                                                           {
                                                               fprintf(y,"o");
                                                               break;
                                                               }
                                                      case 'f':
                                                           {
                                                               fprintf(y,"c");
                                                               break;
                                                           }
                                                      case 'g':
                                                           {
                                                               fprintf(y,"v");
                                                               break;
                                                               }
                                                      case 'h':
                                                           {
                                                               fprintf(y,"x");
                                                               break;
                                                               }
                                                      case 'i':
                                                           {
                                                               fprintf(y,"d");
                                                               break;
                                                               }
                                                      case 'j':
                                                           {
                                                               fprintf(y,"u");
                                                               break;
                                                               }
                                                      case 'k':
                                                           {
                                                               fprintf(y,"i");
                                                               break;
                                                               }
                                                      case 'l':
                                                           {
                                                               fprintf(y,"g");
                                                               break;
                                                               }
                                                      case 'm':
                                                           {
                                                               fprintf(y,"l");
                                                               break;
                                                               }
                                                      case 'n':
                                                           {
                                                               fprintf(y,"b");
                                                               break;
                                                               }
                                                      case 'o':
                                                           {
                                                               fprintf(y,"k");
                                                               break;
                                                               }
                                                      case 'p':
                                                           {
                                                               fprintf(y,"r");
                                                               break;
                                                               }
                                                      case 'q':
                                                           {
                                                               fprintf(y,"z");
                                                               break;
                                                               }
                                                      case 'r':
                                                           {
                                                               fprintf(y,"t");
                                                               break;
                                                               }
                                                      case 's':
                                                           {
                                                               fprintf(y,"n");
                                                               break;
                                                               }
                                                      case 't':
                                                           {
                                                               fprintf(y,"w");
                                                               break;
                                                               }
                                                      case 'u':
                                                           {
                                                               fprintf(y,"j");
                                                               break;
                                                               }
                                                      case 'v':
                                                           {
                                                               fprintf(y,"p");
                                                               break;
                                                               }
                                                      case 'w':
                                                           {
                                                               fprintf(y,"f");
                                                               break;
                                                               }
                                                      case 'x':
                                                           {
                                                               fprintf(y,"m");
                                                               break;
                                                               }
                                                      case 'y':
                                                           {
                                                               fprintf(y,"a");
                                                               break;
                                                               }
                                                      case 'z':
                                                           {
                                                               fprintf(y,"q");
                                                               break;
                                                           }
                                                      case ' ':
                                                           {
                                                               fprintf(y," ");
                                                               break;
                                                           }
                                          }
                                                         
                        }                                       
                    
                    fprintf(y,"\n");
                    
    }
    return 0;
}
