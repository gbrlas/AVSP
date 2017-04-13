#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int p=t;
    getchar();
    char arr[4][4];
    while(t--)
    {
	printf("Case #%d: ",p-t);
	int i,j,over=0;
	for(i=0; i<4; i++)
	{
	    for(j=0; j<4; j++)
	    {
		arr[i][j]=getchar();
		if(arr[i][j]=='.')
		    over=1;
	    }
	    getchar();
	}
	int count=0,win=0;
	for(i=0; i<4; i++)
	{
	    int s=1;
	    for(j=0; j<4; j++)
	    {
		s*=arr[i][j];
	    }
	    if(s=='O'*'O'*'O'*'O' || s=='O'*'O'*'O'*'T')
	    {
		count=1;
		win=1;
		break;
	    }
	    if(s=='X'*'X'*'X'*'X' || s=='X'*'X'*'X'*'T')
	    {
		count=1;
		win=2;
		break;
	    }
	}
	if(count==0)
	{
	    for(i=0; i<4; i++)
	    {
		int s=1;
		for(j=0; j<4; j++)
		{
		    s*=arr[j][i];
		}
		if(s=='O'*'O'*'O'*'O' || s=='O'*'O'*'O'*'T')
		{
		    count=1;
		    win=1;
		    break;
		}
		if(s=='X'*'X'*'X'*'X' || s=='X'*'X'*'X'*'T')
		{
		    count=1;
		    win=2;
		    break;
		}
	    }
	}
	if(count==0)
	{
	    int s=1;
	    for(i=0; i<4; i++)
		s*=arr[i][i];
	    if(s=='O'*'O'*'O'*'O' || s=='O'*'O'*'O'*'T')
	    {
		count=1;
		win=1;
	    }
	    if(s=='X'*'X'*'X'*'X' || s=='X'*'X'*'X'*'T')
	    {
		count=1;
		win=2;
	    }
	}
	if(count==0)
	{
	    int s=1;
	    s=s*arr[3][0]*arr[2][1]*arr[1][2]*arr[0][3];
	    if(s=='O'*'O'*'O'*'O' || s=='O'*'O'*'O'*'T')
	    {
		count=1;
		win=1;
	    }
	    if(s=='X'*'X'*'X'*'X' || s=='X'*'X'*'X'*'T')
	    {
		count=1;
		win=2;
	    }

	}
	if(count==0 && over==1)
	{
	    printf("Game has not completed\n");
	}
	else if(count==0 && over==0)
	{
	    printf("Draw\n");
	}
	else
	{
	    if(win==2)
		printf("X won\n");
	    if(win==1)
		printf("O won\n");
	}
	getchar();
    }
    return 0;
}
