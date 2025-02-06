# Open the data.csv file for reading
with open("data.csv", "r") as file:
    lines = file.readlines()

# Process and print each line
for line in lines:
    # Split by comma and strip extra spaces/newlines from each element
    print(list(map(lambda x: x.strip(), line.split(","))))
