import java.util.*;
import java.io.*;
import java.math.*;

class A {
    public static void main(String args[]) {
	Scanner scanner = new Scanner(System.in);

	int cases = scanner.nextInt();

	for (int i=0; i<cases; i++) {
	    int a, b;

	    a = scanner.nextInt();
	    b = scanner.nextInt();

	    int c = 1 << a;
	    b %= c;
	    
	    String ans;

	    if (b+1 == c) ans = "ON"; else ans = "OFF";

	    System.out.printf("Case #%d: %s\n", i+1, ans);
	}
    }
}
