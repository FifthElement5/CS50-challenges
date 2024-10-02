s = input("Do you agree?")

s = s.lower()
# if s == "Y" or s =="y":
if s in ["y", "yes"]:
# if s.lower() in ["Y", "y"]:
    print("Agreed.")

# elif s == "N" or "n":
elif s in ["n", "no"]:
# elif s.lower() in ["N", "n"]:

    print("Not agreed.")