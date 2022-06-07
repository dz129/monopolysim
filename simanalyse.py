color = open("C:/Users/laser/Desktop/C++/monopoly/color.txt", 'r')
colorlist = color.readlines()
newcolorlist = [line.rstrip() for line in colorlist]
print(newcolorlist)
win = open("C:/Users/laser/Desktop/C++/monopoly/winner.txt", 'r')
winlist = win.readlines()
newwinlist = [line.rstrip() for line in winlist]
print(newwinlist)
def countcolor(list):
    total = 0
    purp = 0
    lblue = 0
    pink = 0
    orange = 0
    red = 0
    yellow = 0
    green = 0
    blue = 0
    for i in list:
        if i == "purple":
            total  += 1
            purp += 1
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
    print("Purple Percent: " + str(purp/total))
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
        if i == "2":
            total += 1
            two += 1
        if i == "3":
            total += 1
            three += 1
    print("Player1 percentage win: " + str(one/total))
    print("Player2 percentage win: " + str(two/total))
    print("Player3 percentage win: " + str(three/total))
        
countcolor(newcolorlist)
countwins(newwinlist)