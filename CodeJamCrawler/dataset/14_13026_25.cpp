#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fp=NULL;

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


void filltc( int *tc)
{
    char*line=NULL;
    size_t n=0;
    getline(&line, &n, fp);
    trim(&line);
    *tc=atoi(line);
    free(line);
}

void fill_CFX(double *c, double *f, double *x)
{
    char*line=NULL;
    size_t n=0;
    int i=0;
    int count=0;
    char ch[16]="\0";

    getline(&line, &n, fp);
    //trim(&line);
    for(i=0; i<strlen(line); i++)
	if(line[i]==' ' || line[i]=='\n')
	{
	    if ( count == 0 )
		*c=atof(ch);
	    else if( count == 1)
		*f=atof(ch);
	    else
		*x=atof(ch);
	    count++;
	    memset(ch, '\0', 16); 
	}
	else
	{
	    strncat(ch, &(line[i]), 1);
	}

    free(line);
}


double time_to_buy_farm(double c, double f)
{
    return c/f;
}

double min_time(double c, double f, double x)
{
    double current_f = 2.0;
    double total_time = 0.0;
    int counter = 1;
    while(1)
    {
	if( ( (c*counter)/current_f + x/(current_f+f) ) < (x/current_f) )
	{
	    // buy farm
	    total_time = total_time + c/current_f;
	    current_f = current_f +f;
	}
	else
	{
	    total_time = total_time + x/current_f;
	    break;
	}
    }
    return total_time;
}

int main()
{
    int tc;
    int i=0;
    double c, f, x    =0.0;
    fp=fopen("input.txt", "r");

    filltc(&tc);
    for(i=1;i<=tc; i++)
    {
	fill_CFX(&c, &f, &x);
	printf("Case #%d: %.7f\n", i, min_time(c,f,x) );
    }
    fclose(fp);
    return 0;
}
