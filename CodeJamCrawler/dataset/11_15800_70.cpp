#include<stdio.h>

int main()
{
int i,j,k,n,N,bt,b1,o1,b,o,B[101],O[101],A[101],p,bp,op,t,ch;
char c;

scanf("%d",&N);
for(n=1;n<=N;n++)
{
o=0;b=0;b1=0;o1=0,bp=1;op=1;
scanf("%d",&bt);

while(bt--)
{
c='a';
while((c!='B')&&(c!='O'))
scanf("%c",&c);

if(c=='B')
  {
	scanf("%d",&p);
	B[b]=p;
	A[b+o]=0;
//	A[b+o]=p;	
	b++;

  }
else
  {
	scanf("%d",&p);
	O[o]=p;
	A[b+o]=1;
//	A[b+o]=p;	
	o++;

  }
}

//printf("Input Ok\n");


i=0;j=0,k=0;t=0;
while(1)
  {		
	ch=-1;
	if(i>(o+b-1))
            {break;}
	
	if(A[i]==0)
        {
	if(B[b1]==bp)
          {	ch=0;
		b1++;
		i++;
	  }
	}	
	else
        {
	if(O[o1]==op)
          {	ch=1;
		o1++;
		i++;
	  }
	}

	if(ch!=1)
  	{
	if(O[o1]>op)
             op++;
	else if(O[o1]<op)
		op--;

	}
	
	if(ch!=0)
  	{
	if(B[b1]>bp)
             bp++;
	else if(B[b1]<bp)
		bp--;

	}

	t++;
	//printf("T=%d \n",t);
  }




printf("Case #%d: %d\n",n,t);
}


return 0;
}
