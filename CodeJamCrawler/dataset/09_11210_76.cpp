#include<iostream>
#include<cstdio>
#include<vector>



using namespace std;

 struct area{
    int sinksTox;
    int sinksToy;
    
    int value;
    int kokx;
    int koky;
    
  };


int main()
{

  FILE *f;

  f = fopen("B-small-attempt2.in","r");

  int caseNumber,height,width;
  
  fscanf(f,"%d",&caseNumber);
   
  
  
  int batman = 101;
  
  
  
  
  int count,i,j,temp;
  
  for(count=0;count<caseNumber;count++)
  {
    fscanf(f,"%d",&height);
    fscanf(f,"%d",&width);
    
    batman = 101;
    
    struct area x[height][width];  
     
    for(i=0;i<height;i++)
    {
	for(j=0;j<width;j++)
	{
	  fscanf(f,"%d",&temp);
	  x[i][j].value = temp;
	}
    }
    
    for(i=0;i<height;i++)
    {
	for(j=0;j<width;j++)
	{
	   int north,west,east,south,self;
	   int hnow = i;
	   int wnow = j;
	   int h = height;
	   int w = width;
  
	   self = x[hnow][wnow].value; 
	   
	    if(hnow-1<0)north = 100000;else north = x[hnow-1][wnow].value;
	    if(wnow-1<0)west  = 100000;else west  = x[hnow][wnow-1].value;
	    if(hnow+1>=h)south = 100000;else south = x[hnow+1][wnow].value;
	    if(wnow+1>=w)east  = 100000;else east  = x[hnow][wnow+1].value;
  
	    if((self<=north) && (self<=west) && (self<=east) && (self<=south))
	    {	
	      x[hnow][wnow].sinksTox = -1;
	      x[hnow][wnow].sinksToy = -1;
	      
	     
	    } 
	    else if((north<=west) && (north <= east) && (north <= south))
	    {
	      x[hnow][wnow].sinksTox = hnow-1;
	      x[hnow][wnow].sinksToy = wnow;
	    }
	    else if((west<=east) && (west<= south))
	    {
	      x[hnow][wnow].sinksTox = hnow;
	      x[hnow][wnow].sinksToy = wnow-1;
	    }
	    else if(east <= south)
	    {
	      x[hnow][wnow].sinksTox = hnow;
	      x[hnow][wnow].sinksToy = wnow+1;
	    }
	    else 
	    {
	      x[hnow][wnow].sinksTox = hnow+1;
	      x[hnow][wnow].sinksToy = wnow;
	    }
	  
	}
    }
      
    
    int tx,ty;
    int anlikx,anliky;
    
    for(i=0;i<height;i++)
    {
	for(j=0;j<width;j++)
	{
	  tx = x[i][j].sinksTox;
	  ty = x[i][j].sinksToy;
	  anlikx = i;
	  anliky = j;
    
	  while(1)
	  {
	      if(tx == -1)
	      {
		break;
	      }
	      else 
	      {
		
		anlikx = tx;
		anliky = ty;
		
		tx = x[anlikx][anliky].sinksTox;
		ty = x[anlikx][anliky].sinksToy;
		
	      }
      
	  }
	  
	  x[i][j].kokx = anlikx;
	  x[i][j].koky = anliky;
	  
	}
    }
    
    int gotux,gotuy,a,b;
    int kont = 0;
    
    
    for(a=0;a<height;a++)
    {
	  for(b=0;b<width;b++)
	  {
	    
	    gotux = x[a][b].kokx;
	    gotuy = x[a][b].koky;
	    
      
	      for(i=0;i<height;i++)
	      {
		  for(j=0;j<width;j++)
		  {
			if(x[i][j].sinksTox>100)continue;
			
			if(x[i][j].kokx == gotux && x[i][j].koky == gotuy)
			{
			  x[i][j].sinksTox = batman;
			  kont = 1;
			}
		  }
	      }
	  if(kont == 1)
	  {batman++;kont = 0;}
      
	  } 
    }
    
    
    printf("Case #%d:\n",count+1);
    
    for(i=0;i<height;i++)
    {
	for(j=0;j<width;j++)
	{
	  if( (j == 0) )printf("%c",x[i][j].sinksTox -4);
	  else printf(" %c",x[i][j].sinksTox -4);
	}
	if((count+1 == caseNumber) && j == width && i == height-1);
	  else cout<<endl;
    }
  }
  


  return 0;
} 



