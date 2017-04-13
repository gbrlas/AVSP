import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



//Q, W, E, R, A, S, D, F       
             
public class qualif2 {
	
	static int index_bc[] = new int[26];

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static char cl[][] = new char[8][8];

	static boolean opposition_list[][] = new boolean[8][8];

	
	static private void init_index()
	{
		for(int i=0;i<26;i++)
			index_bc[i] = 70;
		
		index_bc['Q'-'A'] = 0; 
		index_bc['W'-'A'] = 1; 
		index_bc['E'-'A'] = 2;
		index_bc['R'-'A'] = 3;
		index_bc['A'-'A'] = 4;
		index_bc['S'-'A'] = 5;
		index_bc['D'-'A'] = 6;
		index_bc['F'-'A'] =  7;
	}

	static int getIndex(char c){
	
		return index_bc[c-'A'];
	}
	
	
	static void addToConvertList(char c1,char c2,char c3){
	
		cl[getIndex(c1)][getIndex(c2)] = c3;
		cl[getIndex(c2)] [getIndex(c1)]=c3;
	}
	
	static void addToOpositionList(char c1,char c2){
		opposition_list[getIndex(c1)][getIndex(c2)] = true;
		opposition_list[getIndex(c2)] [getIndex(c1)]=true;
		
	}
	
	static  boolean isBaseCharacter(char c ){
		
		if ( getIndex(c) == 70)
			return false ;
		
		return true;
		
	}
	
	static void clear_lists(){
		
		for(int i=0;i<8;i++)
			for(int i1=0;i1<8;i1++){
				cl[i][i1]=0;
				opposition_list[i][i1]=false;

			}
	}

	
	static char[]  runTestCase(String line){
		
		StringTokenizer tkns = new StringTokenizer(line);
		char output[] = new char[200];
		int output_loc=-1;
		
		int n = Integer.parseInt(tkns.nextToken());

		clear_lists();
		
		for(int i=0; i<n;i++){
			char str[] = tkns.nextToken().toCharArray();
			addToConvertList(str[0], str[1], str[2]);
			
		}
		
		n = Integer.parseInt(tkns.nextToken());
		for(int i=0; i<n;i++){
			char str[] = tkns.nextToken().toCharArray();
			addToOpositionList(str[0], str[1]);
		}
		
	   
		n = Integer.parseInt(tkns.nextToken());
		char str[] = tkns.nextToken().toCharArray();
		

		int i;
		for( i=0; i<n;i++){
			
			if (output_loc == -1){
				output[++output_loc]= str[i];
				continue;
			}

	if( isBaseCharacter(output[output_loc]) && cl[getIndex(output[output_loc])][getIndex(str[i])] != 0){
				output[output_loc] = cl[getIndex(output[output_loc])][getIndex(str[i])];
				continue;
			}

			output[++output_loc]= str[i];
	
			for(int j =0;j<output_loc;j++){
				if( isBaseCharacter( output[j]) && opposition_list[getIndex(output[j])][getIndex(str[i])]){
					output_loc = -1;
					break;
				}
				
			}
		}

		output[++output_loc] = '\0';
		return output;
		
	}
	
	public static void main(String a[]) throws IOException{
	
		String line;
		init_index();
	
		line = br.readLine();
		int n_testcases = Integer.parseInt(line);
		char[] rslt={};
		
		for (int tc = 0;tc < n_testcases;tc++){
			rslt = runTestCase(br.readLine());
			int i=0;
			System.out.print("Case #"+(tc+1) + ": [");

			while(rslt[i] != '\0'){
				System.out.print(rslt[i++]);
				if(rslt[i] == '\0')
					break;
				System.out.print(", ");
			}
			
			System.out.print("]");
			if( tc!= n_testcases - 1)
				System.out.println("");
		}
	}

}
