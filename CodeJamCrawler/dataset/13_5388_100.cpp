package com.wildhemp.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class FairSquare {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	int maxNum = 10000000;
	long[] squares = new long[maxNum + 1];
	int idx = 0;
	for (int num = 0; num < maxNum; num++) {
	    int sqr = num * num;
	    if (isPalindrome(num) && isPalindrome(sqr)) {
		squares[idx ++] = sqr;
	    }
	}

	BufferedReader dis = new BufferedReader(new InputStreamReader(
		new FileInputStream(args[0])));
	int testNum = Integer.parseInt(dis.readLine());
	for (int test = 0; test < testNum; test++) {
	    String[] nums = dis.readLine().split(" ");
	    long a = Long.parseLong(nums[0]);
	    long b = Long.parseLong(nums[1]);
	    
	    int idx1 = Arrays.binarySearch(squares, 0, idx, a);
	    if (idx1 < 0) {
		idx1 = Math.abs(idx1) - 1;
	    }
	    int idx2 = Arrays.binarySearch(squares, idx1, idx, b);
	    if (idx2 < 0) {
		idx2 = Math.abs(idx2) - 1;
	    }
	    int inc = 0;
	    if (squares[idx2] == b) {
		inc ++;
	    }
	    
	    System.out.println("Case #" + (test + 1) + ": " + (idx2 - idx1 + inc));
	}
    }

    private static boolean isPalindrome(long number) {
	long num = number;
	long rev = 0;

	while (num > 0) {
	    rev = rev * 10 + num % 10;
	    num /= 10;
	}

	return number == rev;
    }
}
