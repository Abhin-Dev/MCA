import csv

# Data to be written to CSV
datadict = [
    {"Id": 101, "Name": "Joseph", "Age": 18, "Mark": 40},
    {"Id": 102, "Name": "Aju", "Age": 18, "Mark": 47},
    {"Id": 103, "Name": "Navya", "Age": 20, "Mark": 45},
    {"Id": 104, "Name": "Praveen", "Age": 21, "Mark": 47},
]

# Writing data to CSV using csv module
with open("result.csv", mode="w", newline="") as file:
    writer = csv.DictWriter(file, fieldnames=datadict[0].keys())
    writer.writeheader()
    writer.writerows(datadict)

# Reading and printing data from CSV
print("File data")
with open("result.csv", mode="r") as file:
    reader = csv.reader(file)
    for row in reader:
        print(" ".join(row))
