#include <iostream>
#include <cstdint>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::uint64_t;
using std::sqrt;


// Get the greatest prime factor of n
uint64_t greatest_prime_factor(uint64_t n) {
	int max_factor = 1;
	if (n % 2 == 0) {
		max_factor = 2;
		while (n % 2 == 0)
			n /= 2;
	}
	for (int factor = 3; n > 1 && factor <= sqrt(n); factor += 2 ) {
		if (n % factor == 0) {
			max_factor = factor;
			while (n % factor == 0)
				n /= factor;
		}
	}
	return (n == 1) ? max_factor : n;
}


int main() {
	uint64_t n;
	cout << "Enter a positive number: ";
	cin >> n;
	cout << "Largest prime factor of " << n << " is: "
		 << greatest_prime_factor(n) << endl;

	return 0;
}