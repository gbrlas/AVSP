#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*

 */
FILE *fp=NULL;
void fops()
{
    FILE *fp=NULL;
    char *line=NULL;
    fp=fopen("input.txt", "r");
    getline(&line, NULL, fp);
    printf("%s\n", line);
    
}

void trim(char**line)
{
    int i=0;
    i=strlen(*line);
    for(i=strlen(*line)-1;i>=0; i--)
	if( (*line)[i]=='\n' )
	    (*line)[i]='\0';
	else
	    break;
}

void fillarr(int arr[][4])
{
    char*line=NULL;
    size_t n=0;
    int i,j=0;
    int col=0;
    char ch[3]="\0";
    for(i=0;i<4; i++)
    {
	col=0;

	getline(&line, &n, fp);
	//trim(&line);
	for(j=0; j<=strlen(line)-1; j++)
	    if(line[j]==' ' || line[j]=='\n')
	    {
		arr[i][col]=atoi(ch);
		memset(ch, '\0', 3);
		//printf("%d ", arr[i][col]);
		col++;
	    }
	    else
	    {
		strncat(ch, &(line[j]), 1);

	    }
	free(line);
	line=NULL;
	//printf("\n");
    }

}

void filltc( int *tc)
{
    char*line=NULL;
    size_t n=0;
    getline(&line, &n, fp);
    trim(&line);
    *tc=atoi(line);
    free(line);
}

void fillr1(int *r1)
{
    filltc(r1);
}


int main()
{
    int tc;
    int arr1[4][4];
    int arr2[4][4];
    int r1, r2;
    int i=0;
    int x,y=0;
    int count=0;
    int crdno=0;
    fp=fopen("input.txt", "r");

    filltc(&tc);

    for(i=0; i<tc; i++)
    {
	fillr1(&r1);
	//printf("r1:%d\n", r1);
	fillarr(arr1);
	fillr1(&r2);
	fillarr(arr2);
	
	for(x=0;x<4;x++)
	    for(y=0; y<4; y++)
	    {
		if(arr1[r1-1][x]==arr2[r2-1][y])
		{
		    count++;
		    crdno=arr1[r1-1][x];
		}
		//printf("arr1[r1][x]=%d arr2[r2][y]=%d \n", arr1[r1-1][x], arr2[r2-1][y]);
	    }
	if(count==1)
	    printf("Case #%d: %d\n", i+1, crdno);
	else if(count>1)
	    printf("Case #%d: Bad magician!\n", i+1);
	else
	    printf("Case #%d: Volunteer cheated!\n",i+1);

	crdno=0;
	count=0;
    }
    fclose(fp);
    return 0;
}
