#include<iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int start, end;

    // Input range from the user
    std::cout << "Enter the starting number of the range: ";
    std::cin >> start;

    std::cout << "Enter the ending number of the range: ";
    std::cin >> end;

    // Display whether each number in the range is prime or not
    std::cout << "Prime numbers in the range [" << start << ", " << end << "] are: \n";
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            std::cout << i << " is prime.\n";
        } else {
            std::cout << i << " is not prime.\n";
        }
    }

    return 0;
}
