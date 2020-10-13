#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

#include "../primes.h"

using std::copy;
using std::sqrt;
using std::floor;
using std::log;
using std::pow;
using std::vector;
using std::uint64_t;
using std::cin;
using std::cout;
using std::endl;

// Get the smallest number that is multiple of all numbers upto n
uint64_t smallest_range_multiple(uint64_t n) {
	uint64_t ret = 1;
	vector<int> primes = get_primes(n);

	bool check = true;
	uint64_t limit = sqrt(n);
	uint64_t p_occurance;
	cout << endl;
	for (vector<int>::size_type i = 0; i != primes.size(); i++) {
		cout << primes[i] << endl;
		p_occurance = 1;
		if (check) {
			if (primes[i] <= limit)
				p_occurance = floor(log(n) / log(primes[i]));
			else
				check = false;
		}
		ret *= pow(primes[i], p_occurance);
	}

	return ret;
}

int main() {
	int n;
	cout << "Enter a positive number: ";
	cin >> n;

	cout << "Smallest number that is evenly divisible by all numbers from 1 to " << n
		<< " is: " << smallest_range_multiple(n) << endl;

	return 0;
}