import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;

public class MainClass {

	/**
	 * The entry point of the application
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		// Read the input file 
		String input_file = "B-large.in.txt";
		BufferedReader reader = new BufferedReader(new FileReader(input_file));
		int num_cases = Integer.parseInt(reader.readLine());
		
		// Load all the schedules from the input file.
		TrainTimetable[] tables = new TrainTimetable[num_cases];
		for(int i=0; i<num_cases; i++){
			tables[i] = new TrainTimetable(reader);
		}
		
		// Open the output file ready for writing
		String output_file = "B-small.out";
		FileOutputStream file_out = new FileOutputStream(output_file);
		
		// The logic
		for(int i=0; i<num_cases; i++){
			TrainTimetable timetable = tables[i];
			int num_trains_from_A = 0;
			int num_trains_from_B = 0;
			int turn_around_time = timetable.turnAroundTime;
			// Find the number of trains to start from A
			
			for(int trip_a=0; trip_a<timetable.numTripsFromA; trip_a++){
				boolean isArrived = false;
				String departure_time = timetable.tripsFromA[trip_a].departureTime;
				// Check if there is any train arrived in station A from B
				for(int trip_b=0; trip_b<timetable.numTripsFromB; trip_b++){
					if(timetable.tripsFromB[trip_b].reserved) continue;
					String arrival_time = timetable.tripsFromB[trip_b].arrivalTime;
					int hour = Integer.parseInt(arrival_time.split(":")[0]);
					int minutes = Integer.parseInt(arrival_time.split(":")[1]);
					minutes += turn_around_time;
					if(minutes>=60){
						minutes -= 60;
						hour++;
					}
					String hh = (hour<=9)?"0"+hour:""+hour;
					String mm = (minutes<=9)?"0"+minutes:""+minutes;
					String ready_for_departure_time = hh+":"+mm; 
					System.out.println(departure_time+"|"+ready_for_departure_time+" = "+departure_time.compareTo(ready_for_departure_time));
					if(departure_time.compareTo(ready_for_departure_time)>=0){
						isArrived = true;
						timetable.tripsFromB[trip_b].reserved = true;
						//timetable.tripsFromB[trip_b].arrivalTime = "00:00";
						trip_b = timetable.numTripsFromB;
					}
				}
				if(!isArrived)num_trains_from_A++;
			}
			// Find the number of trains to start from B
			for(int trip_b=0; trip_b<timetable.numTripsFromB; trip_b++){
				boolean isArrived = false;
				String departure_time = timetable.tripsFromB[trip_b].departureTime;
				// Check if there is any train arrived in station B from A
				isArrived = false;
				for(int trip_a=0; trip_a<timetable.numTripsFromA; trip_a++){
					if(timetable.tripsFromA[trip_a].reserved) continue;
					String arrival_time = timetable.tripsFromA[trip_a].arrivalTime;
					int hour = Integer.parseInt(arrival_time.split(":")[0]);
					int minutes = Integer.parseInt(arrival_time.split(":")[1]);
					minutes += turn_around_time;
					if(minutes>=60){
						minutes -= 60;
						hour++;
					}
					String hh = (hour<=9)?"0"+hour:""+hour;
					String mm = (minutes<=9)?"0"+minutes:""+minutes;
					String ready_for_departure_time = hh+":"+mm; 
					System.out.println(departure_time+"|"+ready_for_departure_time+" = "+departure_time.compareTo(ready_for_departure_time));
					if(departure_time.compareTo(ready_for_departure_time)>=0){
						isArrived = true;
						timetable.tripsFromA[trip_a].reserved = true;
						//timetable.tripsFromA[trip_a].arrivalTime = "00:00";
						trip_a = timetable.numTripsFromA;
					}
				}
				if(!isArrived)num_trains_from_B++;
			}
			
			// Now write the output to the file
			String output = "Case #"+(i+1)+": "+num_trains_from_A+" "+num_trains_from_B+"\r\n";
			file_out.write(output.getBytes());
		}
	}
}
