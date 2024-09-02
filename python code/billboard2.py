fin = open("billboard.in", "r")
fout = open("billboard.out", "w")

bill = list(map(int, fin.readline().split()))
bess = list(map(int, fin.readline().split()))

Bwidth = bill[2] - bill[0]
Bheight = bill[3] - bill[1]

if bill[3] <= bess[1] or bill[1] >= bess[3] or bill[0] >= bess[2] or bill[2] <= bess[0]:
    tarp = Bwidth * Bheight
    
else:
    Iwidth = min(bill[2], bess[2]) - max(bill[0], bess[0])
    Iheight = min(bill[3], bess[3]) - max(bill[1], bess[1])
    
    if Iwidth == Bwidth and Iheight == Bheight:
        tarp = 0

    elif Iwidth == Bwidth:
        tarp = Bwidth * (Bheight - Iheight)
    
    elif Iheight == Bheight:
        tarp = Bheight * (Bwidth - Iheight)
    
    else:
        tarp = Bwidth * Bheight

fout.write(str(tarp))