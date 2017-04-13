
public class RandomByteTest
{
	/*testing random shit from random.org
	
	1. xor is commutative
	2. there is a solution iff xor of everything = 0
	3. if xor everything = 0, you can give only smallest to patrick
	
	*/
	public static void main(String[] args)
	{
		String[] k =  {"10001001", "01111101", "00101100", "11101100", "11111101", "01111101",
						"10110100", "00010010", "10111001", "01111001", "11011010", "01100100",
						"10100010", "01011010", "00110001", "10101101", "01010000", "01101100",
						"11000100", "11110000"};
		
		int t = 0;
		int total = 0;
		for(String x: k)
		{
			int f = Integer.parseInt(x ,2);
			System.out.println(f);
			t = intXOR(t, f);
			total = total + f;
		}
		System.out.println();
		System.out.println(t);
		System.out.println(total);
	}
	
	public static int intXOR(int i1, int i2)
	  {
		  String s1 = Integer.toBinaryString(i1);
		  String s2 = Integer.toBinaryString(i2);
		  char[] s3;
		  if(s1.length() > s2.length())
		  {
			  s3 = s1.toCharArray();
			  int offset = s1.length() - s2.length();
			  for(int i = 0; i < s2.length(); i++)
			  {
				  s3[i + offset] = charXOR(s1.charAt(i + offset), s2.charAt(i));
			  }
		  }
		  else
		  {
			  s3 = s2.toCharArray();
			  int offset = s2.length() - s1.length();
			  for(int i = 0; i < s1.length(); i++)
			  {
				  s3[i + offset] = charXOR(s2.charAt(i + offset), s1.charAt(i));
			  }
		  }
		  String answer = new String(s3);
		  return Integer.parseInt(answer, 2);
	  }
	
	  public static char charXOR(char a, char b)
	  {
		  if(a == '1' && b == '1' || a == '0' && b == '0')
			  return '0';
		  else
			  return '1';
	  }
}
