/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.*;
import java.util.*;
/**
 *
 * @author harry
 */

 class Queue
 {
     int elements[];
   /**
009:        Constructs an empty queue.
010:        @param capacity the maximum capacity of the queue
011:        @precondition capacity > 0
012:    */
   public Queue(int capacity)
   {
      elements= new int[capacity];
      count = 0;
      head = 0;
      tail = 0;
   }


   /**
       Remove object at head.
       @return the object that has been removed from the queue
051:        @precondition size() > 0
052:    */
   public int removeFirst()
   {
      int r = elements[head];
      head = (head + 1) % elements.length;
      count--;
      return r;
   }

   /**
:        Append an object at tail.
063:        @param anObject the object to be appended
064:        @return true since this operation modifies the queue.
065:        (This is a requirement of the collections framework.)
066:        @precondition !isFull()
067:    */
   public boolean add(int an)
   {
      elements[tail] = an;
      tail = (tail + 1) % elements.length;
      count++;
      return true;
    }

    public int size()
    {
       return count;
    }

    /**
082:        Checks whether this queue is full.
083:        @return true if the queue is full
084:    */
    public boolean isFull()
    {
       return count == elements.length;
    }

    /**
:        Gets object at head.
092:        @return the object that is at the head of the queue
093:        @precondition size() > 0
094:    */
    public int getFirst()
    {
       return elements[head];
    }
    private int head;
    private int tail;
    private int count;
 }

public class roller {
    public static void main(String args[]) throws Exception {
        BufferedReader in   = new BufferedReader(new FileReader("C-small-attempt0.in"));
        int T=Integer.parseInt(in.readLine());
        BufferedWriter out = new BufferedWriter(new FileWriter("prac", true));
        for (int i=0;i<T;i++){
            String line=in.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            int R = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            Queue q = new Queue(N);
            int j=0,k=1,euros=0;
            String line2=in.readLine();
            StringTokenizer st2 = new StringTokenizer(line2, " ");
            while(st2.hasMoreTokens()) {
                int tempo=Integer.parseInt(st2.nextToken());
                q.add(tempo);
            }
            while(k++<=R){
                int temp,sum=0,removed,counter=0;
                while(true){
                    temp=q.getFirst();
                    counter++;
                    sum+=temp;
                    if (sum<=K && counter<=q.size()){
                        removed=q.removeFirst();
                        q.add(removed);
                    }
                    else{
                        sum=sum-temp;
                        break;
                    }
            }
                euros+=sum;
        }
            out.write("Case #"+(i+1)+": "+euros+"\n");
        }
        out.close();
    }
}


