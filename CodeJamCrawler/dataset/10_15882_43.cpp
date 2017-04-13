
/**
 * File Name: ThemePark.java
 * Google Code Jam 2010
 * @author Enrique Gonzalez
 */


import java.util.Scanner; // File Reader
import java.io.*; // Input and Output Library

// The ArrayQueue class is part of the
// jss2 library creared by Lewis/Chase
import jss2.ArrayQueue;


public class ThemePark {

    public static void main(String[] args) throws FileNotFoundException{

        // Input file declarations
        String fileName = "C-small-attempt0.in";
        File rFile = new File(fileName);
        Scanner inFile = new Scanner(rFile);

        // Output file declaration
        PrintStream outFile = new PrintStream(new FileOutputStream("C-small-solution.in"));

        // Variables
        // eMoney: Holds the Roller Coaster earnings
        // lSeats: Holds the amount of seats left after each group
        // lGroup: Holds the number of groups left for each run
        // fGroup: Holds the first group in the queue
        int tCase, rRun, kHold, nGroup, eMoney, lSeats, lGroup, fGroup;
        ArrayQueue<Integer> gSize; // The Queue object used to hold the group size

        tCase = inFile.nextInt();

        for(int i = 1; i <= tCase; i++){

            eMoney = 0;
            rRun = inFile.nextInt();
            kHold = inFile.nextInt();
            nGroup = inFile.nextInt();

            gSize = new ArrayQueue(nGroup);

            // Store each group size in the queue
            for(int x = 0; x < nGroup; x++){

                gSize.enqueue(inFile.nextInt());
            }

            for(int x = 0; x < rRun; x++){

                // Initialize lGroup and lSeats
                lGroup = nGroup;
                lSeats = kHold;

                // Fill the Roller Coaster until there are no
                // more groups left or the seats available
                // are not enough for the next group
                while(lGroup > 0){

                    if(gSize.first() <= lSeats){

                        fGroup = gSize.dequeue();
                        lSeats = lSeats - fGroup;
                        eMoney = eMoney + fGroup;
                        gSize.enqueue(fGroup);
                        lGroup--;
                    }
                    else{

                        break;
                    }
                }
            }

            // Print output to file
            outFile.println("Case #" + i + ": " + eMoney);
        }
    }

}
