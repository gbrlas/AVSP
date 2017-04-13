import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.List;


public class TimeTable {	
	int turnAroundTime = 0;

	private class Trip implements Comparable<Trip> {
		GregorianCalendar start;
		GregorianCalendar stop;		

		public Trip(String start, String stop) {
			String[] timeStart = start.split(":");
			String[] timeStop = stop.split(":");

			this.start = new GregorianCalendar();
			this.start.set(GregorianCalendar.HOUR_OF_DAY, new Integer(timeStart[0]).intValue());
			this.start.set(GregorianCalendar.MINUTE, new Integer(timeStart[1]).intValue());

			this.stop = new GregorianCalendar();
			this.stop.set(GregorianCalendar.HOUR_OF_DAY, new Integer(timeStop[0]).intValue());
			this.stop.set(GregorianCalendar.MINUTE, new Integer(timeStop[1]).intValue() + turnAroundTime);			
		}

		public int compareTo(Trip o) {
			long diff1 = 0, diff2 = 0;
			
			if (o.start.equals(this.start)) {
				diff1 = o.start.compareTo(o.stop);
				diff2 = this.start.compareTo(this.stop);
				return (int)(diff1 - diff2);
			} else {
				return this.start.compareTo(o.start);
			}
		}		
	}

	private class Trips extends ArrayList<Trip> {		
		public int needsTrain(GregorianCalendar time) {
			int trains = 0;
			for (Trip t : this) {
				if (getTime(t.start).equals(getTime(time))) {					
					trains++;
				}
			}

			return trains;
		}
		
		public int hasTrain(GregorianCalendar time) {
			int trains = 0;
			for (Trip t : this) {
				if (getTime(t.stop).equals(getTime(time))) {
					trains++;
				}
			}

			return trains;
		}
	}

	public String getTime(Calendar cal) {
		return cal.get(GregorianCalendar.HOUR_OF_DAY) + ":" + cal.get(GregorianCalendar.MINUTE);
	}
		
	private String getTrainCount(Trips a, Trips b) {
		int aTrains = 0;
		int bTrains = 0;
		int bNeeds = 0;
		int aNeeds = 0;
		int bSpawned = 0;
		int aSpawned = 0;

		GregorianCalendar cal = new GregorianCalendar();

		cal.set(GregorianCalendar.HOUR_OF_DAY, 0);
		cal.set(GregorianCalendar.MINUTE, 0);
		int day = cal.get(GregorianCalendar.DATE);
		
		if (a.size() > 0 && a.get(0) != null) {
			cal.set(GregorianCalendar.HOUR, a.get(0).start.get(GregorianCalendar.HOUR_OF_DAY));
			cal.set(GregorianCalendar.MINUTE, a.get(0).start.get(GregorianCalendar.MINUTE));			
			if (b.size() > 0 && b.get(0) != null) {
				if (cal.after(b.get(0).start)) {
					cal.set(GregorianCalendar.HOUR, b.get(0).start.get(GregorianCalendar.HOUR_OF_DAY));
					cal.set(GregorianCalendar.MINUTE, b.get(0).start.get(GregorianCalendar.MINUTE));			
				}
			}
		}

		while (cal.get(GregorianCalendar.DATE) == day) {
			aTrains += b.hasTrain(cal);
			bTrains += a.hasTrain(cal);
			
			if ((bNeeds = b.needsTrain(cal)) > 0) {
				bTrains-=bNeeds;
				if (bTrains < 0) {
					bSpawned += bTrains * -1;
					bTrains = 0;					
				}				
			}
			
			if ((aNeeds = a.needsTrain(cal)) > 0) {
				aTrains-=aNeeds;
				if (aTrains < 0) {
					aSpawned += aTrains * -1;
					aTrains = 0;
				}
			}
			
			cal.add(GregorianCalendar.MINUTE, 1);
		}
		
		return aSpawned + " " + bSpawned;
	}

	private String processCase(BufferedReader buf) throws IOException
	{		
		turnAroundTime = new Integer(buf.readLine()).intValue();
		
		String[] trips = buf.readLine().split(" ");
		int tripACount = new Integer(trips[0]).intValue();
		int tripBCount = new Integer(trips[1]).intValue();

		Trips tripsA = new Trips();
		Trips tripsB = new Trips();		

		System.out.println("Processing!");

		for (int i = 0; i < tripACount; i++) {
			trips = buf.readLine().split(" ");
			tripsA.add(new Trip(trips[0], trips[1]));				
		}

		for (int i = 0; i < tripBCount; i++) {
			trips = buf.readLine().split(" ");
			tripsB.add(new Trip(trips[0], trips[1]));					
		}

		java.util.Collections.sort(tripsA);
		java.util.Collections.sort(tripsB);

		return getTrainCount(tripsA, tripsB);		
	}

	public TimeTable() {
		int cases = 0;
		String rawLine = null;

		try
		{
			BufferedReader buf = new BufferedReader(new FileReader("D:\\GoogleContest\\B-small-attempt3.in"));
			FileWriter out = new FileWriter("D:\\GoogleContest\\B-small-attempt3.out");

			rawLine = buf.readLine();
			cases = new Integer(rawLine).intValue();

			for (int i = 0; i < cases; i++)
			{					
				out.write("Case #" + (i+1) + ": " + processCase(buf) + "\n");
			}
			buf.close();
			out.close();
		}
		catch (IOException ex)
		{
			System.out.println("IO Error: " + ex.getMessage());
		}
		catch (Exception e)
		{
			System.out.println("Unknown Error: " + e.getMessage());
		}	
	}	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new TimeTable();
	}
}
