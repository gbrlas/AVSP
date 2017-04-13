import java.io.BufferedWriter;
import java.util.*;

//port java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;	
//import java.lang.Math;
//import java.util.ArrayList;
//import java.util.HashMap;
import java.math.BigInteger;

public class Problem3new
{

	//	static BigInteger[][] palins = new BigInteger[2][10];
	static int inpalin=0; //index of palin to compute next palin
	//	static int outpalini=2,outpalinj=0; //index of output palin to be stored*/
	static ArrayList<BigInteger> bigpalin = new ArrayList<BigInteger>();
	static ArrayList<BigInteger> bigpalinout = new ArrayList<BigInteger>();



	public static void getNextPalin()
	{
		//check it in palin is even digits
		String palin =(bigpalin.get(inpalin)).toString();

		//System.out.println("palin="+palin);
		int digits = palin.length();
		int rem= digits%2;
		int i=0;
		if(rem==0)//it is even digit then add 0-9 in middle
		{
			String firsthalf= palin.substring(0, digits/2);
			String secondhalf= palin.substring( digits/2);
			//System.out.println("Even digit palin. current palin ="+ palin +" first half="+firsthalf+" seconhalf="+secondhalf);
			for (i=0;i<3;i++)
			{
				BigInteger temp =new BigInteger(firsthalf.concat(i+"").concat(secondhalf));
				//System.out.println(temp.toString());
				bigpalin.add(temp);
			}
			inpalin++;

		}
		else
		{
			String firsthalf= palin.substring(0, digits/2);
			String middle =palin.substring( digits/2,digits/2+1);
			String secondhalf= palin.substring( digits/2+1);
			//System.out.println("Odd digit palin. current palin ="+ palin +" first half="+firsthalf+" middle"+middle+" seconhalf="+secondhalf);

			BigInteger temp =new BigInteger(firsthalf.concat(middle).concat(middle).concat(secondhalf));
			//System.out.println(temp.toString());
			bigpalin.add(temp);


			inpalin++;

		}
	//	System.out.println("inpalin="+inpalin);

	}

	public static int checkPalin(BigInteger bi) //returns 1 when palindrome
	{
		String temp = bi.toString();
		int  e=0;
		e=temp.length()-1;
		int cnt=temp.length()/2 ;
		int i=0,success=1;
		for (i=0;i<cnt;i++)
		{
			if(temp.charAt(i)==temp.charAt(e-i))
			{
				continue;
			}
			else
			{
				success = 0;
				break;
			}
		}

		return success;


	}
	
	public static void main(String args[])
	{

		bigpalin.add(new BigInteger("1"));
		bigpalin.add(new BigInteger("2"));
		bigpalin.add(new BigInteger("3"));
	/*	bigpalin.add(new BigInteger("4"));
		bigpalin.add(new BigInteger("5"));
		bigpalin.add(new BigInteger("6"));	
		bigpalin.add(new BigInteger("7"));
		bigpalin.add(new BigInteger("8"));
		bigpalin.add(new BigInteger("9"));*/
		bigpalin.add(new BigInteger("11"));
		bigpalin.add(new BigInteger("22"));
	/*	bigpalin.add(new BigInteger("33"));
		bigpalin.add(new BigInteger("44"));
		bigpalin.add(new BigInteger("55"));
		bigpalin.add(new BigInteger("66"));
		bigpalin.add(new BigInteger("77"));
		bigpalin.add(new BigInteger("88"));
		bigpalin.add(new BigInteger("99"));	*/
		inpalin=3;

		getNextPalin();

		//System.out.println("calling again next oalin");

		getNextPalin();

		//System.out.println("calling again next palin 10 times");
		int k=0;
		for(k=0;k<1210224;k++)
			getNextPalin();

		//compute palin
		// compute its square
		//chek its palin
		// if yes count it and print it
		int index=0;
		String out="";
		String outpalin="";
		BufferedWriter bufferedWriter = null;
		BufferedWriter bufferedWriter1 = null;
		BufferedWriter bufferedWriter2 = null;
		try { 
			String str="",output2="";



			//Construct the BufferedWriter object
			bufferedWriter = new BufferedWriter(new FileWriter("fairnsq.txt"));
			bufferedWriter1 = new BufferedWriter(new FileWriter("palin.txt"));
			bufferedWriter2 = new BufferedWriter(new FileWriter("outputtest.txt"));


			while (index < 1210224)
			{
				BigInteger p = bigpalin.get(index);
				outpalin=p.toString()+"\n";
				bufferedWriter1.write(outpalin);
				BigInteger p2 = p.multiply(p);
				int check=checkPalin(p2);
				if(check==1)
				{
					//System.out.println("SUCCESSS FAIR AND SQUARE IS "+ p2.toString());
					bigpalinout.add(p2);
					out=p2.toString()+"\t"+p.toString()+"\n";
					bufferedWriter.write(out);
				}
				/*	else
				System.out.println("not palin "+ p2.toString());
				 */		index++;
			}




			String filename = args[0];
			BufferedReader in = new BufferedReader(new FileReader(filename));
			int testcase=0 ;
			int k1=0;
			str = in.readLine();
			testcase = Integer.parseInt(str);
			for (k1=0;k1 <testcase; k1++)
			{
				BigInteger n;
				BigInteger m;

				str = in.readLine(); //read n m
				String str1= str.substring(0, str.indexOf(' '));
				n = new BigInteger(str1);
				str1= str.substring( str.indexOf(' ')+1);
				m = new BigInteger(str1);

				int g=0;
				int count=0;

				while ( bigpalinout.get(g).compareTo(n)<0)
				{
					g++;
				}

				while( bigpalinout.get(g).compareTo(m)<=0 )
				{
					count++;
					g++;
				}
				output2="Case #"+(k1+1)+": "+count+"\n";
				bufferedWriter2.write(output2);
			} 
			}
			catch (IOException ex) {               ex.printStackTrace();} 
			finally {
				//Close the BufferedWriter
				try {
					if (bufferedWriter != null) {
						bufferedWriter.flush();
						bufferedWriter.close();
					}
				} catch (IOException ex) {
					ex.printStackTrace();
				}
				try {
					if (bufferedWriter1 != null) {
						bufferedWriter1.flush();
						bufferedWriter1.close();
					}
				} catch (IOException ex) {
					ex.printStackTrace();
				}
				try {
					if (bufferedWriter2 != null) {
						bufferedWriter2.flush();
						bufferedWriter2.close();
					}
				} catch (IOException ex) {
					ex.printStackTrace();
				}

			}
		



		}
	}
	
