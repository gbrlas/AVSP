import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;



/**
 * @author fabrizio
 *
 */
public class ThemePark {

	long[][]memo;
	
	public long getEuros(int rides,int maxPeople,int[]groups) {
		memo=new long[groups.length][];  //0 the euros, 1 the next index of ride
		fillMemo(maxPeople, groups);
		
		long res=0;
		int index=0;
		long[][]indexesUsed=new long[groups.length][2]; //to detect the cycle, 0 euros 1 the rides
		for (long[] ls : indexesUsed) {
			Arrays.fill(ls, -1);			
		}
		int ridesDone=0;
		for (; ridesDone < rides; ridesDone++) {
			if (indexesUsed[index][0]!=-1) {
				break;
			}
			indexesUsed[index]=new long[]{res,ridesDone};
			res+=memo[index][0];
			index=(int) memo[index][1];
		}
		long peopleCycle=res-indexesUsed[index][0];
		long ridesCycle=ridesDone-indexesUsed[index][1];
		res+=peopleCycle*((rides-ridesDone)/ridesCycle);
		ridesDone+=((rides-ridesDone)/ridesCycle)*ridesCycle;
		
		for (; ridesDone < rides; ridesDone++) {
			res+=memo[index][0];
			index=(int) memo[index][1];
		}
		
		return res;
		
	}

	private void fillMemo(int maxPeople, int[] groups) {
		for (int i = 0; i < groups.length; i++) {
			long people=0;
			int nextIndex=i;
			for (int j = 0; j < groups.length; j++) {
				if (people+groups[nextIndex]>maxPeople) {
					break;
				}
				people+=groups[nextIndex];
				nextIndex=(nextIndex+1)%groups.length;
			}
			memo[i]=new long[]{people,nextIndex};
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc=new Scanner(new File("C-large.in"));
		PrintWriter p=new PrintWriter("out-c-large.txt");
		int cases=sc.nextInt();
		for (int c = 1;  c <=cases; c++) {
			int rides=sc.nextInt();
			int maxPeople=sc.nextInt();
			int numberGroups=sc.nextInt();
			int[]groups=new int[numberGroups];
			for (int g = 0; g < numberGroups; g++) {
				groups[g]=sc.nextInt();
			}
			p.println("Case #"+c+": "+new ThemePark().getEuros(rides, maxPeople, groups));
		}
		p.close();
	}
}
