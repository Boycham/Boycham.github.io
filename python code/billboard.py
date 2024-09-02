fin = open("billboard.in", "r")
fout = open("billboard.out", "w")

farmer = list(map(int, fin.readline().split()))
bessie = list(map(int, fin.readline().split()))

Fwidth = abs(farmer[2] - farmer[0])
Fheight = abs(farmer[3] - farmer[1])

corner = 0
lbcorner = 0
ltcorner = 0
rbcorner = 0
rtcorner = 0

if bessie[0] <= farmer[0] and bessie[1] <= farmer[1]:
    lbcorner = 1
    corner += 1

if bessie[0] <= farmer[0] and bessie[3] >= farmer[3]:
    ltcorner = 1
    corner += 1
    
if bessie[2] >= farmer[2] and bessie[3] >= farmer[3]:
    rtcorner = 1
    corner += 1

if bessie[2] >= farmer[2] and bessie[1] <= farmer[1]:
    rbcorner = 1
    corner += 1
    
if corner == 2:
    if lbcorner == 1 and ltcorner == 1:
        tarp = abs(farmer[2] - bessie[2]) * Fheight
        
    elif lbcorner == 1 and rbcorner == 1:
        tarp = abs(farmer[3] - bessie[3]) * Fwidth

    elif ltcorner == 1 and rtcorner == 1:
        tarp = abs(farmer[1] - bessie[1]) * Fwidth

    elif rtcorner == 1 and rbcorner == 1:
        tarp = abs(farmer[0] - bessie[0]) * Fheight

elif corner < 2:
    tarp = Fwidth * Fheight
    
else:
    tarp = 0

fout.write(str(tarp))
