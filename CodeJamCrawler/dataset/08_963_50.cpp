
import java.io.*;
import java.util.*;

class SearchEngine{
	public String name;
	public int count;
	public int pos;
}

class ProblemA {

	static final Comparator<SearchEngine> MY_ORDER =
        new Comparator<SearchEngine>() {	
    		public int compare(SearchEngine s1, SearchEngine s2) {
    				/*if(s1.count < s2.count)
    					return -1;
    				else if(s1.count == s2.count){ 
    					if(s1.pos> s2.pos)
    						return -1;
    					else 
    						return 1;
    					}
    				else 
    					return 1;*/
    			if(s1.pos > s2.pos)
					return -1;
				else if(s1.pos == s2.pos){ 
					if(s1.count < s2.count)
						return -1;
					else 
						return 1;
					}
				else 
					return 1;
    			}
    	};
	
    
    public static void main (String [] args) throws IOException {
    
	    BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
	                                                
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
	    
	    int N = Integer.parseInt(f.readLine());
	    
	    for(int i=1; i<=N; i++){
	    	int S = Integer.parseInt(f.readLine());
	    	
	    	SearchEngine searchEng[] = new SearchEngine[S]; 
	    	
	    	for(int j=0; j<S; j++){
	    		searchEng[j] = new SearchEngine();
	    		searchEng[j].name = f.readLine();
	    		searchEng[j].count = 0;
	    	}	
	    	
	    	ArrayList<String> queries = new ArrayList<String>();
	    	
	    	int Q = Integer.parseInt(f.readLine());
	    	for(int j=0; j<Q; j++){
	    		String str = f.readLine();
	    		queries.add(str);
	    	}
	    	
	    	   	
	    	int numSwitch = 0;
	    	
	    	boolean flag = true;
	    	while(true){
		    	for(int j=0; j<S; j++){
		    		String str = searchEng[j].name;
		    		searchEng[j].count = 0;
		    		
		    		for(int k=0; k<queries.size(); k++){
		        		String str2 = queries.get(k);
		        		if(str.equals(str2)){
		        			searchEng[j].count++;
		        		}
		        	}
		    		
		    		if(searchEng[j].count == 0){
		    			flag = false; 
		    			break;
		    		}
		    		searchEng[j].pos = queries.indexOf(str);
		    	}
		    
		    	if(!flag)
		    		break;
		    	Arrays.sort(searchEng, MY_ORDER);
		    	
		    	/*
		    	System.out.println("\nAfter Sort:"+ queries);
		    	for(int j=0; j<S; j++){
		    		System.out.println(searchEng[j].name+": "+searchEng[j].count+": "+searchEng[j].pos);
		    	}*/
		    	
		    	if(searchEng[0].count==0 || queries.size()<=0)
		    		break;
		    	
		    	numSwitch++;
		    	
		    	int n=0;
		    	if(searchEng[0].name.equals(queries.get(0)))
		    		n=1;
		    	for(int k=0; k<searchEng[n].pos; k++){
		    		queries.remove(0);
		    	}
	    	}
	    	
	    	out.println("Case #"+i+": "+numSwitch);
	    }
	    	
	    out.close();                                
	    
	    System.exit(0);                             
    }
}
