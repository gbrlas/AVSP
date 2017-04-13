import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader.Array;


public class ThemePark extends GoogleCodeJam {
	
	
	public static void main(String[] args) throws Exception
	{
		inputDataSource = "C:/Users/Lian/Desktop/C-small-attempt0.in";
		outputDataSource = "C:/Users/Lian/Desktop/C-small-attempt0.out";
		//print();
		readFile();
		
		for(int i = 0; i <= inputData.size() -1; i= i+2)
		{
			int earn = 0;
			int runTimes = 0;
			int capblity = 0;
			int groupCount = 0;
			LinkedList<Integer> groups = new LinkedList<Integer>();
			LinkedList<Integer> roller = new LinkedList<Integer>();
			//init
			String[] tmp = inputData.get(i).split(" ");
			runTimes = Integer.parseInt(tmp[0]);
			capblity = Integer.parseInt(tmp[1]);
			groupCount = Integer.parseInt(tmp[2]);
			
			for(String num:(inputData.get(i+1).split(" ")))
			{
				groups.offer(Integer.parseInt(num));
			}
			
			//run!
			for(int j = 0;j <= runTimes -1 ; j++)
			{
				int inNum = 0;
				while(inNum < capblity)
				{
					if(groups.peek() == null)
					{
						break;
					}
					if((inNum + groups.peek())<=capblity)
					{
						int in = groups.pop();
						inNum += in;
						earn += in;
						roller.offer(in);
					}
					else
					{
						break;
					}
				}
				//System.out.println(inNum);
				groups.addAll(roller);
				roller.clear();
				
			}
			add("Case #" + loop + ": " + earn + "\n\r");
			
		}
		writeFile();
	}
}
