import random

# Function to get a number from the user
def get_user_number():
    while True:
        try:
            user_number = int(input("Enter a number between 1 and 10: "))
            if 1 <= user_number <= 10:
                return user_number
            else:
                print("Please enter a number between 1 and 10.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

# Generate a random number between 1 and 10
random_number = random.randint(1, 10)

# Get the user's number
user_number = get_user_number()

# Check if the guessed number matches the user's number
if random_number == user_number:
    print(f"Congratulations! The random number was {random_number}, and you guessed it correctly!")
else:
    print(f"Sorry, the random number was {random_number}. Your guess was incorrect.")