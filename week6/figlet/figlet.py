import sys
import random
from pyfiglet import Figlet

figlet = Figlet()



if len(sys.argv) == 1:
    isRandomFont = True
    #print(f"Output: {isRandomFont}")
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    isRandomFont = False
else:
    sys.exit(1)


# print(isRandomFont)


# list of avaliable fonts
figlet.getFonts()


if isRandomFont == False:
    try:
        figlet.setFont(font=sys.argv[2])
        #print(figlet.renderText(input))
    except:
        print("Invalid usage")
        sys.exit(1)
else:
    font = random.choice(figlet.getFonts())

input = input("Input:")


print("Output: ")
print(figlet.renderText(input))

