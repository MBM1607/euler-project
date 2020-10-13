#include <cstdint>
#include <iostream>

using std::uint64_t;
using std::cin;
using std::cout;
using std::endl;

// Reverse a number
uint64_t reverse(uint64_t n) {
	uint64_t reversed = 0;
	while (n > 0) {
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}
	return reversed;
}


bool is_palindrome(uint64_t n) {
	return n == reverse(n);
}

// Return the maximum palindrom product of two n-digit numbers
uint64_t max_palindrome_product(int n) {
	// get maximum and minimum n-digit number
	int max_number = 0, min_number = 0, max_palindrome = 0;
	for (int i = 0; i < n; i++) {
		max_number = max_number * 10 + 9;
		min_number *= 10;
	}

	for (int i = max_number; i >= min_number; i--)
		for (int j = max_number; j >= i && i * j > max_palindrome; j--)
			if (is_palindrome(i * j))
				max_palindrome = i * j;
	return max_palindrome;
}


int main() {
	int n;
	cout << "Insert a positive number: ";
	cin >> n;
	cout << "The largest palindrom product of two " << n << "-digit is: "
		<< max_palindrome_product(n) << endl;
	return 0;
}