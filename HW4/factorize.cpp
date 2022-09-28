
#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include "primes.h"

#include <time.h>
#include <chrono>

using namespace std;
// ./factorize 576460752303423484 576460752303423489

const long long MAX_NUM = 9223372036854775807;
const long long MIN_NUM = 2;
const int MAX_FACTORS = 64;

long long factors[MAX_FACTORS];
int num_factors;
int num_small_factors;

/**
 * SOURCES :

(1) General Sources 
// https://iq.opengenus.org/integer-factorization-algorithms/
// https://cp-algorithms.com/algebra/factorization.html
// https://cp-algorithms.com/algebra/factorization.html#implementation_1

(2) Helper Functions
- mult
// https://codeforces.com/blog/entry/96759
// https://stackoverflow.com/questions/18439520/is-there-a-128-bit-integer-in-c
- gcd
// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
// https://cs.stackexchange.com/questions/1447/what-is-most-efficient-for-gcd
- mod-pow
// https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number


(3) Pollard Rho and Brent's Modification
// https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
// https://web.archive.org/web/20160304185017/http://maths-people.anu.edu.au/~brent/pd/rpb051i.pdf
//https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants

(4) Miller's Primarility Test
// https://www.quora.com/What-is-the-fastest-deterministic-primality-test
 * https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Miller_test
 * https://gist.github.com/Ayrx/5884790 referenced from


(5) Advanced Factorization Techniques
// https://www.mersenneforum.org/showthread.php?t=23177
// https://en.wikipedia.org/wiki/Lenstra_elliptic-curve_factorization 
// https://github.com/delta003/lenstra_algorithm/blob/master/ mainly adapted from
// https://github.com/pkruk/pylenstra/tree/master/src reference
// https://github.com/alpertron/calculators
// https://www.alpertron.com.ar/ECM.HTM

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
        unsigned long long ua = a;
        while (b) {
            if (b & 1)
                res = (res + ua) % mod;
            ua = (2 * ua) % mod;
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
 * todo: check miller
 */
    
    int miller_index = 0;
    while (miller_index < MILLER_NUM_BOUNDS && num > MILLER_BOUNDS[miller_index]) miller_index++; // make this a binary search
    // cout << miller_index << endl;

    int s = 0;
    long long d = num - 1;
    // cout << "d " << (d & 1) << " s " << s << endl;
    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }    
    // cout << "ended" << endl;

    int x, k = 0;
    // cout << "d " << d << endl;
    // cout << "d " << d << " s " << s << endl;
    for (long long a = MILLER_PRIMES[miller_index][0]; k < MILLER_NUM_PRIMES[miller_index]; a = MILLER_PRIMES[miller_index][++k]) {
        // cout << "a " << a << endl;
        x = mod_pow(a, d, num);
        if (x == 1 || x == num - 1) continue;
        int i = 0;
        for (; i < s - 1; i++) {
            // cout << "s " << s << endl;
            x = mod_pow(x, 2, num);
            if (x == num - 1) break;
            // if (x == num - 1) continue;
        }
        if (i == s - 1) return false;
        // return false;
    }
    return true;

}


/**
 * @brief Floyd Pollard (Not used now)
 */
