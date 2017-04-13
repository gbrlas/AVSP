
import java.io.*;
import java.util.*;

class Train{
	public int depart;
	public int arrive;
	public int type;
}

class ProblemB {
	
	static final Comparator<Train> MY_ORDER =
        new Comparator<Train>() {	
    		public int compare(Train s1, Train s2) {
    			if(s1.depart < s2.depart)
					return -1;
				else if(s1.depart == s2.depart){
					if(s1.arrive <= s2.arrive)
						return -1;
					else 
						return  1; 
				}
				else 
					return 1;
    			}
    	};
    	
  public static void main (String [] args) throws IOException {
    
    BufferedReader f = new BufferedReader(new FileReader("B-large.in"));
     
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
    
    
    int N = Integer.parseInt(f.readLine());
    
    for(int i=1; i<=N; i++){
    	int T = Integer.parseInt(f.readLine());
    	
    	StringTokenizer st = new StringTokenizer(f.readLine());    
    	
    	int NA = Integer.parseInt(st.nextToken());
    	int NB = Integer.parseInt(st.nextToken());
    	
    	Train trains[] = new Train[(NA+NB)];
    	
    	for(int j=0; j<NA; j++){
    		st = new StringTokenizer(f.readLine());
    		
    		String s1 = st.nextToken();
    		String s2 = st.nextToken();
    		
    		String h, m;
    		int hour, min;
    		
    		h = s1.substring(0, 2);
    		m = s1.substring(3, 5);
    		hour = Integer.parseInt(h);
    		min = Integer.parseInt(m);	
    		
    		trains[j] = new Train();
    		trains[j].type = 0;
    		trains[j].depart = hour*60 + min;
    		
    		
    		h = s2.substring(0, 2);
    		m = s2.substring(3, 5);
    		hour = Integer.parseInt(h);
    		min = Integer.parseInt(m);
    		
    		trains[j].arrive = hour*60 + min;
    	}	
    	
    	for(int j=NA; j<NB+NA; j++){
    		st = new StringTokenizer(f.readLine());
    		
    		String s1 = st.nextToken();
    		String s2 = st.nextToken();
    		
    		String h, m;
    		int hour, min;
    		
    		h = s1.substring(0, 2);
    		m = s1.substring(3, 5);
    		hour = Integer.parseInt(h);
    		min = Integer.parseInt(m);	
    		
    		trains[j] = new Train();
    		trains[j].type = 1;
    		trains[j].depart = hour*60 + min;
    		
    		
    		h = s2.substring(0, 2);
    		m = s2.substring(3, 5);
    		hour = Integer.parseInt(h);
    		min = Integer.parseInt(m);
    		
    		trains[j].arrive = hour*60 + min;
    	}
    	
    	/*
    	for(int j=0; j<NB+NA; j++){
    		System.out.println(trains[j].type+": "+trains[j].depart+" - "+ trains[j].arrive);
    	}*/
    	
    	Arrays.sort(trains, MY_ORDER);
    	
    	/*
    	System.out.println("\nAfter sorting:");
    	for(int j=0; j<NB+NA; j++){
    		System.out.println(trains[j].type+": "+trains[j].depart+" - "+ trains[j].arrive);
    	}*/
    	
    	
    	ArrayList<Train> travelTrain = new ArrayList<Train>(); 
    	
    	int count[] = new int[2];
    	count[0] = count[1] = 0;
    	for(int j=0; j<NB+NA; j++){
    		boolean flag = false;
    		for(Train trn: travelTrain){
    			if((trains[j].depart >= trn.arrive + T) && (trains[j].type == trn.type)){
    				trn.depart = trains[j].depart;
    				trn.arrive = trains[j].arrive;
    				trn.type = (trains[j].type+1)%2;
    				flag = true;
    				break;
    			}
    		}
    		
    		if(!flag){
    			Train tn = new Train();
    			tn.depart = trains[j].depart;
				tn.arrive = trains[j].arrive;
				tn.type = (trains[j].type+1)%2;
				
				travelTrain.add(tn);
				
				count[trains[j].type]++;
    		}
    	}	
    	
    	out.println("Case #"+i+": "+count[0]+" "+count[1]);
    }
    
    out.close();                                  
    
    System.exit(0);                          
  }
}
