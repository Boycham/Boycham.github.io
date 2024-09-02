fin = open("blocks.in", "r")
fout = open("blocks.out", "w")

abc = [0] * 26

n = int(fin.readline())


for i in range(n):
    letters1, letters2 = fin.readline().split()
    added = [0] * 26
    
    for letter in letters1:
        added[ord(letter)-97] += 1
    
    for a in letters2:
        if letters2.count(a) > added[ord(a)-97]:
            added[ord(a)-97] = letters2.count(a)
   
    for num in range(26):
        abc[num] += added[num]
    
    added = [0] * 26
    

for b in abc:
    fout.write(str(b) + "\n")
            