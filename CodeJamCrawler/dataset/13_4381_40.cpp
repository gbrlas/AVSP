# include <stdio.h>


int main(void)
{
    //var 
    int t, n, a, b, emptycell, win;
    int temp,temp1,temp2;

    //loop
    int i,j,k,l;

    //string
    char temparr[4][4];
    char chtemp, chtemp2, row;
    char temprow[4] = { 'T','T','T','T' };
    char tempd1 = 'T';
    char tempd2 = 'T'; 


    scanf("%d ",&t);

    for(n=1;n<(t+1);n++)
    {
//        printf("iter \n");
        for(a=0;a<4;a++)
            temprow[a] = 'T';

        chtemp = 'T';
        chtemp2 = 'T';
        tempd1 = 'T';
        tempd2 = 'T';
        emptycell = 0;
        win = 0;
        if ((n != 1))
           scanf("%c",&chtemp);

        for(a=0;a<4;a++)
        {
            row = 'T';
            for(b=0;b<4;b++)
            {
                scanf("%c",&chtemp);
  //              printf("\n char %c",chtemp);
                //empty cell
                if (chtemp == '.')
                    emptycell = 1;
                // update columns
                if (temprow[b] == 'T')
                    temprow[b] = chtemp;
                else if (chtemp == 'T')
                    ;
                else if (temprow[b] != chtemp)
                    temprow[b] = 'Z';
                // update row
                if (row == 'T')
                    row = chtemp;
                else if (chtemp == 'T')
                    ;
                else if (chtemp != row)
                    row = 'Z';
                if (a == b)
                {
                    // update diag
                    if (tempd1 == 'T')
                        tempd1 = chtemp;
                    else if (chtemp == 'T')
                        ;
                    else if (chtemp != tempd1)
                        tempd1 = 'Z';
                }
                if ((a + b) == 3)
                {
                    // update diag
                    if (tempd2 == 'T')
                        tempd2 = chtemp;
                    else if (chtemp == 'T')
                        ;
                    else if (chtemp != tempd2)
                        tempd2 = 'Z';
                }
            }
            //printf(" rrr %c row, d1 %c, d2 %c - \n",row,tempd1,tempd2);
            if( win != 1)
            {
                // check for row victory
                if (row == 'X')
                {
                    printf("Case #%d: X won\n",n);
                    win = 1;
                }
                if (row == 'O')
                {
                    printf("Case #%d: O won\n",n);
                    win = 1;
                }
            }
            // eat \n 
            scanf("%c",&chtemp);
        }
        if(win == 1)
            continue;
        //check for column victory
        for(a=0;a<4;a++)
        {
            if (temprow[a] == 'X')
            {
                printf("Case #%d: X won\n",n);
                win = 1;
                break;
            }

            if (temprow[a] == 'O')
            {
                printf("Case #%d: O won\n",n);
                win = 1;
                break;
            }
        }
        if(win == 1)
            continue;
        // check for diag victory
        if ((tempd1 == 'X') || (tempd2 == 'X'))
        {
            printf("Case #%d: X won\n",n);
            win = 1;
        }
        if(win == 1)
            continue;
        if ((tempd1 == 'O') || (tempd2 == 'O'))
        {                
            printf("Case #%d: O won\n",n);
            win = 1;
        }
        if(win == 1)
            continue;
        // draw
        if( (win == 0) && (emptycell == 0))
        {
            printf("Case #%d: Draw\n",n);
        }
        if( (win == 0) && (emptycell == 1))
        {
            printf("Case #%d: Game has not completed\n",n);
        }
    }

    return 1;
}

