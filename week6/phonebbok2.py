import csv

# file = open("phonebbok2.csv", "a")
with open("phonebbok2.csv", "a") as file:

    # get name and number
    name = input("Name: ")
    number = input("Number: ")

    #OPEN csv file
    # writer = csv.writer(file)
    writer = csv.DictWriter(file, fieldnames=["name", "number"])

    # PRINT to file
    # writer.writerow([name, number])
    writer.writerow({"name": name, "number": number})

file.close()

