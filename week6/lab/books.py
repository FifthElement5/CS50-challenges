books = []

# Add three books to your shelf
for i in range(3):
    # blank dictionary
    book = dict()
    # add a key
    #add new valuse for a key title and key author
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ")
    #print(book)

    # insert books in our list
    books.append(book)

for book in books:
    print(book["title"])




# print(books)