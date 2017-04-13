import java.util.HashMap;


public class ProblemA {
	
	public long process(String number){
		HashMap<Character,Integer> check = new HashMap<Character,Integer>();
		HashMap<Character,Integer> map = new HashMap<Character,Integer>();
		char c;
		for(int i =0;i<number.length();i++){
			c = number.charAt(i);
			if(!check.containsKey(c)){
				check.put(c, 1);
				
			}
			else{
				check.put(c, check.get(c)+1);
			}
		}
		int base = check.size();
		int length = number.length();
		int[] resultArray = new int[number.length()]; 
		resultArray[0]=1;
		map.put(number.charAt(0), 1);
		int current = 0;
		for(int i=1;i<length;i++){
			c = number.charAt(i);
			if(map.containsKey(c)){
				resultArray[i] = map.get(c);
			}
			else{
				resultArray[i] = current;
				map.put(c, current);
				current++;
			}
			if(current==1){
				current =2;
			}
		}
	
		
		long result = 0 ;
		int len = length-1;
		for(int i=0;i< length;i++ ){
			result+=(long)resultArray[i]*(long)Math.pow(base, len-i);
		}
		return result;
		
		
	}
	
	
	public static void main(String[] args){
		String fileInputName = "D:\\ex1\\A-small-attempt0.in.txt";
		String fileOutputName = "D:\\ex1\\result";
		FileDataInput fdi = new FileDataInput(fileInputName);
		FileDataOutput fdo = new FileDataOutput(fileOutputName);
		
		ProblemA problemA= new ProblemA();
		
		try {
			fdi.open();
			fdo.open();
			String tString = fdi.readNextLine();
			int n = Integer.parseInt(tString);
			String line;

			
			long result = 0;
		
			
			String outCase = "Case #";
			int count = 1;
			
			while((line = fdi.readNextLine()) != null){

				result = problemA.process(line);
				
		
				fdo.writeLine(outCase+count+": "+result);	
				
				count++;

			}
			fdo.close();
			fdi.close();
		}
		catch(Exception e){
			System.out.println("exception:"+e);
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