inline long long g(long long val) {
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
inline long long lrand() {
    union {
        uint32_t a[2];
        uint64_t b;
    } c;
    c.a[0] = rand();
    c.a[1] = rand() >> 1;
    return c.b;
}

inline long long brent(long long num) {
    long long x = lrand(); // 8053658402728213007;
    long long G = 1; // divisor
    long long q = 1;
    long long xs, y, k;
    long long mrkmin = 0;

    long long m = lrand(); // 927927493989584170;
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
#define __ADD_PRIME(inc) if (num == 1) return; while (num % (i + inc) == 0) {append_factor(i + inc); num /= (i + inc);}
inline void factor_prime(long long num) { // todo: write two different algo, and check_prime after every factor found
    // cout << "uh oh";
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
    // cout << "num is rpime" << num << " " << is_prime(num) << endl;
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

inline long long factor_small_primes(long long num) { // can binary search
    long long num_sqrt = sqrt(num) + 1;

    if (num_sqrt > SMALL_PRIME_LIMIT) {
        for (int i = 0; i < SMALL_NUM_PRIMES && num > 1; i++) {
            while (num % SMALL_PRIMES[i] == 0) {
                append_factor(SMALL_PRIMES[i]);
                num /= SMALL_PRIMES[i];
            }
        }
        num_small_factors = num_factors;
        return num;
    } else {
        factor_prime(num);
        num_small_factors = num_factors;
        return 1;
    }
}

inline void find_factors(long long num) {
    // factor_prime(num);
    // return;
    // cout << "wahhh" << endl;

    num = factor_small_primes(num);
    _find_factors(num);
    // if (num % 2 == 0) {
    //     // cout << "wah2";
    //     append_factor(2);
    //     find_factors(num/2);
    // } else if (num % 3 == 0) {
    //     // cout << "wah3";
    //     append_factor(3);
    //     find_factors(num/3);
    // } else if (num % 5 == 0) {
    //     // cout << "wah5";
    //     append_factor(5);
    //     find_factors(num/5);
    // } else if (num % 7 == 0) {
    //     // cout << "wah7";
    //     append_factor(7);
    //     find_factors(num/7);
    // } else {
    //     _find_factors(num);
    // }
}

// .\factorize 16339207 16339207
string buff;
int buff_len;
inline void print_factors(long long num) {
    sort(factors + num_small_factors, factors + num_factors);

    /**
     * cout is slow because its interaction with the OS
     * avoiding the use of endl can reduce interaction
     * using cout less can also speed up stuff
     */

    int small_fac = 0;
    int big_fac = num_small_factors;

    cout << num << "=";
    for (int i = 0; i < num_factors - 1; i++) {
        cout << factors[i] << "*";
    }
    cout << factors[num_factors - 1] << "\n";
    // if (num_small_factors == num_factors) {
    // } else {
    //     while (small_fac < num_small_factors && factors[small_fac] <= factors[num_small_factors])
    //         cout << factors[small_fac++] << "*";
    //     while (small_fac < num_small_factors && big_fac < num_factors) {
    //         if (factors[small_fac] < factors[big_fac])
    //             cout << factors[small_fac++] << "*";
    //         else
    //             cout << factors[big_fac++] << "*";
    //     }
    //     if (small_fac == num_small_factors) {
    //         while (big_fac < num_factors - 1) cout << factors[big_fac++] << "*";
    //         cout << factors[num_factors - 1] << "\n";
    //     } else {
    //         while (small_fac < num_small_factors - 1) cout << factors[small_fac++] << "*";
    //         cout << factors[num_small_factors - 1] << "\n";
    //     }
    // }
    
}

int main(int argc, char *argv[]) {
    srand(1);

    // cout << gcd(4453788356655706920 , 9223372036854775309);
    // for (int i =0; i < 100; i++) {
    // cout << lrand() << endl;

    // return 0;
    // }
    // return 0;
    if (argc != 3) // 0 is "./factorize", 1 and 2 are from, to
        return -1;
    long long num;
    long long from, to;
    from = atoll(argv[1]);
    to = atoll(argv[2]);
    // from = 576460752303423571;
    // to = 576460752303425489;
    // from = 9223372036854774811;
    // to = 9223372036854775807;
    // from = 9223372036854775308;
    // to = 9223372036854775807;
    // 9223372036854775309





/**
 * @brief Final Implementation
 * 
 */


    for (num = from; num < to; num++) {
        num_factors = 0;
        find_factors(num);
        print_factors(num);
    }
    num_factors = 0;
    find_factors(num);
    print_factors(num);
    cout.flush();

/**
 * @brief Testing Codes
 * 
 */

    // chrono::time_point<chrono::high_resolution_clock> start_point, end_point;
    // double time_used;

    // cout << "debug started" << endl;
    // for (num = from; num <= to; num++) {
    //     num_factors = 0;
    //     start_point = chrono::high_resolution_clock::now(); 
    //     find_factors(num);
    //     end_point = chrono::high_resolution_clock::now();
    //     auto start = chrono::time_point_cast<chrono::microseconds>(start_point).time_since_epoch().count(); 	
    //     auto end = chrono::time_point_cast<chrono::microseconds>(end_point).time_since_epoch().count();
    //     auto time_used = end - start;
    //     // cout << time_used << " ";
    //     // print_factors(num);
    //     if (time_used > 6000) {
    //         cout << time_used << " ";
    //         print_factors(num);
    //     }
    // }



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

