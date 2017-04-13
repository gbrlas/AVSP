 #include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
	int j; 
	int k;
} node;





node findSinks(int **map, node **sinks , int j , int k , int h , int w)
{
	int x , y , Minj , Mink;
	node temp;
	if( !(sinks[j][k].j == -1 && sinks[j][k].k == -1) )
		return sinks[j][k];
// 	printf("j=%d k=%d\n" , j , k);
	//check if all the neghbours are greater or equal in height
	Minj = j ; Mink = k;
	if( j-1 >=0)
	{	
		if(map[j-1][k] < map[Minj][Mink] )
		{	
			Minj = j-1;
			Mink = k ;
		}
	}	
	if( k-1 >=0)
	{	
		if( map[j][k-1] < map[Minj][Mink] )
		{	
			Minj = j;
			Mink = k-1 ;
		}
	}
	
	if( k+1 < w)
	{	
		if(  map[j][k+1] < map[Minj][Mink]  )
		{	
			Minj = j;
			Mink = k+1 ;
		}
	}
	
	if( j+1 < h)
	{	
		if(  map[j+1][k] < map[Minj][Mink]  )
		{	
			Minj = j+1;
			Mink = k ;
		}
	}
	
	//
	if( Minj == j && Mink == k)
	{
		sinks[j][k].j = j;
		sinks[j][k].k = k;
// 		printf("found sink (%d,%d)\n" , j , k);
		return sinks[j][k];
	}
	else
	{
		temp = findSinks( map , sinks , Minj , Mink , h , w);
		sinks[j][k].j = temp.j;
		sinks[j][k].k = temp.k;
// 		printf("sinks[%d][%d] =  (%d,%d)\n" , j , k , temp.j , temp.k);
	}	
	return sinks[j][k];
}

void labelSinks(node **sinks , char **labels , int h, int w)
{
	node t;
	int m , n , o , p;
	char c= 'a';
	for( m =0 ; m< h ; m++)
		for( n=0 ; n<w ;n++)
		{
			if(labels[m][n] != '@') continue;
			t.j = sinks[m][n].j; 
			t.k = sinks[m][n].k;
			for( o = m ; o< h  ; o++)
			{
				for( p = o==m?n:0 ; p<w; p++)
					if(sinks[o][p].j == t.j && sinks[o][p].k == t.k )
						labels[o][p] = c;
			
			}	
			c++;
		}
}

int main()
{
	int t, h , w , i , j , k;
	int **map;
	node **sinks;
	char **labels;
	scanf("%d" , &t);
	//printf("Number of maps : %d\n\n" , t);
	for( i =0 ; i<t ; i++)
	{
 		printf("Case #%d:\r\n" , i+1);
		scanf("%d %d" , &h , &w);
		//printf("h= %d w=%d\n" , h , w);
		map = (int **) malloc(h*sizeof(int*));
		sinks = (node **) malloc(h*sizeof(node*));
		labels = (char **) malloc(h*sizeof(char*));
		for( j=0;j<h ; j++ )
		{	
			map[j] = (int* )malloc(w*sizeof(int) );
			sinks[j] = (node * )malloc(w*sizeof(node) );
			labels[j] = (char * )malloc(w*sizeof(char) );
		}
		
		for(j=0;j<h;j++)
		{	
			for(k=0;k<w;k++)
			{	
				sinks[j][k].j = -1;
				sinks[j][k].k = -1;
				labels[j][k]= '@';
				scanf("%d" , &map[j][k]);
//   				printf("%d ", map[j][k]);
			}
//   			printf("\n");
		}
		
		
		//printf("Sinks before filling: \n");
		for(j=0;j<h;j++)
		{	
			for(k=0;k<w;k++)
			{	
				
// 				printf("(%d,%d) ", sinks[j][k].j , sinks[j][k].k);
			}	
// 			printf("\n");
		}
		
		for(j=0;j<h;j++)
			for(k=0;k<w;k++)
			{			
				findSinks( map , sinks , j , k , h , w);
				//printf(" returned to main . sinks[%d][%d] = (%d, %d) \n" , j , k , sinks[j][k].j ,sinks[j][k].k );
			}	
		
//    		printf("Sinks after filling: \n");
		for(j=0;j<h;j++)
		{	
			for(k=0;k<w;k++)
			{	
				
//    				printf("(%d,%d) ", sinks[j][k].j , sinks[j][k].k);
			}	
//    		/**/	printf("\n");
		}
		
		//label the sinks
		labelSinks( sinks , labels , h , w);
//    		printf("Labels: \n");
		for(j=0;j<h;j++)
		{	
			for(k=0;k<w;k++)
			{	
				
				printf("%c", labels[j][k]);
				if(k!=w-1) printf(" ");
			}	
			if( i==t-1 && j==h-1);
			else
			printf("\r\n");
		}
		
		for( j=0;j<h ; j++ )
		{	
			free(map[j]);
			free(sinks[j]);
			free(labels[j]);
		}
		free(map);
		free(sinks);
		free(labels);
// 		printf("\n\n");
	}	


}

