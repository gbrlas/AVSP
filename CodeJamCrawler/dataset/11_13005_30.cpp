import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class Magicka {

	/**
	 * @param args
	 */
	static FileWriter fw;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small-attempt1.in"));
		fw =  new FileWriter("output.txt");
		int n = sc.nextInt();
		sc.nextLine();
		for(int q =0; q <n;q++)
		{
			//System.out.println(q);
			String forms = "",remove ="",str ="";
			int C = sc.nextInt();
			if(C>0)forms = sc.next();
			int D = sc.nextInt();
			if(D>0)remove =sc.next();
			int N = sc.nextInt();
			 str = sc.next();
			fw.write("Case #"+(q+1)+": ");
			solve(C,D,N,forms,remove,str,q,n);
			
		}
		fw.close();

	}
	public static void solve(int C, int D, int N, String forms, String remove,String str,int q, int n) throws IOException 
	{//System.out.println(forms + " "+remove + " "+str);
		ArrayList<Character> arr = new ArrayList<Character>();
		HashMap<String, Character> fMap = new HashMap<String,Character>();
		HashMap<Character,Character> rMap = new HashMap<Character,Character>();
		if(N==1)fw.write("["+str+"]\n");
		else
		{
			for(int i = 0; i < C;i+= 3)
			{
				fMap.put(""+forms.charAt(i)+forms.charAt(i+1),forms.charAt(i+2));
				fMap.put(""+forms.charAt(i+1)+forms.charAt(i),forms.charAt(i+2));
			}
			for(int i = 0; i < D;i+=2)
			{
				rMap.put(remove.charAt(i),remove.charAt(i+1));
				rMap.put(remove.charAt(i+1),remove.charAt(i));
			}
			arr.add(str.charAt(0));

			for(int i =1; i < str.length();i++)
			{
			
				if(str.equals("FAQFDFQ")){}
				arr.add(str.charAt(i));
				char c1 = arr.remove(arr.size()-1);
				char c2 = 'i';if(arr.size()>0)c2=arr.remove(arr.size()-1);
			
				boolean form = false;
				for(char k = 'A';k<='Z'&& c2 != 'i';k++)
				{
					String s = ""+c1 +k;
				
					if(C!= 0 && fMap.get(s)!=null && c2 == k)
					{
						arr.add(fMap.get(s));
						form = true;
					}
				}
				if(!form)
				{
					if(c2 != 'i')arr.add(c2);
					arr.add(c1);
				}
				char r = arr.remove(arr.size()-1);
				if(D!= 0 &&rMap.get(r)!=null && arr.contains(rMap.get(r)))
				{
					arr.clear();
				}
				else
				{
					arr.add(r);
				}
				
			}fw.write("[");
			for(int j = 0; j < arr.size()-1;j++)
			{
				fw.write(arr.get(j)+", ");
			}if(arr.size()>0)fw.write(arr.get(arr.size()-1));
			//fw.write("]\n");
			if(q == n-1)fw.write("]");
			else{
				fw.write("]\n");
			
			}
	
		}
	}

}
