import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;

public final class Round_1B {
	public static String INPUT_FILE = "C:\\Users\\Jonathanasdf\\Desktop\\B-large.in";
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
	// TODO Auto-generated method stub
		 File inFile  = new File(INPUT_FILE);
		 File outFile = new File("C:\\Users\\Jonathanasdf\\Desktop\\Output.txt");  
		 BufferedReader reader = new BufferedReader(new FileReader(inFile));
	     BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));
	     String line = null;
	     int lineNumber = 0;
	     String result = "";
	     reader.readLine();
	     System.out.println("Starting program.");
	     while ((line=reader.readLine()) != null) {
	    	 lineNumber++;
		 int numLines = Integer.parseInt(line);
		 String[] lines = new String[numLines];
		 for (int i=0; i<numLines; i++) {
 			lines[i] = reader.readLine();
		 }
	    	 result += "Case #" + lineNumber + ": " + solve(lines) + "\r\n";
	    	 System.out.println("Done parsing: " + lineNumber);
	     }
	     writer.write(result);
	     writer.newLine();
	     reader.close();  
	     writer.close(); 
	}
	
	public static String solve(String[] lines) {

		double [][] pos = new double[lines.length][3];
		double [][] vels = new double[lines.length][3];
		for (int i=0; i<lines.length; i++) {
			String[] inputs = lines[i].split(" ");
			for (int j=0; j<3; j++) {
				pos[i][j] = Double.parseDouble(inputs[j]);
				vels[i][j] = Double.parseDouble(inputs[j+3]);
			}
		}
		double[] startPos = averageVector(pos);
		double startDistance = Math.sqrt(dot(startPos, startPos));
		double[] vel = averageVector(vels);

		if (vel[0] == 0 && vel[1] == 0 && vel[2] == 0) {
			return startDistance + " 0";
		}
		
		double t = (-startPos[0]*vel[0] - startPos[1] * vel[1] - startPos[2] * vel[2]) / dot(vel,vel);

		if (t < 0) {
			return startDistance + " 0";
		}
	
		double[] point = new double[3];
		for (int i=0; i<3; i++) {
			point[i] = startPos[i]+t*vel[i];
		}
		double distance = Math.sqrt(dot(point, point));

		if (distance >= startDistance) {
			t = 0;
			distance = startDistance;
		}

		return distance + " " + t;
		
	}

	private static double dot( double[] point1, double[] point2) {
		return point1[0]*point2[0]+point1[1]*point2[1]+point1[2]*point2[2];
	}

	private static double[] averageVector(double[][] pos) {
		double x =0, y=0, z=0;
		for (int i=0; i<pos.length; i++) {
			x += pos[i][0];
			y += pos[i][1];
			z += pos[i][2];
		}
		double[] result = new double[3];
		result[0] = x / pos.length;
		result[1] = y / pos.length;
		result[2] = z / pos.length;
		return result;
	}
}
