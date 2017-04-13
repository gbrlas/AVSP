
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Namil
 */
public class QC {
    
    public static void main(String args[]){
    	
    	Scanner s=new Scanner(System.in);
        int numofLines=Integer.parseInt(s.nextLine());
        int counter=0;
        while(counter<numofLines){
        	
        	String numbersStr[]=s.nextLine().split(" ");
        	long num1=Long.parseLong(numbersStr[0]);
        	long num2=Long.parseLong(numbersStr[1]);
        	
        	int x=0;
        	
        	for(long i=num1;i<num2+1;i++){
        		if(isPalindrome(""+i)&&isSqrtPalindrome(""+i)){
                    x++; 
                 }
        	}
        	System.out.println("Case #"+(counter+1)+": "+x);
        	
        	counter++;
        }
        
    }
    public static boolean isPalindrome(String number){
        while(number.charAt(0)=='0'){
            number=number.substring(1);
        }
        String reverse="";
        for ( int i = number.length() - 1 ; i >= 0 ; i-- ){
            reverse = reverse + number.charAt(i);
        }
        
        if(number.equalsIgnoreCase(reverse)){
            return true;
        }
        return false;
        
    }
    public static boolean isSqrtPalindrome(String numberstr){
        
        long number=Long.parseLong(numberstr);
        double num=Math.sqrt(number);
        if(num%1==0.0){
        	long sqrt=(long)num;
        	//System.out.println("number "+sqrt);
        	if(isPalindrome(""+sqrt)){
                return true;
            }
        }
        return false;
    }
    
}
