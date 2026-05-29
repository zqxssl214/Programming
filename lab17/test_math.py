import pytest
from mathematic import factorial, is_prime, gcd, square_root

def test_factorial():
    assert factorial(0) == 1
    assert factorial(1) == 1
    assert factorial(5) == 120
    assert factorial(6) == 720

def test_factorial_error():
    with pytest.raises(ValueError):
        factorial(-5)


def test_is_prime():
    assert is_prime(2) == True
    assert is_prime(7) == True
    assert is_prime(4) == False
    assert is_prime(1) == False
    assert is_prime(0) == False
    assert is_prime(-5) == False


def test_gcd():
    assert gcd(10, 5) == 5
    assert gcd(14, 28) == 14
    assert gcd(3, 7) == 1
    assert gcd(0, 5) == 5


def test_square():
    assert square_root(9) == pytest.approx(3.0, abs=1e-5)
    assert square_root(2) == pytest.approx(1.414213, abs=1e-5)
    assert square_root(0) == 0.0
    assert square_root(1) == 1

def test_square_error():
    with pytest.raises(ValueError):
        square_root(-9)