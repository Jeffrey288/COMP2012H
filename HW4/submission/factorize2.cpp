#define PRIME_CHECKS_(X) X(11) X(13) X(17) X(19) X(23) X(29) X(31) X(37) X(41) X(43) X(47) X(53) X(59) X(61) X(67) X(71) X(73) X(79) X(83) X(89) X(97) X(101) X(103) X(107) X(109) X(113) X(121) X(127) X(131) X(137) X(139) X(143) X(149) X(151) X(157) X(163) X(167) X(169) X(173) X(179) X(181) X(187) X(191) X(193) X(197) X(199) X(209)
#define PRIME_CHECKS(X) X(1) PRIME_CHECKS_(X)
#define __CHECK_PRIME_(inc) if (inc >= num_sqrt) return true; if (num % inc == 0) return false;
#define __CHECK_PRIME(inc) if (inc >= num_sqrt) return true; if (num % (i + inc) == 0) {return false;}


// typedef int int128_t __attribute__((mode(TI)));
// https://stackoverflow.com/questions/34588650/uint128-t-does-not-name-a-type

const int SMALL_NUM_PRIMES = 1755;
const int SMALL_PRIMES[SMALL_NUM_PRIMES] = \
 {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057, 4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139, 4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231, 4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297, 4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409, 4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279, 5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387, 5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443, 5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521, 5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639, 5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693, 5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791, 5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857, 5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939, 5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053, 6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133, 6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221, 6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301, 6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997, 7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919, 7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017, 8039, 8053, 8059, 8069, 8081, 8087, 8089, 8093, 8101, 8111, 8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219, 8221, 8231, 8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291, 8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 8387, 8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501, 8513, 8521, 8527, 8537, 8539, 8543, 8563, 8573, 8581, 8597, 8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677, 8681, 8689, 8693, 8699, 8707, 8713, 8719, 8731, 8737, 8741, 8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831, 8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929, 8933, 8941, 8951, 8963, 8969, 8971, 8999, 9001, 9007, 9011, 9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109, 9127, 9133, 9137, 9151, 9157, 9161, 9173, 9181, 9187, 9199, 9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283, 9293, 9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377, 9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 9437, 9439, 9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533, 9539, 9547, 9551, 9587, 9601, 9613, 9619, 9623, 9629, 9631, 9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733, 9739, 9743, 9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811, 9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 9887, 9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973, 10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093, 10099, 10103, 10111, 10133, 10139, 10141, 10151, 10159, 10163, 10169, 10177, 10181, 10193, 10211, 10223, 10243, 10247, 10253, 10259, 10267, 10271, 10273, 10289, 10301, 10303, 10313, 10321, 10331, 10333, 10337, 10343, 10357, 10369, 10391, 10399, 10427, 10429, 10433, 10453, 10457, 10459, 10463, 10477, 10487, 10499, 10501, 10513, 10529, 10531, 10559, 10567, 10589, 10597, 10601, 10607, 10613, 10627, 10631, 10639, 10651, 10657, 10663, 10667, 10687, 10691, 10709, 10711, 10723, 10729, 10733, 10739, 10753, 10771, 10781, 10789, 10799, 10831, 10837, 10847, 10853, 10859, 10861, 10867, 10883, 10889, 10891, 10903, 10909, 10937, 10939, 10949, 10957, 10973, 10979, 10987, 10993, 11003, 11027, 11047, 11057, 11059, 11069, 11071, 11083, 11087, 11093, 11113, 11117, 11119, 11131, 11149, 11159, 11161, 11171, 11173, 11177, 11197, 11213, 11239, 11243, 11251, 11257, 11261, 11273, 11279, 11287, 11299, 11311, 11317, 11321, 11329, 11351, 11353, 11369, 11383, 11393, 11399, 11411, 11423, 11437, 11443, 11447, 11467, 11471, 11483, 11489, 11491, 11497, 11503, 11519, 11527, 11549, 11551, 11579, 11587, 11593, 11597, 11617, 11621, 11633, 11657, 11677, 11681, 11689, 11699, 11701, 11717, 11719, 11731, 11743, 11777, 11779, 11783, 11789, 11801, 11807, 11813, 11821, 11827, 11831, 11833, 11839, 11863, 11867, 11887, 11897, 11903, 11909, 11923, 11927, 11933, 11939, 11941, 11953, 11959, 11969, 11971, 11981, 11987, 12007, 12011, 12037, 12041, 12043, 12049, 12071, 12073, 12097, 12101, 12107, 12109, 12113, 12119, 12143, 12149, 12157, 12161, 12163, 12197, 12203, 12211, 12227, 12239, 12241, 12251, 12253, 12263, 12269, 12277, 12281, 12289, 12301, 12323, 12329, 12343, 12347, 12373, 12377, 12379, 12391, 12401, 12409, 12413, 12421, 12433, 12437, 12451, 12457, 12473, 12479, 12487, 12491, 12497, 12503, 12511, 12517, 12527, 12539, 12541, 12547, 12553, 12569, 12577, 12583, 12589, 12601, 12611, 12613, 12619, 12637, 12641, 12647, 12653, 12659, 12671, 12689, 12697, 12703, 12713, 12721, 12739, 12743, 12757, 12763, 12781, 12791, 12799, 12809, 12821, 12823, 12829, 12841, 12853, 12889, 12893, 12899, 12907, 12911, 12917, 12919, 12923, 12941, 12953, 12959, 12967, 12973, 12979, 12983, 13001, 13003, 13007, 13009, 13033, 13037, 13043, 13049, 13063, 13093, 13099, 13103, 13109, 13121, 13127, 13147, 13151, 13159, 13163, 13171, 13177, 13183, 13187, 13217, 13219, 13229, 13241, 13249, 13259, 13267, 13291, 13297, 13309, 13313, 13327, 13331, 13337, 13339, 13367, 13381, 13397, 13399, 13411, 13417, 13421, 13441, 13451, 13457, 13463, 13469, 13477, 13487, 13499, 13513, 13523, 13537, 13553, 13567, 13577, 13591, 13597, 13613, 13619, 13627, 13633, 13649, 13669, 13679, 13681, 13687, 13691, 13693, 13697, 13709, 13711, 13721, 13723, 13729, 13751, 13757, 13759, 13763, 13781, 13789, 13799, 13807, 13829, 13831, 13841, 13859, 13873, 13877, 13879, 13883, 13901, 13903, 13907, 13913, 13921, 13931, 13933, 13963, 13967, 13997, 13999, 14009, 14011, 14029, 14033, 14051, 14057, 14071, 14081, 14083, 14087, 14107, 14143, 14149, 14153, 14159, 14173, 14177, 14197, 14207, 14221, 14243, 14249, 14251, 14281, 14293, 14303, 14321, 14323, 14327, 14341, 14347, 14369, 14387, 14389, 14401, 14407, 14411, 14419, 14423, 14431, 14437, 14447, 14449, 14461, 14479, 14489, 14503, 14519, 14533, 14537, 14543, 14549, 14551, 14557, 14561, 14563, 14591, 14593, 14621, 14627, 14629, 14633, 14639, 14653, 14657, 14669, 14683, 14699, 14713, 14717, 14723, 14731, 14737, 14741, 14747, 14753, 14759, 14767, 14771, 14779, 14783, 14797, 14813, 14821, 14827, 14831, 14843, 14851, 14867, 14869, 14879, 14887, 14891, 14897, 14923, 14929, 14939, 14947, 14951, 14957, 14969, 14983};
