def main(file)
	file.gets.to_i.times do |i_case|
		a,b = file.gets.split.map{|s| s.to_i}
		prob = file.gets.split.map{|s| s.to_f}
		probs = []
		prob.each_with_index do |pb,i|
			if ( i==0 ) then
				probs[0] = pb
				next
			end
			probs[i] = probs[i-1] * pb
		end

		dst = b+2
		a.times do |i|
			pb = probs[a-i-1]
			after = b-a+i
			stroke = pb*after + (1.0-pb)*(after+1+b) + 1 + i
			dst = stroke if (stroke<dst)
		end

		
		puts 'Case #' + (i_case+1).to_s + ': ' + dst.to_s
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

