import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;


public class CodeJamSavingTheUniverse {
	public static void main(String[] args) throws IOException{
		if(args.length!=1){
			System.out.println("must provide input file as arg");
			System.exit(0);
		}
	    BufferedReader in = new BufferedReader(new FileReader(args[0]));
	    int N=new Integer(in.readLine()).intValue();
	    for(int i=0; i<N; i++){ //for each testcase (The first line of the input file contains the number of cases, N. N test cases follow). 
	    	int S=new Integer(in.readLine()).intValue();
	    	HashMap SEs=new HashMap();
	    	for (int j=0; j<S; j++){//read in all seach engines
	    		SEs.put(in.readLine(), new Integer(j)); //associate a number with each search engine - enumerate them
	    	}
	    	int Q=new Integer(in.readLine()).intValue();
	    	int [] Qs=new int[Q];
	    	for (int k=0; k<Q; k++){ //mark for each query which search engines name it contains
	    		String line=in.readLine();
	    		Qs[k]=((Integer)SEs.get(line)).intValue();
	    	}
	    	
	    	int m=0;
	    	int switches=-1;
	    	while(m<Q){ //m is the index of the query we are to assign a search engine to
	    		int numberOfPossibleEngines=S;
	    		boolean[] possibleEngines=new boolean[S];
	    		for (int z=0; z<S; z++)possibleEngines[z]=true;
	    		int p=m;//now p is the index we are trying to assign an engine to
	    		for(p=m; (p<Q) && numberOfPossibleEngines>0; p++){ //proceed until we eliminate the last engine
	    			if(possibleEngines[Qs[p]]){
	    				possibleEngines[Qs[p]]=false;
	    				numberOfPossibleEngines--;
	    			}
	    		}
	    		switches++;
	    		if((p==Q) && (numberOfPossibleEngines>0)){
	    			m=Q; //a bit hacky way to terminate the while loop 
	    		} else {
	    			m=p-1; 
	    		}
	    	}
	    	if(switches==-1)switches=0;
	    	System.out.println("Case #"+(i+1)+": "+switches);
	    }
	    in.close();
	}
}
