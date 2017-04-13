import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
public class a{
	public static boolean pal(String s){
		if(s.charAt(0)=='0') return false;
		else{
			int n=s.length();
			int temp=n/2 -1;
			boolean answer=true;
			for(int i=0;i<=temp;i++){
				if(s.charAt(i)!=s.charAt(n-i-1)){
					answer=false;
					break;
				}
			}
			return answer;
		}
	}
	public static void main(String args[]) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		int n=Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++){
			st=new StringTokenizer(br.readLine());
			System.out.println("Case #"+(i+1)+": "+answer(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken())));
		}
	}
	public static int answer(int a,int b){
		int first=(int)Math.ceil(Math.sqrt(a));
		int second=(int)Math.floor(Math.sqrt(b));
		int answer=0;
		for(int i=first;i<=second;i++){
			if(pal(Integer.toString(i)) && pal(Integer.toString(i*i))) answer++;
		}
		return answer;
	}
}