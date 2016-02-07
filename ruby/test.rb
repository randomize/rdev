# Comment
#

=begin
first_num = gets.to_i

puts "Enter another: "
second_num = gets.to_i


result = first_num + second_num

puts first_num.to_s + "+" + second_num.to_s + "=" + result.to_s


num_one = 1.000
num_99 = 1.999

puts (num_one - num_99).to_s

puts "a".class

A_CONST = 1.0f
=end

write_handler = File.new("sum.txt", "w")
write_handler.puts("Rando Test")
write_handler.close

data_from_filr = File.read("sum.txt")
puts "Data form file: " + data_from_filr

# load 