const int SMALL_PRIME_LIMIT = 14983;

/*
 * @brief Miller Primes
 * According to Wikiwiki
 * 
if n < 2,047, it is enough to test a = 2;
if n < 1,373,653, it is enough to test a = 2 and 3;
if n < 9,080,191, it is enough to test a = 31 and 73;
if n < 25,326,001, it is enough to test a = 2, 3, and 5;
if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7;
if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
if n < 18,446,744,073,709,551,616 = 264, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
*/

const long long MILLER_BOUNDS[11] = {2047, 1373653, 9080191, 25326001, 3215031751, 4759123141, 1122004669633, 2152302898747, 3474749660383, 341550071728321, 3825123056546413051};
const int MILLER_NUM_BOUNDS = 11;
const int MILLER_PRIMES[12][14] = {
    {2},
    {2, 3},
    {31, 73},
    {2, 3, 5},
    {2, 3, 5, 7},
    {2, 7, 61},
    {2, 13, 23, 1662803},
    {2, 3, 5, 7, 11},
    {2, 3, 5, 7, 11, 13},
    {2, 3, 5, 7, 11, 13, 17},
    {2, 3, 5, 7, 11, 13, 17, 19, 23},
    {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37},
};
const int MILLER_NUM_PRIMES[12] = {1, 2, 2, 3, 4, 3, 4, 5, 6, 7, 9, 12};

