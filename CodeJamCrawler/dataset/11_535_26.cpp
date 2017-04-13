import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Map;
import java.util.TreeMap;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class AirportWalkway {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader("input.txt"));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        String[] parts = br.readLine().split(" ");
        int corridorLength = Integer.parseInt(parts[0]);
        int walkSpeed = Integer.parseInt(parts[1]);
        int runSpeed = Integer.parseInt(parts[2]);
        int maxRunTime = Integer.parseInt(parts[3]);
        int numWalkways = Integer.parseInt(parts[4]);
        int[] walkwayStart = new int[numWalkways];
        int[] walkwayEnd = new int[numWalkways];
        int[] walkwaySpeed = new int[numWalkways];
        for (int j = 0; j<numWalkways; j++) {
          parts = br.readLine().split(" ");
          walkwayStart[j] = Integer.parseInt(parts[0]);
          walkwayEnd[j] = Integer.parseInt(parts[1]);
          walkwaySpeed[j] = Integer.parseInt(parts[2]);
        }
        System.out.println("Case #" + (i + 1) + ": " + solve(corridorLength, walkSpeed, runSpeed, maxRunTime, numWalkways, walkwayStart, walkwayEnd, walkwaySpeed));
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }

  }

  private static double solve(int corridorLength, int walkSpeed, int runSpeed, double maxRunTime, int numWalkways, int[] walkwayStart, int[] walkwayEnd, int[] walkwaySpeed) {
//    System.out.println("corridorLength = " + corridorLength);
//    System.out.println("walkSpeed = " + walkSpeed);
//    System.out.println("runSpeed = " + runSpeed);
//    System.out.println("maxRunTime = " + maxRunTime);
    Map<Integer, Integer> distancesBySpeed = new TreeMap<Integer, Integer>();
    int noWalkway = corridorLength;
    for (int i = 0; i<numWalkways; i++) {
      noWalkway -= (walkwayEnd[i] - walkwayStart[i]);
      int speed = walkwaySpeed[i] + walkSpeed;
      if (distancesBySpeed.containsKey(speed)) {
        distancesBySpeed.put(speed, distancesBySpeed.get(speed) + walkwayEnd[i] - walkwayStart[i]);
      } else {
        distancesBySpeed.put(speed, walkwayEnd[i] - walkwayStart[i]);
      }
    }
    distancesBySpeed.put(walkSpeed, noWalkway);
//    System.out.println("distancesBySpeed = " + distancesBySpeed);
    double totalTime = 0;
    for (Map.Entry<Integer, Integer> entry : distancesBySpeed.entrySet()) {
      int speed = entry.getKey();
      double distance = entry.getValue();
      if (maxRunTime > 0) {
        double timeForWalkway = distance / (double)(speed + runSpeed - walkSpeed);
        if (timeForWalkway <= maxRunTime) {
          maxRunTime -= timeForWalkway;
          totalTime += timeForWalkway;
        } else {
          distance -= maxRunTime * (double)(speed + runSpeed - walkSpeed);
          totalTime += maxRunTime;
          maxRunTime = 0;
          totalTime += distance/(double)speed;
        }
      } else {
        totalTime += distance/(double)speed;
      }
    }

    return totalTime;
  }
}
