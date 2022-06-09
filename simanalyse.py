#CURRENTLY ONY DISPLAYS PERCENTAGES AND COUNTS, WILL ADD FUTURE FUNCTIONALITY
color = open("C:/Users/laser/Desktop/C++/monopoly/color.txt", 'r')
colorlist = color.readlines()
newcolorlist = [line.rstrip() for line in colorlist]

win = open("C:/Users/laser/Desktop/C++/monopoly/winner.txt", 'r')
winlist = win.readlines()
newwinlist = [line.rstrip() for line in winlist]

props = open("C:/Users/laser/Desktop/C++/monopoly/prop.txt", 'r')
proplist = props.readlines()
newproplist = [line.rstrip() for line in proplist]
def countcolor(list):
    total = 0
    brown = 0
    lblue = 0
    pink = 0
    orange = 0
    red = 0
    yellow = 0
    green = 0
    blue = 0
    for i in list:
        if i == "brown":
            total  += 1
            brown += 1
        if i == "lblue":
            total  += 1
            lblue += 1
        if i == "pink":
            total  += 1
            pink += 1
        if i == "orange":
            total  += 1
            orange += 1
        if i == "red":
            total  += 1
            red += 1
        if i == "green":
            total  += 1
            green += 1
        if i == "yellow":
            total  += 1
            yellow += 1
        if i == "blue":
            total  += 1
            blue += 1
    print("Brown Percent: " + str(brown/total))
    print("Light Blue Percent: " + str(lblue/total))
    print("Pink Percent: " + str(pink/total))
    print("orange Percent: " + str(orange/total))
    print("red Percent: " + str(red/total))
    print("yellow Percent: " + str(yellow/total))
    print("green Percent: " + str(green/total))
    print("blue Percent: " + str(blue/total))

def countwins(list):
    total = 0
    one = 0
    two = 0
    three = 0
    for i in list:
        if i == "0":
            total += 1
            one += 1
        if i == "1":
            total += 1
            two += 1
        if i == "2":
            total += 1
            three += 1
    print("Player1 percentage win: " + str(one/total))
    print("Player2 percentage win: " + str(two/total))
    print("Player3 percentage win: " + str(three/total))
        
def countprops(list):
    total = 0
    med = 0
    com = 0
    chance = 0
    bal = 0
    tax = 0
    rail = 0
    ori = 0
    ver = 0
    con = 0
    jail = 0
    stC = 0
    electric = 0
    stat = 0
    virg = 0
    stJ = 0
    ten = 0
    NY = 0
    fpark = 0
    ken = 0
    ind = 0
    ill = 0
    atl = 0
    ven = 0
    ww = 0
    marv = 0
    pac = 0
    NC = 0
    penn = 0
    PP = 0
    Bw = 0
    go = 0
    for i in list:
        if i == "Go":
            total += 1
            go += 1
        if i == "Mediterranean Avenue":
            total += 1
            med += 1
        if i == "Community Chest":
            total += 1
            com += 1
        if i == "Baltic Ave":
            total += 1
            bal += 1
        if i == "Income Tax":
            total += 1
            tax += 1
        if i == "Reading Railroad" or i == "Pennsylvania Railroad" or i == "B&O Railroad" or i== "Short Line":
            total += 1
            rail += 1
        if i == "Oriental Ave":
            total += 1
            ori += 1
        if i == "Chance":
            total += 1
            chance += 1
        if i == "Vermont Ave":
            total += 1
            ver += 1
        if i == "Connecticut Ave":
            total += 1
            con += 1
        if i == "Jail":
            total += 1
            jail += 1
        if i == "St Charles Place":
            total += 1
            stC += 1
        if i == "Electric Company":
            total += 1
            electric += 1
        if i == "States Avenue":
            total += 1
            stat += 1
        if i == "Virginia Ave":
            total += 1
            virg += 1
        if i == "St James Place":
            total += 1
            stJ += 1
        if i == "Tennessee Avenue":
            total += 1
            ten += 1
        if i == "New York Ave":
            total += 1
            NY += 1
        if i == "Free Parking":
            total += 1
            fpark += 1
        if i == "Kentucky Ave":
            total += 1
            ken += 1
        if i == "Indiana Avenue":
            total += 1
            ind += 1
        if i == "Illinois Ave":
            total += 1
            ill += 1
        if i == "Atlantic Ave":
            total += 1
            atl += 1
        if i == "Ventnor Avenue":
            total += 1
            ven += 1
        if i == "Water Works":
            total += 1
            ww += 1
        if i == "Marvin Gardens":
            total += 1
            marv += 1
        if i == "Pacific Avenue":
            total += 1
            pac += 1
        if i == "North Carolina Avenue":
            total += 1 
            NC += 1
        if i == "Pennsylvania Avenue":
            total += 1
            penn += 1
        if i == "Park Place":
            total += 1
            PP += 1
        if i == "Luxury Tax":
            total += 1
            tax += 1
        if i == "Boardwalk":
            total += 1
            Bw += 1
    #Yes I know I could have just done a single function to get the count and the percentages as well as print it, i was tired lol
    print("Total: " + str(total))
    print("Med: " + str(med) + " %: " + str(med/total))
    print("Com: " + str(com) + " %: " + str(com/total))
    print("Chance: " + str(chance) + " %: " + str(chance/total))
    print("Bal: " + str(bal) + " %: " + str(bal/total))
    print("Tax: " + str(tax) + " %: " + str(tax/total))
    print("Rail: " + str(rail) + " %: " + str(rail/total))
    print("Ori: " + str(ori) + " %: " + str(ori/total))
    print("Ver: " + str(ver) + " %: " + str(ver/total))
    print("Con: " + str(con) + " %: " + str(con/total))
    print("Jail: " + str(jail) + " %: " + str(jail/total))
    print("stC: " + str(stC) + " %: " + str(stC/total))
    print("Electric: " + str(electric) + " %: " + str(electric/total))
    print("Stat: " + str(stat) + " %: " + str(stat/total))
    print("Virg: " + str(virg) + " %: " + str(virg/total))
    print("stJ: " + str(stJ) + " %: " + str(stJ/total))
    print("Ten: " + str(ten) + " %: " + str(ten/total))
    print("NY: " + str(NY) + " %: " + str(NY/total))
    print("Fpark: " + str(fpark) + " %: " + str(fpark/total))
    print("Ken: " + str(ken) + " %: " + str(ken/total))
    print("Ind: " + str(ind) + " %: " + str(ind/total))
    print("Ill: " + str(ill) + " %: " + str(ill/total))
    print("Atl: " + str(atl) + " %: " + str(atl/total))
    print("Ven: " + str(ven) + " %: " + str(ven/total))
    print("WW: " + str(ww) + " %: " + str(ww/total))
    print("Marv: " + str(marv) + " %: " + str(marv/total))
    print("Pac: " + str(pac) + " %: " + str(pac/total))
    print("NC: " + str(NC) + " %: " + str(NC/total))
    print("Penn" + str(penn) + " %: " + str(penn/total))
    print("PP: " + str(PP) + " %: " + str(PP/total))
    print("Bw: " + str(Bw) + " %: " + str(Bw/total))
    print("Go: " + str(go) + " %: " + str(go/total))
countcolor(newcolorlist)
countwins(newwinlist)
countprops(newproplist)
