import random

def game():
    print("Welcome to the Guessing Game!")
    print("You have to guess if the next number will be higher or lower.")
    print("The odds of guessing correctly are 1 out of 7.")
    print("Let's start!")

    current_number = random.randint(1, 100)
    print(f"The current number is {current_number}.")

    while True:
        guess = input("Do you think the next number will be higher or lower? (H/L): ")
        next_number = random.randint(1, 100)

        if guess.lower() == 'h' and next_number > current_number:
            print(f"Congratulations! The next number was {next_number}, which is higher than {current_number}.")
            break
        elif guess.lower() == 'l' and next_number < current_number:
            print(f"Congratulations! The next number was {next_number}, which is lower than {current_number}.")
            break
        else:
            print(f"Sorry, the next number was {next_number}. Try again!")
            current_number = next_number

game()
