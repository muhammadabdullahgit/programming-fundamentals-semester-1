def product(a, b):
    if a <= 0 or b <= 0:
        return 0
    else:
        return a + product(a, b-1)


def q1():
    print("q1 is running now")
    print("enter first number")
    x = int(input())
    print("enter second number")
    y = int(input())
    print("product = ", product(x, y))


def sumOfDigits(a):
    if a <= 0:
        return 0
    else:
        return int(a % 10 + sumOfDigits(a/10))


def q2():
    print("q2 is running now")
    print("enter a number")
    x = int(input())
    print("sum of digits = ", sumOfDigits(x))


def prime(a, b):
    if b == 1:
        return 1
    if a % b == 0:
        return 0
    return prime(a, b-1)


def q3():
    print("q3 is running now")
    print("enter number to check prime or not")
    x = int(input())
    if x == 0 or x == 1:
        print("the number entered is not a prime number")
    else:
        y = prime(x, x//2)
        if y == 1:
            print(" the number entered is a prime number")
        else:
            print("the number entered is not a prime number")


def sumOfEvenNumbers(x, y):
    if x > y:
        return 0
    elif x % 2 == 0:
        return x+sumOfEvenNumbers(x+2, y)
    elif x % 2 == 1:
        return sumOfEvenNumbers(x+1, y)
    else:
        return 0


def sumOfOddNumbers(x, y):
    if x > y:
        return 0
    elif x % 2 == 1:
        return x + sumOfOddNumbers(x + 2, y)
    elif x % 2 == 0:
        return sumOfOddNumbers(x + 1, y)
    else:
        return 0


def q4():
    print("q4 is running now")
    print("enter number to have sum of even and odd number")
    x = 1
    y = int(input())
    print("sum of even numbers=", sumOfEvenNumbers(x, y))
    print("sum of odd numbers", sumOfOddNumbers(x, y))


def square(size, numRows, currentRows=0):
    if currentRows < size:
        print(numRows * size)
        square(size, numRows, currentRows+1)


def q5():
    print("q5 is running now")
    print("enter key")
    x = input()
    print("enter number of rows to print")
    y = int(input())
    square(y, x)


def series(a):
    if a == 0:
        return 0
    elif a == 1:
        return 1
    else:
        return series(a - 1) + series(a - 2)


def q6():
    print("q6 is running now")
    print("enter a number")
    x = int(input())
    for i in range(x):
        print(series(i), end=",")


def factorial(a):
    if a <= 1:
        return 1
    else:
        return int(a * factorial(a-1))


def q7():
    print("q7 is running now")
    print("enter a number")
    x = int(input())
    print("factorial = ", factorial(x))


q1()
q2()
q3()
q4()
q5()
q6()
q7()
