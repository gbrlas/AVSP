import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class SwingingWild {

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
			int N=Integer.parseInt(br.readLine());
			int d[]=new int[N];
			int l[]=new int[N];
			for(int i=0;i<N;i++){
				st=new StringTokenizer(br.readLine());
				d[i]=Integer.parseInt(st.nextToken());
				l[i]=Integer.parseInt(st.nextToken());
			}
			int D=Integer.parseInt(br.readLine());
			int low[]=new int[N];
			Arrays.fill(low, Integer.MAX_VALUE);
			low[0]=0;
			boolean okay=false;
			for(int i=0;i<N;i++){
				if(low[i]==Integer.MAX_VALUE)
					continue;
				int max=d[i]+(d[i]-low[i]);
				if(max>=D)
					okay=true;
				for(int j=i+1;j<N;j++){
					if(d[j]<=max)
						low[j]=Math.min(low[j], Math.max(d[i], d[j]-l[j]));
				}
			}
			if(okay)
				bw.append("Case #"+cn+": YES\n");
			else
				bw.append("Case #"+cn+": NO\n");
		}
		bw.flush();
	}
}
