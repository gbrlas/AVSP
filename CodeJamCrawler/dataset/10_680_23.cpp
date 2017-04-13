main(){
 int T,t,N,K,i,j,r,b,k;
 char str[60][60];
 scanf("%d%*c",&T);
 for(t=1;t<=T;t++)
 {
  r=b=0;
  scanf("%d%d%*c",&N,&K);
  for(i=0;i<N;i++) gets(  str[i] );
  for(i=N-1;i>=0;i--)
  {
   for(j=N-2;j>=0;j--)
   {
    if(str[i][j]=='.') continue;
    k=j;
	while(k<N && str[i][k+1]=='.')
	{
	 str[i][k+1]=str[i][k];
	 str[i][k]='.';
	 k++;
	}
   }
  }
  for(i=0;i<N;i++)
  {
   for(j=0;j<N;j++)
   {
    if(str[i][j]=='.') continue;
	if( i+K-1 < N )
	{
		for(k=1;k<K;k++)
		{
		 if( str[i+k][j]!=str[i][j])break;
		}
		if(k==K && (str[i][j]=='R') ) r=1;
		else if(k==K) b=1;
	}
	if( j+K-1 < N )
	{
		for(k=1;k<K;k++)
		{
			 if( str[i][j+k]!=str[i][j])break; 
		}
		if(k==K && (str[i][j]=='R')) r=1;
		else if(k==K) b=1;
	}
	if( i+K-1 < N && j+K-1<N )
	{
		for(k=1;k<K;k++)
		{
			 if( str[i+k][j+k]!=str[i][j])break;
		}
		if(k==K && (str[i][j]=='R')) r=1;
		else if(k==K) b=1;
	}
	if( i+K-1 < N && j-K+1<N )
	{
		for(k=1;k<K;k++)
		{
			 if( str[i+k][j-k]!=str[i][j])break;
		}
		if(k==K && (str[i][j]=='R')) r=1;
		else if(k==K) b=1;
	}
	// if(r==1 || b==1) 
	// {
	 // printf("%d %d\n",i,j);
	 // goto x;
	// }
   }
  }
  //x:
  //for(i=0;i<N;i++)
   //printf("%s\n",str[i]);
  printf("Case #%d: ",t);
  if(r+b==0)
   printf("Neither\n");
  else if(r==1 && b==0)
   printf("Red\n");
  else if(b==1 && r==0)
   printf("Blue\n");
  else 
   printf("Both\n");
 }
 return 0;
}