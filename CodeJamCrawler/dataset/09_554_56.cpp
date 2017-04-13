import java.io.*;
import java.util.*;
import java.math.*;

class node{
	node left;
	node right;
	double weight;
	String feature;
}

class A{
	private static String dtree[]=new String[100];
	
	private static int L,x,y,nf;
	
	private static String f[]=new String[5];
	
	private static void ignorespace(){
		if(y==dtree[x].length())
		{
			x++;
			y=0;
		}
		while( (dtree[x].charAt(y)==' ') )
		{
			y++;
			if(y==dtree[x].length())
			{
				x++;
				y=0;
			}
			
		}
	}
	
	private static int nextspace(){
		int j=y;
		while((j<dtree[x].length()) && (dtree[x].charAt(j)!=' ') && (dtree[x].charAt(j)!=')'))
		j++;
		return j;
	}
	
	private static node readDec(){
		int i,j;
		node c=new node();
		if(y==dtree[x].length())
		{
		x++;
		y=0;
		}
		else
		y++;
		ignorespace();
		//System.out.println(dtree[x].charAt(y));
		c.weight=Double.parseDouble(dtree[x].substring(y,nextspace()));
		y=nextspace();
		ignorespace();
		if( dtree[x].charAt(y)==')')
		{
			if(y==dtree[x].length())
			{
			x++;
			y=0;
			}
			else
			y++;
			return c;
		}
		if((dtree[x].charAt(y)>='a') && (dtree[x].charAt(y)<='z') )
		{
			c.feature=dtree[x].substring(y,nextspace());
			y=nextspace();
			ignorespace();
		}
		c.left=readDec();
		ignorespace();
		c.right=readDec();
		ignorespace();
		y++;
		return c;
	}
	
	private static Boolean exists(String fe){
		int i;
		for(i=0;i<nf;i++)
		if(f[i].equals(fe))
		return true;
		return false;
	}
	
	private static double value(node n){
		double v=n.weight;
		if( (n.left==null) && (n.right==null))
		return v;
		if( (n.feature != null) && (!exists(n.feature)))
		return v*value(n.right);
		return v*value(n.left);
	}
	
	private static void print(node n){
		System.out.println(n.weight);
		if(n.feature!=null)
		System.out.println(n.feature);
		if(n.left!=null)
		print(n.left);
		if(n.right!=null)
		print(n.right);
	}
	
	public static void main(String args[]) throws IOException{
		int N,A,n,cases,i,j,k;
		Stack s;
		node root;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String animal;
		N=Integer.parseInt(br.readLine());
		for(cases=1;cases<=N;cases++)
		{
			L=Integer.parseInt(br.readLine());
			for(i=0;i<L;i++)
				dtree[i]=br.readLine();
			x=y=0;
			root=readDec();
			n=Integer.parseInt(br.readLine());
			System.out.println("Case #"+cases+":");
			//print(root);
			for(j=0;j<n;j++)
			{
				st=new StringTokenizer(br.readLine());
				st.nextToken();
				nf=Integer.parseInt(st.nextToken());
				for(k=0;k<nf;k++)
				f[k]=st.nextToken();
				System.out.printf("%.7f\n",value(root));
			}
		}
	}
}