# Searches database popularity of a problem
import csv

from cs50 import SQL

# open databese
db = SQL("sqlite:///favorites.db")

# prompt user for favorites
favorite = input("Favorites: ")

# search for title
rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem LIKE ?", "%" + favorite + "%")

# get first (and only ) row

row = rows[0]

# print popularity
print(row["COUNT(*)"])