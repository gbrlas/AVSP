import java.util.HashMap;
import java.util.Scanner;


public class A {

  public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    int numTest = sc.nextInt();
    
    HashMap<Character,Character> hm = new HashMap<Character,Character>();
    hm.put('y', 'a');
    hm.put('n', 'b');
    hm.put('f', 'c');
    hm.put('i', 'd');
    hm.put('c', 'e');
    hm.put('w', 'f');
    hm.put('l', 'g');
    hm.put('b', 'h');
    hm.put('k', 'i');
    hm.put('u', 'j');
    hm.put('o', 'k');
    hm.put('m', 'l');
    hm.put('x', 'm');
    hm.put('s', 'n');
    hm.put('e', 'o');
    hm.put('v', 'p');
    hm.put('z', 'q');
    hm.put('p', 'r');
    hm.put('d', 's');
    hm.put('r', 't');
    hm.put('j', 'u');
    hm.put('g', 'v');
    hm.put('t', 'w');
    hm.put('h', 'x');
    hm.put('a', 'y');
    hm.put('q', 'z');
    
    String s = sc.nextLine();
    for(int i=1;i<=numTest;i++){
      s = sc.nextLine();
      System.out.print("Case #"+i+": ");
      for(int j=0;j<s.length();j++){
        if(s.charAt(j) == ' ')
          System.out.print(" ");
        else 
          System.out.print(hm.get(s.charAt(j)));
      }
      System.out.println();
    }
  }
}