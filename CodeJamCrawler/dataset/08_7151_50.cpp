import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;



public class SavingTheUniverse {
    public static void main(String[] args) throws IOException {
        File input = new File("/home/visibletrap/Desktop/A-large.in");
        FileWriter output = new FileWriter(new File("/home/visibletrap/Desktop/A-large.out"));
        Scanner inputSC = new Scanner(input);
        int numOfTestCase = Integer.parseInt(inputSC.nextLine());
        System.out.println("TestCase = " +numOfTestCase);
        for(int i=0;i<numOfTestCase;i++){
            int answer = 0;
            boolean end = true;
            int numOfSearchEngine = Integer.parseInt(inputSC.nextLine());
            System.out.println("SE = " +numOfSearchEngine);
            ArrayList<String> searchEngine = new ArrayList<String>();
            for(int j=0;j<numOfSearchEngine;j++){
                String currentSearchEngine = inputSC.nextLine();
                searchEngine.add(currentSearchEngine);
            }
            int numOfQuery = Integer.parseInt(inputSC.nextLine());
            System.out.println("Queries = " +numOfQuery);
            ArrayList<String> query = new ArrayList<String>();
            HashSet<String> querySet = new HashSet<String>();
            for(int k=0;k<numOfQuery;k++){
                String currentQuery = inputSC.nextLine();
                query.add(currentQuery);
                querySet.add(currentQuery);
            }
            for(String se : searchEngine){
                if(querySet.contains(se))end = false;
            }
            if(!end){
                HashSet<String> set = new HashSet<String>();
                int counter = 0;
                for(String q : query){
                    if(!set.contains(q)){
                        set.add(q);
                        counter++;
                    }
                    if(counter == numOfSearchEngine){
                        answer++;
                        set.clear();
                        counter = 1;
                        set.add(q);
                    }
                }
            }
            output.write("Case #" +(i+1) +": " +answer +"\n");
            System.out.println("---------------------------------------------");
        }
        output.close();
    }

}
