import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Q1 {

	private static int swaps;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int cases = scn.nextInt();
		for( int c = 1; c <= cases; c++ )
		{
			int size = scn.nextInt();
			scn.nextLine();
			int[] matrix = new int[size];
			List<Integer> list = new LinkedList<Integer>();
			for(int s = 0; s < size; s++ )
			{
				int pos = 0;
				String input = scn.nextLine().trim();
				for(int i = input.length()-1; i >= 0; i-- )
				{
					if( input.charAt(i) == '1' ) {
						pos = i;
						break;
					}
				}
				matrix[s] = pos;
				list.add(pos);
			}
			int x = order(list);
			StringBuilder builder = new StringBuilder();
			builder.append("Case #");
			builder.append(c);
			builder.append(": ");
			builder.append(x);
			System.out.println(builder.toString());
		}

	}

	private static int order(List<Integer> matrix) {
		int sw = 0;
		
		int current = 0;
		while(matrix.size() > 0) {
			
			int index = 0;
			for(Integer p : matrix) {
				if( p <= current ){
					sw += index;
					matrix.remove(index);
					break;
				}
				index++;
			}
			current++;
		}
		
		return sw;
	}
	
	private static void order(int[] matrix, int start, int end) {
		swaps = 0;
		for(int i = 0; i < matrix.length; i++ )
		{
			for(int j = i; j < matrix.length; j++ )
			{
				if( matrix[j] <= i ) {
					
				}
			}
		}
		mergesort(matrix, start, end);
	}

	public static void mergesort(int[ ] data, int first, int n)
	{
		int n1; // Size of the first half of the array
		int n2; // Size of the second half of the array

		if (n > 1)
		{
			// Compute sizes of the two halves
			n1 = n / 2;
			n2 = n - n1;

			mergesort(data, first, n1);      // Sort data[first] through data[first+n1-1]
			mergesort(data, first + n1, n2); // Sort data[first+n1] to the end

			// Merge the two sorted halves.
			merge(data, first, n1, n2);
		}
	} 

	private static void merge(int[ ] data, int first, int n1, int n2)
	{
		int[ ] temp = new int[n1+n2]; // Allocate the temporary array
		int copied  = 0; // Number of elements copied from data to temp
		int copied1 = 0; // Number copied from the first half of data
		int copied2 = 0; // Number copied from the second half of data
		int i;           // Array index to copy from temp back into data

		// Merge elements, copying from two halves of data to the temporary array.
		while ((copied1 < n1) && (copied2 < n2))
		{
			if (data[first + copied1] <= data[first + n1 + copied2]) {
				
				temp[copied++] = data[first + (copied1++)];
			} else {
				swaps++;
				temp[copied++] = data[first + n1 + (copied2++)];
			}
		}

		// Copy any remaining entries in the left and right subarrays.
		while (copied1 < n1)
			temp[copied++] = data[first + (copied1++)];
		while (copied2 < n2)
			temp[copied++] = data[first + n1 + (copied2++)];

		// Copy from temp back to the data array.
		for (i = 0; i < n1+n2; i++)
			data[first + i] = temp[i];
	}

}
