
#include <iostream>
#include <cmath>
using namespace std;

// Check whether a number is even or odd
void checkEvenOdd(int n) {
    if (n % 2 == 0)
        cout << "Type: Even number\n";
    else
        cout << "Type: Odd number\n";
}

// Check whether a number is prime
void checkPrime(int n) {
    if (n < 2) {
        cout << "Prime: No\n";
        return;
    }

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            cout << "Prime: No\n";
            return;
        }
    }

    cout << "Prime: Yes\n";
}

// Analyze multiple numbers
void analyzeNumbers() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Enter a count between 1 and 100.\n";
        return;
    }

    double numbers[100];
    double sum = 0;
    double largest, smallest;

    cout << "Enter " << n << " numbers:\n";

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        sum += numbers[i];

        if (i == 0) {
            largest = smallest = numbers[i];
        } else {
            if (numbers[i] > largest)
                largest = numbers[i];

            if (numbers[i] < smallest)
                smallest = numbers[i];
        }
    }

    cout << "\nSum: " << sum << '\n';
    cout << "Average: " << sum / n << '\n';
    cout << "Largest: " << largest << '\n';
    cout << "Smallest: " << smallest << '\n';
}

// Main program
int main() {
    int choice, number;

    do {
        cout << "\n===== SMART NUMBER ANALYZER =====\n";
        cout << "1. Check Even or Odd\n";
        cout << "2. Check Prime Number\n";
        cout << "3. Calculate Square Root\n";
        cout << "4. Compare Two Numbers\n";
        cout << "5. Analyze Multiple Numbers\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                checkEvenOdd(number);
                break;

            case 2:
                cout << "Enter a number: ";
                cin >> number;
                checkPrime(number);
                break;

            case 3:
                cout << "Enter a number: ";
                cin >> number;

                if (number < 0)
                    cout << "Square root is not real.\n";
                else
                    cout << "Square root: "
                         << sqrt(number) << '\n';
                break;

            case 4: {
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;

                if (a > b)
                    cout << a << " is greater.\n";
                else if (b > a)
                    cout << b << " is greater.\n";
                else
                    cout << "Both numbers are equal.\n";
                break;
            }

            case 5:
                analyzeNumbers();
                break;

            case 0:
                cout << "Thank you for using the analyzer!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
