import argparse
from random import randint
from math import gcd


# Sieve of Eratosthenes
def primes(n):
    b = [True] * (n + 1)
    ps = []
    for p in range(2, n + 1):
        if b[p]:
            ps.append(p)
            for i in range(p, n + 1, p):
                b[i] = False
    return ps


# Finds modular inverse
# Returns inverse, unused helper and gcd
def modular_inv(a, b):
    if b == 0:
        return 1, 0, a
    q, r = divmod(a, b)
    x, y, g = modular_inv(b, r)
    return y, x - q * y, g


# Addition in Elliptic curve modulo m space
def elliptic_add(p, q, a, b, m):
    # If one point is infinity, return other one
    if p[2] == 0: return q
    if q[2] == 0: return p
    if p[0] == q[0]:
        if (p[1] + q[1]) % m == 0:
            return 0, 1, 0  # Infinity
        num = (3 * p[0] * p[0] + a) % m
        denom = (2 * p[1]) % m
    else:
        num = (q[1] - p[1]) % m
        denom = (q[0] - p[0]) % m
    inv, _, g = modular_inv(denom, m)
    # Unable to find inverse, arithmetic breaks
    if g > 1:
        return 0, 0, denom  # Failure
    z = (num * inv * num * inv - p[0] - q[0]) % m
    return z, (num * inv * (p[0] - z) - p[1]) % m, 1


# Multiplication (repeated addition and doubling)
def elliptic_mul(k, p, a, b, m):
    r = (0, 1, 0)  # Infinity
    while k > 0:
        # p is failure, return it
        if p[2] > 1:
            return p
        if k % 2 == 1:
            r = elliptic_add(p, r, a, b, m)
        k = k // 2
        p = elliptic_add(p, p, a, b, m)
    return r


# Lenstra's algorithm for factoring
# Limit specifies the amount of work permitted
def lenstra(n, limit):
    g = n
    while g == n:
        # Randomized x and y
        q = randint(0, n - 1), randint(0, n - 1), 1
        # Randomized curve coefficient a, computed b
        a = randint(0, n - 1)
        b = (q[1] * q[1] - q[0] * q[0] * q[0] - a * q[0]) % n
        g = gcd(4 * a * a * a + 27 * b * b, n)  # singularity check
    # If we got lucky, return lucky factor
    if g > 1:
        return g
    # increase k step by step until lcm(1, ..., limit)
    for p in primes(limit):
        pp = p
        while pp < limit:
            q = elliptic_mul(p, q, a, b, n)
            # Elliptic arithmetic breaks
            if q[2] > 1:
                return gcd(q[2], n)
            pp = p * pp
    return None

from sympy import *


factors = []
count = 0
def factor(num):
    global factors
    global count
    
    if (num == 1): return
    print("ispriming")
    if (simplify(num).is_prime):
        print("isprimingdone")
        factors.append(num)
        return
    else:
        print("isprimingdone")
    f = None
    print("lenstraing")
    while f is None:
        count += 1
        f = lenstra(num, 1000)
        print("lenstraed")
    factor(num / f)
    factor(f)

# Command line tool
def main():
    global factors
    global count
    # parser = argparse.ArgumentParser(description = 'Process arguments')
    # parser.add_argument('--n', type = int,
    #                     help = 'number to factor')
    # parser.add_argument('--limit', type = int, default = 1000,
    #                     help = 'work limit (default = 1000)')
    # args = parser.parse_args()
    for i in range(576460752303423571, 576460752303425489):
        count = 0
        factors = []    
        factor(i)
        print(factors, count)


if __name__ == '__main__':
    main()