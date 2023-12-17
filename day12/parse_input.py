# part 2
with open('to_process.txt', 'r') as file:
    st = ""
    total = 0
    for line in file:
        s, nums = line.split()
        ss = [s for _ in range(5)]
        s = '?'.join(ss)
        nums = [nums for _ in range(5)]
        nums = ','.join(nums)
        nums = nums.split(',')

        st += s
        st += " " + str(len(nums)) + " "
        for num in nums:
            st += num + " "
        st += "\n"
        total += 1
    st = str(total) + "\n" + st

        
    # print(st)

        # output_s = add_line(output_s, len(s))
        # for x in s:
        #     rs = x.split(', ')
        #     output_s = add_line(output_s, len(rs))
        #     for y in rs:
        #         output_s = add_line(output_s, y)

    print("\n")

with open("test_input.txt", "w") as f:
    f.write(st)