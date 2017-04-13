package com

class TicTac {

	String xWon = "X won"
	String oWon = "O won"
	String draw = "Draw"
	String incomplete = "Game has not completed"
	
	public loader(){
		def firstLine = true
		def caseNumbers = 0
		def caseCounter = 1
		int lineCounter = 0
		String[][] gameboard = [["","","",""],["","","",""],["","","",""],["","","",""]]
		System.in.eachLine() { line ->
			if(firstLine){
				firstLine = false
				caseNumbers = line.toInteger()
			}
			else if(line.isEmpty()){
				lineCounter = 0;
			}
			else{ 
				gameboard[lineCounter][0] = line.substring(0,1);
				gameboard[lineCounter][1] = line.substring(1,2);
				gameboard[lineCounter][2] = line.substring(2,3);
				gameboard[lineCounter][3] = line.substring(3);
				
				if (lineCounter == 3 && caseCounter <= caseNumbers){
					print "Case #"+ caseCounter +": "
					analyzeGameBoard(gameboard)
					gameboard = [["","","",""],["","","",""],["","","",""],["","","",""]]
					caseCounter++
				}
				lineCounter ++;
				

			}
		}
	}


	public void analyzeGameBoard(String [][] gameboard){
		
		def inProgress = false
		
		//Analyze Horizontal
		int counter = 0
		while (counter <= 3 ){
			int outcome = winningLine(gameboard[counter][0] + gameboard[counter][1] + gameboard[counter][2] + gameboard[counter][3] )
			if (outcome == 1){
				println xWon
				return
			}
			if (outcome == 2){
				println oWon
				return
			}
			if (outcome == 3){
				inProgress = true
			}
			counter ++;
		}
		
		//Analyze Vertical
		counter = 0
		while (counter <= 3 ){
			int outcome = winningLine(gameboard[0][counter] + gameboard[1][counter] + gameboard[2][counter] + gameboard[3][counter] )
			if (outcome == 1){
				println xWon
				return
			}
			if (outcome == 2){
				println oWon
				return
			}
			if (outcome == 3){
				inProgress = true
			}
			counter ++;
		}
		
		//Analyze diagonals
		int outcome = winningLine(gameboard[0][0] + gameboard[1][1] + gameboard[2][2] + gameboard[3][3])
		if (outcome == 1){
			println xWon
			return
		}
		if (outcome == 2){
			println oWon
			return
		}
		if (outcome == 3){
			inProgress = true
		}
		
		outcome = winningLine(gameboard[3][0] + gameboard[2][1] + gameboard[1][2] + gameboard[0][3])
		if (outcome == 1){
			println xWon
			return
		}
		if (outcome == 2){
			println oWon
			return
		}
		if (outcome == 3){
			inProgress = true
		}
		
		if (inProgress){
			println incomplete
		}
		else{
			println draw
		}
		
		
	}
	
	// 0 = no win
	// 1 = X win
	// 2 = O win
	// 3 = still space open
	public int winningLine (String line){
		char[] charLine = line.toCharArray();
		if (charLine[0].compareTo(charLine[1]) == 0 && 
			charLine[2].compareTo(charLine[3]) == 0 &&
			charLine[1].compareTo(charLine[2]) == 0){
			if (line.contains("X")){
				return 1
			}
			else if (line.contains("O")){
				return 2
			}
			else{
				return 3
			}
		}
		else if (line.contains("T")){
			if (line.count("X") == 3){
				return 1
			} 
			else if (line.toString().count("O")  == 3){
				return 2
			}
			else{
				return 0
			}
		}
		else if (line.contains(".")){
			return 3
		}
		else{
			return 0
		}
	}

}
