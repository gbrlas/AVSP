import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Googlerese
{
    static char[] alfabet = new char[] { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x',
                                         'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
                                         'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q', ' '};
        
    /**
     * @param args
     * @throws IOException 
     */
    public static void main(String[] args) throws IOException
    {
        FileWriter fileWriter = new FileWriter("out.txt");
        PrintWriter printWriter = new PrintWriter(fileWriter);
        int index = 0;
        
        Scanner scanner = new Scanner(new File(args[0]));
       
        scanner.nextLine();
        while (scanner.hasNextLine())
        {
            String line = scanner.nextLine().toLowerCase();
            String newLine = "";
            char[] linesc = line.toCharArray();
            for (int i = 0; i < linesc.length; i++)
            {
                int value = (int) linesc[i];
                newLine += alfabet[value == 32 ? (26): value - 97];
            }
            printWriter.println("Case #" + (++index) + ": " + newLine);
        
        }        // TODO Auto-generated method stub
        printWriter.close();
    }

}
