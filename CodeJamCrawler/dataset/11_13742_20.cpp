def calculate_wp_without(schedule,number_of_teams,wp_for,wp_without):
	numerator = 0
	denominator = 0
	for ix in range(number_of_teams):
		if ix != wp_for:
			if ix != wp_without:
				win_flag = schedule[wp_for][ix]
				if win_flag == '1':
					numerator = numerator + 1
					denominator = denominator + 1
				if win_flag == '0':
					denominator = denominator + 1
	result = numerator / denominator
	return result

def do_rpi(input_file,output_file):
	fout = open(output_file,'w')
	fin = open(input_file,'r')
	count_line = fin.readline()
	count_line = count_line.strip()
	line_count = int(count_line)
	for lnum in range(line_count):
		casenum = lnum + 1
		fout.write('Case #' + str(casenum) + ': ')
		dataline = fin.readline()
		dataline = dataline.strip()
		number_of_teams = int(dataline)
		schedule = list ()
		for teamno in range(number_of_teams):
			dataline = fin.readline()
			dataline = dataline.strip()
			schedule.append(dataline)
		wp_list = list ()
		for teamno in range(number_of_teams):
			wp_team = calculate_wp_without(schedule,number_of_teams,teamno,-1)
			wp_list.append(wp_team)
		owp_list = list ()
		for teamno in range(number_of_teams):
			total_num = 0
			total_dnom = 0
			for opponentno in range(number_of_teams):
				if schedule[teamno][opponentno] != '.':
					wp_team_wout = calculate_wp_without(schedule,number_of_teams,opponentno,teamno)
					total_num = total_num + wp_team_wout
					total_dnom = total_dnom + 1
			owp_final = total_num / total_dnom
			owp_list.append(owp_final)
		oowp_list = list ()
		for teamno in range(number_of_teams):
			total_num = 0
			total_dnom = 0
			for opponentno in range(number_of_teams):
				if schedule[teamno][opponentno] != '.':
					total_num = total_num + owp_list[opponentno]
					total_dnom = total_dnom + 1
			oowp_final = total_num / total_dnom
			oowp_list.append(oowp_final)
		fout.write("\n")
		for teamno in range(number_of_teams):
			rpi = (0.25 * wp_list[teamno]) + (0.50 * owp_list[teamno]) + (0.25 * oowp_list[teamno])
			fout.write(str(rpi))
			fout.write("\n")
	fin.close()
	fout.close()

def main():
	runname = 'A-large'
	input_file = runname + '.in'
	output_file = runname + '.out'
	do_rpi(input_file,output_file)

main()
