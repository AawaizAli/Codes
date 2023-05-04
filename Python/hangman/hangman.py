import random
from words import words
import string

def get_valid_word(words):
    word = random.choice(words)
    while '-' in word or ' ' in word:
        word = random.choice(words)

    return word.upper()

word = get_valid_word(words)

letters = set(word)
used_letters = set()
alphabet = set(string.ascii_uppercase)
correct_guesses = set()

# print(word)
# print(letters)
# print(alphabet)

tries_given = 8
tries_taken = 0

for i in word: 
    print("_ ", end = "")

print("\n\n")

while True:

    if tries_taken == tries_given:
        print(f'You are out of chances, please get lost \nThe word was {word}')
        break

    letter = input('Enter a letter: ').upper()

    used_letters.add(letter)

    if letter in alphabet:
        if letter in letters:
            print('The letter exists in word!')
            print()
            correct_guesses.add(letter)
            for i in word:
                if (i == letter) or (i in used_letters):
                    print(i, end = " ")
                else:
                    print('_', end = " ")
            print()
        else:
            print('Letter doesn\'t exist in word')
            tries_taken += 1
    else:
        print('Invalid Input')

    if letters.issubset(correct_guesses):
        print()
        print('YOU WON!')
        break

    print()
    print(f'Chances left: {tries_given-tries_taken}')

    print()
                

    

    


