import java.io.*;
/**
 * Write a description of class robot here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class A
{
  public static void main(String args[])
  {
    BufferedWriter bufferedWriter = null;
    try
    {
       FileInputStream fstream = new FileInputStream("textfilelarge.in");
       DataInputStream in = new DataInputStream(fstream);
       BufferedReader br = new BufferedReader(new InputStreamReader(in));
       bufferedWriter = new BufferedWriter(new FileWriter("Output.txt"));
       String strLine = br.readLine();
       int x = 1;
       strLine = br.readLine();
       while (strLine != null)
       {
           int seconds = 0;
           int Op = 1;
           int Bp = 1;
           int numKeys = 0;
           String num = "";
           while (strLine.charAt(0) != ' ')
           {
               num = num + strLine.charAt(0);
               strLine = strLine.substring(1);
           }
           numKeys = Integer.parseInt(num);
           int[] positionO = new int[numKeys];
           int[] positionB = new int[numKeys];
           int colorIndex = 0;
           int positionIndexO = 0;
           int positionIndexB = 0;
           Character[] color = new Character[numKeys];
           Boolean flag = false;
           Boolean orange = false;
           Boolean blue = false;
           strLine = strLine.substring(1);
           String temp = "";
           while (strLine.length() > 1 || orange || blue)
           {
               if (strLine.charAt(0) == 'O')
               {
                  color[colorIndex] = 'O';
                  strLine = strLine.substring(2);
                  colorIndex++;
                  orange = true;
               }
               else if (strLine.charAt(0) == 'B')
               {
                  color[colorIndex] = 'B';
                  strLine = strLine.substring(2);
                  colorIndex++;
                  blue = true;
               }
               else if (strLine.charAt(0) != 'O' && strLine.charAt(0) != 'B')
               {
                  temp = temp + strLine.charAt(0);
                  if (strLine.length() > 1)
                  {
                     strLine = strLine.substring(1);
                     if (strLine.charAt(0) != ' ')
                     {
                         temp = temp + strLine.charAt(0);
                         if (strLine.length() > 1)
                         {
                             strLine = strLine.substring(1);
                             if (strLine.charAt(0) != ' ')
                             {
                                 temp = temp + strLine.charAt(0);
                                 if (strLine.length() > 1)
                                 {
                                     strLine = strLine.substring(1);
                                 }
                             }
                         }
                     }
                  }
                  if (strLine.length() > 1)
                  {
                      strLine = strLine.substring(1);
                  }
                  if (blue)
                  {
                     positionB[positionIndexB] = Integer.parseInt(temp);
                     positionIndexB++;
                     temp = "";
                     blue = false;
                  }
                  if (orange)
                  {
                     positionO[positionIndexO] = Integer.parseInt(temp);
                     positionIndexO++;
                     temp = "";
                     orange = false;
                  }
               }
           }
           int andy = 0;
           int tsao = 0;
           int puChun = 0;
           Boolean toggle = false;
           while (!flag)
           {
               if (Op != positionO[andy])
               {
                   if (Op < positionO[andy])
                   {
                      Op++;
                   }
                   else
                   {
                       Op--;
                   }
               }
               else if (color[puChun] == 'O')
               {
                   andy++;
                   toggle = true;
               }
               if (Bp != positionB[tsao])
               {
                   if (Bp < positionB[tsao])
                   {
                      Bp++;
                   }
                   else
                   {
                      Bp--;
                   }
               }
               else if (color[puChun] == 'B')
               {
                   tsao++;
                   toggle = true;
               }
               if (toggle)
               {
                   puChun++;
                   toggle = false;
               }
               seconds++;
               if (color.length <= puChun)
               {
                   flag = true;
               }
           }
           bufferedWriter.write("Case #" + x + ": " + seconds);
           bufferedWriter.newLine();
           x++;
           strLine = br.readLine();
       }
       in.close();
    }
    catch (Exception e)
    {
      System.err.println("Error: " + e.getMessage());
    }
    finally 
    {
       try 
       {
          if (bufferedWriter != null) 
          {
              bufferedWriter.flush();
              bufferedWriter.close();
          }
       } 
       catch (IOException ex) 
       {
           ex.printStackTrace();
       }
    }
  }
}
