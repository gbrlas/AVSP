def main():
	# get top line
	infile = open("C-large.in","r")
	outfile = open("C-large.out","w")
	magic_phrase = "welcome to code jam"
	number_of_lines = infile.readline()
	number_of_lines = int(number_of_lines)
	for line_num in range(number_of_lines):
		test_line = infile.readline()
		already_done = False
		done_already = dict()
		possibility_map = dict()
		for char in magic_phrase:
			possibility_map[char] = []
		for char in magic_phrase:
			if not(char in done_already):
				done_already[char] = True
				pos = test_line.find(char)
				if pos == -1:
					already_done = True
				possibility_map[char].append(pos)
				pos = test_line.find(char,pos + 1)
				while pos != -1:
					possibility_map[char].append(pos)
					pos = test_line.find(char,pos + 1)
		sequence_map = dict()
		for idx in range(len(magic_phrase)):
			char = magic_phrase[idx]
			corresponding = possibility_map[char]
			new_map = dict ()
			for numb in corresponding:
				new_map[numb] = 1
				sequence_map[idx] = new_map
		idx = len(magic_phrase) - 2
		while idx >= 0:
			for primary_ix in sequence_map[idx]:
				total = 0
				for secondary_ix in sequence_map[idx+1]:
					if secondary_ix > primary_ix:
						total = total + sequence_map[idx+1][secondary_ix]
				sequence_map[idx][primary_ix] = total
			idx = idx - 1
		final_total = 0
		for idx in sequence_map[0]:
			final_total = final_total + sequence_map[0][idx]
		final_digits = "00000" + str(final_total)
		final_digits = final_digits[len(final_digits)-4:]
		case_num = line_num + 1
		outfile.write("Case #" + str(case_num) + ": " + final_digits + "\n")
	infile.close()
	outfile.close()

main()
