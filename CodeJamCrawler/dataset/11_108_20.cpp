public class CandySplitting
{
    
    public static void main(String[] args)
    {
       //System.out.println(Integer.parseInt(BinaryArithmetic.add(Integer.toBinaryString(), Integer.toBinaryString(5)),2));
        int case_no = StdIn.readInt();
        
        for (int b = 0; b<case_no; b++)
        {Stack<Integer> sum_array = new Stack<Integer>();
            boolean flag = false;
        int N = StdIn.readInt();
        int[] nums = new int[N];
            for(int h =0;h<N;h++)
                nums[h] = StdIn.readInt();
            int count = 0;
        for (int i = 1; i <N ; i++)//sizes of piles
        {
            
            
            for(int j = 0; j < N-i+1; j++)//rethink as i inc, the number of times you need to go through decreases
            {
                int [] arr = new int[i];
                long sum_curr = 0;
                long sum_rest = 0;
                int k;
                for(k = 0 ; k < i; k++)
                    arr[k] = nums[j+k];
                for(int l = 0 ; l < i; l++)
                    sum_curr = Integer.parseInt(BinaryArithmetic.add(Binary.getBin(sum_curr), Integer.toBinaryString(arr[l])),2);
               // System.out.print("    i: "+i+ "    j: " +j+ "   k: " +k);
                
                for(int m = 0; m < j; m++)//beg to curr
                {  sum_rest = Integer.parseInt(BinaryArithmetic.add(Binary.getBin(sum_rest), Integer.toBinaryString(nums[m])),2);
                /*if(sum_rest > (2*sum_curr))
                    break;*/}
                //System.out.println(sum_rest);
                for(int m = (j + i); m < N; m++)//curr to end
                    sum_rest = Integer.parseInt(BinaryArithmetic.add(Binary.getBin(sum_rest), Integer.toBinaryString(nums[m])),2);
                if(sum_rest == sum_curr && sum_curr != 0)
                {
                 flag = true;
                 //System.out.print("    i: "+i+ "    j: " +j+ "   k: " +k+ " ");
                // System.out.printf("\nCase %d: ", b+1);
                 int new_sum=0;
                 int new_sum1 = 0;
                 for(int v = 0; v < i;v++)
                 {
                     //System.out.print(nums[v] + " ");
                 new_sum1 += arr[v];
                 }
                 //System.out.print(new_sum1);
                 for(int m = 0; m < j; m++)//beg to curr
                {  new_sum += nums[m];
                /*if(sum_rest > (2*sum_curr))
                    break;*/}
                //System.out.println(sum_rest);
                for(int m = (j + i); m < N; m++)//curr to end
                    new_sum += nums[m];
                 
                if(new_sum >new_sum1)
                 sum_array.push(new_sum);
                else sum_array.push(new_sum1);
                 
               // System.out.print(new_sum);
                 //System.out.println();
                }
            }
            
        }
        if(flag == false)
            System.out.printf("\nCase #%d: NO", b+1);
        else if(flag ==true)
        {
         int max = sum_array.peek();
            for(int f: sum_array)
            {
             if(f > max)
                 max =f;
            }
            System.out.printf("\nCase #%d: ", b+1);
            
                 System.out.print(max);

            
        }
        }
    }
}