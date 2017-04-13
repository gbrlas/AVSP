#include <stdio.h>
#include <string.h>

const int maxn=60;

char s[maxn];

struct bint
{
	int dig[maxn];
	int len;
};

void init_bint(bint &a)
{
	for(int i=0;i<maxn;i++)
		a.dig[i]=0;
	a.len=0;
}

void adjust_bint(bint &a)
{
	while(a.len>0)
	{
		if(a.dig[a.len]!=0)
			break;
		a.len--;
	}
}

void add_int(bint a,int b,bint &c)
{
	int cc=b;
	for(int i=0;i<=a.len;i++)
	{
		c.dig[i]=a.dig[i]+cc;
		cc=c.dig[i]/10;
		c.dig[i]=c.dig[i]%10;
		
	}
	c.len=a.len;
	if(cc)
		c.dig[++c.len]=cc;
	adjust_bint(c);
}

void mul_10(bint &c)
{
	if(c.len==0 && c.dig[0]==0)
		return ;
	c.len=c.len+1;
	for(int i=c.len;i>=1;i--)
		c.dig[i]=c.dig[i-1];
	c.dig[0]=0;

}

int rel_bint(bint &a,bint &b)
{
	adjust_bint(a);
	adjust_bint(b);
	if(a.len>b.len)
		return 1;
	if(a.len<b.len)
		return -1;
	for(int i=a.len;i>=0;i--)
	{
		if(a.dig[i]>b.dig[i])
			return 1;
		if(a.dig[i]<b.dig[i])
			return -1;
	}
	return 0;
}


void mul_int(bint a,int b,bint &c)
{
	int cc=0;
	for(int i=0;i<=a.len;i++)
	{
		c.dig[i]=a.dig[i]*b+cc;
		cc=c.dig[i]/10;
		c.dig[i]=c.dig[i]%10;

	}
	c.len=a.len;
	while(cc)
	{
		c.dig[i]=cc%10;
		cc=cc/10;
		c.len++;
	}
	adjust_bint(c);
}

void sub_bint(bint a,bint b,bint &c)
{
	int cc=0;
	for(int i=0;i<=b.len;i++)
	{
		c.dig[i]=a.dig[i]-b.dig[i]-cc;
		if(c.dig[i]<0)
		{
			c.dig[i]+=10;
			cc=1;
		}
		else
			cc=0;
	}
	for(i=b.len+1;i<=a.len;i++)
	{
		c.dig[i]=a.dig[i]-cc;
		if(c.dig[i]<0)
		{
			c.dig[i]+=10;
			cc=1;
		}
		else
			cc=0;
	}
	c.len=a.len;
	adjust_bint(c);


}
void div_bint(bint a,bint b,bint &c,bint &d)
{
	if(rel_bint(a,b)<0)
	{
		init_bint(c);
		d=a;
		return ;
	}
	bint mod,div;
	init_bint(mod);
	
	for(int i=a.len;i>=0;i--)
	{
		mul_10(mod);
		add_int(mod,a.dig[i],mod);
		int k=9;
		init_bint(div);
		while(k>=0)
		{
			mul_int(b,k,div);
			if(rel_bint(div,mod)<=0)
				break;
			k--;
		}
		c.dig[i]=k;
		mul_int(b,k,div);
		sub_bint(mod,div,mod);
		if(i==0)
			d=mod;
	}
	c.len=a.len;
	adjust_bint(c);
	adjust_bint(d);
}


void str_bint(char *s,bint &a)
{
	int len;
	len=strlen(s);
	a.len=len-1;
	for(int i=0;i<len;i++)
		a.dig[i]=int(s[len-i-1]-'0');
	adjust_bint(a);
}

int n;
bint secs[1010];
bint sub_secs[1010];
bint mbint,gbint;
bint zero;



void find_gcd(int m)
{
	bint a,b,c,d;

	init_bint(gbint);
	gbint=sub_secs[0];
	
	for(int i=1;i<m;i++)
	{
		if(rel_bint(gbint,sub_secs[i])>0)
		{
			a=gbint;
			b=sub_secs[i];
		}
		else
		{
			a=sub_secs[i];
			b=gbint;
		}
		while(rel_bint(b,zero)!=0)
		{
			div_bint(a,b,c,d);
			a=b;
			b=d;	
		}
		gbint=a;
	}
}

void print_bint(bint &a)
{

	for(int i=a.len;i>=0;i--)
		printf("%d",a.dig[i]);
}
/*
void test()
{
	bint a[4];
	for(int i=0;i<2;i++)
	{
		scanf("%s",s);
		str_bint(s,a[i]);
	}
	for(int j=0;j<2;j++)
	{
		print_bint(a[j]);
		printf("\n");
	}
	div_bint(a[0],a[1],a[2],a[3]);
	for(int k=0;k<4;k++)
	{
		print_bint(a[k]);
		printf("\n");
	}
}
*/

int main()
{

	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	int cases,icases;
	int i,k;
	bint a,b;

	scanf("%d",&cases);
	icases=1;
	init_bint(zero);

	while(icases<=cases)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			str_bint(s,secs[i]);
		}

		k=0;
		for(i=1;i<n;i++)
		{
			if(rel_bint(secs[k],secs[i])>0)
				k=i;
		}
		mbint=secs[k];
		secs[k]=secs[0];
		secs[0]=mbint;

		for(i=1;i<n;i++)
			sub_bint(secs[i],secs[0],sub_secs[i-1]);

		find_gcd(n-1);

		div_bint(secs[0],gbint,a,b);
		if(rel_bint(b,zero)!=0)
			sub_bint(gbint,b,b);
		printf("Case #%d: ",icases);
		print_bint(b);
		printf("\n");
		icases++;
		

	}

  
	return 0;
}