const long long PRIME_START_NUM = 64 * 90;
const unsigned long long PRIME_FLAGS[] = {
    0x7f6f5bb4fc366b59,0xe23d956e43c29d2b,0x4c99b4f133460a56,0x95ae2758d2492b2c,0xc246790f0f0324d4,0x3528d9a6683d4a81,0x92548d689076f1a0,0x548243d3a27d112,0x2d330dda40b80e46,0x4aa0b891210be454,0x186052f299094791,0x86e4820348721cac,0x605b42ed150d12c0,0x2093681184c4272b,0xd3a64c246e10d2c1,0x254910d601930c8a,0x340984038b14c81e,0x201ab63198614084,0xf81229da62642d2a,0x11c2c92a0590d064,0x390c83763020475a,0x6851a21d0e08096,0x66599480264a4144,0x60b50642f018a12a,0x876a51106c1203d,0x8c200944291d29c2,0xb661120d1aa01432,0x4883c04585424300,0x552e2e817071b00a,0xc90021be42c940e8
};

#include <iostream>
int main() {
    std::cout << SMALL_PRIMES[3];
    return 0;
}
// #include <algorithm>
// #include <numeric>
// #include <math.h>

// #include <time.h>
// #include <chrono>
// #include <stdint.h>

// using namespace std;
// // ./factorize 576460752303423484 576460752303423489

// const long long MAX_NUM = 9223372036854775807;
// const long long MIN_NUM = 2;
// const int MAX_FACTORS = 64;

// long long factors[MAX_FACTORS];
// int num_factors;
// int num_small_factors;

// /**
//  * SOURCES :

// (1) General Sources 
// // https://iq.opengenus.org/integer-factorization-algorithms/
// // https://cp-algorithms.com/algebra/factorization.html
// // https://cp-algorithms.com/algebra/factorization.html#implementation_1

// (2) Helper Functions
// - mult
// // https://codeforces.com/blog/entry/96759
// // https://stackoverflow.com/questions/18439520/is-there-a-128-bit-integer-in-c
// - gcd
// // https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
// // https://cs.stackexchange.com/questions/1447/what-is-most-efficient-for-gcd
// - mod-pow
// // https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number


// (3) Pollard Rho and Brent's Modification
// // https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
// // https://web.archive.org/web/20160304185017/http://maths-people.anu.edu.au/~brent/pd/rpb051i.pdf
// //https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants

// (4) Miller's Primarility Test
// // https://www.quora.com/What-is-the-fastest-deterministic-primality-test
//  * https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Miller_test
//  * https://gist.github.com/Ayrx/5884790 referenced from


// (5) Advanced Factorization Techniques
// // https://www.mersenneforum.org/showthread.php?t=23177
// // https://en.wikipedia.org/wiki/Lenstra_elliptic-curve_factorization 
// // https://github.com/delta003/lenstra_algorithm/blob/master/ mainly adapted from
// // https://github.com/pkruk/pylenstra/tree/master/src reference
// // https://github.com/alpertron/calculators
// // https://www.alpertron.com.ar/ECM.HTM

// */

// /**
//  *  HELPER FUNCTIONS
//  */

// # define append_factor(factor) factors[num_factors++] = factor

// // inline long long mult(long long a, long long b, long long mod) {
// //     // multiplcation of two long long integers modded by mod

// //     // unsigned long long res = 0;
// //     // a %= mod; 
// //     // b %= mod;
// //     // if (a < 3037000500 && b < 3037000500) 
// //     //     return (a * b) % mod;
// //     // if (mod > 70368744177664) { // 2^46: binary multiplication
// //     //     unsigned long long ua = a;
// //     //     while (b) {
// //     //         if (b & 1)
// //     //             res = (res + ua) % mod;
// //     //         ua = (2 * ua) % mod;
// //     //         b >>= 1;
// //     //     }
// //     //     return res;
// //     // } else { // real multiplication, dunno why double is worse
// //     //     res = (a * b - (unsigned long long) ((long double) a * b / mod) * mod) % mod;
// //     //     if (res < 0) res += mod;
// //     //     return res;
// //     // }

