def main(file)
	tbl_src = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv'.split('')
	tbl_dst = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up'.split('')

	tbl = tbl_src.zip(tbl_dst).uniq
	tbl.push(['q','z'])
	tbl.push(['z','q'])

	hash = Hash[*tbl.flatten]


	file.gets.to_i.times do |i_case|
		src = file.gets.split('')
		dst = src.map{|s| hash[s]}.join

		puts 'Case #' + (i_case+1).to_s + ': ' + dst
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

