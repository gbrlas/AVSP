#include<stdio.h>
#include<math.h>
long int min(long int a,long int b)
{
    if(b>a)
    {
        return a;
    }
    return b;
}
main()
{
    FILE *fin=fopen("a.in","r");
    FILE *fout=fopen("a.out","w");
    long int b,d,e,f,c,g,h,x,y,z;
    char a[101],m[37][4],n[29][4];
    long int l[101];
    fscanf(fin,"%ld",&b);
    for(x=1;x<=b;x=x+1)
    {
        fscanf(fin,"%ld",&c);

        if(c>0)
        {
        for(y=0;y<c;y=y+1)
        {
            fscanf(fin,"%s",&m[y]);
        }
        }
        fscanf(fin,"%ld",&d);
        if(d>0)
        {
        for(y=0;y<d;y=y+1)
        {
            fscanf(fin,"%s",&n[y]);
        }
        }
        fscanf(fin,"%ld %s",&e,&a);
        for(z=0;z<=100;z=z+1)
        {
        l[z]=1;
        }
        for(y=0;y<e;y=y+1)
        {
            if(y>0 && l[y]==1)
            {
                /*number 1 operation*************************/

                if(c>0)
                {
                for(z=0;z<c;z=z+1)
                {
                    if(m[z][0]==a[y])
                    {
                        h=y-1;
                        while(l[h]==0 && h>=0)
                        {
                            h--;
                        }
                        if(h>=0 && a[h]==m[z][1] && l[h]==1)
                        {
                            l[h]=0;
                            a[y]=m[z][2];
                        }
                    }
                    else if(m[z][1]==a[y])
                    {
                        h=y-1;
                        while(l[h]==0 && h>=0)
                        {
                            h--;
                        }
                        if(h>=0 && a[h]==m[z][0] && l[h]==1)
                        {
                            l[h]=0;
                            a[y]=m[z][2];
                        }
                    }
                }
                }



                /*done job ******************************/


                if(d>0)
                {
                for(z=0;z<d;z=z+1)
                {
                    if(n[z][0]==a[y])
                    {
                        for(g=0;g<y;g=g+1)
                        {
                            if(a[g]==n[z][1] && l[g]==1)
                            {
                                for(h=0;h<=y;h=h+1)
                                {
                                    l[h]=0;
                                }
                                break;
                            }
                        }
                    }
                    else if(n[z][1]==a[y])
                    {
                        for(g=0;g<y;g=g+1)
                        {
                            if(a[g]==n[z][0] && l[g]==1)
                            {
                                for(h=0;h<=y;h=h+1)
                                {
                                    l[h]=0;
                                }
                                break;
                            }
                        }
                    }
                }
                }



                /*finished*****************************/
            }
        }
        fprintf(fout,"Case #%ld: [",x);
        z=0;
        for(y=0;y<e;y=y+1)
        {
            if(l[y]==1)
            {
                if(z>0)
                {
                    fprintf(fout,", ");
                }
                fprintf(fout,"%c",a[y]);
                z++;
            }
        }
        fprintf(fout,"]\n");

    }
    /*scanf("%ld %ld",&b,&c);
    printf("%ld",b^c);*/
    return 0;
}
