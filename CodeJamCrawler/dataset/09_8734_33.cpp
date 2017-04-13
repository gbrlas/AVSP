import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;



public class AlienLanguage {

	

	char[][] matrix;
	int L,D,N;
	HashMap words;
	int index=0;
	int number;
	int maxCol;
	char[][] dict;
	
	public static void main(String args[]){
		BufferedReader in;
		FileOutputStream out;
		PrintStream p;
		
		
		try{
			in=new BufferedReader(new FileReader("D:/Practice/Temp.txt"));
			out = new FileOutputStream("D:/Practice/A-small.out");
			p = new PrintStream(out);
			String output="";
			AlienLanguage alLang=new AlienLanguage();
			
			while(in.ready()){
				String readLine = in.readLine();
				String[] values = readLine.split(" ");
				alLang.L = Integer.parseInt(values[0]);
				alLang.D = Integer.parseInt(values[1]);
				alLang.N = Integer.parseInt(values[2]);
				
				alLang.dict=new char[alLang.D][alLang.L];
				
				for(int i=0;i<alLang.D;i++){
					String input = in.readLine();
					alLang.putWords(input);
					
				}
				
				for(int i=0;i<alLang.N;i++){
					String input = in.readLine();
					alLang.generateCombinations(input);
					
					System.out.println("Case #"+(i+1)+": "+alLang.number);
					p.println("Case #"+(i+1)+": "+alLang.number);
				}
			}
			in.close();
			out.close();
		}
		catch(Exception e)
		{
			System.out.println("Error="+e);
		}
	}
	
	void putWords(String word){
		int l= word.length();
		for(int i=0;i<l;i++){
			dict[index][i]=	word.charAt(i);
		}
		index++;
	}
	void generateCombinations(String pattern){
		number=0;
		int l=pattern.length();
		matrix=new char[l][L];
		int row=0,col=0;
		for(int i=0;i<l;i++){
			row=0;
			if(pattern.charAt(i)=='('){
				i++;
				while(pattern.charAt(i)!=')'){
					matrix[row][col]=pattern.charAt(i);
					row++;
					i++;
				}
				col++;
			}
			else{
				
				matrix[row][col]=pattern.charAt(i);
				col++;
			}
		}
		maxCol=col;
		combinations();
	}
	
	void combinations(){
		
		
		int[] checkList=new int[D];
		int i=0;
		
		for(int c=0;c<D;c++)
			checkList[c]=0;
		
		while(i<maxCol){
			int j=0;
			while((int)matrix[j][i]!=0){
				for(int k=0;k<D;k++){
					if(checkList[k]==0 && matrix[j][i]==dict[k][i])
					{
						checkList[k]=1;
					}
				}
				j++;
			}
			for(int c=0;c<D;c++)
			{
				if(checkList[c]==1)
					checkList[c]=0;
				else
					checkList[c]=-1;
			}
			i++;
		}
		
		number=0;
		for(int c=0;c<D;c++)
		{
			if(checkList[c]==0)
				number++;
		}
			
	}
}
