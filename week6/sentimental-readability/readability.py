from cs50 import get_string


def main():
    text = get_string("Text: ")

    averageL = count_letters(text)/count_words(text)*100
    averageS = count_sentences(text)/count_words(text)*100
    print(f"av{averageL}")
    print(f"se{count_sentences(text)}")

    # coleman_liau formula
    index = 0.0588 * averageL - 0.296 * averageS - 15.8

    # grade level computed by formula
    x = round(index)

    # prints the output
    if x < 1:
        print("Before Grade 1")
    elif x >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {x}")


# analyze input

# calculate letters
def count_letters(text):
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


# calculate words
def count_words(text):
    words = 0
    for i in text:
        if i == " ":
            words += 1
    return words + 1


# calculate sentences
def count_sentences(text):
    sentences = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            sentences += 1
    return sentences


main()