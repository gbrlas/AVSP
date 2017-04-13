#include<stdio.h>
#include<stdlib.h>
int map[110][110];
int map2[110][110];
int nidp[110][110],njdp[110][110];
int w,h,test,basin=1;
int id[5]={-1,0,0,1},jd[5]={0,-1,1,0};

int getflowtoi(int i,int j)
{
    if(nidp[i][j]!=-1)return nidp[i][j];
    int x,lowest=map[i][j],ni=i,nj=j;
    //Flow to
    for(x=0;x<4;x++)
    {
        if(i+id[x]>0&&i+id[x]<=h&&j+jd[x]>0&&j+jd[x]<=w)
        {
        if(map[i+id[x]][j+jd[x]]<lowest)
        {
         ni=i+id[x];
         nj=j+jd[x];
         lowest=map[i+id[x]][j+jd[x]];
        }
        }
    }
    return nidp[i][j]= ni;

}

int getflowtoj(int i,int j)
{
    if(njdp[i][j]!=-1)return njdp[i][j];
    int x,lowest=map[i][j],ni=i,nj=j;
    //Flow to
    for(x=0;x<4;x++)
    {
        if(i+id[x]>0&&i+id[x]<=h&&j+jd[x]>0&&j+jd[x]<=w)
        {
        if(map[i+id[x]][j+jd[x]]<lowest)
        {
         ni=i+id[x];
         nj=j+jd[x];
         lowest=map[i+id[x]][j+jd[x]];
        }
        }
    }
    return njdp[i][j]= nj;
}

void drain(int i,int j)
{
    int x,ni,nj;
    if(map2[i][j]!=0)return;
    map2[i][j]=basin;
    ni=getflowtoi(i,j);
    nj=getflowtoj(i,j);
    if(ni!=i||nj!=j)drain(ni,nj);

    //Flow From
    for(x=0;x<4;x++)
    {
        if(i+id[x]>0&&i+id[x]<=h&&j+jd[x]>0&&j+jd[x]<=w)
        {
        if(map[i+id[x]][j+jd[x]]>map[i][j])
        {
            if(i==getflowtoi(i+id[x],j+jd[x])&&j==getflowtoj(i+id[x],j+jd[x]))drain(i+id[x],j+jd[x]);
        }
        }
    }

}

main()
{
    int i,j,k,z;
    scanf("%d",&test);
    for(z=0;z<test;z++)
    {
        for(i=0;i<110;i++)for(j=0;j<110;j++){ nidp[i][j]=njdp[i][j]=-1; map2[i][j]=0; }
        basin=1;
        scanf("%d%d",&h,&w);
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)scanf("%d",&map[i][j]);
        }
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                if(map2[i][j]==0){ drain(i,j); basin++; }
            }
        }
        printf("Case #%d:\n",z+1);
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                printf("%c ",map2[i][j]+'a'-1);
            }
            printf("\n");
        }
    }

}
