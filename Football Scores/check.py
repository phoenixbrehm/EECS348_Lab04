file = open("check.txt", "r")

chc = []

for line in file:
    if line in chc:
        print(line)
    else:
        chc.append(line)