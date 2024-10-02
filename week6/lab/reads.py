import csv

books = []

# add books to your shelf by reading fro books.csv
#file = open("books.csv")
with open("books.csv") as file:
    # text = file.read()
    # print(text)
    file_reader = csv.DictReader(file)
    for book in file_reader:
        # print(book)
        books.append(book)
print(books)

for book in books:
    print(book["title"])
