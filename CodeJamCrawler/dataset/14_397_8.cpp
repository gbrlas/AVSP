import java.io.*;

public class ans1{
	public static void main(String args[])throws IOException{
		String input="B-small-attempt0.in";
		String output="output.txt";
		File f=new File(input);
		FileInputStream fis=new FileInputStream(f);
		BufferedReader in=new BufferedReader(new InputStreamReader(fis));
		PrintWriter out=new PrintWriter(new FileWriter(output));
		int t=Integer.parseInt(in.readLine());
		String s[];
		int q=1,a,b,k,ans,small;
		while(q<=t){
			s=in.readLine().trim().split(" ");
			a=Integer.parseInt(s[0]);
			b=Integer.parseInt(s[1]);
			k=Integer.parseInt(s[2]);
			ans=0;
			small=Math.min(a,b);
			if(small==a){
				ans=func(a,b,k);
			}
			else ans=func(b,a,k);
			out.println("Case #"+q+": "+ans);
			q++;
		}
		out.close();
	}

	public static int func(int small,int large,int k){
		int ans=0;
		int temp;
		for(int i=small-1;i>=0;i--){
			for(int j=large-1;j>=0;j--){
				temp=i&j;
				if(temp<k){
					ans++;
				}
			}
		}
		return ans;
	}
}