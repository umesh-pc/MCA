def fibonacci_even_sum(limit):
    a, b = 0, 1
    even_terms = []
    series = []
    total = 0

    while a <= limit:
        series.append(a)          

        if a % 2 == 0:           
            even_terms.append(a)
            total += a

        a, b = b, a + b         
    return series, even_terms, total



limit =int(input("enter the limit"))
series, evens, sum_even = fibonacci_even_sum(limit)

print("Fibonacci series up to", limit, ":")
print(series)

print("\nEven Fibonacci terms:")
print(evens)

print("\nSum of even Fibonacci terms:", sum_even)