// //     long long result = 0;
// //     while (b) {
// //         if (b & 1)
// //             result = (result + a) % mod;
// //         a = (a + a) % mod;
// //         b >>= 1;
// //     }
// //     return result;

// // }

// #define mult(a, b, mod) ((__uint128_t) (a) * (b) % (mod))

// // note that b > a
// inline long long _gcd(long long a, long long b) {
//     if (a == 0) return b;
//     return _gcd(b % a, a);
// }

// inline long long gcd(long long a, long long b) {
//     if (a > b) return _gcd(b, a); // reduce this check
//     else return _gcd(a, b);
// }

// inline long long mod_pow(long long val, long long exp, long long mod) { // O(log n)
//     long long result = 1;
//     val %= mod;
//     while (exp) {
//         if (exp & 1) result = mult(result, val, mod);
//         val = mult(val, val, mod);
//         exp >>= 1;
//     }
//     return result;
// }

// // Generates Random Numbers
// inline long long lrand() {
//     union {
//         uint32_t a[2];
//         uint64_t b;
//     } c;
//     c.a[0] = rand();
//     c.a[1] = rand() >> 1;
//     return c.b;
// }

// /**
//  * @brief Primarility Test
//  */

// inline bool is_prime(long long num) {

// /**
//  * @brief Square root testing
//  */
//     // if (num == 1) return false;
//     // long long num_sqrt = sqrt(num) + 1;
//     // if (num == 2) return true; if (num % 2 == 0) return false;
//     // if (num == 3) return true; if (num % 3 == 0) return false;
//     // if (num == 5) return true; if (num % 5 == 0) return false;
//     // if (num == 7) return true; if (num % 7 == 0) return false;
//     // PRIME_CHECKS_(__CHECK_PRIME_)
//     // for (int i = 210; i < num_sqrt; i += 210) { 
//     //     PRIME_CHECKS(__CHECK_PRIME)
//     // }
//     // return true;   

// /**
//  * @brief LUT
//  * 
//  */

//     if (num == 2) return true;
//     if (num % 2 == 0) return false;
//     if (num == 3) return true;
//     if (num % 3 == 0) return false;
//     if (num < PRIME_START_NUM) return (((PRIME_FLAGS[num/3/64] >> (63-(num/3)%64)) & 1) == 1);
    
// /**
//  * @brief Miller
//  * todo: check miller
//  */

//     int miller_index = 0;
//     while (miller_index < MILLER_NUM_BOUNDS && num > MILLER_BOUNDS[miller_index]) miller_index++; // make this a binary search
//     // cout << num << " " << miller_index << endl; 

//     long long s = num - 1;
//     while (s % 2 == 0) {
//         s /= 2;
//     }

//     int k = 0;
//     for (long long a = MILLER_PRIMES[miller_index][0]; k < MILLER_NUM_PRIMES[miller_index]; a = MILLER_PRIMES[miller_index][++k]) {
//         long long temp = s;
//         long long mod = mod_pow(a, temp, num);
//         while (temp != num - 1 && mod != 1 && mod != num - 1) {
//             mod = mult(mod, mod, num);
//             temp <<= 1;
//         }
//         if (mod != num - 1 && temp % 2 == 0) return false;
//     }
//     return true;

// // int miller_index = 0;
// // while (miller_index < MILLER_NUM_BOUNDS && num > MILLER_BOUNDS[miller_index]) miller_index++; // make this a binary search

// // int s = 0;
// // long long d = num - 1;
// // // cout << "d " << (d & 1) << " s " << s << endl;
// // while ((d & 1) == 0) {
// //     s++;
// //     d >>= 1;
// // }    
// // // cout << "ended" << endl;

// // int x, k = 0;
// // // cout << "d " << d << endl;
// // // cout << "d " << d << " s " << s << endl;
// // for (long long a = MILLER_PRIMES[miller_index][0]; k < MILLER_NUM_PRIMES[miller_index]; a = MILLER_PRIMES[miller_index][++k]) {
// //     // cout << "a " << a << endl;
// //     x = mod_pow(a, d, num);
// //     if (x == 1 || x == num - 1) continue;
// //     int i = 0;
// //     for (; i < s - 1; i++) {
// //         // cout << "s " << s << endl;
// //         x = mod_pow(x, 2, num);
// //         if (x == num - 1) break;
// //         // if (x == num - 1) continue;
// //     }
// //     if (i == s - 1) return false;
// //     // return false;
// // }
// // return true;

