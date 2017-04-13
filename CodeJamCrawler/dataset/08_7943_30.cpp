#include "stdio.h"
#include "string"
#include "map"

using namespace std;

int main()
{
       map<string, int> mapEngine;

       FILE* fp = NULL;
	   FILE* fo = NULL;

	   fp = fopen("e:\\A-large.in.txt", "rt");
 	   fo = fopen("e:\\A-large.out.txt", "wt");

	   char sInput[100];
       int inTestCase = 0;

       fgets(sInput, 100, fp);
       inTestCase = atoi(sInput);

       for(int i = 0; i < inTestCase; i++)
       {
               mapEngine.erase( mapEngine.begin(), mapEngine.end() );
               
               int inEngine = 0, iOutput = 0;
               fgets(sInput, 100, fp);
				inEngine = atoi(sInput);

               //map of search engines
               for(int j = 0; j < inEngine; j++)
               {
                       char str[102];
                       str[101] = NULL;
                       fgets(str,101, fp);

                       if(str[strlen(str) - 1] == 10)
                               str[strlen(str) - 1] = 0;

                       mapEngine[str] = 0;
               }
               int iMarkFlag = 1;
               int iTotalMarked = 0;

               int inQueue = 0;
               fgets(sInput, 100, fp);
               inQueue = atoi(sInput);
              for(j = 0; j < inQueue; j++)
               {
                       char str[102];
                       str[101] = NULL;
                       fgets(str,101, fp);
                       if(str[strlen(str) - 1] == 10)
                               str[strlen(str) - 1] = 0;

                       if( mapEngine[str] < iMarkFlag )
                       {
                               mapEngine[str] = iMarkFlag;
                               iTotalMarked++;
                               if(iTotalMarked == inEngine)
                               {
                                       iOutput++;
                                       iMarkFlag++;
                                       iTotalMarked = 1;
                                      mapEngine[str] = iMarkFlag;
                               }
                       }
               }

               printf("Case #%d: %d\n", i+1, iOutput);
 			   fprintf(fo,"Case #%d: %d\n", i+1,iOutput);
      }
	   fcloseall();
	   getchar();
       return 0;
}
