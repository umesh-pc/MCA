def is_power_of_two(n: int) -> bool:
    if n < 0:
        raise ValueError("Negative numbers are not allowed.")
    if n == 0:
        return False  
    return (n & (n - 1)) == 0
n=int(input("enter a number "))
print(" Is the number power of 2 :",(is_power_of_two(n)))