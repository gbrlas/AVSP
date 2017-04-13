import sys
import sets

def main():
	if len(sys.argv) != 2:
		print "Please pass file argument"
		return
		
	f = open(sys.argv[1], 'r')
	input = f.readline()
	nums = input.rsplit(' ')
	
	out = open("out.txt", 'w')
	
	if len(nums) != 3:
		print "First line incorrect"
		return
	
	print "Reading",nums[1]
	
	words = []

	for x in range(int(nums[1])):
		word = f.readline()
		words = words + [word]
		
	print "Length of dictionary:",len(words)
	
	for x in range(int(nums[2])):
		print "Checking ",x
		line = f.readline()
		i = 0
		isList = False
		list = []
		for w in line:
			y = w.strip()
			if y == '(':
				isList = True
				list = list + [[]]
				continue
			if y == ')':
				isList = False
				i = i + 1
				continue
			if isList:	
				list[i] = list[i] + [y]
			else:
				list = list + [[y]]
				i = i + 1
		
		count = 0
		
		print list
		
		for w in words:
			y = w.strip()
			match = True
			for z in range(len(y)):
				if not y[z] in list[z]:
					match = False
			if match:
				count = count + 1
				
		out.write("Case #")
		out.write(str(x + 1))
		out.write(": ")
		out.write(str(count))
		out.write("\n")
	out.close()
	
if __name__ == "__main__":
    main()