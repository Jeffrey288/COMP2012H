#include <iostream>
#include <chrono>
using namespace std;

// Optimize
inline long long mult(unsigned long long a, unsigned long long b, long long mod) {
    unsigned long long res = 0;
    a %= mod; 
    b %= mod;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

// https://codeforces.com/blog/entry/96759
inline long long mult2(unsigned long long a, unsigned long long b, long long mod) {

    unsigned long long res = 0;
    a %= mod; 
    b %= mod;
    if (a < 3037000500 && b < 3037000500) 
        return (a * b) % mod;
    if (mod > 70368744177664) { // 2^46: binary multiplication
        while (b) {
            if (b & 1)
                res = (res + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }
        return res;
    } else { // real multiplication, dunno why double is worse
        res = (a * b - (unsigned long long) ((long double) a * b / mod) * mod) % mod;
        if (res < 0) res += mod;
        return res;
    }

}

        // cout << "b " << b << endl;
        // cout << (long double) a * b / mod << endl;
        // printf("%.19Le\n", (long double) a * b / mod);
        // printf("%llu\n", (unsigned long long) ((long double) a * b / mod));

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

int main() {
	
    // for (long long i = 78004573282159; i < 300000000000000; i = i * 1.001) {
    //     if (5555555 != (long long) ((long double) (5555555*i+i-1)/i)) cout << i << endl;
    // }

    cout << mult(8053658402728213007, 8053658402728213007, 9223372036854774811) << endl;
    cout << mult2(8053658402728213007, 8053658402728213007, 9223372036854774811) << endl;
	// chrono::time_point<chrono::high_resolution_clock> start_point, end_point; // creating time points
	
    // // long long temp1 = 1490;
    // long long temp2 = 1490;

	// start_point = chrono::high_resolution_clock::now(); // storing the starting time point in start 
    // for (long long i = 107800; i < 1323183983421323222; i+=393213122333) {
    //     // temp1 = mult(temp1, i, 2377432132313231);
    //     temp2 = mult2(temp2, i, 2377432132313231);
    //     // cout << i << " " << temp1 << " " << temp2 << endl;
    //     // if (temp1 != temp2)  break;
    //     // temp = (temp * i) % 2377423;
    // }
    // // cout << mult(1390260103586620, 727442777739405 ,  2377432132313231) << endl;
    // // cout << mult2(1390260103586620, 727442777739405 ,  2377432132313231) << endl;
	// end_point = chrono::high_resolution_clock::now(); //storing the ending time in end 
	
	// auto start = chrono::time_point_cast<chrono::microseconds>(start_point).time_since_epoch().count(); 	
	// auto end = chrono::time_point_cast<chrono::microseconds>(end_point).time_since_epoch().count();
	
	// cout <<"\nTime taken = "<<(end-start)<<" microseconds"<< endl;
    // cout << temp2;
	
	// return 0; 
    
}