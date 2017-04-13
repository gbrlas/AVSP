package hu.wildhemp.codejam.timetable;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class TimeTable {

	private int caseNum;
	private int[] turnAroundTime;
	
	private Trip[][] naTrips;
	private Trip[][] nbTrips;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		TimeTable timeTable = new TimeTable();
		timeTable.process();
	}
	
	public void process() {
		try {
			readInput("B-small-attempt0.in");
			System.setOut(new PrintStream("B-small-attempt0.out"));
			
			for (int caseIdx = 0; caseIdx < caseNum; caseIdx ++) {
				List<Trip> aTrips = new ArrayList<Trip>(Arrays.asList(naTrips[caseIdx]));
				Collections.sort(aTrips);
				List<Trip> bTrips = new ArrayList<Trip>(Arrays.asList(nbTrips[caseIdx]));
				Collections.sort(bTrips);
				List<Trip> allTrips = new ArrayList<Trip>(aTrips);
				allTrips.addAll(bTrips);
				Collections.sort(allTrips);
				
				List<LinkedList<Trip>> trips = new ArrayList<LinkedList<Trip>>();
				int aTrains = 0;
				int bTrains = 0;
				
				for (Trip actuaTrip: allTrips) {
					List<Trip> actuaList = null;
					List<Trip> actuaSearchList = null;
					
					if (aTrips.contains(actuaTrip)) {
						actuaList = aTrips;
						actuaSearchList = bTrips;
						aTrains ++;
					} else if (bTrips.contains(actuaTrip)) {
						actuaList = bTrips;
						actuaSearchList = aTrips;
						bTrains ++;
					} else {
						continue;
					}
					
					LinkedList<Trip> linkedTrips = new LinkedList<Trip>();
					trips.add(linkedTrips);
					
					linkedTrips.add(actuaTrip);
					Trip trip = actuaTrip;
					actuaList.remove(trip);
					
					while (true) {
						Trip otherTrip = findClosestAfter(trip, actuaSearchList);
						if (otherTrip != null) {
							linkedTrips.add(otherTrip);

							trip = otherTrip;
							actuaSearchList.remove(trip);
							
							List<Trip> tempList = actuaList;
							actuaList = actuaSearchList;
							actuaSearchList = tempList;
						} else {
							break;
						}
					}
				}
				
				System.out.println("Case #" + (caseIdx + 1) + ": " + aTrains + " " + bTrains);
			}
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private Trip findClosestAfter(Trip trip, List<Trip> tripList) {
		for(Trip actualTrip: tripList) {
			if (trip.getAvailMinuteOfDay() <= actualTrip.getStartMinuteOfDay()) {
				return actualTrip;
			}
		}
		
		return null;
	}
	
	private void readInput(String fileName) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)));

		caseNum = Integer.parseInt(reader.readLine());
		naTrips = new Trip[caseNum][];
		nbTrips = new Trip[caseNum][];
		turnAroundTime = new int[caseNum];
		
		for (int caseIdx = 0; caseIdx < caseNum; caseIdx ++) {
			turnAroundTime[caseIdx] = Integer.parseInt(reader.readLine());
			
			String[] trips = reader.readLine().split(" ");
			int naNum = Integer.parseInt(trips[0]);
			int nbNum = Integer.parseInt(trips[1]);
			
			naTrips[caseIdx] = new Trip[naNum];
			nbTrips[caseIdx] = new Trip[nbNum];
			
			for (int tripIdx = 0; tripIdx < naNum; tripIdx ++) {
				naTrips[caseIdx][tripIdx] = readTrip(reader, caseIdx);
			}

			for (int tripIdx = 0; tripIdx < nbNum; tripIdx ++) {
				nbTrips[caseIdx][tripIdx] = readTrip(reader, caseIdx);
			}
		}
		
	}
	
	private Trip readTrip(BufferedReader reader, int caseIdx) throws Exception {
		Trip trip = new Trip();
		String[] times = reader.readLine().split(" ");
		String[] hourMin = times[0].split(":");
		trip.setStartMinuteOfDay(Integer.parseInt(hourMin[0]) * 60 + Integer.parseInt(hourMin[1]));
		hourMin = times[1].split(":");
		trip.setEndMinuteOfDay(Integer.parseInt(hourMin[0]) * 60 + Integer.parseInt(hourMin[1]));
		trip.setAvailMinuteOfDay(trip.getEndMinuteOfDay() + turnAroundTime[caseIdx]);
		
		return trip;
	}
	
	
}