//     /**
//      * @brief incorrect but faster miller :D
//      * 
//      */

//     // int miller_index = 0;
//     // while (miller_index < MILLER_NUM_BOUNDS && num > MILLER_BOUNDS[miller_index]) miller_index++;
//     // // cout << miller_index << endl;

//     // int s = 0;
//     // long long d = num - 1;
//     // while (d & 1 == 0) {
//     //     s++;
//     //     d >>= 1;
//     // }    
//     // // cout << "ended" << endl;

//     // int x, k = 0;
//     // // cout << "d " << d << endl;
//     // for (long long a = MILLER_PRIMES[miller_index][0]; k < MILLER_NUM_PRIMES[miller_index]; a = MILLER_PRIMES[miller_index][++k]) {
//     //     // cout << "a " << a << endl;
//     //     x = mod_pow(a, d, num);
//     //     if (x == 1 | x == num - 1) continue;
//     //     for (int i = 0; i < s - 1; i++) {
//     //         // cout << "s " << s << endl;
//     //         x = mod_pow(x, 2, num);
//     //         if (x == num - 1) continue;
//     //     }
//     //     return false;
//     // }
//     // return true;

// }


// /**
//  * @brief Floyd Pollard (Not used now)
//  */
// inline long long g(long long val) {
//     return (val) * (val) + 101;
// }
// inline long long pollard_rho(long long num) {
//     long long x = 2;
//     long long y = 2;
//     long long d = 1;
//     while (d == 1) {
//         x = g(x) % num;
//         y = g(y) % num;
//         y = g(y) % num;
//         d = gcd(abs(x - y), num);
//     }
//     return d;
// }


// /**
//  * @brief Brent Pollard
//  */
// inline long long g2(long long val, long long mod) {
//     return (mult(val, val, mod) + 499) % mod;
// }

// inline long long brent(long long num) {
//     long long y = lrand();
//     long long G = 1;
//     long long q = 1;
//     long long ys, x;

//     int m = lrand();
//     int r = 1;
//     while (G == 1) {
//         x = y;
//         for (int i = 1; i < r; i++)
//             y = g2(y, num);
//         int k = 0;
//         while (k < r && G == 1) {
//             ys = y;
//             for (int i = 0; i < m && i < r - k; i++) {
//                 y = g2(y, num);
//                 q = mult(q, abs(x - y), num);
//             }
//             G = gcd(q, num);
//             k += m;
//         }
//         r <<= 1;
//     }
//     if (G == num) {
//         do {
//             ys = g2(ys, num);
//             G = gcd(abs(ys - x), num);
//         } while (G == 1);
//     }
//     return G;
//     // long long x = lrand(); // 8053658402728213007;
//     // long long G = 1; // divisor
//     // long long q = 1;
//     // long long xs, y, k;
//     // long long mrkmin = 0;

//     // long long m = lrand(); // 927927493989584170;
//     // long long r = 1;
//     // while (G == 1) {
//     //     y = x;
//     //     for (int i = 1; i <= r; i++) {
//     //         x = g2(x, num);
//     //     }
//     //     // cout << "done " << x << endl;
//     //     k = 0;
//     //     while (k < r && G == 1) {
//     //         xs = x;
//     //         mrkmin = min(m, r-k);
//     //         for (long long i = 0; i < mrkmin; i++) {
//     //             x = g2(x, num);
//     //             q = mult(q, abs(y-x), num);
//     //         }
//     //         // cout << "q, " << q << endl;
//     //         G = gcd(q, num);
//     //         k += m;
//     //     }
//     //     r <<= 1;
//     //     // cout << "r " << r << endl;
//     //     // cout << "g " << G << endl;
//     // }
//     // if (G == num) {
//     //     do {
//     //         xs = g2(xs, num);
//     //         // cout << "xs " << xs << endl;
//     //         G = gcd(abs(xs - y), num);
//     //         // cout << "G " << G << endl;
//     //     } while (G == 1);
//     // }
//     // return G;
// }

