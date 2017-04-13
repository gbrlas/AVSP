
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;
public class main
{
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(new BufferedReader(new FileReader("README.txt")));
        int numCases = scan.nextInt();
        for(int i = 0; i < numCases; i++){
            int bound1 = scan.nextInt();
            int bound2 = scan.nextInt();
            System.out.println("Case #" + (i+1) + ": " + findAmount(bound1, bound2));
            
    }
}
    public static int findAmount(int b1, int b2){
        int amount = 0;
        for(int i = b1; i <= b2; i++){
            if(isFairAndSquare(i)) amount++;
        }
        return amount;
}
public static boolean isFairAndSquare(int i){
    int length = String.valueOf(i).length();
    String str1 = String.valueOf(i);
    String str = "";
    for(int j = length -1; j >= 0; j--){
        str = str + str1.charAt(j);
    }
    if(!str1.equals(str)) return false;
    int str3 = (int)(Math.sqrt(i));
    if(str3 * str3 != i) return false;
    length = String.valueOf(str3).length();
    String string3 = String.valueOf(str3);
    String string = "";
    for(int j = length -1; j >= 0; j--){
        string = string + string3.charAt(j);
    }
    if(!string3.equals(string))return false;
    
    return true;
    
    
    
}
}
