/**
 * @(#)Magician.java
 *
 *
 * @author Jiahua Zhang
 * @version 1.00 2014/4/12
 */
 
 import java.util.Scanner;
 import java.io.File;
 import java.io.FileNotFoundException;
 import java.io.IOException;


public class Magician {

    public static void main(String args[]) throws FileNotFoundException {
    	Scanner attempt = new Scanner(new File("A-small-attempt0.in"));
    	int rounds = attempt.nextInt();
    	Magic card = new Magic();
    	for (int i = 1; i <= rounds; i++){
    		card.setCurrent(i);
    		int First = attempt.nextInt();
    		int [] list = new int [16];
    		for (int j = 0; j < 16; j++){
    			list[j] = attempt.nextInt();
    		}
    		int Second = attempt.nextInt();
    		card.Row(First, Second);
    		int [] newList = new int [16];
    		for (int k = 0; k < 16; k++){
    			newList [k] = attempt.nextInt();
    		}
    		int index1 = (First - 1) * 4;
    		int index2 = (Second - 1) * 4;
    		card.magic(list[index1], list[index1+1], list[index1+2], list[index1+3], newList[index2], newList[index2+1], newList[index2+2], newList[index2+3]);
    		System.out.println(card.getOutcome());   		
    		}
    }
    
    
}

class Magic{
	int current, row1, row2, num1, num2, num3, num4, shu1, shu2, shu3, shu4;
	
	public void setCurrent(int c){
		current = c;
	}
	
	public String getCase(){
		return "Case #" + current;
	}
	
	public void Row(int one, int two){
		row1 = one;
		row2 = two;
	}
	
	public void magic(int one, int two, int three, int four, int five, int six, int seven, int eight){
		num1 = one;
		num2 = two;
		num3 = three;
		num4 = four;
		shu1 = five;
		shu2 = six;
		shu3 = seven;
		shu4 = eight;
	}
	
	public String getOutcome(){
		String temp = "Case #" + current + ": ";
		int poss = 0;
		int number = 0;
		if(num1 == shu1 | num2 == shu1 | num3 == shu1 | num4 == shu1){
			poss++;
			number = shu1;
		}
		if(num1 == shu2 | num2 == shu2 | num3 == shu2 | num4 == shu2){
			poss++;
			number = shu2;
		}
		if(num1 == shu3 | num2 == shu3 | num3 == shu3 | num4 == shu3){
			poss++;
			number = shu3;
		}
		if(num1 == shu4 | num2 == shu4 | num3 == shu4 | num4 == shu4){
			poss++;
			number = shu4;
		}
		if(poss == 0)
			temp = temp + "Volunteer cheated!";
		else if(poss > 1)
			temp = temp + "Bad magician!";
		else
			temp = temp + number;
		return temp;
	}
}