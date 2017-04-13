import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Aerobics {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken());
			int W=Integer.parseInt(st.nextToken());
			int L=Integer.parseInt(st.nextToken());
			Pair p[]=new Pair[N];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++)
				p[i]=new Pair(Double.parseDouble(st.nextToken()), i);
			Arrays.sort(p);
//			for(int i=0;i<N;i++)
//				System.out.println(p[i].r);
			double x[]=new double[N];
			double y[]=new double[N];
			double curx=-p[0].r;
			int ctr=0;
			int in=0;
			for(;in<N;in++){
				int nn=p[in].n;
				if(curx+p[in].r<=W){
					ctr++;
					x[nn]=curx+p[in].r;
					y[nn]=0;
					curx+=2*p[in].r;
				}
				else{
					break;
				}
			}
//			System.out.println(""+ctr);
			boolean okay=true;
			for(;in<N;in++){
				int nn=p[in].n;
				x[nn]=x[p[in-ctr].n];
				y[nn]=y[p[in-ctr].n]+p[in-ctr].r+p[in].r;
				if(y[nn]>L)
					okay=false;
			}
			bw.append("Case #"+cn+":");
			for(int i=0;i<N;i++)
				bw.append(" "+x[i]+" "+y[i]);
			bw.append("\n");
			if(!okay)
				System.out.println("ERROR!!");
			bw.flush();
		}
	}
	static class Pair implements Comparable<Pair>{
		double r;
		int n;
		public Pair(double a, int b){
			r=a;
			n=b;
		}
		public int compareTo(Pair that){
			return (int) Math.signum(that.r-this.r);
		}
	}
}
