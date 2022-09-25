
#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include "primes.h"
// https://stackoverflow.com/questions/18439520/is-there-a-128-bit-integer-in-c
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;

// ./factorize 576460752303423484 576460752303423489
//https://www.alpertron.com.ar/ECM.HTM
//https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants

// https://cp-algorithms.com/algebra/factorization.html
// quadratic seive
// https://www.mersenneforum.org/showthread.php?t=23177

const long long MAX_NUM = 9223372036854775807;
const long long MIN_NUM = 2;
const int MAX_FACTORS = 64;

long long factors[MAX_FACTORS];
int num_factors;

long long brent(long long);




/**
 * SOURCES :

(1) General Sources 
// https://iq.opengenus.org/integer-factorization-algorithms/
// https://cp-algorithms.com/algebra/factorization.html#implementation_1

(2) Helper Functions
- mult
// https://codeforces.com/blog/entry/96759
- gcd
// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
// https://cs.stackexchange.com/questions/1447/what-is-most-efficient-for-gcd
- mod-pow
// https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number


(3) Pollard Rho and Brent's Modification
// https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
// https://web.archive.org/web/20160304185017/http://maths-people.anu.edu.au/~brent/pd/rpb051i.pdf

(4) Miller's Primarility Test
// https://www.quora.com/What-is-the-fastest-deterministic-primality-test
 * https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Miller_test
 * https://gist.github.com/Ayrx/5884790 referenced from


(5) Advanced Factorization Techniques
// https://en.wikipedia.org/wiki/Lenstra_elliptic-curve_factorization 
// https://github.com/delta003/lenstra_algorithm/blob/master/ mainly adapted from
// https://github.com/pkruk/pylenstra/tree/master/src reference
// https://github.com/alpertron/calculators

*/

/**
 *  HELPER FUNCTIONS
 */

# define append_factor(factor) factors[num_factors++] = factor

inline long long mult(long long a, long long b, long long mod) {
    // multiplcation of two long long integers modded by mod

    unsigned long long res = 0;
    a %= mod; 
    b %= mod;
    if (a < 3037000500 && b < 3037000500) 
        return (a * b) % mod;
    if (mod > 70368744177664) { // 2^46: binary multiplication
        while (b) {
            if (b & 1)
                res = (res + a) % mod;
            a = (2 * (unsigned long long) a) % mod;
            b >>= 1;
        }
        return res;
    } else { // real multiplication, dunno why double is worse
        res = (a * b - (unsigned long long) ((long double) a * b / mod) * mod) % mod;
        if (res < 0) res += mod;
        return res;
    }

}

