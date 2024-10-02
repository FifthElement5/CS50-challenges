import csv

from cs50 import SQL



# creat table of house
def table_house(house, houses, head):
    count = 0
    for h in houses:
        if h["house"] == house:
            count += 1
    if count == 0:
        houses.append({"house": house, "head": head})


def table_student(name, students):
    students.append({"student_name": name})


def table_assignment(name, house, assignments):
    assignments.append({"student_name": name, "house": house})


db = SQL("sqlite:///roster.db")



# creating lists
students = []
houses = []
assignments = []



# reading file
with open("students.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # creating variable

        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        print(row)
       # print(head)
        table_house(house, houses, head)
        table_student(name, students)
        table_assignment(name, house, assignments)

    print(houses)
    #print(students)
    print("ASSIGNMENT:    ", assignments)


for student in students:
    db.execute("INSERT INTO students (student_name) VALUES(?)", student["student_name"])

for a in assignments:
    db.execute("INSERT INTO assignments (student_name, house) VALUES(?, ?)", a["student_name"], a["house"])


for house in houses:
    db.execute("INSERT INTO houses (house, head) VALUES(?, ?)", house["house"], house["head"])



