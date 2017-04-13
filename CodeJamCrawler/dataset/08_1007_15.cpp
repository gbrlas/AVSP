
import java.io.*;
import java.util.*;

class A {
    
    public static void main (String [] args) throws IOException {
    
	    BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
	                                                
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
	    
	    int N = Integer.parseInt(f.readLine());
	    
	    for(int kas=1; kas<=N; kas++){
	    	StringTokenizer st = new StringTokenizer(f.readLine());    
	    	
	    	int P = Integer.parseInt(st.nextToken());
	    	int K = Integer.parseInt(st.nextToken());
	    	int L = Integer.parseInt(st.nextToken());
	    	
	    	st = new StringTokenizer(f.readLine());
	    	int letter[] = new int[L];
	    	for(int i=0; i<L; i++){
	    		letter[i] = Integer.parseInt(st.nextToken());
	    		//System.out.println(letter[i]);
	    	}
	    	
	    	Arrays.sort(letter);
	    	
	    	/*
	    	for(int i=0; i<L; i++){
	    		System.out.print(letter[i]+" ");
	    	}
	    	System.out.println();*/
	    	
	    	int nums[] = new int[K];
	    	for(int j=0; j<K; j++){
    			nums[j] = 0;
    		}
	    	
	    	long res=0;
	    	boolean fail = false;
	    	for(int i=L-1; i>=0; i--){
	    		int min = P+1;
	    		int index=0;
	    		for(int j=0; j<K; j++){
	    			if(min>nums[j]){
	    				min = nums[j];
	    				index = j;
	    			}
	    		}
	    		if(nums[index] < P){
    				nums[index]++;
    				res += letter[i]*nums[index]; 
    			}
	    		else {
	    			fail = true;
	    			break;
	    		}
	    		
	    		//System.out.print(letter[i]+" ");
	    	}
	    	
	    	
	    	
	    	if(!fail)
	    		out.println("Case #"+kas+": "+res);
	    	else 
	    		out.println("Case #"+kas+": Impossible");
	    }
	    	
	    out.close();                                
	    
	    System.exit(0);                             
    }
}
