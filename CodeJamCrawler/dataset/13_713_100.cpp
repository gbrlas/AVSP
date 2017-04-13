dp_keys = []
dp_all = {}

def is_kaibun(n)
	str = n.to_s
	digit = str.length
	ret = false
	if digit == 1
		ret = true
	else
		half = digit/2
		ret = (str[0,half].reverse == str[-half])
	end
	return ret
end

def get_next(n)
	str = n.to_s
	digit = str.size
	if digit == 1
		return n+1
	end

	half = digit/2
	front = str[0,half]
	front_reverse = front.reverse
	back = str[-half]
	if front_reverse.to_i > back.to_i
		str[half,half] = front_reverse
		return str.to_i
	end

	str[half-1] = (str[half-1].to_i + 1).to_s
	return str.to_i - back.to_i
end

def calc_list(range)
	current = range.first
	ret = []
	while(current<=range.last)
		if ( is_kaibun(current) && is_kaibun(current*current))
			ret.push current
		end
		current = get_next(current)
	end
	return ret
end

def check(a_sr,b_sr)
	#dps = []
	#dp_keys.each do |range|
	#	break if b_sr < range.first
	#	dps.push(range) if a_sr < range.last
	#end

	#new_dps = {}
	#dps.each do |range|
	#	if a_sr < range.first
	#		new_range = (a_sr..range.first)
	#		new_dps[new_range] = calc_list(new_range)
	#	elsif a_sr < range.last
	#	end
	#end

	return calc_list(a_sr..b_sr).size.to_s
end

def main(file)
	file.gets.to_i.times do |i_case|
		a,b = file.gets.split(' ').map{|s| s.to_i}

		dst = check(Math::sqrt(a).ceil, Math::sqrt(b).truncate)
		puts 'Case #' + (i_case+1).to_s + ': ' + dst
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

