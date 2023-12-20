res = ""
s = ""
with open('to_process.txt', 'r') as file:
    for line in file:
        s += line

s = s.replace(",", "").replace("-> ", "")
res = str(len(s.split("\n"))) + "\n"

s = s.split("\n")
for line in s:
    res += str(len(line.strip().split())-1) + " " + line + "\n"

print(res)
with open("test_input.txt", "w") as f:
    f.write(res)