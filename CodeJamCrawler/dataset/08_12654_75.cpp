import java.util.*;
import java.io.*;
public class B {

	/**
	 * @param args
	 */
	public static int timeCal(int a, int b, int gap) {
		b=b+gap;
		while (b>60) {
			b=b-60;
			a++;
		}
		return a*100+b;

	}
	public static int isIn(int[] input, int a) {
		int count = 0;
		for (int i=0; i<input.length;i++) {
			if (a==input[i]) count++;
		}
		return count;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			//BufferedReader br = new BufferedReader(new FileReader("b.txt"));
			BufferedReader br = new BufferedReader(new FileReader("b.in"));
			PrintWriter pw = new PrintWriter(new FileWriter("b_output.txt"));

			int num = Integer.parseInt(br.readLine());
			for (int i=0; i<num; i++) {
				int gap = Integer.parseInt(br.readLine());
				String s = br.readLine();
				StringTokenizer token = new StringTokenizer(s);
				int startA = Integer.parseInt(token.nextToken());
				int startB = Integer.parseInt(token.nextToken());
				int timeAd[] = new int[startA];
				int timeAa[] = new int[startA];
				int timeBd[] = new int[startB];
				int timeBa[] = new int[startB];
				int timeTable[] = new int[2*startA+2*startB+1];
				int count = 0;
				for (int j=0; j<startA; j++) {
					s = br.readLine();

					token = new StringTokenizer(s,": ");
					int temp = Integer.parseInt(token.nextToken());
					int temp2 = Integer.parseInt(token.nextToken());

					timeAd[j]=timeCal(temp,temp2,0);
					temp = Integer.parseInt(token.nextToken());
					temp2 = Integer.parseInt(token.nextToken());
					timeAa[j]=timeCal(temp,temp2,gap);

					timeTable[count++] = timeAd[j];
					timeTable[count++] = timeAa[j];

				}
				for (int j=0; j<startB; j++) {
					s = br.readLine();
					token = new StringTokenizer(s,": ");
					int temp = Integer.parseInt(token.nextToken());
					int temp2 = Integer.parseInt(token.nextToken());
					timeBd[j]=timeCal(temp,temp2,0);
					temp = Integer.parseInt(token.nextToken());
					temp2 = Integer.parseInt(token.nextToken());
					timeBa[j]=timeCal(temp,temp2,gap);

					timeTable[count++] = timeBd[j];
					timeTable[count++] = timeBa[j];

				}
				timeTable[count] = 9999;
				Arrays.sort(timeTable);


				int minA= 0;
				int minB = 0;
				int curA = 0;
				int curB = 0;

				for (int j=0; j<count;j++) {

					while (timeTable[j]==timeTable[j+1]) {
						j++;
					}

					//System.out.println(timeTable[j]+" "+Arrays.binarySearch(timeBa, timeTable[j]));


					/*
					if (isIn(timeBa,timeTable[j]) >0)  {

						curA++;
						System.out.println("A+"+timeTable[j]);
					}
					if (isIn(timeAd, timeTable[j])>0) {
						curA--;
						System.out.println("A-"+timeTable[j]);
					}
					 */


					/*
					if (isIn(timeAa, timeTable[j])) {
						curB++;
						System.out.println("B+"+timeTable[j]);
					}
					if (isIn(timeBd, timeTable[j])) {

						curB--;
						System.out.println("B-"+timeTable[j]);
					}
					 */
					curA+= isIn(timeBa,timeTable[j]);
					curA-= isIn(timeAd, timeTable[j]);
					curB+= isIn(timeAa, timeTable[j]);
					curB-= isIn(timeBd, timeTable[j]);
					
					if (curA<minA) {
						minA = curA;
					}
					if (curB<minB) {
						minB = curB;
					}




				}
				System.out.println("Case #"+(i+1)+": "+(-minA)+" "+(-minB));
				pw.println("Case #"+(i+1)+": "+(-minA)+" "+(-minB));

			}
			pw.close();
		} catch (IOException e) {
			System.out.println("io error");
		}
	}

}
