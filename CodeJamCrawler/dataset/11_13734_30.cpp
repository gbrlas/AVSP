def patrick_add(n1,n2):
	bitwise_and = n1 & n2
	sum = (n1 - bitwise_and) + (n2 - bitwise_and)
	return sum

def do_candy_splitting(input_file,output_file):
	bitflags = list ()
	bitval = 1
	for idx in range(31):
		bitflags.append(bitval)
		bitval = bitval * 2
	fout = open(output_file,'w')
	fin = open(input_file,'r')
	test_cases = fin.readline()
	test_cases = test_cases.strip()
	test_cases = int(test_cases)
	for lnum in range(test_cases):
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ')
		num_candies = fin.readline()
		num_candies = num_candies.strip()
		num_candies = int(num_candies)
		candies_line = fin.readline()
		candies_line = candies_line.strip()
		candies_list = candies_line.split()
		found_match = False
		match_msk = -1
		max_sean = -1
		loop_top = bitflags[num_candies]
		for mask in range(loop_top):
			p_sum_one = 0
			p_sum_two = 0
			real_sum_one = 0
			real_sum_two = 0
			for whx in range(num_candies):
				bit_x = bitflags[whx]
				candy_val = candies_list[whx]
				candy_val = int(candy_val)
				combine_m_w_b = bit_x & mask
				if combine_m_w_b == 0:
					p_sum_one = patrick_add(p_sum_one,candy_val)
					real_sum_one = real_sum_one + candy_val
				else:
					p_sum_two = patrick_add(p_sum_two,candy_val)
					real_sum_two = real_sum_two + candy_val
			if p_sum_one == p_sum_two:
				if (real_sum_one != 0) and (real_sum_two != 0):
					found_match = True
					max_sum = real_sum_one
					if real_sum_two > max_sum:
						max_sum = real_sum_two
					if max_sum > max_sean:
						max_sean = max_sum
						match_msk = mask
		if found_match:
			fout.write(str(max_sean))
		else:
			fout.write('NO')
		fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'C-small-attempt0'
	input_file = runname + '.in'
	output_file = runname + '.out'
	do_candy_splitting(input_file,output_file)

main()
