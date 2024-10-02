import csv
import sys


def main():

    # TODO: Check for command-line usage
    from sys import argv
    if len(argv) != 3:
        print("Error")
        sys.exit(1)

    # TODO: Read database file into a variable
    data = []
    with open(argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            data.append(row)
    # print(f"data{data}")

    # TODO: Read DNA sequence file into a variable
    with open(argv[2], "r") as file:
        sequence = file.read()
    # print(f"Dna: {sequence}")

    # TODO: Find longest match of each STR in DNA sequence
    subs = list(data[0].keys())[1:]
    # print(f"sub{subs}")
    STR = {}
    for subsequence in subs:
        STR[subsequence] = longest_match(sequence, subsequence)

    # print(f"str{STR}")
    # print(f"s:{STR[subsequence]}")
    # TODO: Check database for matching profiles
    for profile in data:
        matches = 0
        for subsequence in subs:
            if int(profile[subsequence]) == STR[subsequence]:
                matches += 1

        if matches == len(subs):
            print(profile["name"])
            return
    print("no match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
