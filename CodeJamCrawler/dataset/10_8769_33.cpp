int i,t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
		scanf("%d%d",&n,&k),n=1<<n,printf("Case #%d: O%s\n",++i,n-k%n-1?"FF":"N");
}
