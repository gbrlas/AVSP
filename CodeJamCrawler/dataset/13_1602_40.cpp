package com

class FairSquare {

	public loader(){
		def firstLine = true
		def caseNumbers = 0
		def caseCounter = 1
		System.in.eachLine() { line ->
			if(firstLine){
				firstLine = false
				caseNumbers = line.toInteger()
			}
			else{
				if(caseCounter <= caseNumbers){
					print "Case #"+ caseCounter +": "
					String[] args = line.split(" ")
					range(args[0], args[1])
					caseCounter++
				}
			}
		}
	}



	public range(String min, String max){
		Double minDouble = Double.valueOf(min)
		Double maxDouble = Double.valueOf(max)

		int validFairSquare = 0
		Double currentNumber = minDouble
		while(currentNumber <= maxDouble){
			if (isSquare(currentNumber.toString())){
				String pali = currentNumber.toString()
				//slice off the zero &decimal
				pali = pali.substring(0,pali.size()-2)
				//println pali
				if(isPalindrome(pali)){
					validFairSquare++
				}
			}
			currentNumber ++;
		}

		println validFairSquare

	}


	public boolean isPalindrome(String number){
		char[] intAsNum = number.toCharArray();
		boolean palindrome = false;
		int j = intAsNum.length - 1

		for(int i = 0; i <= j ; i++){
			palindrome = intAsNum[i] == intAsNum[j]
			if (palindrome == false){
				break;
			}
			j--
		}
		return palindrome
	}

	public boolean isSquare(String number){
		Double d = Double.valueOf(number)
		Double squareResult = Math.sqrt(d)

		//see if it is square
		String[] remainder = squareResult.toString().split("\\.");
		if (remainder[1].compareTo("0") == 0){
			if(isPalindrome(remainder[0])){
				return true
			}
		}
		else{
			return false
		}

	}
}