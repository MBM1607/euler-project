#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::uint64_t;
using std::sqrt;

// Get nth prime number
uint64_t n_prime(int n) {
	if (n == 1)
		return 2;

	uint64_t max_size = n;
	while (true) {
		uint64_t num_prime = 1; // 2 is prime and even so its already incremented
		max_size *= n;

		// last index of sieve
		uint64_t sievebound = (max_size - 1) / 2;
		uint64_t limit = (sqrt(max_size) - 1) / 2;

		vector<bool> sieve(sievebound, true);

		for (uint64_t i = 1; i <= limit; i++)
			if (sieve[i])
				for (uint64_t j = 2 * i * (i + 1); j <= sievebound; j += 2 * i + 1)
					sieve[j] = false;

		for (uint64_t i = 1; i <= sievebound; i++)
			if (sieve[i]) {
				num_prime++;
				if (num_prime == n)
					return 2 * i + 1;
			}
	}
}

int main() {
	cout << "Enter the index of the prime number: ";
	int n;
	cin >> n;
	cout << "The " << n << "th prime number is: "
		<< n_prime(n) << endl;
	return 0;
}