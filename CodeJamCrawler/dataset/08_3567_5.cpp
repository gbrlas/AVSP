import java.util.*;

public class Main{
	static Scanner sc = new Scanner(System.in);	
	public static void main(String[] args) {
	    int n = sc.nextInt();
	    for(int id = 1; id <= n; id++){
		    int P = sc.nextInt();
		    int K = sc.nextInt();
		    int L = sc.nextInt();
		    int[] freq = new int[L];
		    for(int i = 0; i < L; i++) freq[i] = sc.nextInt();
		    
		    if(P*K<L){System.out.printf("Case #%d: Impossible", id); continue;}
		    
		    int keyPress = 0;
		    for(int i = 1; i <= P; i++){
			for(int j = 1; j <= K; j++){
				keyPress += popMax(freq) * i;				
			}
		    }
		    System.out.printf("Case #%d: %d\n", id, keyPress);
	    }
	}
	
	static int popMax(int[] freq){
	    
		if(freq.length == 0)
			return 0;
	    
		int i = 0, j = Integer.MIN_VALUE;
		for(int k = 0; k < freq.length; k++){
			if(freq[k]>j){
				j=freq[k];
				i=k;
			}
		}
		freq[i] = 0;
		return j;
	    
	    
	}
	    
    
}