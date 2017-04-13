#include<stdio.h>
main()
{
      int t,i,j,a1,a2,a[4][4],b[4][4],m=0,s,cas;
      FILE *p1,*p2;
      p1 = fopen("A-small-attempt3.in","r");
      p2 = fopen("output","w");
      fscanf(p1,"%d",&t);
      cas=1;
      while(t)
      {
              m=0;
              fscanf(p1,"%d",&a1);
              for(i=0;i<4;i++)
              fscanf(p1,"%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
              fscanf(p1,"%d",&a2);
              for(i=0;i<4;i++)
              fscanf(p1,"%d%d%d%d",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);
              for(i=0;i<4;i++)
              {
                              j=0;
                              while(j<4&&a[a1-1][i]!=b[a2-1][j])
                              j++;
                              if(j<4&&a[a1-1][i]==b[a2-1][j])
                              {
                                                            m++;
                                                            s=a[a1-1][i];
                              }
              }
              if(m==1)
              fprintf(p2,"Case #%d: %d\n",cas,s);
              else if(m>1)
              fprintf(p2,"Case #%d: Bad magician!\n",cas);
              else
              fprintf(p2,"Case #%d: Volunteer cheated!\n",cas);
              cas++;
              t--;     
      }
      fclose(p1);
      fclose(p2);
}
