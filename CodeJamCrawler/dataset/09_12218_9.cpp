
public class ProblemB {
	public long process(long number){
		long [] digit = new long[10];
		for(int i=0;i<9;i++){
			digit[i]=0;
		}
		long n = number;
		long r = 0,p=0,x=0,count =0;
		while(n!=0){
			 count++;
			 r = n%10;
			 digit[(int)r]++;
			 
			 if(r<p){
				 break;
			 }
			 n/=10;

			 p=r;
		}
		if(n!=0){
			if(n>=0){
				n/=10;
			}
			int j =(int)r+1;
			while(digit[j]==0){
				j++;
			}
			digit[j]--;
			StringBuffer result = new StringBuffer();
			int i =1;
			while(digit[i]==0){
				i++;
				if(i>=10){
					break;
				}
			}
			long longresult =0;
			if(i<10){
				result.append(i);
				digit[i]-=1;
				for(i=0;i<10;i++ ){
					while(digit[i]>0){
						result.append(i);
						digit[i]--;
					}	
				}	
				longresult = Long.parseLong(result.toString());
			}
			
			
			long baseHigh = (long)Math.pow((double)10, (double)(count));
			long newN = n*baseHigh+j*baseHigh/10;
			
			return longresult+newN;
//			
//			long n2 = number,count2 =0,r2=0;
//			int i = (int)r+1;
//			for(;i<10;i++){
//				if(digit[i]>0){	
//					while(n2!=0){
//						count2++;
//						r2 = n2%10;
//						 if(r2==i){
//							 break;
//						 }
//						 n2/=10;
//					}
//					break;
//				}			
//			}
//			
//			
//			long baseHigh = (long)Math.pow((double)10, (double)(count-1));
//			long baseLow = (long)Math.pow((double)10, (double)(count2-1));
//			long result = number+baseHigh*(i-r)-(p-r)*baseHigh/10;

		}	
		else{
			StringBuffer result = new StringBuffer();
			int i =1;
			while(digit[i]==0){
				i++;
			}
			result.append(i);
			digit[i]-=1;
			result.append(0);
			for(i=0;i<10;i++ ){
				while(digit[i]>0){
					result.append(i);
					digit[i]--;
				}	
			}	
			long longresult = Long.parseLong(result.toString());
			return longresult;
		}
		
	}
	
	
	
	public static void main(String[] args){
		String fileInputName = "D:\\ex2\\B-small-attempt2.in.txt";
		String fileOutputName = "D:\\ex2\\result";
		FileDataInput fdi = new FileDataInput(fileInputName);
		FileDataOutput fdo = new FileDataOutput(fileOutputName);
		
		ProblemB problemB= new ProblemB();
		
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
				long s = Long.parseLong(line);
				result = problemB.process(s);
		
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
