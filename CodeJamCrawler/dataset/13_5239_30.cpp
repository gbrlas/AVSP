#include <stdio.h>
int main()
{
    int i,t,j,k,fl1,fl2,fl3,flag;
        char a[5][5];
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                flag=fl3=0;
                for(j=0;j<4;j++)
                        scanf("%s",a[j]);
                for(j=0;j<4;j++)
                {
                        fl1=fl2=0;
                        for(k=0;k<4;k++)
                        {
                                if(a[j][k]=='X'||(a[j])[k]=='T')
                                        fl1++;
                                else if(a[j][k]=='O'||(a[j])[k]=='T')
                                        fl2++;
                        }
                        if(fl1==4)
                        {
                                printf("Case #%d: X won\n",i+1);
                                flag=1;
                                break;
                        }
                        if(fl2==4)
                        {
                                printf("Case #%d: O won\n",i+1);
                                flag=1;
                                break;
                        }
                }
                if(flag==1)
                continue;
                for(j=0;j<4;j++)
                {
                        fl1=fl2=0;
                        for(k=0;k<4;k++)
                        {
                                if(a[k][j]=='X'||(a[k])[j]=='T')
                                        fl1++;
                                else if(a[k][j]=='O'||(a[k])[j]=='T')
                                        fl2++;
                                else
                                        fl3++;
                                
                        }
                        if(fl1==4)
                        {
                                printf("Case #%d: X won\n",i+1);
                                flag=1;
                                break;
                        }
                        if(fl2==4)
                        {
                                printf("Case #%d: O won\n",i+1);
                                flag=1;
                                break;
                        }
                }
                if(flag==1)
                continue;
                fl1=fl2=0;
                for(j=0;j<4;j++)
                {
                        if(a[j][j]=='X'||a[j][j]=='T')
                        fl1++;
                        else if(a[j][j]=='O'||a[j][j]=='T')
                        fl2++;
                }
                if(fl1==4)
                {
                                printf("Case #%d: X won\n",i+1);
                                        continue;
                                }
                else if(fl2==4)
                {
                                        printf("Case #%d: O won\n",i+1);
                                        continue;
                                }
                if((a[3][0]=='X'||a[3][0]=='T')&&(a[1][2]=='X'||a[1][2]=='T')&&(a[2][1]=='X'||a[2][1]=='T')&&(a[0][3]=='X'||a[0][3]=='T'))
                        printf("Case #%d: X won\n",i+1);
                else if((a[3][0]=='O'||a[3][0]=='T')&&(a[1][2]=='O'||a[1][2]=='T')&&(a[2][1]=='O'||a[2][1]=='T')&&(a[0][3]=='O'||a[0][3]=='T'))
                        printf("Case #%d: O won\n",i+1); 
                else if(fl3==0)
                        printf("Case #%d: Draw\n",i+1);
                else
                        printf("Case #%d: Game has not completed\n",i+1);
        }
        return 0;
}
