
def main():
	outfile = open("A-large.out","w")
	# get top line
	infile = open("A-large.in","r")
	first_line = infile.readline()
	firstlnlist = first_line.split()
	num_tokens = firstlnlist.pop(0)
	num_tokens = int(num_tokens)
	dictionary_words = firstlnlist.pop(0)
	dictionary_words = int(dictionary_words)
	num_patterns = firstlnlist.pop(0)
	num_patterns = int(num_patterns)
	# read in dictionary
	possibility_map = dict ()
	for idx in range(num_tokens):
		possibility_map[idx] = dict()
	for line_num in range(dictionary_words):
		word_line = infile.readline()
		if word_line.endswith("\n"):
			word_line = word_line[0:len(word_line) - 1]
		for idx in range(num_tokens):
			ch = word_line[idx]
			if ch in possibility_map[idx]:
				possibility_map[idx][ch].append(line_num)
			else:
				possibility_map[idx][ch] = [(line_num)]
	for line_num in range(num_patterns):
		case_number = line_num + 1
		pattern_line = infile.readline()
		if pattern_line.endswith("\n"):
			pattern_line = pattern_line[0:len(pattern_line) - 1]
		how_many_possibilities = dict()
		possibilities_for_this_pattern = dict()
		current_choice = dict()
		this_letter_position = 0
		paren_open = False
		for this_char in pattern_line:
			if this_char == "(":
				paren_open = True
				count = 0
				increment_position = False
				possibilities_for_this_pattern[this_letter_position] = []
			elif this_char == ")":
				paren_open = False
				increment_position = True
			else:
				if paren_open:
					count = count + 1
					increment_position = False
				else:
					count = 1
					increment_position = True
					possibilities_for_this_pattern[this_letter_position] = []
				how_many_possibilities[this_letter_position] = count
				current_choice[this_letter_position] = 0
				possibilities_for_this_pattern[this_letter_position].append(this_char)
			if increment_position:
				this_letter_position = this_letter_position + 1
		number_of_letters = this_letter_position
		# pattern should be ready to loop through and test against dictionary
		# initialize with first position
		line_map = dict()
		for possible_char in possibilities_for_this_pattern[0]:
			if possible_char in possibility_map[0]:
				line_list = possibility_map[0][possible_char]
				for line_num in line_list:
					line_map[line_num] = False
		for idx in range(1,num_tokens):
			for possible_char in possibilities_for_this_pattern[idx]:
				if possible_char in possibility_map[idx]:
					line_list = possibility_map[idx][possible_char]
					for line_num in line_list:
						if line_num in line_map:
							line_map[line_num] = True
			deletelist = []
			for line_num in line_map:
				if line_map[line_num] == False:
					deletelist.append(line_num)
			for line_num in deletelist:
				line_map.pop(line_num)
			for line_num in line_map:
				# this is to set up for the next loop
				line_map[line_num] = False
		count_for_output = len(line_map)
		outfile.write("Case #" + str(case_number) + ": " + str(count_for_output) + "\n")
	outfile.close()
	infile.close()

main()
