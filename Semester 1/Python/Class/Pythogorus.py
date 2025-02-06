class PythagoreanTripletFinder:
    def __init__(self, limit):
        self.limit = limit

    def find_triplets(self):
        triplets = []
        for a in range(1, self.limit):
            for b in range(a, self.limit):
                c = (a**2 + b**2) ** 0.5
                if c == int(c) and c <= self.limit:
                    triplets.append((a, b, int(c)))
        return triplets

    def display_triplets(self):
        triplets = self.find_triplets()
        if triplets:
            print(f"Pythagorean triplets up to {self.limit}:")
            for triplet in triplets:
                print(triplet)
        else:
            print(f"No Pythagorean triplets found up to {self.limit}.")

# Example usage
if __name__ == "__main__":
    limit = int(input("Enter the limit to find Pythagorean triplets: "))
    finder = PythagoreanTripletFinder(limit)
    finder.display_triplets()