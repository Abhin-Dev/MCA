import random

# Sample list of people in the group
group = [
    "Alice", "Bob", "Charlie", "David", "Eve", 
    "Frank", "Grace", "Hank", "Ivy", "Jack", 
    "Karen", "Leo", "Mona", "Nina", "Oscar", 
    "Paul", "Quincy", "Rachel", "Steve", "Tina"
]

# Ensure the group has at least 10 people
if len(group) < 10:
    print("The group does not have enough people.")
else:
    # Select 10 random people from the group
    selected_people = random.sample(group, 10)
    
    # Print the selected people
    print("Selected people:")
    for person in selected_people:
        print(person)