def factorial(n, stop=0):
    o = 1
    while n > stop:
        o *= n
        n -= 1
    return o

def choose(n, k):
    left = factorial(n, stop=k)
    #print(left)
    right = factorial(n - k)
    print(len(bin(right)))
    return left / right

if __name__ == '__main__':
    print choose(50000, 50)
