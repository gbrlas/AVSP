
/**
 * Write a description of class main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;
public class main
{
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(new BufferedReader(new FileReader("README.txt")));
        int numBoards = scan.nextInt();
        for(int i = 0; i < numBoards; i++){
            char[][] board = buildArray(scan);
            String str = processBoard(board);
            System.out.println("Case #" + (i+1) + ": " + str);

        }
    }

    public static char[][] buildArray(Scanner scan){
        char[][] board = new char[4][4];
        for(int j = 0; j <4;j++){
            String str = scan.next();
            for(int h =0; h <4; h++)
                board[j][h] = str.charAt(h);

        }
        return board;
    }

    public static String processBoard(char[][] board){
        boolean done = true;
        for(int i =0; i<4; i++){
            char[] sectionChar = new char[4];
            for(int j = 0; j<4; j++){
                sectionChar[j] = board[i][j];
            }
            int num = checkWin(sectionChar);
            if(num == 1){ 
                return "X won";}
            if(num == 2) {return "O won";}
            else if(num == 3) done = false;
        }

        for(int i =0; i<4; i++){
            char[] sectionChar = new char[4];
            for(int j = 0; j<4; j++){
                sectionChar[j] = board[j][i];
            }
            int num = checkWin(sectionChar);
            if(num == 1){  return "X won";}
            if(num == 2) {return "O won";}
            else if(num == 3) done = false;
        }
        char[] sectionChar = new char[4];
        for(int j = 0; j<4; j++){
            sectionChar[j] = board[j][j];
        }
        int num = checkWin(sectionChar);
       
        if(num == 1){  return "X won";}
        if(num == 2) {return "O won";}
        else if(num == 3) done = false;
        int inte = 0;
        char[] sectionChar2 = new char[4];
        for(int j = 3; j>=0; j--){
            sectionChar2[inte] = board[j][inte];
             inte++;
        }
        
        num = checkWin(sectionChar2);
        if(num == 1){  return "X won";}
        if(num == 2) {return "O won";}
        else if(num == 3) done = false;

        if(done){return "Draw";}
        else {return "Game has not completed";}

    }

    public static int checkWin(char[] sectionChar){
        String section = "";
        for(int i = 0; i <4; i++)
            section = section + sectionChar[i];

        if(section.equals("OOOT") || section.equals("OOTO") || section.equals("OTOO") || section.equals("TOOO") || section.equals("OOOO")){
            return 2;
        }

        if(section.equals("XXXT") || section.equals("XXTX") || section.equals("XTXX") || section.equals("TXXX") || section.equals("XXXX")){
            return 1;
        }


        else if(section.contains("."))
            return 3;
        else return 4;
    }
}

