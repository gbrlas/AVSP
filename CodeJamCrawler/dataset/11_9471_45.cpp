
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
 
public class BotTrust {
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BotTrust bot= new BotTrust();
		FileReader inf = new FileReader("data/A-large.in"); 
		BufferedReader in = new BufferedReader(inf); 
		FileWriter outf = new FileWriter("result/A-large.out");  
		BufferedWriter out = new BufferedWriter(outf);  
		int numCases = Integer.parseInt(in.readLine());
		for(int index = 1; index <=numCases; index++)
		{
			String line = in.readLine();
			String [] tokens = line.split(" ");
			int numAcctions = Integer.parseInt(tokens[0]);
			ArrayList<Action> actionArray = new ArrayList<Action>();
			for(int j = 1;j<tokens.length-1;j=j+2)
			{
				String host = tokens[j];
				int botton = Integer.parseInt(tokens[j+1]);
				Action acc = bot.new Action(host,botton);
				actionArray.add(acc);
			}
		 
			 
			/*End of getting data, begin to process*/
			int totalTime = 0;
			int bPos = 1;
			int oPos = 1;
			int bTimeused = 0;
			int oTimeused = 0;
			int distance = 0;
			String preHost = "";
			for(int i = 0; i< actionArray.size();i++)
			{
				Action curAction = actionArray.get(i);
				String curHost = curAction.getHost();
				int curBotton = curAction.getBotton();
				if(curHost.equals("O"))
				{
					distance = Math.abs(curBotton - oPos); 
					if(preHost.equals("O")||preHost.equals(""))
					{
						oTimeused += distance+1;
						totalTime += distance+1;
						oPos = curBotton;
						preHost ="O";
						System.out.println(i+ ": pre is O and now is O, oTime: "+oTimeused+" totalTime:"+totalTime+" oPos:"+oPos);
					}
					else
					{
						 
						if(distance > bTimeused)
						{
							oTimeused = distance+1 - bTimeused;
							totalTime += oTimeused;
							oPos = curBotton;
							preHost = "O";
							System.out.println(i+ ": pre is B and now is O, larger distance,oTime: "+oTimeused+" totalTime:"+totalTime+" oPos:"+oPos);
						}
						else
						{
							oTimeused =1;
							totalTime +=1;
							oPos = curBotton;
							preHost = "O";
							System.out.println(i+ ": pre is O and now is O, oTime: "+oTimeused+" totalTime:"+totalTime+" oPos:"+oPos);
						}
					}
				}//end of curHost = O
				else if(curHost.equals("B"))               //curHost = "B"
				{
					distance = Math.abs(curBotton - bPos); 
					if(preHost.equals("B")||preHost.equals(""))
					{
						bTimeused += distance+1;
						totalTime += distance+1;
						bPos = curBotton;
						preHost ="B";
						System.out.println(i+ ": pre is B and now is B, bTime: "+bTimeused+" totalTime:"+totalTime+" bPos:"+bPos);
					}
					else
					{
						
						if(distance > oTimeused)
						{
							bTimeused = distance+1 - oTimeused;
							totalTime += bTimeused;
							bPos = curBotton;
							preHost = "B";
							System.out.println(i+ ": pre is O and now is B, larger distance,bTime: "+bTimeused+" totalTime:"+totalTime+" bPos:"+bPos);
						}
						else
						{
							bTimeused =1;
							totalTime +=1;
							bPos = curBotton;
							preHost = "B";
							System.out.println(i+ ": pre is O and now is B, bTime: "+bTimeused+" totalTime:"+totalTime+" bPos:"+bPos);
						}
					}
				}//end of curHost = "B"
			}//end of loop of the action list
			
			/*End of process, getting results*/
			System.out.println("Case #"+index+": "+totalTime);
			out.write("Case #"+index+": "+" "+totalTime);
			out.newLine();
			out.flush();
		}
	}
	
	class Action
	{
		private String host;
		private int botton;
		public Action(String h, int b)
		{
			this.host = h;
			this.botton = b;
		}
		public String getHost(){
			return this.host;
		}
		public int getBotton(){
			return this.botton;
		}
	}

}
