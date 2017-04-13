/**
 * Created on Jul 16, 2008
 */
package net.galluzzo.gcj.traintimetable;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

/**
 * @author Eric Galluzzo, eric@galluzzo.net
 */
public class TrainTimetable
{
	protected static class Journey implements Comparable<Journey>
	{
		protected int departureMinute;
		protected int arrivalMinute;
		protected boolean forward;
		
		public Journey( int departureMinute, int arrivalMinute, boolean forward )
		{
			this.departureMinute = departureMinute;
			this.arrivalMinute = arrivalMinute;
			this.forward = forward;
		}
		
		public int compareTo( Journey other )
		{
			int firstComparison = departureMinute - other.departureMinute;
			if ( firstComparison == 0 )
			{
				return arrivalMinute - other.arrivalMinute;
			}
			else
			{
				return firstComparison;
			}
		}

		public int getDepartureMinute()
		{
			return departureMinute;
		}

		public int getArrivalMinute()
		{
			return arrivalMinute;
		}

		public boolean isForward()
		{
			return forward;
		}
	}
	
	protected static class ReverseIntegerComparator implements Comparator<Integer>
	{
		public int compare( Integer o1, Integer o2 )
		{
			return o2.intValue() - o1.intValue();
		}
	}
	
	protected static class Timetable
	{
		protected int turnaround;
		protected List<Journey> journeys = new ArrayList<Journey>(); // Should be a SortedBag (e.g. from Commons Collections)
		protected int numTrainsStartingAtA;
		protected int numTrainsStartingAtB;
		protected Stack<Integer> timesAvailableAtA = new Stack<Integer>(); // Should be a SortedBag
		protected Stack<Integer> timesAvailableAtB = new Stack<Integer>(); // Should be a SortedBag
		protected Comparator<Integer> reverseIntComparator = new ReverseIntegerComparator();
		
		public int getTurnaround()
		{
			return turnaround;
		}
		
		public void setTurnaround( int turnaround )
		{
			this.turnaround = turnaround;
		}
		
		public void addAToB( String departure, String arrival )
		{
			journeys.add( new Journey( convertTimeToMinuteCount( departure ),
				convertTimeToMinuteCount( arrival ), true ) );
		}
		
		public void addBToA( String departure, String arrival )
		{
			journeys.add( new Journey( convertTimeToMinuteCount( departure ),
				convertTimeToMinuteCount( arrival ), false ) );
		}
		
		public List<Journey> getJourneys()
		{
			return journeys;
		}
		
		public void sort()
		{
			Collections.sort( journeys );
		}
		
		public void addTrainStartingAtA( int timeAvailableAtB )
		{
			numTrainsStartingAtA++;
			timesAvailableAtB.push( timeAvailableAtB );
			Collections.sort( timesAvailableAtB, reverseIntComparator );
		}
		
		public void addTrainStartingAtB( int timeAvailableAtA )
		{
			numTrainsStartingAtB++;
			timesAvailableAtA.push( timeAvailableAtA );
			Collections.sort( timesAvailableAtA, reverseIntComparator );
		}
		
		public boolean isTrainAvailableAtA( int time )
		{
			return ( !timesAvailableAtA.isEmpty() &&
				timesAvailableAtA.peek() <= time );
		}
		
		public boolean isTrainAvailableAtB( int time )
		{
			return ( !timesAvailableAtB.isEmpty() &&
				timesAvailableAtB.peek() <= time );
		}
		
		public void moveTrainFromAToB( int timeAvailableAtB )
		{
			timesAvailableAtA.pop();
			timesAvailableAtB.push( timeAvailableAtB );
			Collections.sort( timesAvailableAtB, reverseIntComparator );
		}
		
		public void moveTrainFromBToA( int timeAvailableAtA )
		{
			timesAvailableAtB.pop();
			timesAvailableAtA.push( timeAvailableAtA );
			Collections.sort( timesAvailableAtA, reverseIntComparator );
		}
		
		public int getNumTrainsStartingAtA()
		{
			return numTrainsStartingAtA;
		}
		
		public int getNumTrainsStartingAtB()
		{
			return numTrainsStartingAtB;
		}
		
		protected int convertTimeToMinuteCount( String time )
		{
			return Integer.parseInt( time.substring( 0, 2 ) ) * 60 +
				Integer.parseInt( time.substring( 3, 5 ) );
		}
	}
	
	public static void main( String[] args ) throws IOException
	{
		if ( args.length == 2 )
		{
			new TrainTimetable().run( args[0], args[1] );
		}
		else
		{
			System.err.println( "Usage: java " +
				TrainTimetable.class.getName() + " inputFile outputFile" );
		}
	}
	
	public void run( String inputFile, String outputFile ) throws IOException
	{
		Reader in = new FileReader( inputFile );
		Writer out = new FileWriter( outputFile );
		try
		{
			run( in, out );
		}
		finally
		{
			in.close();
			out.close();
		}
	}
	
	public void run( Reader in, Writer out ) throws IOException
	{
		List<Timetable> timetables = readTimetables( in );
		int caseIndex = 1;
		for ( Timetable timetable : timetables )
		{
			calculateNecessaryNumberOfTrains( timetable );
			out.write( "Case #" + caseIndex + ": " +
				timetable.getNumTrainsStartingAtA() + " " +
				timetable.getNumTrainsStartingAtB() + "\n" );
			caseIndex++;
		}
	}
	
	public List<Timetable> readTimetables( Reader in ) throws IOException
	{
		List<Timetable> timetables = new ArrayList<Timetable>();
		
		Scanner scanner = new Scanner( in );
		int numTests = scanner.nextInt();
		scanner.nextLine();
		for ( int i = 0; i < numTests; i++ )
		{
			Timetable timetable = new Timetable();
			timetable.setTurnaround( scanner.nextInt() );
			scanner.nextLine();
			int numAToB = scanner.nextInt();
			int numBToA = scanner.nextInt();
			scanner.nextLine();
			for ( int j = 0; j < numAToB; j++ )
			{
				timetable.addAToB( scanner.next(), scanner.next() );
				scanner.nextLine();
			}
			for ( int j = 0; j < numBToA; j++ )
			{
				timetable.addBToA( scanner.next(), scanner.next() );
				scanner.nextLine();
			}
			
			timetables.add( timetable );
		}
		return timetables;
	}
	
	public void calculateNecessaryNumberOfTrains( Timetable timetable )
	{
		timetable.sort();
		for ( Journey journey : timetable.getJourneys() )
		{
			// Could reduce duplication by having generic methods instead of
			// A- and B-specific, but hey, this works for now.
			if ( journey.isForward() )
			{
				int timeAvailableAtDest = journey.getArrivalMinute() +
					timetable.getTurnaround();
				if ( timetable.isTrainAvailableAtA( journey.getDepartureMinute() ) )
				{
					timetable.moveTrainFromAToB( timeAvailableAtDest );
				}
				else
				{
					timetable.addTrainStartingAtA( timeAvailableAtDest );
				}
			}
			else
			{
				int timeAvailableAtDest = journey.getArrivalMinute() +
					timetable.getTurnaround();
				if ( timetable.isTrainAvailableAtB( journey.getDepartureMinute() ) )
				{
					timetable.moveTrainFromBToA( timeAvailableAtDest );
				}
				else
				{
					timetable.addTrainStartingAtB( timeAvailableAtDest );
				}
			}
		}
	}
}
