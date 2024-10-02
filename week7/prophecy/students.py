from cs50 import SQL
import csv

db = SQL("sqlite:///roster.db")

with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        try:
            db.execute("INSERT INTO students (student_name) VALUES(?)", row["student_name"])
            student_id = db.execute("SELECT id FROM students WHERE student_name = ?", row["id"])
            db.execute("INSERT INTO houses (house, head) VALUES(?, ?)", row["house"], row["head"])
            house_id = db.execute("SELECT id FROM houses WHERE house = ?", row["id"])
            db.execute("INSERT INTO assignment (student_id, house_id) VALUES(?, ?)", student_id, house_id)
        except ValueError:
            continue