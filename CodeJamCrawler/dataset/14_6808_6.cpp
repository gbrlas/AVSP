import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class MagicTrick {
	
	
	static PrintWriter pw;
	static BufferedReader br;	
	
public static void main(String[] Args) throws IOException{
		
		try{
			br = new BufferedReader(new FileReader("C:\\A-small-practice.in"));
			pw = new PrintWriter( new BufferedWriter(new FileWriter("C:\\A-small-out.in")));
			int size = Integer.parseInt(br.readLine());
			int caseNum=1;
			while(size>0){
				
				
				//System.out.println("Case #"+(caseNum++)+": "+checkTrickNget());
				
				pw.println("Case #"+(caseNum++)+": "+checkTrickNget());
				
				
				size--;
			}
		}
		
		catch(Exception ex){
			
			ex.printStackTrace();
			
		}
		finally{
			br.close();
			pw.flush();
			pw.close();
			
		}
	}

static String checkTrickNget(){
	try{
	int row1= Integer.parseInt(br.readLine());
	
	int[] row1_ele= getRowEle(row1);
	
	int row2= Integer.parseInt(br.readLine());
	
	int[] row2_ele= getRowEle(row2);
	
	return checkEleNprint(row1_ele,row2_ele);
	
	}
	catch(IOException e){
		
		e.printStackTrace();
	}
	
	return " ";
}

static int[] getRowEle(int row1) throws IOException{
	int i=1;
while(i<row1){
		
		br.readLine();
		i++;
	}

String[] str = br.readLine().split(" ");
	i=row1+1;
while(i<=4){
	
	br.readLine();
	i++;
}

int size = str.length;
int[] ele =  new int[size];

for(int j=0;j<size;j++){
	
	ele[j]= Integer.parseInt(str[j]);
}

return ele ;
}

static String checkEleNprint(int[] row1_ele_l ,int[] row2_ele_l){
	
	int match=0;
	int num =0;
	for(int i=0;i<row1_ele_l.length;i++){
		
		for(int j=0;j<row2_ele_l.length;j++){
			
			
			if(row1_ele_l[i]==row2_ele_l[j]){
				
				match++;
				
				if(match==1){
					
					num=row2_ele_l[j];
				}
			}
		}
	}
	
	if(match>1){
		
		return "Bad magician!";
		
	}
	else if(match==0){
		
		return"Volunteer cheated!";
	}
	else if(match==1){
		
		return Integer.toString(num);
	}
	
	return " ";
}
}
