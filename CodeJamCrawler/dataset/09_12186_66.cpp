import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class Alien {
	
	private boolean in(char a,String b){
		if(b.indexOf(a)>=0){
			return true;
		}
		return false;	
	}
	
	public int process(String alien,TreeMap<Character,ArrayList> dic,int l){
		String[] pword = this.de(alien, l);
		int result = 0;
		for(int i = 0; i<pword[0].length();i++){
			ArrayList list;
			if((list = dic.get(pword[0].charAt(i)))!=null){
				for(int j = 0;j<list.size();j++){
					String line = (String)list.get(j);
					int k  = 1;
					for(; k<line.length();k++){
						if(!in(line.charAt(k),pword[k])){
							break;
						}
							
					}
					if(k==line.length()){
						result++;
					}
				}
			}
		}
		return result;
	}
	
	public String[] de(String line,int l){
		String[] result = new String[l];

		int start = -1,end = -1;
		int g = 0;
		int i = 0;
		while(g<l){
			
			if(line.charAt(i)=='('){
				start = i;
			}
			if(line.charAt(i)==')'){
				end = i;
			}
			if(start<0){
				result[g] = line.substring(i, i+1);
				g++;
			}
			else if(end>=0){
				result[g] = line.substring(start+1, end);
				g++;
				start = -1;
				end =-1;
			}
			i++;

		}

		return result;
	}
	
	
	public static void main(String[] args){
		

		Alien alien = new Alien();

		
		String fileInputName = "D:\\ex1\\A-small-attempt1.in";
		String fileOutputName = "D:\\ex1\\result";
		FileDataInput fdi = new FileDataInput(fileInputName);
		FileDataOutput fdo = new FileDataOutput(fileOutputName);
		
//		SavingTheUniverse savingTheUniverse= new SavingTheUniverse();
		
		try {
			fdi.open();
			fdo.open();
			String tString = fdi.readNextLine();
			StringTokenizer st = new StringTokenizer(tString);
			
			int L = Integer.parseInt(st.nextToken());
			int D = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			
			
			
			String line;

			TreeMap<Character,ArrayList> dic = new TreeMap<Character,ArrayList>();
			
			for(int i = 0 ;i<D;i++){
				line = fdi.readNextLine();
				ArrayList tm;
				if((tm = dic.get(line.charAt(0)))==null){
					tm = new ArrayList();
					tm.add(line);
					dic.put(line.charAt(0), tm);
				}
				else{
					tm.add(line);
				}
				
			}
			
			int result = 0;	
			String outCase = "Case #";
			int count = 1;
			while((line = fdi.readNextLine()) != null){


				result =  alien.process(line, dic, L);
				
		
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
