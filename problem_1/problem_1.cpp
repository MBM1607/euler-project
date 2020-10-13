#include <iostream>
#include <cstdint>

using std::cin;
using std::cout;
using std::endl;
using std::uint64_t;


// Get sum of all multiples of 3 or 5 below limit
uint64_t sum_multiples_3_or_5(int limit) {
	uint64_t sum = 0;
	for (int i = 1; i < limit; i++) {
		sum += i % 3 == 0 || i % 5 == 0 ? i : 0;
	}
	return sum;
}


int main() {
	int n;
	cout << "Enter the limit: ";
	cin >> n;

	cout << "Sum of multiples of 3 or 5 bellow " << n << " is: "
		<< sum_multiples_3_or_5(n) << endl;

	return 0;
}
