import java.util.Scanner;


public class Googlerese {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        char[] map = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
        
        /* mapping generated from example (and manually ordered, filled)
        String a = in.nextLine();
        String b = in.nextLine();
        for (int i = 0; i < a.length(); i++) {
            char ca = a.charAt(i);
            char cb = b.charAt(i);
            
            if (ca != ' ') {
                System.out.printf("map[%d] = '%c';\n", ca - 'a', cb);
            }
        }*/

        int num = in.nextInt();
        in.nextLine(); // empty line
        for (int i = 0; i < num; i++) {
            StringBuilder sb = new StringBuilder();
            for (char ch : in.nextLine().toCharArray()) {
                if (ch >= 'a' && ch <= 'z') {
                    sb.append(map[ch - 'a']);                    
                }
                else {
                    sb.append(ch);
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + sb.toString());
        }
    }

}
