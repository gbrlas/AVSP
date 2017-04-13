#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;
int main(){
   int dim, m, ns, *d, i, j, k, count, switches,cases;
   char **matr;
   char * inname = "A-small-attempt4.in";
   char * outname = "A-small4.out";
   char   machine[100],  query[100],trash[100];
   FILE *infile;
   FILE *outfile;
   infile = fopen (inname , "r");
   outfile = fopen (outname , "w");

   
   if (!infile) {
      cout << "Cannot open file " << inname << " for reading." << endl;
      exit(EXIT_FAILURE);
   }
   cases = 0;
   fscanf(infile,"%d",&cases);
   for(m=1;m<=cases;m++) {
  	   fscanf(infile,"%d",&dim);
           fgets(trash,100,infile);

           //Create the array for repeated positions till last not in array
	   matr = new char*[dim];
	   for(i=0; i<dim; i++) {
	      matr[i] = new char[100];
	      fgets(machine,100,infile);
	      strcpy(matr[i],machine);
           }
	   d = new int[dim];
	   for(i=0; i<dim; i++)
		d[i]=0;
	  
	   fscanf(infile,"%d",&ns);
	   fgets(trash,100,infile);
           count = 0; //Will check for machines left before query
	   switches = 0; //Count 
	   for(i=0; i<ns; i++) {
	   fgets(query,100,infile);		
        	for(j=0; j<dim; j++) {
	  		if(!strcmp(query,matr[j])) {

				if(!d[j]) {
					d[j] = 1;
					count++;
					if (count == dim) {
							switches++;
 							for(k=0; k<dim; k++)
								d[k]=0;
							d[j]=1;
							count = 1;
						

					}
				}
				j=dim; //break
			}
		}
	   }
	  fprintf(outfile,"Case #%d: %d\n",m,switches);
	   
	   //Deleting contents
	   for(i=0; i<dim; i++){
	      delete [] matr[i];
	   }
	   delete [] matr;
	   delete [] d;
  }
   fclose(infile);
   fclose(outfile);
  return 0;
}
