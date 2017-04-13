import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by Thalley on 12-04-14.
 */
public class A {
    public static void main(String[] args){
        try {
            BufferedReader br = new BufferedReader(new FileReader("A.txt"));
            String line;
            ArrayList<String> input = new ArrayList<String>();

            while (!((line = br.readLine()) == null)){
                input.add(line);
            }

            int testcases = Integer.parseInt(input.get(0));

            for (int i = 0; i < testcases; i++) {
                String answer1 = input.get(10 * i + 1);
                ArrayList<String> row1 = new ArrayList<String>();
                for (String s : input.get(10 * i + 1 + Integer.parseInt(answer1)).split(" "))
                    row1.add(s);

                String answer2 = input.get(10 * i + 1 + 5);
                ArrayList<String> row2 = new ArrayList<String>();
                for (String s : input.get(10 * i + 1 + Integer.parseInt(answer2) + 5).split(" "))
                    row2.add(s);

                ArrayList<String> result = intersection(row1, row2);


                if (result.size() == 1)
                    System.out.println("Case #"+(i+1)+": " + result.get(0));
                else if (result.size() > 1)
                    System.out.println("Case #"+(i+1)+": " + "Bad magician!");
                else
                    System.out.println("Case #"+(i+1)+": " + "Volunteer cheated!");
            }

        } catch (Exception e) {e.printStackTrace();}
    }

    public static ArrayList<String> intersection(ArrayList<String> l1, ArrayList<String> l2){
        ArrayList<String> result = new ArrayList<String>();
        for (String s1 : l1)
            for (String s2 : l2)
                if (s1.equals(s2))
                    result.add(s1);
        return result;
    }
}
