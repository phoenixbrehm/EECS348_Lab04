file = open("check.txt", "r")
fileMatch = open("match.txt", "r")
chc = []
tr1 = False
tr2 = False
for line in file:
    if line in chc:
        print(line)
        tr1 = True
    else:
        chc.append(line)

for line in fileMatch:
    if line not in chc:
        print(f"{line} is not in our output")
        tr2 = True

if not tr1:
    print("We have no duplicates")
if not tr2:
    print("We are not missing any")