import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;


public class Multibasehappiness {
	public HashMap<String,Integer> total = new HashMap<String,Integer>();
	
	public List<Integer> baseConverse(int number,int base){
		List result = new ArrayList<Integer>();
		int x = number;
		while(x>0){
			result.add(x%base);
			x/=base;
		}
		return result;
		
	}
	
	public boolean isHappy(int number,int base){
		String key = new String(number+"_"+base);
		if(total.containsKey(key)){
			if(total.get(key)==1){
				return true;
			}
			else if(total.get(key)==0){
				return false;
			}
		}
		List<Integer> x;
		int result=number;
		HashMap history = new HashMap();
		
		while(result!=1&&!history.containsKey(result)){
			history.put(result, 1);
			x = baseConverse(result,base);
			result = 0;
			for(int i :x){
				result+=(i*i);
			}
			
		}
		if(result==1){
			total.put(key, 1);
			return true;
		}
		else{
			total.put(key, 0);
			return false;
		}

		
	}
	public int process(List<Integer> bases){
		int j=1;
		int flag= 0;
		while(flag!=bases.size()){
			j++;
			flag=0;
			for(int i : bases){
				if(!isHappy(j,i)){
					break;
				}
				flag++;
			}
		
		}
		return j;
	}
	
	
	
	public static void main(String[] args){
		String fileInputName = "D:\\r1Ex1\\1";
		String fileOutputName = "D:\\r1Ex1\\result";
		FileDataInput fdi = new FileDataInput(fileInputName);
		FileDataOutput fdo = new FileDataOutput(fileOutputName);
		
		Multibasehappiness multibasehappiness = new Multibasehappiness();
		
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
				StringTokenizer st = new StringTokenizer(line);
				List<Integer> x = new ArrayList<Integer>();
				while(st.hasMoreTokens()){
					x.add(Integer.parseInt(st.nextToken()));
				}
				result = multibasehappiness.process(x);

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
