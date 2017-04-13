import array

def main():
	# get top line
	infile = open("B-small-attempt0.in","r")
	outfile = open("B-small-attempt0.out","w")
	number_of_maps = infile.readline()
	number_of_maps = int(number_of_maps)
	for map_number in range(number_of_maps):
		dims_line = infile.readline()
		dims_list = dims_line.split()
		map_height = dims_list.pop(0)
		map_width = dims_list.pop(0)
		map_height = int(map_height)
		map_width = int(map_width)
		the_map = array.array('l')
		output_map = array.array('l')
		for map_row in range(map_height):
			map_line = infile.readline()
			map_list = map_line.split()
			for map_column in range(map_width):
				map_cell = map_list.pop(0)
				map_cell = int(map_cell)
				idx = ( map_row * map_width ) + map_column
				the_map.append(0)
				the_map[ idx ] = map_cell
				output_map.append(idx)
		for y in range(map_height):
			for x in range(map_width):
				# to start, give every coord a unique code
				output_map[ ( y * map_width ) + x ] = ( y * map_width ) + x
		# now "simulate" water flow:
		for y in range(map_height):
			for x in range(map_width):
				alt = the_map[ ( y * map_width ) + x ]
				dir_flow = 0
				if y > 0:
					north = the_map[ ( (y - 1) * map_width ) + x ]
					if north < alt:
						dir_flow = 1
						alt = north
				if x > 0:
					west = the_map[ ( y * map_width ) + (x - 1) ]
					if west < alt:
						dir_flow = 2
						alt = west
				if x < (map_width - 1):
					east = the_map[ ( y * map_width ) + (x + 1) ]
					if east < alt:
						dir_flow = 3
						alt = east
				if y < (map_height - 1):
					south = the_map[ ( (y + 1) * map_width ) + x ]
					if south < alt:
						dir_flow = 4
						alt = south
				old_code = output_map[ ( y * map_width ) + x ]
				if dir_flow == 1:
					# north
					new_code = output_map[ ( (y - 1) * map_width ) + x ]
				elif dir_flow == 2:
					# west
					new_code = output_map[ ( y * map_width ) + (x - 1) ]
				elif dir_flow == 3:
					# east
					new_code = output_map[ ( y * map_width ) + (x + 1) ]
				elif dir_flow == 4:
					#south
					new_code = output_map[ ( (y + 1) * map_width ) + x ]
				if dir_flow > 0:
					# this is very inefficient, might get hammered for this
					for propagate_row in range(map_height):
						for propagate_col in range(map_width):
							if output_map[ ( propagate_row * map_width) + propagate_col ] == old_code:
								output_map[ ( propagate_row * map_width) + propagate_col ] = new_code
		case_num = map_number + 1
		outfile.write("Case #" + str(case_num) + ":\n")
		map_to_ol_chars = dict()
		nextchar = 96
		for y in range(map_height):
			for x in range(map_width):
				
				code = output_map[ ( y * map_width ) + x ]
				
				if code in map_to_ol_chars:
					outchar = map_to_ol_chars[code]
				else:
					nextchar = nextchar + 1
					
					map_to_ol_chars[code] = nextchar
					outchar = nextchar
				if x > 0:
					outfile.write(" ")
				outfile.write(chr(outchar))
			outfile.write("\n")
	outfile.close()
	infile.close()

main()
