# import math

def number_to_bitflag(num_bits):
	x = 1
	for i in range(num_bits - 1):
		x = x * 2
	return x

def is_power_of_two(number):
	x = 1
	i = 0
	while x < number:
		i = i + 1
		x = x * 2
		if x == number:
			return [True,i]
	return [False,i]


def main():
	fname = 'A-small-attempt1'
	outfile = open(fname + '.out','w')
	infile = open(fname + '.in','r')
	cases_str = infile.readline()
	cases_str.strip()
	cases_count = int(cases_str)
	for case_num in range(cases_count):
		case_line = infile.readline()
		case_line = case_line.strip()
		case_list = case_line.split(' ')
		snappers = case_list[0]
		snappers = int(snappers)
		snaps = case_list[1]
		snaps = int(snaps)
		snapr_bits = number_to_bitflag(snappers + 1)
		sp1 = snaps + 1
		if sp1 > snapr_bits:
			sp1 = sp1 % snapr_bits
		if sp1 == 0:
			result = "ON"
		else:
			izp2 = is_power_of_two(sp1)
			if izp2[0]:
				if izp2[1] == snappers:
					result = "ON"
				else:
					result = "OFF"

			else:
				result = "OFF"
		this_case = case_num + 1
		outfile.write('Case #' + str(this_case) + ': ' + result + "\n")
	infile.close()
	outfile.close()

main()
