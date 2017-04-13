package com.baskok.codejam.round1c2009;

import static org.junit.Assert.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

import org.junit.Test;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("src/com/baskok/codejam/round1c2009/A-large.in");
		Scanner in = new Scanner(file);
		int runs = in.nextInt();
		for (int run = 1; run <= runs; run++) {
			A problem = new A();
			// add arguments
			String result = problem.solve(in);
			System.out.println("Case #" + run + ": " + result);
		}
	}

	private String solve(Scanner in) {
		String input = in.next();
		int base = findBase(input);
		long result = 0;
		HashMap<String, Long> values = new HashMap<String, Long>();
		long nextVal = 2;
		long valuesFound = 0;
		for (int i = 0; i < input.length(); i++) {
			result *= base;
			char decimalValue = input.charAt(i);
			if (!values.containsKey(decimalValue + "")) {
				if (valuesFound == 0) {
					values.put(decimalValue + "", 1l);					
				} else if (valuesFound == 1) {
					values.put(decimalValue + "", 0l);
				} else {
					values.put(decimalValue + "", nextVal++);
				}
				valuesFound++;
			}
			long digit = values.get(decimalValue + "");
			result += digit;
		}
		return result + "";
	}

	private int findBase(String in) {
		HashMap<String, Boolean> seen = new HashMap<String, Boolean>();
		for (int i = 0; i < in.length(); i++) {
			seen.put(""+in.charAt(i), true);
		}
		int base = seen.keySet().size();
		if (base == 1) {
			base = 2;
		}
		return base;			
	}

	@Test
	public void simple() throws Exception {
		A problem = new A();
		assertEquals(2, problem.findBase("0101"));
		assertEquals(3, problem.findBase("0201"));
		assertEquals(3, problem.findBase("0a01"));
	}
	
}
