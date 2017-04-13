import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Scanner;


public class TrainTimetable {
    public static void main(String[] args) throws IOException {
        File input = new File("/home/visibletrap/Desktop/B-small-attempt2.in");
        FileWriter output = new FileWriter(new File("/home/visibletrap/Desktop/B-small-attempt2.out"));
        Scanner inputSC = new Scanner(input);
        int numOfTestCase = Integer.parseInt(inputSC.nextLine());

        for(int i=0;i<numOfTestCase;i++){
            int turnAroundTime = Integer.parseInt(inputSC.nextLine());
            int a = 0;
            int b = 0;
            int numOfA = inputSC.nextInt();
            int numOfB = inputSC.nextInt();
            PriorityQueue<Integer> departA = new PriorityQueue<Integer>();
            PriorityQueue<Integer> departB = new PriorityQueue<Integer>();
            PriorityQueue<Integer> arriveA = new PriorityQueue<Integer>();
            PriorityQueue<Integer> arriveB = new PriorityQueue<Integer>();
            inputSC.nextLine();
            for(int j=0;j<numOfA;j++){
                String line = inputSC.nextLine();
                int depA = Integer.parseInt(line.substring(0, 2))*60;
                depA += Integer.parseInt(line.substring(3, 5));
                departA.add(new Integer(depA));
                int arrB = Integer.parseInt(line.substring(6, 8))*60;
                arrB += Integer.parseInt(line.substring(9, 11));
                arrB += turnAroundTime;
                arriveB.add(new Integer(arrB));
            }
            for(int j=0;j<numOfB;j++){
                String line = inputSC.nextLine();
                int depB = Integer.parseInt(line.substring(0, 2))*60;
                depB += Integer.parseInt(line.substring(3, 5));
                departB.add(new Integer(depB));
                int arrA = Integer.parseInt(line.substring(6, 8))*60;
                arrA += Integer.parseInt(line.substring(9, 11));
                arrA += turnAroundTime;
                arriveA.add(new Integer(arrA));
            }

            while (departA.size()>0){
                if(arriveA.size()==0){
                    a += departA.size();
                    break;
                }
                Integer toDepart = departA.poll();
                Integer nextArrive = arriveA.peek();
                if(toDepart.compareTo(nextArrive) < 0){
                    a++;
                }else{
                    arriveA.poll();
                }
            }
            while (departB.size()>0){
                if(arriveB.size()==0){
                    b += departB.size();
                    break;
                }
                Integer toDepart = departB.poll();
                Integer nextArrive = arriveB.peek();
                if(toDepart.compareTo(nextArrive) < 0){
                    b++;
                }else{
                    arriveB.poll();
                }
            }
            output.write("Case #" +(i+1) +": " +a +" " +b+"\n");
        }
        output.close();
    }

}
