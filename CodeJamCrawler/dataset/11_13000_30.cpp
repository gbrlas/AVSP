import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Bot2 {

	/**
	 * @param args
	 */
	static FileWriter fw;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		fw =  new FileWriter("output.txt");
		int n = sc.nextInt();
		sc.nextLine();
		for(int q =0; q <n;q++)
		{
			System.out.println(q);
			fw.write("Case #"+(q+1)+": ");
			solve(sc.nextLine());
			
		}
		fw.close();

	}
	public static void solve(String str) throws IOException
	{
		Scanner scan = new Scanner(str);
		int numButtons = scan.nextInt();
		String[] commands = new String[numButtons];
		int index = 0;
		while(scan.hasNext())
		{
			String c = scan.next();
			int n = scan.nextInt();
			commands[index] = ""+c+n;
			index++;
		}
		
		int O = 1;
		int B = 1;
		int time = 0;

		for(int i = 0; i < numButtons;i++)
		{
			char bot = commands[i].charAt(0);
			System.out.println(B + " "+O);
			int dist = Integer.parseInt(commands[i].substring(1));
			if(bot =='O')
			{
				for(int j = i;j<numButtons;j++)
				{
					if(commands[j].charAt(0)=='B')
					{
						int comm2 = Integer.parseInt(commands[j].substring(1));
						if(Math.abs(comm2-B) <= Math.abs(dist-O))
						B = comm2;
						else
							B += Math.signum(Integer.parseInt(commands[j].substring(1)) -B)*(Math.abs(dist-O)+1); 

						break;
					}
				}
				time += Math.abs(dist-O)+1;
				O = dist;
				
			
			}
				if(bot =='B')
				{
					for(int j = i;j<numButtons;j++)
					{
						if(commands[j].charAt(0)=='O')
						{
							int comm2 = Integer.parseInt(commands[j].substring(1));
							if(Math.abs(comm2-O) <= Math.abs(dist-B))
							O = comm2;
							else
								O += Math.signum( Integer.parseInt(commands[j].substring(1)) -O)*(Math.abs(dist-B)+1);
							break;
						}
					}
					time += Math.abs(dist-B)+1;
					B = dist;
					
				
				}
		}fw.write(time+"\n");

	}
}

