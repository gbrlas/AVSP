#include <stdio.h>
#include <string.h>
#include <list>
using std::list;

int main(){
    FILE *f=fopen("input.txt","rt");
    FILE *out=fopen("output.txt","wt");

    int tests=1;
    fscanf(f,"%d",&tests);

   // tests=1;
    for(int tests_iter=0;tests_iter<tests;tests_iter++){
        int candies_count;
        fscanf(f,"%d",&candies_count);

        int* candies = new int[candies_count];
        int check=0,temp,min=1000000;
        long sum=0;
        for (int var = 0; var < candies_count; ++var) {
            fscanf(f,"%d",&temp);
            if(temp<min) min=temp;
            check^=temp;
            candies[var]=temp;
            sum+=temp;
        }

        if(check){
            fprintf(out,"Case #%d: NO\n",tests_iter+1);
            continue;
        }



        fprintf(out,"Case #%d: %d\n",tests_iter+1,sum-min);
    }
    return 0;
}
