def main():
	fname = 'C-small-attempt1'
	outfile = open(fname + '.out','w')
	infile = open(fname + '.in','r')
	cases_str = infile.readline()
	cases_str.strip()
	cases_count = int(cases_str)
	for case_num in range(cases_count):
		case_line = infile.readline()
		case_line = case_line.strip()
		case_list = case_line.split(' ')
		runs_per_day = case_list[0]
		runs_per_day = int(runs_per_day)
		coaster_size = case_list[1]
		coaster_size = int(coaster_size)
		num_groups = case_list[2]
		num_groups = int(num_groups)
		g_line = infile.readline()
		g_line = g_line.strip()
		g_str_list = g_line.split(' ')
		g_list = []
		for some_value in g_str_list:
			g_list.append(int(some_value))
		# precompute for optimization
		g_next_position = []
		g_number_riders = []
		loop_detect = []
		for i in range(num_groups):
			g_next_position.append(0)
			g_number_riders.append(0)
			loop_detect.append(False)
		for i in range(num_groups):
			people_in_coaster = 0
			loading_coaster = True
			position = i
			prev_pos = -1
			first_pos = -1 #not set
			while loading_coaster:
				if position == first_pos:
					loading_coaster = False
					nxt_pos = prev_pos
				else:
					if first_pos == -1:
						first_pos = position
					group_size = g_list[position]
					if (people_in_coaster + group_size) <= coaster_size:
						people_in_coaster = people_in_coaster + group_size
						prev_pos = -1
						position = position + 1
						if position == num_groups:
							position = 0
					else:
						loading_coaster = False
						nxt_pos = position
			g_number_riders[i] = people_in_coaster
			g_next_position[i] = nxt_pos
		position = 0
		euros = 0
		this_run = 0
		loop_dtc_mode = 99
		while this_run < runs_per_day:
			if loop_dtc_mode == 1:
					if position == loop_start_pos:
						loop_total_runs = this_run - loop_start_run
						loop_total_euros = euros - loop_start_amount
						loop_dtc_mode = 2
						runs_left = runs_per_day - this_run
						mult_fact = runs_left // loop_total_runs
						euros = euros + (loop_total_euros * mult_fact)
						this_run = this_run + (loop_total_runs * mult_fact)
			if loop_dtc_mode == 0:
				if loop_detect[position]:
					loop_start_run = this_run
					loop_start_pos = position
					loop_start_amount = euros
					loop_dtc_mode = 1
			if this_run < runs_per_day:
				# ^^ necessary because breaking out of loop detect can cause us to add extra on the end
				euros = euros + g_number_riders[position]
			loop_detect[position] = True
			position = g_next_position[position]
			this_run = this_run + 1
		this_case = case_num + 1
		outfile.write('Case #' + str(this_case) + ': ' + str(euros) + "\n")
	infile.close()
	outfile.close()

main()
