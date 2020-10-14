#include <iostream>
#include <cstdint>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::uint64_t;
using std::pow;

// Difference between the sum squared and sum of squares of the first n natural numbers
uint64_t sum_square_difference(int n) {
	// sum squared
	uint64_t sum = pow(n * (n + 1) / 2, 2);
	// sum of the squares
	uint64_t sum_square = (2*n + 1) * (n + 1) * n / 6;

	return sum - sum_square;
}

int main() {
	int n;
	cout << "Enter a positive number: ";
	cin >> n;
	cout << "Sum square difference of the first " << n << " natural numbers is: "
		 << sum_square_difference(n) << endl;
	return 0;
}