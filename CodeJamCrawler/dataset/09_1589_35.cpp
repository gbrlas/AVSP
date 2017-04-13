package com.baskok.codejam.round1b2009;

import static org.junit.Assert.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

import org.junit.Test;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("src/com/baskok/codejam/round1b2009/B-small-attempt1.in"));
		int runs = in.nextInt();
		for (int run = 1; run <= runs; run++) {
			B problem = new B();
			// add arguments
			String result = problem.solve(in);
			System.out.println("Case #" + run + ": " + result);
		}
	}

	private String solve(Scanner in) {
		String result = "";
		String startNumber = in.next();
		
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		int len = startNumber.length();
		for (int i = 0; i < len; i++) {
			numbers.add(Integer.parseInt(""+startNumber.charAt(i)));
		}

		boolean computed = false;
		
		for (int curIndex = len - 1; curIndex > 0; curIndex--) {
			Integer cur = numbers.get(curIndex);
			int nextIndex = curIndex - 1;
			Integer next = numbers.get(nextIndex);
			if (cur > next) {

				// determine the number between numbers[len] and numbers[len-i] which is closest to next
				int best = Integer.MAX_VALUE;
				int swapIndex = Integer.MAX_VALUE;
				for (int j = curIndex; j < len; j++) {
					if (numbers.get(j) < best && numbers.get(j) > next) {
						best = numbers.get(j);
						swapIndex = j;
					}
				}
				
				// swap next and best
				numbers.set(swapIndex, next);
				numbers.set(nextIndex, best);
				
				// sort the tail
				List<Integer> tail = numbers.subList(curIndex, len);
				Collections.sort(tail);
				for (int j = curIndex; j < len; j++) {
					numbers.set(j, tail.get(j - curIndex));
				}
				
				// we're done
				computed = true;
				break;
			}
		}
		
		if (!computed) {
			// we need to add a zero
			Collections.sort(numbers);
			// make sure we don't start with a zero
			if (numbers.get(0) == 0) {
				for (int i = 0; i < numbers.size(); i++) {
					if (numbers.get(i) > 0) {
						numbers.set(0,numbers.get(i));
						numbers.set(i, 0);
						break;
					}
				}
			}
			// add a new zero after first numbers
			numbers.add(1, 0);
		}
		
		for (Integer digit : numbers) {
			result += digit;
		}
		return result;
	}
	
	@Test
	public void simple() throws Exception {
		assertEquals("10", solve(new Scanner("01")));
		assertEquals("110", solve(new Scanner("101")));
		assertEquals("361613", solve(new Scanner("361361")));
		assertEquals("787594", solve(new Scanner("787549")));
		assertEquals("1015", solve(new Scanner("511")));
		assertEquals("10000", solve(new Scanner("1000")));
	}
	

}
