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
def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]
# print(len(primes(10000)))

# # print(primes(100000000)[-1000:])
# N = 255000000
# # N = 64*9
# flags = ["0" for _ in range(N+1)]
# print("flags created")
# p = primes(N)
# print(p)
# for k in p: 
#     flags[k] = "1"
#     # print(flags)

# flags = [flags[i] for i in range(N+1) if (i%6 == 1 or i%6==5)]

# # print(flags[:10])

# # exit()

# ints = ["".join(flags[64*k:64*k+64]) for k in range((N//3)//64)]
# print(ints[:4], len(ints[0]), len(ints[1]))
# ints2 = [int(k, 2) for k in ints]
# print(ints2[:4])
# ints = [hex(int(k, 2)) for k in ints]
# print(ints[:4])
# f = open("primes.txt", "w")
# f.write(",".join(ints))
# f.close()


# # print(hex(ints2[0]))
# def is_prime(n):
#     if (n == 2 or n == 3): return True
#     if (n % 2 == 0): return False
#     if (n % 3 == 0): return False
#     idx = n//3
#     # if (flags[n//3] == "1"): return True
#     # else: return False
#     print(idx, 63-idx%64, bin(ints2[idx//64]), bin((ints2[idx//64] >> (63-idx%64))))
#     if (((ints2[idx//64] >> (63-idx%64)) & 1) == 1): return True
#     else: return False
# for k in range(1, 100):
#     print(k, is_prime(k))

# print(len(primes(15000)))


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

# print([check_prime(i) for i in range(1, 100)])
# print("done")

# for i in range(1, 100):
#   # print((102 * 152 * i * i) % 103)
#   print((103 ** i) % 31)

import primefac


output_my = """5308048003531188904=2*2*2*259697*2554923624229
5308048003531188905=5*11*103*936989938840457
5308048003531188906=2*3*3*17*181*337*284383856633
5308048003531188907=31*47*3643135211757851
"""
lines = [line for line in output_my.split("\n") if (line)]
for line in lines:
    nums = line.split("=")
    num = int(nums[0])
    # factors = primefac.primefac(num)
    factors = nums[1].split("*")
    factors = list(map(int, factors))
    # print(factors)
    # print(np.prod(factors))
    if not ((np.prod(factors) == num) and (sorted(factors) == factors)):
    # if (line != f'{num}={"*".join(map(str, list(factors)))}'):
        print("Oh no!")
        break