// /**
//  * @brief Wheelprime
//  * 
//  */
// #define __ADD_PRIME_(inc) if (num == 1) return; while (num % inc == 0) {append_factor(inc); num /= inc;}
// #define __ADD_PRIME(inc) if (num == 1) return; while (num % (i + inc) == 0) {append_factor(i + inc); num /= (i + inc);}
// inline void factor_prime(long long num) { // todo: write two different algo, and check_prime after every factor found
//     // cout << "uh oh";
//     if (num == 1) return;
//     long long num_sqrt = sqrt(num) + 1;
//     while (num % 2 == 0) {append_factor(2); num /= 2;}
//     while (num % 3 == 0) {append_factor(3); num /= 3;}
//     while (num % 5 == 0) {append_factor(5); num /= 5;}
//     while (num % 7 == 0) {append_factor(7); num /= 7;}
//     PRIME_CHECKS_(__ADD_PRIME_)
//     for (long long i = 210; i < num_sqrt; i += 210) { 
//         PRIME_CHECKS(__ADD_PRIME)
//     }
//     if (num != 1) append_factor(num);
// }


// /**
//  * @brief FACTORIZATION
//  */

// inline void _find_factors(long long num) {
//     // cout << "wah" << endl;
//     if (num == 1) return;
//     // cout << num << endl;;
//     // cout << "num" << num << endl;
//     // cout << "isprime" << is_prime(num) << is_prime(2719) << endl;
//     // cout << "num is rpime" << num << " " << is_prime(num) << endl;
//     cout << "started prime" << endl;
//     if (is_prime(num)) {
//         append_factor(num); 
//         // cout << "isprime" << num << endl; 
//         return;
//     }
//     cout << "hai" << num << endl;
//     long long factor;
//     if (num < PRIME_START_NUM) {
//         factor = pollard_rho(num);
//     } else {
//         factor = brent(num);
//     }
//     // cout << "fin factor la" << factor << endl;
//     // long long factor = pollard_rho(num);
//     // int factor = lenstra(num);
//     cout << factor << endl;
//     if (factor == num) {
//         // cout << "oh no!" << endl; 
//         factor_prime(num);
//     }  else {
//         _find_factors(num/factor);
//         _find_factors(factor);
//     }
//     // cout << factor << endl;
// }

// inline long long factor_small_primes(long long num) { // can binary search
//     // long long num_sqrt = sqrt(num) + 1;

//     for (int i = 0; i < SMALL_NUM_PRIMES && num > 1; i++) {
//         while (num % SMALL_PRIMES[i] == 0) {
//             // cout << " - " << num << " " << SMALL_PRIMES[i] << endl;
//             append_factor(SMALL_PRIMES[i]);
//             num /= SMALL_PRIMES[i];
//         }
//     }
//     num_small_factors = num_factors;
//     return num;
//     // if (num_sqrt < SMALL_PRIME_LIMIT) {
//     // } else {
//     //     factor_prime(num);
//     //     num_small_factors = num_factors;
//     //     return 1;
//     // }
// }

// inline void _find_factors_2(long long num) {
//     if (num == 1) return;
//     if (is_prime(num)) {
//         append_factor(num); 
//         return;
//     }
//     long long factor;
//     factor = pollard_rho(num);
//     // cout << num << " factor: " << factor << endl;
//     if (factor == num) {
//         factor_prime(num);
//     } else {
//         _find_factors(num/factor);
//         _find_factors(factor);
//     }
// }

// inline void find_factors(long long num) {
//     // factor_prime(num);
//     // return;
//     // cout << "wahhh" << endl;

//     if (num < 1234567) {
//         _find_factors_2(num);
//     } else {
//         num = factor_small_primes(num);
//         cout << "ged" << endl;
//         _find_factors(num);
//     }
//     // if (num % 2 == 0) {
//     //     // cout << "wah2";
//     //     append_factor(2);
//     //     find_factors(num/2);
//     // } else if (num % 3 == 0) {
//     //     // cout << "wah3";
//     //     append_factor(3);
//     //     find_factors(num/3);
//     // } else if (num % 5 == 0) {
//     //     // cout << "wah5";
//     //     append_factor(5);
//     //     find_factors(num/5);
//     // } else if (num % 7 == 0) {
//     //     // cout << "wah7";
//     //     append_factor(7);
//     //     find_factors(num/7);
//     // } else {
//     //     _find_factors(num);
//     // }
// }

// // .\factorize 16339207 16339207
// // #include <sstream>
// // string buff;
// // char temp_buff[200];
// // int temp_buff_len;
// char* buff;
// char* pt;
// inline void print_factors(long long num) {
//     sort(factors + num_small_factors, factors + num_factors);

