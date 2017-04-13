def main(file)
	file.gets.to_i.times do |i_case|
		data = file.gets.split.map{|s| s.to_i}
		num = data[0]
		sup = data[1]
		over = data[2]
		scores = data[3..data.size]

		dst = 0
		scores.each do |score|
			two_amount = score - over
			if two_amount>=[(over-1),0].max*2 then
				dst = dst + 1
				next
			end

			if sup>0 && two_amount>=[(over-2),0].max*2 then
				sup = sup - 1
				dst = dst + 1
			end
		end
		puts 'Case #' + (i_case+1).to_s + ': ' + dst.to_s
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

