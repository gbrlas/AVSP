package google.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;

public class TrainTable {

	private static final SimpleDateFormat sf = new SimpleDateFormat("HH:mm");
	
	public static void main(String[] args) throws Exception {

		List<Case> caseList = getFromText();
	
		/*int i = 1;
		for (Case c : caseList) {
			System.out.println("---------case no. " + i + "----------");
			System.out.println("- A");
			for (Time time : c.timeAList) {
				System.out.println("from " + sf.format(time.dateIn) + " to " + sf.format(time.dateOut) + "");
			}
			System.out.println("- B");
			for (Time time : c.timeBList) {
				System.out.println("from " + sf.format(time.dateIn) + " to " + sf.format(time.dateOut) + "");
			}
			i++;
		}*/
		
		calculate(caseList);
		
	}
	
	private static void calculate(List<Case> caseList) {
		int i = 1;
		for (Case c : caseList) {
			List<Integer> list = calculateBusCount(c);
			int cntA = list.get(0);
			int cntB = list.get(1);
			System.out.println("Case #" + i + ": " + cntA + " " + cntB + "");
			i++;
		}
		
	}
	
	private static List<Integer> calculateBusCount(Case c) {
		
		List<Time> timeAList = c.timeAList;
		List<Time> timeBList = c.timeBList;
		
		int cntA = 0;
		int cntB = 0;
		
		while (!timeAList.isEmpty() && !timeBList.isEmpty()) {
			Date dateOut =null;
			int flag = 0;
			if (timeBList.get(0).dateIn.compareTo(timeAList.get(0).dateIn) < 0) { //B < A
				dateOut = timeBList.get(0).dateOut;
				timeBList.remove(0);
				flag = 1;
				cntB++;
			} else {
				dateOut = timeAList.get(0).dateOut;
				timeAList.remove(0);
				flag = 2;
				cntA++;
			}
			calculateBusCount(dateOut, timeAList, timeBList, flag, c.turnTime);
		}
		
		if (!timeAList.isEmpty()) {
			cntA += timeAList.size();
		}
		
		if (!timeBList.isEmpty()) {
			cntB += timeBList.size();
		}
		
		List<Integer> list = new ArrayList<Integer>();
		list.add(cntA);
		list.add(cntB);
		
		return list;
	}
	
	private static void calculateBusCount(Date dateOut, List<Time> timeAList, List<Time> timeBList, int flag, int turnTime) {
		
		Calendar cal = Calendar.getInstance();
		cal.setTime(dateOut);
		cal.add(Calendar.MINUTE, turnTime);
		dateOut = cal.getTime();
		
		List<Time> timeList = null;
		int reFlag = 0;
		
		if (flag == 1) {
			reFlag = 2;
			timeList = timeAList;
		} else {
			reFlag = 1;
			timeList = timeBList;
		}
		
		for (int i = 0; i < timeList.size(); i++) {
			Time time = timeList.get(i);
			if (dateOut.compareTo(time.dateIn) <= 0) {
				Date d = time.dateOut;
				timeList.remove(i);
				calculateBusCount(d, timeAList, timeBList, reFlag, turnTime);
				break;
			}
		}
		
		
		
	}
	
	private static List<Case> getFromText() throws Exception {
		
		List<Case> caseList = new ArrayList<Case>();
		
		File file = new File("B-large.in.txt");
		FileReader fileReader = new FileReader(file);
		BufferedReader bufferedReader = new BufferedReader(fileReader);
		
		String caseSize = bufferedReader.readLine();
		
		Case c = null;
		Time time = null;
		List<Time> timeAList = null;
		List<Time> timeBList = null;
		for (int i = 1, size = Integer.parseInt(caseSize); i <= size; i++) {
			
			 c = new Case();
			 timeAList = new ArrayList<Time>();
			 timeBList = new ArrayList<Time>();
			 c.timeAList = timeAList;
			 c.timeBList = timeBList;
			 
			 c.turnTime = Integer.parseInt(bufferedReader.readLine());
			 
			 String sizeAB = bufferedReader.readLine();
			 String[] tmp = sizeAB.split(" ");
			 int sizeA = Integer.parseInt(tmp[0]);
			 int sizeB = Integer.parseInt(tmp[1]);
			 
			 for (int j = 1; j <= sizeA; j++) {
				 time = new Time();
				 String timeA = bufferedReader.readLine();
				 tmp = timeA.split(" ");
				 time.dateIn = getDate(tmp[0]);
				 time.dateOut = getDate(tmp[1]);
				 timeAList.add(time);
			 }
			 
			 for (int j = 1; j <= sizeB; j++) {
				 time = new Time();
				 String timeA = bufferedReader.readLine();
				 tmp = timeA.split(" ");
				 time.dateIn = getDate(tmp[0]);
				 time.dateOut = getDate(tmp[1]);
				 timeBList.add(time);
			 }
			 
			 TimeComparator comparator = new TimeComparator();
			 
			 Collections.sort(timeAList, comparator);
			 Collections.sort(timeBList, comparator);
			 
			 caseList.add(c);
			
		}
		
		return caseList;
		
	}
	
	private static Date getDate(String time) throws Exception {
		
		return sf.parse(time);
		
	}

}

class TimeComparator implements Comparator<Time> {
	
	public int compare(Time t1, Time t2) {
		
		return t1.dateIn.compareTo(t2.dateIn);
	}
	
}

class Case {
	
	List<Time> timeAList;
	List<Time> timeBList;
	int turnTime;
	
}

class Time {
	
	Date dateIn;
	Date dateOut;
	
}
