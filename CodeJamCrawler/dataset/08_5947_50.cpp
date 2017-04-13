import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class TrainTime {

	
	public Long[] countTrains(Integer turnAround,String[] aScheds, String[] bScheds){
		Station a = new Station();
		for (String s: aScheds){
			a.times.add(new Time(s));
		}
		Station b = new Station();
		for (String s: bScheds){
			b.times.add(new Time(s));
		}
		Collections.sort(a.times);
		Collections.sort(b.times);
		//System.out.println(a.times);
		//System.out.println(b.times);
		while (a.times.size()+b.times.size()!=0){
			Station cur;
			Station oth;
			if (a.times.size()==0){ 
				cur=b;
				oth=a;
			} else if (b.times.size()==0){
				cur=a;
				oth=b;
			} else {
				cur=a.times.get(0).startTime<b.times.get(0).startTime? a: b;
				oth=a.times.get(0).startTime<b.times.get(0).startTime? b: a;
			}
			//System.out.println("cur = "+cur.times+" "+cur.trains+",oth = "+oth.times+" "+oth.trains);
			if (cur.trains.size()!=0&&cur.trains.get(0).willRunAt<=cur.times.get(0).startTime){
				Train t=cur.trains.get(0);
				cur.trains.remove(0);
				t.willRunAt=cur.times.get(0).endTime+turnAround;
				oth.trains.add(t);
				Collections.sort(oth.trains);
				cur.times.remove(0);
			} else {
				Train t = new Train(cur.times.get(0).endTime+turnAround);
				cur.count++;
				oth.trains.add(t);
				Collections.sort(oth.trains);
				cur.times.remove(0);
			}
				
		}
		
		return new Long[]{a.count,b.count};
	}
	
	public class Station {
		
		public List<Time> times = new ArrayList<Time>();
		
		public List<Train> trains = new ArrayList<Train>();
		
		public long count =0;
		
		
	}

	public class Train implements Comparable<Train>{
		public Long willRunAt;

		public Train(Long willRunAt){
			this.willRunAt=willRunAt;
		}
		public int compareTo(Train o) {
			return this.willRunAt.compareTo(o.willRunAt);
		}
		/* (non-Javadoc)
		 * @see java.lang.Object#toString()
		 */
		@Override
		public String toString() {
			return willRunAt.toString();
		}
		
		
	}
	
	public class Time implements Comparable<Time>{
		
		public Long startTime;
		
		public Long endTime;
		
		public Time(String time){
			String[] spls= time.split(" ");
			this.startTime=getTime(spls[0]);
			this.endTime= getTime(spls[1]);
		}
		
		private Long getTime(String t){
			String[] spls=t.split(":");
			return (Long.valueOf(spls[0])*60)+Long.valueOf(spls[1]);
		}

		public int compareTo(Time o) {
			if (this.startTime.compareTo(o.startTime)!=0){
				return this.startTime.compareTo(o.startTime);
			} else {
				return this.endTime.compareTo(o.endTime);
			}
		}

		/* (non-Javadoc)
		 * @see java.lang.Object#toString()
		 */
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return startTime+" "+endTime;
		}
		
		
		
	}
	
	public static void main(String[] args) throws FileNotFoundException{
		TrainTime tt = new TrainTime();
		
		Scanner scan = new Scanner(new File("Input.txt"));
        PrintWriter pw = new PrintWriter("Output.txt");
        Integer count =new Integer(scan.nextLine());
        for (int i=0;i<count;i++){
        	Integer turnAround = new Integer(scan.nextLine());
        	String[] cs=(scan.nextLine()).split(" ");
        	Integer aCount = new Integer(cs[0]);
        	Integer bCount = new Integer(cs[1]);
        	String[] aScheds = new String[aCount];
        	String[] bScheds = new String[bCount];
        	for (int j=0;j<aCount;j++){
        		aScheds[j]= scan.nextLine();
        	}
        	for (int j=0;j<bCount;j++){
        		bScheds[j]= scan.nextLine();
        	}
        	Long[] res = tt.countTrains(turnAround, aScheds, bScheds);
        	pw.write("Case #"+(i+1)+": "+res[0]+" "+res[1]+"\n");
        }
        pw.close();
        scan.close();

		
	}
}


