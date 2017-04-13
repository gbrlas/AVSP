#include<stdio.h>
#include<math.h>
int no(int ,int);//returns the no of recycled pairs satisfying all the conditions !
void read_write(FILE* ,FILE *);

int no(int p,int q)
{
        int i,res=0;
        for(i=p;i<q;++i)
        {
         int a[10];
                int b[10];
                int j=0,k=0;
                int u=i;
                int t=u%10;
                while(u>0)
                {
                        a[j]=t;
                        u=u/10;
                        t=u%10;
                        j++;
                }
                int m=0,h=0;
                for(m=0;m<=j-2;++m)
                {
                        int c=0,g=0;
                        if(a[m]>=a[j-1])
                        {
                                int z=m,y=j,x=j,w=1,p=1,f=j-1;
				 while(x)
                                {
                                        if(z>=0&&p!=0)
                                        {
                                                w=1;
                                                int s=0;
                                                for(s=0;s<y-1;++s)
                                                        w*=10;
                                                c+=a[z]*w;
                                                y--;
                                                z--;
                                        }
                                        else
                                        {
                                                p=0;

                                                c+=a[f]*(w/10);
                                                w=w/10;
                                                f--;
                                        }
                                        x--;

                                }

                                if(c>i && c<=q)
                                        {

                                                if(h==0)
                                                {res++;b[h]=c;h++;}
                                                else
                                                {
                                                        int v=h-1,x,flag=1;
                                                        for(x=0;x<=v&&flag==1;++x)
                                                                {
                                                        if(b[x]==c) flag=0;
                                                                }
								 if(flag==1){b[h]=c; res++;h++;}
                                                }
                                        }
                        }

                }
        }


        return res;
}

void read_write(FILE *fp,FILE* foo)
{
	int size,i,a,b,c;
	fscanf(fp,"%d\n",&size);
	for(i=0;i<size;++i)
	{
		fscanf(fp,"%d %d\n",&a,&b);
		c=no(a,b);
		fprintf(foo,"Case #%d: %d\n",i+1,c);
	}
}
int main()
{

       FILE *fp=fopen("C-large(2).in","r");
	if(fp==NULL)
		printf("not found\n");
	FILE *foo=fopen("output1.c","w");
	read_write(fp,foo);//reads the input ,calls the functn and writes in o/p
        return 0;
}

