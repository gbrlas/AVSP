def main(file)
	file.gets.to_i.times do |i_case|
		datas = file.gets.split.map{|i| i.to_i}
		num = datas[0]
		judges = datas[1,num].map{|i| i.to_f}
		bigs = judges.sort.reverse

		total = judges.inject{|sum,i| sum+=i}
		total_d = total * 2.0

		cur = 0
		n = num
		ave = total_d/n
		total_tmp = total_d
		while(bigs[cur]>ave) do
			total_tmp -= bigs[cur]
			cur += 1
			ave = total_tmp/(num-cur)
		end

		dsts = []
		judges.each do |i|
			dst = 0
			if (i<ave) then
				dst = ((ave-i)/total)*100.0
			end

			dsts.push(sprintf("%.6f", dst))
		end

		print 'Case #' + (i_case+1).to_s + ':'
		dsts.each{|dst| print " "+dst}
		print "\n"

	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

