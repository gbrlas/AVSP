    #include <stdio.h>
     
    int main(void) {
    int Test,t,first[4][4],sec[4][4],i,j,f,s,flag,str;
    scanf("%d",&Test);
    for(t=1;t<=Test;t++){
    scanf("%d",&f);
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    scanf("%d",&first[i][j]);
    scanf("%d",&s);
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    scanf("%d",&sec[i][j]);
    flag=0;
    for(i=0;i<4;i++){
    for(j=0;j<4;j++){
    if(first[f-1][i]==sec[s-1][j])
    { str=first[f-1][i];
    flag++;
    }
    }
    }
    if(flag==1)
    printf("Case #%d: %d\n",t,str);
    else if(flag==0)
    printf("Case #%d: Volunteer cheated!\n",t);
    else
    printf("Case #%d: Bad magician!\n",t);
     
    }
    return 0;
    }
     
