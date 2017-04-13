#include<stdio.h>
main()
{
      int cas,k,i,j,l,m,win,chance,n;
      char s1[101],s2[101];      
      FILE *p1,*p2;
      p1 = fopen("A-small-attempt0.in","r");
      p2 = fopen("output.in","w");
      fscanf(p1,"%d",&k);
      cas=1;
      while(k)
      {
              win=0;
              chance=0;
              i=0;
              j=0;
              fscanf(p1,"%d",&n);
            fscanf(p1,"%s",s1);
            fscanf(p1,"%s",s2);
            while(s1[i]!='\0'||s2[j]!='\0')
            {
                        if(s1[i]==s2[j])
                        {               
                                        l=0;
                                        m=0;
                                       while(s1[i]==s1[i+1]&&s1[i+1]!='\0')
                                       {
                                                            l++;
                                                            i++;
                                       }
                                       while(s2[j]==s2[j+1]&&s2[j+1]!='\0')
                                       {
                                                            m++;
                                                            j++;
                                       }
                                       if(l-m>0)
                                       chance=chance +  l-m;
                                       else
                                       chance=chance + m-l;
                        }
                        else
                        {            
                            win=-1;
                            break;
                            }
                       i++;
                       j++;     
            }            
            if(win<0)
            fprintf(p2,"Case #%d: Fegla Won\n",cas,chance);
            else
            fprintf(p2,"Case #%d: %d\n",cas,chance);
              cas++;
              k--;     
      }
      fclose(p1);
      fclose(p2);
}
