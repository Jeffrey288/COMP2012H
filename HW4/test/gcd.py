# import math

# def lgcd(x, y):
#     if x < y:
#         return lgcd(y, x)

#     shift = max(x.bit_length() // 64, y.bit_length() // 64)
#     xbar = x >> (shift * 64)
#     ybar = y >> (shift * 64)
#     while y > 2**64:
#         print("oprand", x, y)
#         a, b, c, d = 1, 0, 0, 1
#         while ybar + c != 0 and ybar + d != 0:
#             q = (xbar + a) // (ybar + c)
#             p = (xbar + b) // (ybar + d)
#             if q != p:
#                 break

#             a, c = c, a - q*c
#             b, d = d, b - q*d
#             xbar, ybar = ybar, xbar - q*ybar

#         if b == 0:
#             x, y = y, x % y
#         else:
#             print("reduced", a, b, c, d)
#             x, y = a*x + b*y, c*x + d*y

#     return math.gcd(x, y)

# print(lgcd(154, 44))

import numpy as np
def check_prime(k):
    if k == 0 or k == 1: return False
    for c in range(2, k):
        if (k % c == 0):
            return False
    return True

# p = [k for k in range(1000) if (check_prime(k))]
# def check_prime_n(num, l):
#     for k in l:
#         if (num % k == 0): return False
#     return True

# for n in [4]:
#     x = [k for k in range(np.prod(p[:n])) if (check_prime_n(k, p[:n]))]
#     print(x)
#     print(" ".join(map(lambda x: f"X({x})",x)))
#     print(n, len(x)/np.prod(p[:n]))

# import math
# N = 40000000
# def gen_primes():
#     flags = [0, 0] + [1 for _ in range(N)]
#     for n in range(2, N):
#         # print(n)
#         if (flags[n] == 0): continue
#         for k in range(n, math.floor(N/n)):
#             flags[n*k] = 0
#     primes = [p for p in range(N) if (flags[p] == 1)]
#     print(primes[-1000:])

        
    # print(primes[-1000:])
# gen_primes()

# f = open("primes.txt", "w")
# def primes(n):
#     """ Returns  a list of primes < n """
#     sieve = [True] * n
#     for i in range(3,int(n**0.5)+1,2):
#         if sieve[i]:
#             sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
#     return [2] + [i for i in range(3,n,2) if sieve[i]]

# # print(primes(100000000)[-1000:])
# N = 100000
# flags = ["0" for _ in range(N)]
# p = primes(N)[1:]
# for k in p: flags[k//2] = "1"
# # ints = ["".join(flags[64*k:64*k+63]) for k in range(N//128)]
# # ints = [hex(int(k, 2)) for k in ints]
# f = open("primes.txt", "w")
# f.write(",".join(flags))
# f.close()



# f.write(", ".join(list(map(str, primes(40000000)))))
# print(len(primes(36000000)))
# f.close()

# import math
# def is_prime(n):
#   if n == 1: return False
#   for i in range(2,int(math.sqrt(n))+1):
#     if (n%i) == 0:
#       return False
#   return True

print([check_prime(i) for i in range(1, 100)])
# print("done")

# for i in range(1, 100):
#   # print((102 * 152 * i * i) % 103)
#   print((103 ** i) % 31)


