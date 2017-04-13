import java.io.*;
public class pa {

	public static BufferedReader sin= new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter sout = new PrintWriter(System.out, true);
	
	public static char arr[][];
	
	public static void print(char arr[][]){
		for(int i=0; i<arr.length; i++){
			for(int j=0; j<arr.length; j++){
				System.out.print(arr[i][j]);
			}
			System.out.println("");
		}
		System.out.println("");
	}
	
	public static boolean solve(char arr[][], int k, char c){		
		for(int i=0; i<arr.length; i++){
			for(int j=0; j<arr.length; j++){
				//print(arr);
				//out.println(i + ", " +j);
				if(arr[i][j]==c){
					int cont=0;
					try{
						for(int a=i; a<arr.length; a++){
							if(arr[a][j]!=c){
								break;
							}
							cont++;
						}
					} catch (Exception e){ }
					//sout.println(cont + "--" +  c + "--" + k);
					if(cont>=k)return true;
				}

				if(arr[i][j]==c){
					int cont=0;
					try{
						for(int a=j; a<arr.length; a++){
							if(arr[i][a]!=c){
								break;
							}
							cont++;
						}
					} catch (Exception e){ }
					//sout.println(cont + "--" +  c + "--" + k);
					if(cont>=k)return true;
				}

				if(arr[i][j]==c){
					int cont=0;
					try{
						for(int a=i, b=j; a<arr.length && b<arr.length; a++, b++){
							if(arr[a][b]!=c){
								break;
							}
							cont++;
						}
					} catch (Exception e){ }
					//sout.println(cont + "--" +  c + "--" + k);
					if(cont>=k)return true;
				}

				if(arr[i][j]==c){
					int cont=0;
					try{
						for(int a=i, b=j; a<arr.length && b>=0; a++, b--){
							if(arr[a][b]!=c){
								break;
							}
							cont++;
						}
					} catch (Exception e){ }
					//sout.println(cont + "--" +  c + "--" + k);
					if(cont>=k)return true;
				}
				//sout.println("--");
			}
		}
		
		return false;
	}
	
	public static char[][] rotate(char arr[][]){
		char aux[][]= new char[arr.length][arr.length];
		int i, j, pos1, pos2;
		
		for(i=0; i<arr.length; i++){
			for(j=0; j<arr.length; j++){
				aux[i][j]='.';
			}
		}
		
		pos1=0;
		for(i=arr.length-1; i>=0; i--){
			pos2=arr.length-1;
			for(j=arr.length-1; j>=0; j--){
				if(j<0){
					break;
				}
				while(arr[i][j]=='.'){
					j--;
					if(j<0){
						break;
					}
				}
				if(j>=0){
					aux[pos2--][pos1]= arr[i][j];
				}
			}
			pos1++;
		}
		
		//print(arr);
		//print(aux);
		return aux;
	}
	
	public static void main(String[] args)throws Exception {
		String line=sin.readLine();
		String arr2[];
		int t=Integer.parseInt(line);
		int n, kk;
		int i, j, k;
		for(i=1; i<=t; i++){
			line= sin.readLine();
			arr2= line.split(" ");
			n= Integer.parseInt(arr2[0]);
			kk= Integer.parseInt(arr2[1]);
		
			arr= new char[n][n];
			for(j=0; j<n; j++){
				line=sin.readLine();
				for(k=0; k<n; k++){
					arr[j][k]=line.charAt(k);
				}
			}
			//print(arr);
			//rotate(arr);
			int out=0;
			arr= rotate(arr);
			if(solve(arr, kk, 'B')) out=1;
			if(solve(arr, kk, 'R')){
				if(out==1){
					out=3;
				} else {
					out=2;
				}
			}
			if(out==0){
				sout.println("Case #" + i + ": Neither");
			} else if(out==1){
				sout.println("Case #" + i + ": Blue");
			} else if(out==2){
				sout.println("Case #" + i + ": Red");
			} else if(out==3){
				sout.println("Case #" + i + ": Both");
			}
			//sout.println("\n..\n");
		}
	}

}
