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
        if min(bill[3], bess[3]) == bill[3] or max(bill[1], bess[1]) == bill[1]:
            tarp = Bwidth * (Bheight - Iheight)
        
        else:
            tarp = Bwidth * Bheight
    
    elif Iheight == Bheight:
        if min(bill[2], bess[2]) == bill[2] or max(bill[0], bess[0]) == bill[0]:
            tarp = Bheight * (Bwidth - Iwidth)
        
        else:
            tarp = Bwidth * Bheight
    
    else:
        tarp = Bwidth * Bheight

fout.write(str(tarp))
