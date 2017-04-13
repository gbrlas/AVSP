import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Magika {

		
	public static void main(String[] args) {
		try {
			
//			BufferedReader buf = new BufferedReader(new java.io.InputStreamReader(System.in));
			BufferedReader buf =  new BufferedReader(new FileReader("B-large.in"));			
			int T = Integer.parseInt(buf.readLine());		
			
			for (int i=0; i<T; i++) {
				Map comb = new HashMap();
				Map opp = new HashMap();
				
				String caseStr = buf.readLine();
				String[] input = caseStr.split(" ");
				int C = Integer.parseInt(input[0]);
				int j = 1;
				for (int k=0; k<C; k++) {
					String baseEl = input[j].substring(0,2);
					char nonBaseEl = input[j].charAt(2);
					comb.put(baseEl, nonBaseEl);
					j++;
				}
					
				int D = Integer.parseInt(input[j]);
				j++;
				for (int k=0; k<D; k++) {
					char el1 = input[j].charAt(0);
					char el2 = input[j].charAt(1);
					List oppList1 = (List)opp.get(el1);
					if (oppList1 == null) 
						oppList1 = new ArrayList();
					oppList1.add(el2);
					opp.put(el1, oppList1);
					List oppList2 = (List)opp.get(el2);
					if (oppList2 == null) 
						oppList2 = new ArrayList();
					oppList2.add(el1);
					opp.put(el2, oppList2);
					j++;
				}
									
				int N = Integer.parseInt(input[j]);
				j++;
				char[] baseString = input[j].toCharArray();
				
				List out = new ArrayList();
				
				for (int n=0; n<N; n++) {
					char currChar = baseString[n];
					// combinations
					Character lastChar = null;
					if (out.size() > 0)
						lastChar = (Character)out.get(out.size()-1);
					if (lastChar != null) {
						Character nonBaseEl = (Character)comb.get(lastChar+""+currChar);
						if (nonBaseEl == null)
							nonBaseEl = (Character)comb.get(currChar+""+lastChar);
						if (nonBaseEl != null) {
							out.remove(out.size()-1);
							out.add(nonBaseEl);
							continue;
						}
					}
					// look for opposing elements
					List oppList = (List)opp.get(currChar);
					boolean cleared = false;
					if (oppList != null) {						
						for (int k =0; k<oppList.size(); k++) {
							if (out.contains(oppList.get(k))) {
								out.clear();
								cleared = true;
								break;
							}
						}					
					}
					if (!cleared)
						out.add(currChar);
				}
				System.out.println("Case #"+(i+1)+": "+out);
				
				comb=null;
				opp=null;
			}
		}
		catch (java.io.IOException ioe) {
			ioe.printStackTrace();
		} 

	}
	

}
