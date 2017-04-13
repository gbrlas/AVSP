package com.wildhemp.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Treasure {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	BufferedReader dis = new BufferedReader(new InputStreamReader(
		new FileInputStream(args[0])));

	int testNum = Integer.parseInt(dis.readLine());
	for (int test = 0; test < testNum; test++) {
	    String[] numStr = dis.readLine().split(" ");
	    int k = Integer.parseInt(numStr[0]);
	    int n = Integer.parseInt(numStr[1]);

	    int[] keyNums = new int[200];

	    numStr = dis.readLine().split(" ");
	    for (int idx = 0; idx < k; idx++) {
		keyNums[Integer.parseInt(numStr[idx])]++;
	    }

	    int[] keyType = new int[n];
	    int[][] keysInChest = new int[n][];
	    for (int idx = 0; idx < n; idx++) {
		numStr = dis.readLine().split(" ");
		keyType[idx] = Integer.parseInt(numStr[0]);
		int keyNum = Integer.parseInt(numStr[1]);
		keysInChest[idx] = new int[keyNum];

		for (int key = 0; key < keyNum; key++) {
		    keysInChest[idx][key] = Integer.parseInt(numStr[key + 2]);
		}
	    }

	    boolean[] opened = new boolean[n];

	    String solution = solve(keyNums, keyType, keysInChest, opened, new HashMap<String, String>());
	    if (solution == null) {
		solution = "IMPOSSIBLE";
	    }
	    
	    System.out.println("Case #" + (test + 1) + ": " + solution);
	}
    }

    private static String solve(int[] keyNums, int[] keyType,
	    int[][] keysInChest, boolean[] opened, Map<String, String> solutions) {
	for (int idx = 0; idx < opened.length; idx++) {
	    if (!opened[idx] && keyNums[keyType[idx]] > 0) {
		opened[idx] = true;
		keyNums[keyType[idx]]--; // using the key

		for (int key : keysInChest[idx]) {
		    keyNums[key]++;
		}

		String hashKey = convertToString(keyNums, opened);
		String solution = solutions.get(hashKey);
		if (solution == null) {
		    solution = solve(keyNums, keyType, keysInChest, opened, solutions);
		    solutions.put(hashKey, (solution == null ? "IMPOSSIBLE" : solution));
		} else if (solution.equals("IMPOSSIBLE")) {
		    solution = null;
		}
		
		if (solution == null) {
		    // restoring the state, since this was not working
		    opened[idx] = false;
		    keyNums[keyType[idx]]++;

		    for (int key : keysInChest[idx]) {
			keyNums[key]--;
		    }
		} else {
		    return (idx + 1) + " " + solution;
		}
	    }
	}
	
	for (int idx = 0; idx < opened.length; idx ++) {
	    if (!opened[idx]) {
		return null;
	    }
	}

	return "";
    }
    
    private static String convertToString(int[] keyNums, boolean[] opened) {
	StringBuilder sb = new StringBuilder();
	for (int num: keyNums) {
	    sb.append(num);
	}
	for (boolean bool: opened) {
	    sb.append(bool);
	}
	
	return sb.toString();
    }

}
