def keys_to_num(keys)
	key_nums = {}
	if (keys)
		keys.each do |key| 
			key_nums[key] = 0 if !key_nums.has_key?(key)
			key_nums[key]  = key_nums[key] + 1
		end
	end
	return key_nums
end

def add_chest_keys(key_nums, chest)
	chest['key_nums'].each_pair do |key,n|
		key_nums[key] = 0 unless key_nums.has_key?(key)
		key_nums[key] += n
	end
end
def check(key_nums_mst, chests_mst)
	total_keys = key_nums_mst.clone
	chests_mst.each_value{|chest| add_chest_keys(total_keys,chest)}
	chests_mst.each_value do |chest|
		key_type = chest['key_type']
		unless total_keys.has_key?(key_type)
			return false
		end
		if total_keys[key_type]==1 && chest['key_nums'][key_type]==1
			return false
		end
	end
	chests_mst.each_value do |chest|
		key_type = chest['key_type']
		total_keys[key_type] -= 1
		if (total_keys[key_type] < 0)
			return false
		end
	end

	#p 'hoge'
	#p key_nums_mst
	#p chests_mst
	chests_mst.each_pair do |i,chest|
		key_type = chest['key_type']
		if key_nums_mst.has_key?(key_type) && key_nums_mst[key_type]>0
			chests = chests_mst.clone
			chests.delete(i)
			if chests.size == 0
				return [i]
			end
			key_nums = key_nums_mst.clone
			add_chest_keys(key_nums,chest)

			key_nums[key_type] -= 1
			if key_nums[key_type]<=0
				key_nums.delete(key_type)
				if key_nums.size<=0
					next
				end
			end

			child_tree = check(key_nums, chests)
			#p child_tree
			if child_tree
				return   [i] + child_tree
			end
		end
	end
	return false
end

def main(file)
	file.gets.to_i.times do |i_case|
		key_num,chest_num = file.gets.split(' ').map{|s| s.to_i}
		keys = file.gets.split(' ').map{|s| s.to_i}

		chests = {}
		(1..chest_num).each do |i|
			datas = file.gets.split(' ').map{|s| s.to_i}

			chests[i] = {
				'key_type' => datas[0], 
				'key_nums' => keys_to_num(datas[2..-1])
			}
		end

		dst = check(keys_to_num(keys), chests)
		dst = dst ? dst.join(' ') : 'IMPOSSIBLE'

		puts 'Case #' + (i_case+1).to_s + ': ' + dst
	end
end

main(ARGF) unless $PROGRAM_NAME == 'irb'

