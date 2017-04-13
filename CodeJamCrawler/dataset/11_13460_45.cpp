import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Magicka {

	public static void main(String args[]){
			
		try {
			FileReader fin = new FileReader(
					new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-in.txt"));
			FileWriter fr = new FileWriter(new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-out.txt"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			
			Magicka magicka = new Magicka();
			
			for(int i=0;i<N;i++){
							
				String listLine = br.readLine();
				
				String[] list = listLine.split(" ");
				
				int count=0;
				int C = Integer.parseInt(list[count++]);
				String[] comb = new String[C];
				for(int j=0;j<C;j++){
					comb[j] =  list[count++];
				}
				
				int D = Integer.parseInt(list[count++]);
				String[] opp = new String[D];
				for(int j=0;j<D;j++){
					opp[j] =  list[count++];
				}
				
				String items = list[count+1];
				String result = "";
				for(int j=0;j<items.length();j++){
					String curItem = items.substring(j, j+1); 
					if(result.length()>0)
					{
						String lastTwoItems = result.substring(result.length()-1)+curItem;
						String combVal = magicka.checkComb(comb, lastTwoItems);
						if(!combVal.equals("")){
							result= result.substring(0, result.length()-1) + combVal;
						}
						else if(magicka.checkOpp(opp, curItem, result)){
							result = "";
						}
						else{
							result+=curItem;
						}
					}
					else{
						result+=curItem;
					}
				}
				
				
				
				fr.write("Case #"+(i+1)+": [");
				
				for(int c=0;c<result.length();c++){
					if(c!=0){
						fr.write(", "+result.charAt(c));
					}
					else
						fr.write(result.charAt(c));
				}
				fr.write("]\r\n");
				
				System.out.print("Case #"+(i+1)+": [");
				for(int c=0;c<result.length();c++){
					if(c!=0){
						System.out.print(", "+result.charAt(c));
					}
					else
						System.out.print(result.charAt(c));
				}
				System.out.print("]\r\n");
			}
			fr.close();
			fin.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	String checkComb(String[] combArray, String lastTwoItems){
		
		for(int i=0;i<combArray.length;i++)
		{
			String comb = combArray[i];
			if((comb.charAt(0)==lastTwoItems.charAt(0) && comb.charAt(1)==lastTwoItems.charAt(1))
					|| (comb.charAt(0)==lastTwoItems.charAt(1) && comb.charAt(1)==lastTwoItems.charAt(0))){
				return comb.substring(2);
			}
		}

		return "";
	}
	boolean checkOpp(String[] oppArray,String item,String list){
		
		for(int i=0;i<oppArray.length;i++){
			String opp = oppArray[i];
			if((opp.charAt(0)==item.charAt(0) && list.indexOf(opp.charAt(1))>=0)
					|| (opp.charAt(1)==item.charAt(0) && list.indexOf(opp.charAt(0))>=0)){
				return true;
			}
		}
		return false;
	}
}