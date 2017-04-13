def solve(name,n)
	poses = [];
	count = 0
	name.each_with_index do |w,idx|
		unless ( w=='a' or w=='i' or w=='u' or w=='e' or w=='o') then
			count+=1
			if (count>=n) then
				poses.push(idx)
			end
		else
			count = 0
		end
	end

	dst = 0
	last_idx = name.size-1
	prev_pos = -1 
	poses.each_with_index do |pos,idx|
		before = pos-n-prev_pos
		after = last_idx-pos
		dst += (before+1) * (after+1)
		prev_pos = pos-n+1
	end

	return dst
end

def main(file)
	file.gets.to_i.times do |i_case|
		name,n = file.gets.split(' ');

		dst = solve(name.split(''), n.to_i)
		puts 'Case #' + (i_case+1).to_s + ': ' + dst.to_s
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

