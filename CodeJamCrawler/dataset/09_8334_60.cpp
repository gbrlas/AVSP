public class genall
{
	public static void main(String[] args)
	{
		System.out.println((1<<9)-1);
		for(int i = 1; i < (1<<9); i++)
		{
			int icpy = i;
			int curr = 2;
			while(curr <= 10)
			{
				if((icpy&1)==1)
					System.out.print(curr+" ");
				icpy >>= 1;
				curr++;
			}
			System.out.println();
		}
	}
}