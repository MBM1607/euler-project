#include <vector>
#include <cstdint>
#include <cmath>

using std::vector;
using std::uint64_t;
using std::sqrt;


vector<int> get_primes(uint64_t n) {
	vector<int> primes;

	uint64_t limit = (sqrt(n) - 1) / 2;
	uint64_t sievebound = (n - 1) / 2;

	vector<bool> sieve(sievebound, true);

	for (int i = 1; i <= limit; i++)
		if (sieve[i])
			for (int j = 2 * i * (i + 1); j <= sievebound; j += 2 * i + 1)
				sieve[j] = false;

	// 2 is the only even prime
	primes.push_back(2);
	for (int i = 1; i <= sievebound; i++)
		if (sieve[i])
			primes.push_back(2 * i + 1);

	return primes;
}


// Return the prime factors of n
vector<int> get_prime_factors(uint64_t n) {
	vector<int> factors;
	if (n % 2 == 0) {
		factors.push_back(2);
		while (n % 2 == 0)
			n /= 2;
	}

	for (int factor = 3; n > 1 && factor <= sqrt(n); factor += 2) {
		if (n % factor == 0) {
			factors.push_back(factor);
			while (n % factor == 0)
				n /= factor;
		}
	}
	if (n != 1)
		factors.push_back(n);

	return factors;
}