//     /**
//      * cout is slow because its interaction with the OS
//      * avoiding the use of endl can reduce interaction
//      * using cout less can also speed up stuff
//      */

//     // int small_fac = 0;
//     // int big_fac = num_small_factors;

//     cout << num << "=";
//     for (int i = 0; i < num_factors - 1; i++) {
//         cout << factors[i] << "*";
//     }
//     cout << factors[num_factors - 1] << "\n";


//     // sprintf(temp_buff, "%lld=", num); buff.append(temp_buff);
//     // for (int i = 0; i < num_factors - 1; i++) {
//     //      sprintf(temp_buff, "%lld*", factors[i]); buff.append(temp_buff);
//     // }
//     // sprintf(temp_buff, "%lld\n", factors[num_factors - 1]); buff.append(temp_buff);

    
//     // pt += sprintf(pt, "%lld=", num); 
//     // for (int i = 0; i < num_factors - 1; i++) {
//     //      pt += sprintf(pt, "%lld*", factors[i]); 
//     // }
//     // pt += sprintf(pt, "%lld\n", factors[num_factors - 1]); 

//     // buff.append(temp_buff);
//     // cout << temp_buff;
    
// }

// // https://stackoverflow.com/questions/18412164/fast-c-string-output
// int main(int argc, char *argv[]) {
//     srand(1);


//     // cout << gcd(4453788356655706920 , 9223372036854775309);
//     // for (int i =0; i < 100; i++) {
//     // cout << lrand() << endl;

//     // return 0;
//     // }
//     // return 0;
//     if (argc != 3) // 0 is "./factorize", 1 and 2 are from, to
//         return -1;
//     long long num;
//     long long from, to;
//     from = atoll(argv[1]);
//     to = atoll(argv[2]);
//     buff = new char[(to - from + 1) * 147];
//     pt = buff;
//     cout << from << " " << to << endl;
//     // from = 576460752303423571;
//     // to = 576460752303425489;
//     // from = 9223372036854774811;
//     // to = 9223372036854775807;
//     // from = 9223372036854775308;
//     // to = 9223372036854775807;
//     // 9223372036854775309


//     // from = 7044386313470;
//     // to = 7044386313470;


// /**
//  * @brief Final Implementation
//  * 
//  */


//     for (num = from; num < to; num++) {
//         cout << num << endl;
//         num_factors = 0;
//         find_factors(num);
//         print_factors(num);
//     }
//     num_factors = 0;
//     find_factors(num);
//     print_factors(num);
//     cout.flush();
//     // cout << buff;
//     *pt = '\0';
//     // printf("%s", buff);
//     // cout << buff;

// /**
//  * @brief Testing Codes
//  * 
//  */

//     // chrono::time_point<chrono::high_resolution_clock> start_point, end_point;
//     // double time_used;

//     // cout << "debug started" << endl;
//     // for (num = from; num <= to; num++) {
//     //     num_factors = 0;
//     //     start_point = chrono::high_resolution_clock::now(); 
//     //     find_factors(num);
//     //     end_point = chrono::high_resolution_clock::now();
//     //     auto start = chrono::time_point_cast<chrono::microseconds>(start_point).time_since_epoch().count(); 	
//     //     auto end = chrono::time_point_cast<chrono::microseconds>(end_point).time_since_epoch().count();
//     //     auto time_used = end - start;
//     //     // cout << time_used << " ";
//     //     // print_factors(num);
//     //     if (time_used > 6000) {
//     //         cout << time_used << " ";
//     //         print_factors(num);
//     //     }
//     // }



//     // cout << "Enter a number to factorize: ";
//     // cin >> num;

//     // print_factors();
//     // cout << pollard_rho(num);
//     // find_factors(num);
//     // for (long long num = 11232332; num < 11233332; num++)
//         // cout << mult(102 * num, 152 * num, 103) << endl;
//     // cout << factor << endl;
//         // cout << mod_pow(103, num, 31) << endl;
//         // cout << ((is_prime(num)) ? 1 : 0);
//     // cout << "done";
//     // for (int i = 0; i < 100; i++) {
//     //     // cout << is_prime(576460752303423487);
//     // }
//     // cout << is_prime(2719);
//     // find_factors(1320917390);
//     // cout << "num factors : " << num_factors << endl;
//     // print_factors(1320917390);

//     return 0;
// }

// // primes.cpp > submission/factorize.cpp && factorize.cpp > submission/factorize.cpp
