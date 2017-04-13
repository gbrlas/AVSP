import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
public class a{
	public static void main(String args[]) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(br.readLine());
		int t=Integer.parseInt(st.nextToken());
		outer:for(int x=0;x<t;x++){
			System.out.print("Case #"+(x+1)+": ");
			char[][] a=new char[4][4];
			int Xs=0;
			int Os=0;
			int Ts=0;
			int Ds=0;
			String[] all = new String[10];
			for(int j=0;j<4;j++){
				all[j] = (new StringTokenizer(br.readLine()).nextToken());
				for(int z=0;z<4;z++){
					a[j][z]=all[j].charAt(z);
					switch(a[j][z]){
						case 'X': Xs++;break;
						case 'O': Os++;break;
						case 'T': Ts++;break;
						case '.': Ds++;break;
					}
				}
			}
			br.readLine();
			all[4] = String.valueOf(a[0][0])+String.valueOf(a[1][0])+String.valueOf(a[2][0])+String.valueOf(a[3][0]);
			all[5] = String.valueOf(a[0][1])+String.valueOf(a[1][1])+String.valueOf(a[2][1])+String.valueOf(a[3][1]);
			all[6] = String.valueOf(a[0][2])+String.valueOf(a[1][2])+String.valueOf(a[2][2])+String.valueOf(a[3][2]);
			all[7] = String.valueOf(a[0][3])+String.valueOf(a[1][3])+String.valueOf(a[2][3])+String.valueOf(a[3][3]);
			all[8] = String.valueOf(a[0][3])+String.valueOf(a[1][2])+String.valueOf(a[2][1])+String.valueOf(a[3][0]);
			all[9] = String.valueOf(a[0][0])+String.valueOf(a[1][1])+String.valueOf(a[2][2])+String.valueOf(a[3][3]);
			if(Xs>Os){
				inner:for(int i=0;i<10;i++){
					String s=all[i];
					if(s.equals("XXXX") || s.equals("XXXT") || s.equals("XXTX") || s.equals("XTXX") || s.equals("TXXX")){
						System.out.println("X won");
						continue outer;
					}
				}
			} else{
				inner:for(int i=0;i<10;i++){
					String s=all[i];
					if(s.equals("OOOO") || s.equals("OOOT") || s.equals("OOTO") || s.equals("OTOO") || s.equals("TOOO")){
						System.out.println("O won");
						continue outer;
					}
				}
			}
			if(Ds==0) System.out.println("Draw");
			else System.out.println("Game has not completed");
		}
		
	}
}
 