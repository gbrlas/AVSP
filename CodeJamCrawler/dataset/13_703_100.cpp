def check(tbl,row_num,col_num)
	row_max = tbl.map{|row| row.max}
	col_max = (0..col_num-1).map{|m| tbl.map{|row| row[m]}.max}

	#ok_list = {}
	(0..row_num-1).each do |n|
		(0..col_num-1).each do |m|
			#next if ok_list.has_key?([n,m])
			if (tbl[n][m]<row_max[n] && tbl[n][m]<col_max[m])
				return false
			end
		end
	end

	return true;
end

def main(file)
	file.gets.to_i.times do |i_case|
		row_num,col_num = file.gets.split(' ').map{|s| s.to_i}
		tbl = []
		row_num.times do 
			tbl.push file.gets.split(' ').map{|s| s.to_i}
		end

		puts 'Case #' + (i_case+1).to_s + ': ' + (check(tbl,row_num,col_num) ? 'YES' : 'NO')
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

