import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class test6 {
	public static void main(String[] args) {
		
		try (BufferedReader br = new BufferedReader(new FileReader("E:\\test5.txt")))
		{
 
			String sCurrentLine;
			String[] allLineString = new String[2000];
			int lineCount = 0;
			while ((sCurrentLine = br.readLine()) != null) {
//				System.out.println(sCurrentLine);
				allLineString[lineCount] = sCurrentLine;
				lineCount++;
			}
			int Count = Integer.parseInt(allLineString[0]);
			int lineNum = 0;
			for(int i = 1 ; i <= Count ; i++){
				String StrLine = allLineString[i];
				String[] dic = StrLine.split("\\s+");
				lineNum = i;
					double C = Double.parseDouble(dic[0]);
					double F = Double.parseDouble(dic[1]);
					double X = Double.parseDouble(dic[2]);
					Find(C,F,X,lineNum);
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} 
 
	}

	private static void Find(double C, double F, double x,int i) {
		// TODO Auto-generated method stub
		double step = 2;
		double c =  C;
		double f = F ;
		double kol = x;
		double time = 0.0;
		
		while(true){
			
			double wait = time + kol / step;
			
			double buyFarm = time + c/step + kol / (step+f);
			if(wait < buyFarm){
				
//				System.out.println(time);
				break;
			}
			time += c / step;
			
			step += f;
		
		}
		String title = "Case #"+ i  +": ";
		time += kol/(step);
		System.out.println(title+time);
		
	}
}