#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *infile  = fopen("A-small-attempt2.in", "r");
    FILE *outfile = fopen("A-small-attempt2.out", "w");

    int cases,c1=1;
    fscanf(infile,"%d",&cases);

    for (c1=1; c1<=cases;c1++){

        //first row//
        int r1, r2;
        int row1[4][4],row2[4][4];
        int i,j;

        fscanf(infile,"%d",&r1);
        for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    fscanf(infile,"%d",&row1[i][j]);
                    fgetc(infile);
                }
        }

        //second row//
        fscanf(infile,"%d",&r2);
        for(i=0;i<4;i++){
                for(j=0;j<4;j++){
                    fscanf(infile,"%d",&row2[i][j]);
                    fgetc(infile);
                }
        }

        //output result
        r1--;
        r2--;

        int foundCard = 0;
        int card=0;
        for (i=0;i<4;i++){
            for(j=0;j<4;j++){
                if (row1[r1][i]==row2[r2][j]){
                    foundCard++;
                    card = row1[r1][i];
                }
            }
        }

        if (foundCard>1){
            fprintf(outfile,"Case #%d: Bad magician!\n",c1);
        }

        else if (foundCard==0){
            fprintf(outfile,"Case #%d: Volunteer cheated!\n",c1);
        }

        else if (foundCard == 1){
            fprintf(outfile,"Case #%d: %d\n",c1,card);
        }

    }

    fclose(infile);
    fclose(outfile);
    return 0;

}
