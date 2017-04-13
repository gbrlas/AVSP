
import java.io.*;
import java.util.*;

public class Q1 {
    HashMap<String, String> googlerese;
    
    public static void main(String[] args) {
        Q1 q = new Q1();
        q.makeDict();
        q.answer();
    }
    
    public void makeDict() {
        googlerese = new HashMap<String, String>();
        String[] from, to;
        String c1, c2, hold;
        hold = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh "
                + "wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr "
                + "lkgc jv";
        from = hold.split(" ");
        hold = "our language is impossible to understand there are twenty six "
                + "factorial possibilities so it is okay if you want to just "
                + "give up";
        to = hold.split(" ");
        
        for(int i = 0; i < from.length; i++) {
            for(int a = 0; a < from[i].length(); a++) {
                c1 = from[i].substring(a, a+1).toLowerCase();
                if(!googlerese.containsKey(c1)) {
                    c2 = to[i].substring(a, a+1).toLowerCase();
                    googlerese.put(c1, c2);
                }
            }
        }
                
        googlerese.put("q", "z");
        googlerese.put("z", "q");
    }
    
    public void answer(){
        read("A-small-attempt0.txt", "Q1_output.txt");
    }
    
    public void test(){
        read("Test1_input.txt", "Test1_output.txt");
    }
    
    public void read(String readFrom, String writeTo){
        try{
            Scanner in = new Scanner(new File(readFrom));
            File f = new File(writeTo);
            FileWriter fw = new FileWriter(f);
            int T = Integer.parseInt(in.nextLine());
            String[] words;
            String answer, c, word;
            
            for(int i = 1; i <= T; i++) {
                words = in.nextLine().split(" ");
                answer = "";
                for(int _ = 0; _ < words.length; _++) {
                    word = words[_];
                    for(int a = 0; a < word.length(); a++) {
                        c = word.substring(a, a+1);
                        if(Character.isUpperCase(c.charAt(0))) {
                            answer += googlerese.get(c).toUpperCase();
                        }else {
                            answer += googlerese.get(c);
                        }
                    }
                    if(_ + 1 < words.length)
                        answer += " ";
                }
                answer.trim();
                if(i + 1 <= T)
                    answer += "\r\n";
                fw.write("Case #" + i + ": " + answer);
            }
            
            
            fw.close();
        }catch(Exception ex) {
            System.out.println(ex);
        }
    }
    
}
