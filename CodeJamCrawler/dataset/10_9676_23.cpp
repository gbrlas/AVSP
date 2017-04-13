def string_to_list(my_st):
	new_list = []
	lx = len(my_st)
	for i in range(lx):
		c = my_st[i]
		new_list.append(c)
	return new_list

def rotate_board(old_board,square):
	new_board = []
	new_board.extend(old_board)
	for x in range(square):
		for y in range(square):
			new_board[(y*square)+x] = old_board[((square-1-x)*square)+y]
	return new_board
			
def apply_gravity(the_board,square):
	for x in range(square):
		new_column = []
		for i in range(square):
			y = square-1-i
			ix = (y*square)+x
			c = the_board[ix] 
			if c != '.':
				new_column.append(c)
			the_board[ix] = '.'
		y = square
		for c in new_column:
			y = y - 1
			ix = (y*square)+x
			the_board[ix] = c
	return the_board

def find_k_in_row(board,square,num_in_row):
	red = False
	blue = False
	for st_num in range(4):
		if st_num == 0:
			deltax = 0
			deltay = 1
		if st_num == 1:
			deltax = 1
			deltay = 0
		if st_num == 2:
			deltax = 1
			deltay = 1
		if st_num == 3:
			deltax = -1
			deltay = 1
		for start_x in range(square):
			for start_y in range(square):
				if board[(start_y*square)+start_x] != '.':
					piece = board[(start_y*square)+start_x]
					all_ok = True
					this_x = start_x
					this_y = start_y
					for i in range(num_in_row-1):
						this_x = this_x + deltax
						this_y = this_y + deltay
						if (this_x >= 0) and (this_x < square):
							if (this_y >= 0) and (this_y < square):
								if board[(this_y*square)+this_x] != piece:
									all_ok = False
							else:
								all_ok = False
						else:
							all_ok = False
					if all_ok:
						if piece == 'R':
							red = True
						if piece == 'B':
							blue = True
	if red and blue:
		return 'Both'
	if red:
		return 'Red'
	if blue:
		return 'Blue'
	return 'Neither'

def main():
	fname = 'A-large'
	outfile = open(fname + '.out','w')
	infile = open(fname + '.in','r')
	cases_str = infile.readline()
	cases_str.strip()
	cases_count = int(cases_str)
	for case_num in range(cases_count):
		case_line = infile.readline()
		case_line = case_line.strip()
		case_list = case_line.split(' ')
		square = case_list[0]
		square = int(square)
		number_to_match = case_list[1]
		number_to_match = int(number_to_match)
		board_string = ''
		for line_num in range(square):
			board_line = infile.readline()
			board_line = board_line.strip()
			board_string = board_string + board_line
		my_board = string_to_list(board_string)
		my_board = rotate_board(my_board,square)
		my_board = apply_gravity(my_board,square)
		result = find_k_in_row(my_board,square,number_to_match)
		this_case = case_num + 1
		outfile.write('Case #' + str(this_case) + ': ' + result + "\n")
	infile.close()
	outfile.close()

main()
