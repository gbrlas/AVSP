import java.io.*;

public class ans2{
	public static void main(String args[])throws IOException{
		String input="B-small-attempt0.in";
		String output="output2.txt";
		File file=new File(input);
		FileInputStream fis=new FileInputStream(file);
		BufferedReader in=new BufferedReader(new InputStreamReader(fis));
		PrintWriter out=new PrintWriter(new FileWriter(output));
		int t=Integer.parseInt(in.readLine().trim());
		double c,f,x,rc,time;
		int k=1;
		String s[];
		while(k<=t){
			time=0;
			s=in.readLine().trim().split(" ");
			c=Double.parseDouble(s[0]);
			f=Double.parseDouble(s[1]);
			x=Double.parseDouble(s[2]);
			if(x<=c){
				time=x/2;
			}
			else {
				rc=2;
				while(!compare(rc,f,x,c)){
					time+=c/rc;
					rc+=f;
				}
				time+=x/rc;
			}
			out.println("Case #"+k+": "+time);
			k++;
		}
		out.close();	
	}

	public static boolean compare(double rc,double inc,double x,double c){
		if(x/rc<=c/rc+x/(rc+inc))return true;
		else return false;
	}
}