import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Vector;

import javax.rmi.CORBA.Tie;


public class Trains {
	public static void main(String args[]) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		int noCases = Integer.parseInt(reader.readLine());
		PrintStream out = new PrintStream(args[1]);
		
		for(int i = 0 ;i < noCases;i++) {
			int turnAroundTime = Integer.parseInt(reader.readLine());
			StringTokenizer tokenizer = new StringTokenizer(reader.readLine()," ");
			int NA = Integer.parseInt(tokenizer.nextToken()); 
			int NB = Integer.parseInt(tokenizer.nextToken());
			Station sa = new Station(NA,NB,turnAroundTime);
			Station sb = new Station(NB,NA,turnAroundTime);
			
			for(int d=0;d<NA;d++) {
				tokenizer = new StringTokenizer(reader.readLine()," :");
				int hh = Integer.parseInt(tokenizer.nextToken());
				int mm = Integer.parseInt(tokenizer.nextToken()); 
				sa.addDeparture(hh*60+mm);
				hh = Integer.parseInt(tokenizer.nextToken());
				mm = Integer.parseInt(tokenizer.nextToken()); 
				sb.addArrival(hh*60+mm);
			}
			
			for(int d=0;d<NB;d++) {
				tokenizer = new StringTokenizer(reader.readLine()," :");
				int hh = Integer.parseInt(tokenizer.nextToken());
				int mm = Integer.parseInt(tokenizer.nextToken()); 
				sb.addDeparture(hh*60+mm);
				hh = Integer.parseInt(tokenizer.nextToken());
				mm = Integer.parseInt(tokenizer.nextToken()); 
				sa.addArrival(hh*60+mm);
			}
			out.println("Case #"+(i+1)+": "+sa.getTrains()+" "+sb.getTrains());
		}
		
		out.close();
		
	}
}

class Station {
	int []arrivals ;
	int [] departures;
	int curArr = 0;
	int curDep = 0;
	int turnAround;
	Station destination;

	
	public Station(int noDep, int noArr, int turnAround) {
		this.turnAround = turnAround;
		arrivals = new int[noArr];
		departures = new int[noDep];
	}
	
	public void setDestination(Station dest) {
		this.destination = dest;
	}
	
	public void addArrival(int time) {
		arrivals[curArr++] = time;
	}
	
	public void addDeparture(int time) {
		departures[curDep++] = time;
	}
	
	public int getTrains() {
		Arrays.sort(arrivals);
		Arrays.sort(departures);
		int trains = departures.length;
		for(int d=0 ;d < departures.length;d++) {
			for(int a=0;a < arrivals.length ;a++) {
				if(departures[d]!=-1 && arrivals[a]!=-1 && departures[d] >= arrivals[a]+turnAround) {
					trains--;
					arrivals[a] = -1; //this train is used now
					departures[d] = -1;
				}
			}
		}
		return trains;
	}
}