// note that b > a
inline long long _gcd(long long a, long long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

inline long long gcd(long long a, long long b) {
    if (a > b) return _gcd(b, a); // reduce this check
    else return _gcd(a, b);
}

inline long long mod_pow(long long val, long long exp, long long mod) { // O(log n)
    long long result = 1;
    val %= mod;
    while (exp > 0) {
        if (exp & 1) result = mult(result, val, mod);
        val = mult(val, val, mod);
        exp >>= 1;
    }
    return result;
}


/**
 * @brief Primarility Test
 */

inline bool is_prime(long long num) {

/**
 * @brief Square root testing
 */
    // if (num == 1) return false;
    // long long num_sqrt = sqrt(num) + 1;
    // if (num == 2) return true; if (num % 2 == 0) return false;
    // if (num == 3) return true; if (num % 3 == 0) return false;
    // if (num == 5) return true; if (num % 5 == 0) return false;
    // if (num == 7) return true; if (num % 7 == 0) return false;
    // PRIME_CHECKS_(__CHECK_PRIME_)
    // for (int i = 210; i < num_sqrt; i += 210) { 
    //     PRIME_CHECKS(__CHECK_PRIME)
    // }
    // return true;   

/**
 * @brief LUT
 * 
 */

    if (num == 2) return true;
    if (num % 2 == 0) return false;
    if (num == 3) return true;
    if (num % 3 == 0) return false;
    if (num < PRIME_START_NUM) return (((PRIME_FLAGS[num/3/64] >> (63-(num/3)%64)) & 1) == 1);
    
/**
 * @brief Miller
 * 
 */
    
    int miller_index = 0;
    while (miller_index < MILLER_NUM_BOUNDS && num > MILLER_BOUNDS[miller_index]) miller_index++;
    // cout << miller_index << endl;

    int s = 0;
    long long d = num - 1;
    while (d & 1 == 0) {
        s++;
        d >>= 1;
    }    
    // cout << "ended" << endl;

    int x, k = 0;
    // cout << "d " << d << endl;
    for (long long a = MILLER_PRIMES[miller_index][0]; k < MILLER_NUM_PRIMES[miller_index]; a = MILLER_PRIMES[miller_index][++k]) {
        // cout << "a " << a << endl;
        x = mod_pow(a, d, num);
        if (x == 1 | x == num - 1) continue;
        for (int i = 0; i < s - 1; i++) {
            // cout << "s " << s << endl;
            x = mod_pow(x, 2, num);
            if (x == num - 1) continue;
        }
        return false;
    }
    return true;

}


/**
 * @brief Floyd Pollard
 */
long long g(long long val) {
    return (val) * (val) + 1;
}
inline long long pollard_rho(long long num) {
    long long x = 2;
    long long y = 2;
    long long d = 1;
    while (d == 1) {
        x = g(x) % num;
        y = g(y) % num;
        y = g(y) % num;
        d = gcd(abs(x - y), num);
    }
    return d;
}


/**
 * @brief Brent Pollard
 */
inline long long g2(long long val, long long mod) {
    return (mult(val, val, mod) + 499) % mod;
}


// Generates Random Numbers
long long lrand() {
    union {
        uint32_t a[2];
        uint64_t b;
    } c;
    c.a[0] = rand();
    c.a[1] = rand() % 2147483647;
    return c.b;
}

long long brent(long long num) {
    long long x = 8053658402728213007;
    long long G = 1; // divisor
    long long q = 1;
    long long xs, y, k;
    long long mrkmin = 0;

    long long m = 927927493989584170;
    long long r = 1;
    while (G == 1) {
        y = x;
        for (int i = 1; i <= r; i++) {
            x = g2(x, num);
        }
        // cout << "done " << x << endl;
        k = 0;
        while (k < r && G == 1) {
            xs = x;
            mrkmin = min(m, r-k);
            for (long long i = 0; i < mrkmin; i++) {
                x = g2(x, num);
                q = mult(q, abs(y-x), num);
            }
            // cout << "q, " << q << endl;
            G = gcd(q, num);
            k += m;
        }
        r <<= 1;
        // cout << "r " << r << endl;
        // cout << "g " << G << endl;
    }
    if (G == num) {
        do {
            xs = g2(xs, num);
            // cout << "xs " << xs << endl;
            G = gcd(abs(xs - y), num);
            // cout << "G " << G << endl;
        } while (G == 1);
    }
    return G;
}

/**
 * @brief Wheelprime
 * 
 */
#define __ADD_PRIME_(inc) if (num == 1) return; while (num % inc == 0) {append_factor(inc); num /= inc;}
#define __ADD_PRIME(inc) if (num == 1) return; if (num % (i + inc) == 0) {append_factor(i + inc); num /= (i + inc);}
inline void factor_prime(long long num) {
    if (num == 1) return;
    long long num_sqrt = sqrt(num) + 1;
    while (num % 2 == 0) {append_factor(2); num /= 2;}
    while (num % 3 == 0) {append_factor(3); num /= 3;}
    while (num % 5 == 0) {append_factor(5); num /= 5;}
    while (num % 7 == 0) {append_factor(7); num /= 7;}
    PRIME_CHECKS_(__ADD_PRIME_)
    for (long long i = 210; i < num_sqrt; i += 210) { 
        PRIME_CHECKS(__ADD_PRIME)
    }
    if (num != 1) append_factor(num);
}


/**
 * @brief FACTORIZATION
 */

inline void _find_factors(long long num) {
    // cout << "wah" << endl;
    if (num == 1) return;
    // cout << num << endl;;
    // cout << "num" << num << endl;
    // cout << "isprime" << is_prime(num) << is_prime(2719) << endl;
    if (is_prime(num)) {append_factor(num); return;}
    // cout << "hai" << num << endl;
    long long factor = brent(num);
    // int factor = lenstra(num);
    // cout << factor << endl;
    if (factor == num || factor < 1) factor_prime(num);
    else {
        _find_factors(num/factor);
        _find_factors(factor);
    }
    // cout << factor << endl;
}

inline void find_factors(long long num) {
    // factor_prime(num);
    // return;
    // cout << "wahhh" << endl;

    if (num % 2 == 0) {
        // cout << "wah2";
        append_factor(2);
        find_factors(num/2);
    } else if (num % 3 == 0) {
        // cout << "wah3";
        append_factor(3);
        find_factors(num/3);
    } else if (num % 5 == 0) {
        // cout << "wah5";
        append_factor(5);
        find_factors(num/5);
    } else if (num % 7 == 0) {
        // cout << "wah7";
        append_factor(7);
        find_factors(num/7);
    } else {
        _find_factors(num);
    }
}

inline void print_factors(long long num) {
    sort(factors, factors + num_factors);
    cout << num << "=";
    for (int i = 0; i < num_factors - 1; i++) {
        cout << factors[i] << "*";
    }
    cout << factors[num_factors - 1] << endl;
}



int main(int argc, char *argv[]) {
    srand(0);

    // cout << gcd(4453788356655706920 , 9223372036854775309);
    // for (int i =0; i < 100; i++) {
    // cout << lrand() << endl;

    // return 0;
    // }
    // return 0;
    long long num;
    long long from, to;
    // from = atoll(argv[1]);
    // to = atoll(argv[2]);
    // from = 576460752303423571;
    // to = 576460752303425489;
    // from = 9223372036854774811;
    // to = 9223372036854775807;
    from = 9223372036854775308;
    to = 9223372036854775807;
    // 9223372036854775309
    for (num = from; num < to; num++) {
        num_factors = 0;
        find_factors(num);
        print_factors(num);
    }
    num_factors = 0;
    find_factors(num);
    print_factors(num);

    // cout << "Enter a number to factorize: ";
    // cin >> num;

    // print_factors();
    // cout << pollard_rho(num);
    // find_factors(num);
    // for (long long num = 11232332; num < 11233332; num++)
        // cout << mult(102 * num, 152 * num, 103) << endl;
    // cout << factor << endl;
        // cout << mod_pow(103, num, 31) << endl;
        // cout << ((is_prime(num)) ? 1 : 0);
    // cout << "done";
    // for (int i = 0; i < 100; i++) {
    //     // cout << is_prime(576460752303423487);
    // }
    // cout << is_prime(2719);
    // find_factors(1320917390);
    // cout << "num factors : " << num_factors << endl;
    // print_factors(1320917390);

    return 0;
}

