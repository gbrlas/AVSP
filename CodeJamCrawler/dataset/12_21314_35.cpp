 #include<stdio.h>
 #include<string.h>
 int main()
 {
     int R[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
     int ans[26],t;
     char str[150],ch;
     int T,i,l;
     
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("output.txt", "w", stdout);
     
     scanf("%d",&T);
     scanf("%c",&ch);
     for(t=1;t<=T;t++)
     {
       gets(str);
       l=strlen(str);
       printf("Case #%d: ",t);
       for(i=0;i<l;i++)
          if(str[i]==' ')
             printf(" ");
          else
             printf("%c",R[str[i]-97]);
       printf("\n");
     }
     return 0;
 }
