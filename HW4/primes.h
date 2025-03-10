#define PRIME_CHECKS_(X) X(11) X(13) X(17) X(19) X(23) X(29) X(31) X(37) X(41) X(43) X(47) X(53) X(59) X(61) X(67) X(71) X(73) X(79) X(83) X(89) X(97) X(101) X(103) X(107) X(109) X(113) X(121) X(127) X(131) X(137) X(139) X(143) X(149) X(151) X(157) X(163) X(167) X(169) X(173) X(179) X(181) X(187) X(191) X(193) X(197) X(199) X(209)
#define PRIME_CHECKS(X) X(1) PRIME_CHECKS_(X)
#define __CHECK_PRIME_(inc) if (inc >= num_sqrt) return true; if (num % inc == 0) return false;
#define __CHECK_PRIME(inc) if (inc >= num_sqrt) return true; if (num % (i + inc) == 0) {return false;}

extern const int SMALL_NUM_PRIMES;
extern const int SMALL_PRIMES[];
extern const int SMALL_PRIME_LIMIT;
extern const long long MILLER_BOUNDS[];
extern const int MILLER_NUM_BOUNDS;
extern const int MILLER_PRIMES[][14];
extern const int MILLER_NUM_PRIMES[];
extern const long long PRIME_START_NUM;
extern const unsigned long long PRIME_FLAGS[];


// cd "c:\Users\pinkp\Documents\GitHub\COMP2012H\HW4\" ; if ($?) { g++ primes.cpp -c primes }
// cd "c:\Users\pinkp\Documents\GitHub\COMP2012H\HW4\" ; if ($?) { g++ factorize.cpp primes.o  -o factorize } ; if ($?) { .\factorize }