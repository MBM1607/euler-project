#include <iostream>
#include <cstdint>

using std::cin;
using std::cout;
using std::endl;
using std::uint64_t;


// Get the sum of all even fibonacci terms whose value do not exceed the limit
uint64_t sum_even_fibonacci(int limit) {
	uint64_t sum = 0;
	uint64_t prev = 1;
	uint64_t current = 1;
	uint64_t tmp;

	while (current < limit) {
		if (current % 2 == 0)
			sum += current;

		// give the previous term current value and add the two for the next term
		tmp = prev + current;
		prev = current;
		current = tmp;
	}
	return sum;
}


int main() {
	int n;
	cout << "Enter the limit: ";
	cin >> n;

	cout << "Sum of the even-values fibonnaci terms below " << n << " is: "
		 << sum_even_fibonacci(n) << endl;

	return 0;
}