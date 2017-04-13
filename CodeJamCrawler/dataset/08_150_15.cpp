def pg #print gap
	puts "\n", "\n", "--", "\n", "\n"
end

def ph msg = ''
	puts "HERE #{msg}"
end

def cv value #copy hash, array by value
	if value.is_a? Array
		r = []
		value.each { |v|
			r << v
		}
		return r
	end
	if value.is_a? Hash
		r = {}
		value.each { |k,v|
			r[k] = v
		}
		return r
	end
end

def p *args #variable dump
	r = ''
	args.each { |e|
		r << e.inspect
		r << ", "
	}
	puts r
end

def ntfs value #number to float as a string
	"%.7f" % value
end

class Fi #read input file
	def initialize filename
		@lines = IO.readlines(filename).map { |e| e.strip }
		@number_of_cases = @lines.shift
	end
	
	def l nuol = 1
		number_of_lines = nuol.to_i
		r = []
		for i in 1..number_of_lines
			r << @lines.shift
		end
		return r.first if r.size == 1
		return r
	end
	
	def ne #end not reached
		return true if @lines.size > 0
		return false
	end
	
end

class Fo #write output file
	def initialize filename
		@f = File.open(filename, 'w')
		@i = 1
	end
	
	def <<(output)
		ans = "Case ##{@i}: #{output}\n"
		puts ans
		@f << ans
		@i = @i.next
	end
	
	def close
		@f.close
	end
end
