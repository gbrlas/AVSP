import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int t = in.nextInt();
		for(int i = 0;i<t;i++){
			int x = in.nextInt();
			int y = in.nextInt();
			out.print("Case #"+(i+1)+": ");
			if (((y+1) & ((1<<x)-1))==0)
				out.println("ON");
			else 
				out.println("OFF");
		}
	}

	public void close() throws Exception{
		out.close();
	}

	public static void main(String[]  args){
		new Thread(){
			public void run(){
				try{
					Main a = new Main();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
