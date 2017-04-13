#include <stdio.h>

int 
main ()
{
  typedef struct enginfo
  {
    char searchengine[100];
    int used;
  }engineinfo;

  int noftestcases;
  int nofsearchengines;
  int nofsearchitems;
  char queryitems[100];
  int allsearchenginesused=1;
  int i=0, j=0, k=0;
  int sw[20];
  engineinfo testeinfo[100];
  scanf ("%d", &noftestcases);

  for (i=0;i<noftestcases;i++)
    {
      sw[i] = 0;
      scanf ("%d", &nofsearchengines);
      getchar ();
      for (j=0;j < nofsearchengines; j++)
	{
	  gets (testeinfo[j].searchengine);
	  testeinfo[j].used=0;
	}
      
      scanf ("%d", &nofsearchitems);
      getchar ();
      for (j=0;j<nofsearchitems;j++)
	{
	  gets (queryitems);
	  for (k=0;k<nofsearchengines; k++)
	    {
	      if (strcmp (testeinfo[k].searchengine, queryitems) == 0)
		{
		  testeinfo[k].used = 1;
		}
	    }

	  allsearchenginesused = 1;
	  for (k=0;k<nofsearchengines;k++)
	    {
	      if (testeinfo[k].used != 1)
		{
		  allsearchenginesused = 0;
		  break;
		}
	    }
	  
	  if (allsearchenginesused == 1)
	    {
	      sw[i] = sw[i] + 1;
	    
	      for (k=0;k<nofsearchengines; k++)
		{
		  if (strcmp (testeinfo[k].searchengine, queryitems) != 0)
		    {
		      testeinfo[k].used = 0;
		    }
		}
	    }
	}

      for (j=0;j < nofsearchengines; j++)
	{
	  testeinfo[j].searchengine[0] = '\0';
	  testeinfo[j].used=0;
	}
    }

  for (i=0;i<noftestcases;i++)
    {
      printf ("Case #%d: %d\n",i+1,sw[i]);
    }
  return 0;
}
