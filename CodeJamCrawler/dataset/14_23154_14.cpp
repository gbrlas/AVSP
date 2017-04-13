#include<stdio.h>
void mergesort(double * ,int ,int);
void merge_(double *,int,int,int);
int main()
{
    FILE *fp;
    fp=fopen("ward.txt","w");
    int t,p=1;
    scanf("%d",&t);
    while(t--)
    {
        int l,sn=0,sk=0,en,ek,i,j,count1=0,count2=0;
        scanf("%d",&l);
        en=l;ek=l;
        double n[10],k[10];
        for(i=0;i<en;i++)
        {
            scanf("%lf",&n[i]);
        }
        for(i=0;i<ek;i++)
        {
            scanf("%lf",&k[i]);
        }



        mergesort(n,0,l-1);
        mergesort(k,0,l-1);



        while(sn<l)
        {

            if(n[sn]<=k[sk])
            {
                sn++;
            }
            else
            {
                sn++;sk++;count1++;
            }
        }
        sn=0;sk=0;
        while(sk<l)
        {
            if(n[sn]<k[sk])
            {
                sn++;sk++;
            }
            else
            {

                count2++;
                sk++;
            }
        }

        fprintf(fp,"Case #%d: %d %d\n",p++,count1,count2);
    }
fclose(fp);
}

void mergesort(double *p,int first,int last)
{
    int i;
     int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        mergesort(p,first,mid);
        mergesort(p,mid+1,last);
        merge_(p,first,mid,last);
    }
}

void merge_(double *p, int first,int mid,int last)
{
    int i,j,k;
    double tp[200];

    i=first;
    j=mid+1;
    k=first;
    while(i<mid+1 && j<last+1)
    {
        if(p[i]<=p[j])
        {
            tp[k]=p[i];

            i++;k++;
        }
        else
        {
            tp[k]=p[j];

            j++;k++;
        }
    }
    if(i>mid)
    {
        while(k<=last)
        {
            tp[k]=p[j];

            j++;k++;
        }
    }

    else
    {
        while(k<=last)
        {
            tp[k]=p[i];

            i++;k++;
        }
    }

    for(k=first;k<=last;k++)
    {
        p[k]=tp[k];
    }

}
