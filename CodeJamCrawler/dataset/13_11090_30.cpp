import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("A-small-attempt2.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-small-attempt.out"));
		
		int qtd = sc.nextInt();
		
		char[][] mapa = new char[4][4];
		for(int i=0;i<qtd;i++){
			sc.nextLine();
			boolean incomplete = false;
			for(int j=0;j<4;j++){
				mapa[j] = sc.nextLine().toCharArray();
			}
			
			for(int k=0;k<4;k++){
				int res=0;
				for(int l=0;l<4;l++){
					if(mapa[k][l]=='.'){
						incomplete = true;
					}
					res = analyze(mapa,k,l);
					if(res==4){
						bw.write("Case #"+(i+1)+": X won\n");
						break;
					}else{
						if(res==-4){
							bw.write("Case #"+(i+1)+": O won\n");
							break;
						}
					}
				}
				if(res==4|| res==-4){
					break;
				}
				if(k==3){
					if(incomplete){
						bw.write("Case #"+(i+1)+": Game has not completed\n");
					}else{
						bw.write("Case #"+(i+1)+": Draw\n");
					}
					
				}
			}
		}
		bw.flush();
		bw.close();
		sc.close();

	}

	private static int analyze(char[][] mapa, int i, int j) {
		if(i!=0&&j!=0){
			return 0;
		}
		int res = 0;
		if(i==0){
			boolean hasT=false;
			for(int k=0;k<4;k++){
				switch(mapa[j][k]){
					case'X':
						res++;
						break;
					case'O':
						res--;
						break;
					case'T':
						hasT=true;
						break;
				}
			}
			if(hasT){
				if(res==3)res++;
				if(res==-3)res--;
			}
		}
		if(j==0 && res!=4 && res!=-4){
			res=0;
			boolean hasT=false;
			for(int k=0;k<4;k++){
				switch(mapa[k][i]){
					case'X':
						res++;
						break;
					case'O':
						res--;
						break;
					case'T':
						hasT=true;
						break;
				}
			}
			if(hasT){
				if(res==3)res++;
				if(res==-3)res--;
			}
		}
		
		if(j==0 && i==0 && res!=4 && res!=-4){
			res=0;
			boolean hasT=false;
			for(int k=0;k<4;k++){
				switch(mapa[k][k]){
					case'X':
						res++;
						break;
					case'O':
						res--;
						break;
					case'T':
						hasT=true;
						break;
				}
			}
			if(hasT){
				if(res==3)res++;
				if(res==-3)res--;
			}
		}
		if(j==3 && i==0 && res!=4 && res!=-4){
			res=0;
			boolean hasT=false;
			for(int k=0;k<4;k++){
				switch(mapa[k][3-k]){
					case'X':
						res++;
						break;
					case'O':
						res--;
						break;
					case'T':
						hasT=true;
						break;
				}
				
			}
			if(hasT){
				if(res==3)res++;
				if(res==-3)res--;
			}
		}
		return res;
		
	}
	

}
