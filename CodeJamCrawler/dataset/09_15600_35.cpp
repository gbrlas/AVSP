import java.lang.reflect.Array;
import java.util.*;
public class NextNumber {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for(int cas=1; cas<=t; cas++)
		{
			String input = sc.nextLine();
			boolean flipped = false;
			for(int i=input.length()-1; i>0; i--)
			{
				if(input.charAt(i)>input.charAt(i-1))
				{
					int mind = getMin(input.substring(i), input.charAt(i-1))+i;
					char[] blah = input.toCharArray();
					char temp = blah[i-1];
					blah[i-1] = blah[mind];
					blah[mind] = temp;
					input = String.valueOf(blah);
					blah = input.substring(i).toCharArray();
					Arrays.sort(blah);
					input = input.substring(0,i)+String.valueOf(blah);
					flipped = true;
					break;
				}
				
			}
			if(!flipped)
			{
				char[] ar = input.toCharArray();
				char[] ans = new char[ar.length+1];
				char[] tempCharArray = new char[ar.length];
				for(int k=ar.length-1; k>=0; k--)
				{
					if(ar[k] != '0')
					{
						ans[0] = ar[k];
						ar[k] = '0';
						// put original string in an array of chars
				        for (int i = 0; i < ar.length; i++) {
				            tempCharArray[i] = ar[i];
				        } 
				        
				        // reverse array of chars
				        for (int j = 0; j < ar.length; j++) {
				            ar[j] = tempCharArray[ar.length - 1 - j];
				        }
				        
				        for(int l=0; l<ar.length; l++)
				        {
				        	ans[l+1] = ar[l];
				        }
				        input = String.valueOf(ans);
				        break;
					}
				}
				
			}
			System.out.println("Case #"+cas+": "+input);
		}
		
	}
	
	public static int getMin(String str, char ch)
	{
		char[] blah = str.toCharArray();
		Arrays.sort(blah);
		int ind=0;
		for(int i=0; i<blah.length; i++)
		{
			if(blah[i]>ch)
			{
				return str.indexOf(blah[i]);
			}
			ind = i;
		}
		return str.indexOf(ind);
	}

}
