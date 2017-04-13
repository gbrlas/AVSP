import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Iterator;
import java.util.List;


public class ExerciseB {
	private static final String BASE_TIME = "2008-07-16 ";

  public static void main(String[] args) throws Exception {
		BufferedReader bufferedReader = 
		  new BufferedReader(new InputStreamReader(System.in));
		String aLine = bufferedReader.readLine();
		int testCaseCount = Integer.parseInt(aLine);

		int testCaseTotal = testCaseCount;
		while (testCaseCount > 0) {
			aLine = bufferedReader.readLine();
			int turnaroundTime = Integer.parseInt(aLine);

			aLine = bufferedReader.readLine();
			String[] numbers = aLine.split(" ");
			int na = Integer.parseInt(numbers[0]);
			int nb = Integer.parseInt(numbers[1]);
			
			List<Date> outboundA = new ArrayList<Date>();
			List<Date> inboundB = new ArrayList<Date>();
			while (na != 0 && (aLine = bufferedReader.readLine()) != null) {
				String[] timetableEntry = aLine.split(" ");

				SimpleDateFormat simpleDateFormat =
				  new SimpleDateFormat("yyyy-MM-dd HH:mm");

				String outboundATime = timetableEntry[0];
				outboundA.add(simpleDateFormat.parse(BASE_TIME + outboundATime));
				na--;

				String inboundBTime = timetableEntry[1];
				inboundB.add(simpleDateFormat.parse(BASE_TIME + inboundBTime));
			}
			
			List<Date> inboundA = new ArrayList<Date>();
			List<Date> outboundB = new ArrayList<Date>();
			while (nb != 0 && (aLine = bufferedReader.readLine()) != null) {
				String[] timetableEntry = aLine.split(" ");

				SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm");

				String outboundBTime = timetableEntry[0];
				outboundB.add(simpleDateFormat.parse(BASE_TIME + outboundBTime));
				nb--;

				String inboundATime = timetableEntry[1];
				inboundA.add(simpleDateFormat.parse(BASE_TIME + inboundATime));
			}
			
			Collections.sort(inboundA);
			Collections.sort(outboundA);
			Collections.sort(inboundB);
			Collections.sort(outboundB);
			
			System.out.println("Case #" + (testCaseTotal - testCaseCount + 1) 
			    + ": " + calculate(inboundA, outboundA, turnaroundTime)
					+ " " + calculate(inboundB, outboundB, turnaroundTime));

			testCaseCount--;
		}
	}

	public static int calculate(List<Date> coming, List<Date> goingOut, int turnaroundTime) {
		int trainCount = 0;
		for (Date date : goingOut) {
			GregorianCalendar departureTime = new GregorianCalendar();
			departureTime.setTime(date);
			
			boolean blAddOneTrain = true;
			for (Iterator<Date> iter = coming.iterator(); iter.hasNext();) {
				Date date2 = iter.next();

				GregorianCalendar arrivalTime = new GregorianCalendar();
				arrivalTime.setTime(date2);
				
				departureTime.add(Calendar.MINUTE, - turnaroundTime);
				if (departureTime.before(arrivalTime)) {
					;
				} else {
					blAddOneTrain = false;
					iter.remove();
					break;
				}

				departureTime.add(Calendar.MINUTE, turnaroundTime);
			}
			
			if (blAddOneTrain) {
				trainCount++;
			}
		}
		
		return trainCount;
	}
}
