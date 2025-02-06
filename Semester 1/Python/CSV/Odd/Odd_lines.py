# Open the email.csv file for reading
with open("email.csv", "r") as file:
    rows = file.readlines()

# Open result.csv file for writing
with open("result.csv", "w") as file:
    file.write(rows[0])  # Writing the heading (first row)
    
    # Write every other row starting from the second row (odd-indexed rows)
    for i in range(1, len(rows)):
        if i % 2 == 1:  # This condition skips even-indexed rows
            file.write(rows[i])
