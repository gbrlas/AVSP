import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Trains
{
	public static void main(String[] args)
	{
		try
		{
			PrintStream o= new PrintStream(new File("outputlarge.txt"));
			Scanner s= new Scanner(new File("largein.in"));
			ArrayList<Trip> trips;
			int numCases, turn, tripsA, tripsB;

			numCases= Integer.valueOf(s.nextLine());
			System.out.println(numCases);
			for(int c= 0; c < numCases; c++)
			{
				
				trips= new ArrayList<Trip>();

				turn= Integer.valueOf(s.next());
				//System.out.println("turn: " + turn);
				
				tripsA = Integer.valueOf(s.next());
				tripsB = Integer.valueOf(s.next());
				for(int t= 0; t < tripsA+tripsB; t++)
				{
					trips.add(new Trip(t<tripsA, s.next(), s.next() ));
					//System.out.println(trips.get(t));
				}

				String str= "Case #" + (c + 1) + ": " + countTrains(trips, turn);
				System.out.println(str);
				o.println(str);
			}
		} catch(IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static String countTrains(ArrayList<Trip> trips, int turn)
	{
		System.out.println("turn: " + turn);
		Collections.sort(trips, Trip.departCompare);
		System.out.println(trips);
		int aTrains = 0;
		int bTrains = 0;
		int aNeed = 0;
		int bNeed = 0;
		int currentTime = 0;
		Trip t;
		int arrived;
		for(int i = 0; i<trips.size(); i++)
		{
			t = trips.get(i);
			currentTime = t.depart;
			if(t.start)
			{
				arrived = countArrivals(t.start, currentTime, trips, turn);
				i-=arrived;
				System.out.println("a: " + currentTime + " " + aTrains + " " + (aTrains+=arrived));
				//aTrains+=countArrivals(temp.start, currentTime, trips, turn);
				if(aTrains < 1)
				{
					aNeed++;
					aTrains = 1;
				}
				aTrains--;
			}
			else
			{
				arrived = countArrivals(t.start, currentTime, trips, turn);
				i-=arrived;
				System.out.println("b: " + currentTime + " " + bTrains + " " + (bTrains+=arrived));
				//bTrains+=countArrivals(temp.start, currentTime, trips, turn);
				if(bTrains < 1)
				{
					bNeed++;
					bTrains = 1;
				}
				bTrains--;
			}
		}
		System.out.println(aNeed + " " + bNeed);
		return(aNeed + " " + bNeed);
	}
	
	public static int countArrivals(boolean destination, int time, ArrayList<Trip> trips, int turn)
	{
		//Collections.sort(trips, Trip.arriveCompare);
		int count = 0;
		Trip t;
		for(int i = 0; i< trips.size(); i++)
		{
			t = trips.get(i);
			if(t.arrive+turn <= time && t.start!=destination)
			{
				count++;
				trips.remove(i);
				i--;
			}
		}
		return count;
	}
}
