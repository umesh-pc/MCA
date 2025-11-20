class Rectangle:
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def area(self):
        return self.length * self.breadth

class Cuboid(Rectangle):
    def __init__(self, length, breadth, height):
        super().__init__(length, breadth)
        self.height = height

    def volume(self):
        return self.area() * self.height

    def __lt__(self, other):
        if isinstance(other, Cuboid):
            return self.volume() < other.volume()
        else:
            return NotImplemented

# --- User Input Section ---
def get_cuboid_data(name):
    """Prompts the user for length, breadth, and height for a cuboid."""
    print(f"\n--- Enter Dimensions for {name} ---")
    
    # Use float() to ensure inputs are treated as numbers (allowing decimals)
    try:
        length = float(input("Enter Length: "))
        breadth = float(input("Enter Breadth: "))
        height = float(input("Enter Height: "))
        return Cuboid(length, breadth, height)
    except ValueError:
        print("Invalid input. Please enter numerical values.")
        return None

# Get inputs for the two cuboids
cuboid_A = get_cuboid_data("Cuboid A")
cuboid_B = get_cuboid_data("Cuboid B")

# --- Comparison and Output ---
if cuboid_A and cuboid_B:
    print("\n--- Results ---")
    
    volume_A = cuboid_A.volume()
    volume_B = cuboid_B.volume()
    
    print(f"Volume of Cuboid A: {volume_A}")
    print(f"Volume of Cuboid B: {volume_B}")
    
    # Use the overloaded '<' operator for comparison
    if cuboid_A < cuboid_B:
        print(f"\n✅ Comparison: Cuboid A is smaller than Cuboid B ({volume_A} < {volume_B})")
    elif cuboid_B < cuboid_A:
        print(f"\n✅ Comparison: Cuboid B is smaller than Cuboid A ({volume_B} < {volume_A})")
    else:
        # If neither A < B nor B < A, their volumes must be equal
        print(f"\n⚖️ Comparison: Cuboid A and Cuboid B have equal volume ({volume_A} = {volume_B})")