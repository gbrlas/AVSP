def calc_robots_time(input_file,output_file):
	fout = open(output_file,'w')
	fin = open(input_file,'r')
	count_line = fin.readline()
	count_line = count_line.strip()
	line_count = int(count_line)
	for lnum in range(line_count):
		dataline = fin.readline()
		dataline = dataline.strip()
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ')
		data_list = dataline.split()
		button_count = data_list[0]
		button_count = int(button_count)
		robostruct = dict ()
		current_time = 0
		for this_button in range(button_count):
			robot = data_list[(this_button * 2) + 1]
			if robot not in robostruct:
				robostruct[robot] = dict ()
				robostruct[robot]['position'] = 1
				robostruct[robot]['time'] = 0
			to_push = data_list[(this_button * 2) + 2]
			to_push = int(to_push)
			# move robot
			distance = abs(robostruct[robot]['position'] - to_push)
			robostruct[robot]['time'] = robostruct[robot]['time'] + distance
			robostruct[robot]['position'] = to_push
			if robostruct[robot]['time'] > current_time:
				current_time = robostruct[robot]['time']
			# add 1 second for the push time
			current_time = current_time + 1
			robostruct[robot]['time'] = current_time
		fout.write(str(current_time))
		fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'A-small-attempt0'
	input_file = runname + '.in'
	output_file = runname + '.out'
	calc_robots_time(input_file,output_file)

main()
