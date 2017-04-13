
/**
 * File Name: SnapperChain.java
 * Google Code Jam 2010
 * @author Enrique Gonzalez
 */


import java.util.Scanner; // File Reader
import java.io.*; // Input and Output Library

public class SnapperChain {

    public static void main(String[] args) throws FileNotFoundException {

        // Input file declarations
        String fileName = "A-small-attempt1.in";
        File rFile = new File(fileName);
        Scanner inFile = new Scanner(rFile);

        // Output file declaration
        PrintStream outFile = new PrintStream(new FileOutputStream("A-small-solution.in"));

        // Variables
        String on = "ON";
        String off = "OFF";

        // sNum used to hold the exact kSnap number needed
        // to turn all snappers and the light ON
        int tCase, nSnapper, kSnap, sNumB, sNum;

        tCase = inFile.nextInt(); // Reads the number of cases to feed the loop

        for(int i = 1; i <= tCase; i++){

            // Reads the nSnapper and kSnap numbers for each case
            nSnapper = inFile.nextInt();
            kSnap = inFile.nextInt();

            if(kSnap < nSnapper){

                outFile.println("Case #" + i + ": " + off);
            }
            else{

                sNum = 1;
                
                // Loop used to get the sNum
                // sNum: Exact kSnap number needed for the light to be ON
                for(int x = 1; x < nSnapper; x++){

                    sNum = 2*sNum + 1;
                }

                
                if(kSnap == sNum){

                    outFile.println("Case #" + i + ": " + on);
                }
                else if(kSnap < sNum){

                    outFile.println("Case #" + i + ": " + off);
                }
                else{

                    sNumB = sNum;

                    // If kSnap is bigger than sNum then for the light to
                    // be ON again sNum needs to be equal to sNum + 1
                    while(sNumB < kSnap){
                        
                        sNumB = sNumB + sNum + 1;
                    }

                    if(sNumB == kSnap){

                        outFile.println("Case #" + i + ": " + on);
                    }
                    else{

                        outFile.println("Case #" + i + ": " + off);
                    }
                }
            }
        }
    }

}
