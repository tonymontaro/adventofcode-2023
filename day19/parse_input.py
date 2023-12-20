s = ""
with open('to_process.txt', 'r') as file:
    for line in file:
        s += line
s, nxt = s.split("\n\n")
s = s.split("\n")
res = str(len(s)) + "\n"

for line in s:
    line = line.replace("{", " ")
    line = line.replace("}", "")
    x, line = line.split()
    
    line = line.split(",")
    res += x + " " + line[-1] + " " + str(len(line)-1) + " "
    line.pop()
    for ln in line:
        ln = ln.split(":")
        res += ln[0] + " " + ln[1] + " "
    res = res.strip()
    res += "\n"

s = nxt.replace("{", "").replace("}", "").split("\n")
res += str(len(s)) + "\n"
for line in s:
    line = line.replace("=", " ").replace(",", " ")
    res += line + "\n"
    

# print(res)
with open("test_input.txt", "w") as f:
    f.write(res)