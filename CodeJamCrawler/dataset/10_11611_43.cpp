#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *myin = fopen("in.in", "r");
    FILE *myout = fopen("out.out", "w");

    unsigned int t=0, r=0, k=0, n=0, i=0;
    int ontrain=0, fil=0, bol=0;
    long long unsigned int euro=0;
    unsigned int *myarray;

    fscanf(myin, "%u", &t);

    while (i < t) {
        fscanf(myin, "%u", &r);
        fscanf(myin, "%u", &k);
        fscanf(myin, "%u", &n);
        myarray = (unsigned int*) malloc(n*sizeof(unsigned int));
        for(fil=0; fil<n; fil++) {
            fscanf(myin, "%u", myarray+fil);
        }

        // for each run fill up train and move queue ptr
        for(fil=0, bol=n-1, euro=0; r>0; r--) {
            ontrain=0;
            while(ontrain < k && myarray[fil] <= (k-ontrain)) {
                ontrain += myarray[fil];
                euro += myarray[fil];
                if(fil == bol) {
                    if(++fil>=n) fil -= n;
                    break;
                }
                if(++fil>=n) fil -= n;

            }
            bol = fil-1;
            if (bol<0) bol += n;
        }
        fprintf(myout, "Case #%u: %llu\n", i+1, euro);
        i++;
        free(myarray);
    }

    fclose(myin);
    fclose(myout);
    return 0;
}

