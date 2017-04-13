def find_latest_occuring(engine_list, query_list):
	indexes = []
	for engine in engine_list:
		try:
			i = query_list.index(engine)
			indexes.append((i, engine))
		except:
			return -1
	indexes.sort()
	return indexes[-1][0]

def compute_switches(engine_list, query_list):
	from time import sleep
	index = find_latest_occuring(engine_list, query_list)
	switches = 0
	while index != -1:
		switches += 1
		query_list = query_list[index:]
		index = find_latest_occuring(engine_list, query_list)
	return switches

def main():
	from sys import argv
	input_file = open(argv[1]).readlines()
	num_cases = int(input_file[0])
	input_file = input_file[1:]
	for case in range(1, num_cases+1):
		num_engines = int(input_file[0])
		engines = input_file[1:1+num_engines]
		input_file = input_file[1+num_engines:]
		num_queries = int(input_file[0])
		queries = input_file[1: 1+num_queries]
		input_file = input_file[1+num_queries:]
		switches = compute_switches(engines, queries)
		print "Case #%d: %d" % ( case, switches)

if __name__=="__main__":
	main()
