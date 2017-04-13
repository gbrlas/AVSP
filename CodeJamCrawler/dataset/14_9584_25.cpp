/**
 * MagicTrick.java
 * 
 * @version 1.0
 * @since 2014-04-11
 * @author Chad Fawcett
 */

import java.util.Scanner;
import java.io.File;

public class MagicTrick {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File("A-small-attempt0.in.txt"));
            
            int caseCount = scan.nextInt();
            
            for (int i = 0; i < caseCount; i++) {
                int firstAnswer = scan.nextInt() - 1;
                int[][] firstArrangement = new int[4][4];
                for (int row = 0; row < 4; row++) {
                    for (int col = 0; col < 4; col++) {
                        firstArrangement[row][col] = scan.nextInt();
                    }
                }
                
                int secondAnswer = scan.nextInt() - 1;
                int[][] secondArrangement = new int[4][4];
                for (int row = 0; row < 4; row++) {
                    for (int col = 0; col < 4; col++) {
                        secondArrangement[row][col] = scan.nextInt();
                    }
                }
                
                //    Naive search, but shouldn't matter for small sample size
                int matchCount = 0;
                int card = 0;
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        if (firstArrangement[firstAnswer][j] == secondArrangement[secondAnswer][k]) {
                            matchCount++;
                            card = firstArrangement[firstAnswer][j];
                        }
                    }
                }
                System.out.print("Case #" + (i + 1) + ": ");
                if (matchCount == 1) {
                    System.out.println(card);
                } else if (matchCount > 1) {
                    System.out.println("Bad magician!");
                } else {
                    System.out.println("Volunteer cheated!");
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}