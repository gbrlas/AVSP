def euclid_gcd(a,b):
	while True:
		if a > b:
			c = a
			a = b
			b = c
		while b >= a:
			if a == 0:
				return b
			b = b % a
		if b == 0:
			return a


def main():
	fname = 'B-small-attempt0'
	outfile = open(fname + '.out','w')
	infile = open(fname + '.in','r')
	cases_str = infile.readline()
	cases_str.strip()
	cases_count = int(cases_str)
	for case_num in range(cases_count):
		case_line = infile.readline()
		case_line = case_line.strip()
		case_list = case_line.split(' ')
		num_great_events = case_list[0]
		num_great_events = int(num_great_events)
		event_list = []
		for i in range(num_great_events):
			event_list.append(int(case_list[i + 1]))
		diff_list = []
		dl_size = 0
		for i in range(num_great_events - 1):
			for j in range(i + 1,num_great_events):
				dx = abs(event_list[i] - event_list[j])
				diff_list.append(dx)
				dl_size = dl_size + 1
		if dl_size == 1:
			my_gcd = diff_list[0]
		else:
			my_gcd = euclid_gcd(diff_list[0],diff_list[1])
			if dl_size > 2:
				for i in range(2,dl_size):
					my_gcd = euclid_gcd(my_gcd,diff_list[i])
		min_of_events = event_list[0]
		for i in range(1,num_great_events):
			if event_list[i] < min_of_events:
				min_of_events = event_list[i]
		remd = min_of_events % my_gcd
		if remd == 0:
			need_to_add = 0
		else:
			need_to_add = my_gcd - remd
		this_case = case_num + 1
		outfile.write('Case #' + str(this_case) + ': ' + str(need_to_add) + "\n")
	infile.close()
	outfile.close()

main()
