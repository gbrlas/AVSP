def get_inheds(cs, inheds, tgt)
	if inheds[tgt] == nil then
		inheds[tgt]=1<<tgt
		ins = cs[tgt]
		if ins!=nil then
			ins.each do |i_tgt|
				#p 'hoge'
				#p tgt+1
				#p i_tgt+1
				list,dia = get_inheds(cs,inheds,i_tgt)
				return nil,dia if dia
				
				dia = (0!=(inheds[tgt]&list))
				return nil,dia if dia

				inheds[tgt] += list
			end
		end
	end
	return inheds[tgt],false
end

def main(file)
	file.gets.to_i.times do |i_case|
		c_num = file.gets.to_i
		cs = []
		c_num.times do |i|
			d = file.gets.split.map{|s| s.to_i}
			num = d[0]
			cs[i] = d[1,num].map{|i| i-1}
		end

		dia = false
		inheds = Array.new(c_num,nil)
		c_num.times do |i|
			list,dia = get_inheds(cs,inheds,i)
			break if dia
		end

		puts 'Case #' + (i_case+1).to_s + ': ' + (dia ?'Yes':'No')
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

