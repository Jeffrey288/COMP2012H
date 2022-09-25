
typedef struct {
    union {
        long long vec[3];
        struct {
            long long x;
            long long y;
            long long z;
        };
    };
} Point, Vec3;

#define V3(X, Y, Z) (Vec3) {.x = (X), .y = (Y), .z = (Z)}


typedef struct {
    union {
        long long vec[2];
        struct {
            long long x;
            long long z;
        };
    };
} XZ, Vec2;

#define V2(X, Y, Z) (Vec2) {.x = (X), .z = (Z)}

void _modular_inv(long long a, long long b, Vec3 &res) {
    if (b == 0) res = V3(1, 0, a);
    else {
        _modular_inv(b, a % b, res);
        res = V3(res.y, res.x - a / b * res.y, res.z);
    }
}

void modular_inv(long long a, long long b, long long &i, long long &g) { // i is inverse, g is gcd
    Vec3 res;
    _modular_inv(a, b, res);
    i = res.x;
    g = res.z;
}

// Adds two points P, Q (in Montgomery form)
void elliptic_add(Vec2 &P, Vec2 &Q, long long m) {
    int U = (P.x - P.z) * (Q.x + Q.z);
    int V = (P.x + P.z) * (Q.x - Q.z);
    int sum = U + V, diff = U - V;
    int X = ()

    long long num, denom, inv, g;
    if (P.z == 0) return;
    if (q.z == 0) {q = p; return;}
    if (p.x == q.x) {
        if ((p.y + q.y) % m == 0) {q = V3(0,1,0); return;}
        num = (3 * p.x * p.x + a) % m;
        denom = (2 * p.y) % m;
    } else {
        num = (q.y - p.y) % m;
        denom = (q.x - p.x) % m;
    }
    modular_inv(denom, m, inv, g);
    if (g > 1) {q = V3(0, 0, denom); return;}
    long long z = (num * inv * num * inv - p.x - q.x) % m;
    q = V3(z, (num * inv * (p.x - z) - p.y) % m, 1);
}

void elliptic_mul(long long k, Vec3 &p, long long a, long long b, long long m) {
    Vec3 r = V3(0, 1, 0); // "infinity"
    while (k > 0) { // binary decomposition of k, which is the prime number
        if (p.z > 1) return;
        if (k % 2 == 1) elliptic_add(p, r, a, b, m);
        k >>= 1; // k /= 2
        elliptic_add(p, p, a, b, m);
    }
    p = r;
}


long long lenstra(long long num) { // lenstra is too low (or some implementation is wrong)
    srand(0);

    // Step 1: generate the random elliptic curve
    long long g = num; // discriminant
    Point r0;
    int a, b;
    while (g == num) {
        r0 = V3(rand() % num + 1, rand() % num + 1, 1);
        a = rand() % num + 1;
        b = (r0.y * r0.y - r0.x * r0.x * r0.x - a * r0.x) % num;
        g = gcd(4 * a * a * a + 27 * b * b, num);
        if (g > 1) {return g;} // the lucky factor
    }

    int i = 0, p = 2, pp = 2, limit = 9000;
    for (; p < limit; p = pp = LENSTRA_PRIMES[++i]) {
        while (pp < limit) {
            elliptic_mul(p, r0, a, b, num);
            if (r0.z > 1) return gcd(r0.z, num);
        }
        pp *= p;
    }
    return num;

}