import java.io.*;
import java.nio.Buffer;

/**
 * User: Stef Janssen
 * Date: 14-4-12
 * Time: 20:38
 */
public class MainClass
{
    int numberOfStrings;
    String[] allStrings;

    public static void main(String[] args)
    {
        FileWriter fstream = null;
        try
        {
            fstream = new FileWriter("solution.txt");
        } catch(IOException e)
        {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        BufferedWriter out = new BufferedWriter(fstream);
        MainClass c = new MainClass();
        c.readFile("small.txt");
        System.out.println(c.allStrings[0]);
        System.out.println(c.numberOfStrings);
        for(int i = 0; i<c.numberOfStrings; i++)
        {
            boolean lastString = i+1 == c.numberOfStrings;
            int number = i+1;
            c.writeToFile(c.createNewString(c.allStrings[i]), number,lastString, out);
        }
        try
        {
            out.close();
        } catch(IOException e)
        {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private String createNewString(String a)
    {
        String temp = "";
        for(int i = 0; i < a.length(); i++)
        {
            if(a.charAt(i) == 'a') //
                temp += 'y';
            else if(a.charAt(i) == 'b') //
                temp += 'h';
            else if(a.charAt(i) == 'c')  //
                temp += 'e';
            else if(a.charAt(i) == 'd') //
                temp += 's';
            else if(a.charAt(i) == 'e')//
                temp += 'o';
            else if(a.charAt(i) == 'f') //
                temp += 'c';
            else if(a.charAt(i) == 'g') //
                temp += 'v';
            else if(a.charAt(i) == 'h')     //
                temp += 'x';
            else if(a.charAt(i) == 'i')   //
                temp += 'd';
            else if(a.charAt(i) == 'j') //
                temp += 'u';
            else if(a.charAt(i) == 'k') //
                temp += 'i';
            else if(a.charAt(i) == 'l')  //
                temp += 'g';
            else if(a.charAt(i) == 'm')   //
                temp += 'l';
            else if(a.charAt(i) == 'n')  //
                temp += 'b';
            else if(a.charAt(i) == 'o')  //
                temp += 'k';
            else if(a.charAt(i) == 'p')   //
                temp += 'r';
            else if(a.charAt(i) == 'q') //
                temp += 'z';
            else if(a.charAt(i) == 'r')   //
                temp += 't';
            else if(a.charAt(i) == 's') //
                temp += 'n';
            else if(a.charAt(i) == 't') //
                temp += 'w';
            else if(a.charAt(i) == 'u')  //
                temp += 'j';
            else if(a.charAt(i) == 'v')   //
                temp += 'p';
            else if(a.charAt(i) == 'w') //
                temp += 'f';
            else if(a.charAt(i) == 'x')  //
                temp += 'm';
            else if(a.charAt(i) == 'y')   //
                temp += 'a';
            else if(a.charAt(i) == 'z')
                temp += 'q';
            else
                temp += ' ';
        }
        return temp;
    }

    private void readFile(String fileName)
    {
        try
        {
            FileInputStream fstream = new FileInputStream(fileName);
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            //Read File Line By Line
            int counter = 0;
            while((strLine = br.readLine()) != null)
            {
                counter ++;
                if(counter == 1)
                {
                    numberOfStrings  = Integer.parseInt(strLine);
                    allStrings = new String[numberOfStrings];
                }
                else
                {
                    allStrings[counter-2] = strLine;
                }
            }
            in.close();

        } catch(Exception e)
        {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private void writeToFile(String s, int caseNumber, boolean lastString, BufferedWriter out)
    {
        try{
        out.write("Case #" + caseNumber + ": " + s);
        if(!lastString)
        {
            out.write("\r\n");
        }
        }catch (Exception e){//Catch exception if any
        System.err.println("Error: " + e.getMessage());
        }

    }
}
