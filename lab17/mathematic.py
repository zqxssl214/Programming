def factorial(num):
    """Вычисление факториала числа."""
    if num < 0:
        raise ValueError("Факториал отрицательного числа не существует")
    if num in (0, 1):
        return 1
    result = 1
    for i in range(2, num + 1):
        result *= i
    return result

def is_prime(num):
    """Проверка числа на то, является ли оно простым."""
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def gcd(a, b):
    """Вычисление наибольшего общего делителя (НОД)."""
    while b:
        a, b = b, a % b
    return abs(a)

def square_root(num):
    """Вычисление квадратного корня вавилонским методом."""
    if num < 0:
        raise ValueError("Нельзя извлечь корень из отрицательного числа")
    if num == 0:
        return 0.0
    x = num
    y = 1.0
    e = 0.000001  # Точность вычислений
    while x - y > e:
        x = (x + y) / 2
        y = num / x
    return x
