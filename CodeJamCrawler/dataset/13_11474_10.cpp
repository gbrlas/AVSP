
import java.util.*;
class hey
{
public static void main(String args[])
{
   Scanner sc=new Scanner(System.in);
   int t=sc.nextInt();
   int c=1;
while(t-->0)
{long  n1=sc.nextLong();
long n2=sc.nextLong();
    long k1=(long)Math.sqrt(n1);
    long k2=(long)Math.sqrt(n2);
    int count=0;
    
           
        if(n1>k1*k1)
        k1++;
        
    
    
    
    for(long i=k1;i<=k2;i++)
    {
        
       String root=Long.toString(i);
       
        
        if(isPalindrome(root))
        {
           long r=i*i;
           String j=Long.toString(r);
            if(isPalindrome(j))
            count++;
        }
        
    
        
    }
    System.out.println("Case #"+c+": "+count);
    c++;
}
   
}
static boolean isPalindrome(String s) {
  int n = s.length();
  for (int i=0;i<(n / 2) + 1;++i) {
     if (s.charAt(i) != s.charAt(n - i - 1)) {
         return false;
     }
  }

  return true;
}

}