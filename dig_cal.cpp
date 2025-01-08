#include <iostream>
#include <limits> // for numeric_limits

// Function to validate and get a numeric input
double getNumericInput(const std::string& prompt) {
    double num;
    while (true) {
        std::cout << prompt;
        if (std::cin >> num) {
            // Check if the input ends correctly
            if (std::cin.peek() == '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any remaining input
                break; // Input is valid
            } else {
                std::cout << "Invalid input. Please enter a valid numeric value.\n";
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            }
        } else {
            std::cout << "Invalid input. Please enter a valid numeric value.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    return num;
}

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double sub(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    return a / b;
}

int main() {
    double a, b;
    int choice;

    while (true) {
        // Display menu
        std::cout << "\n===== Calculator Menu =====\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        std::cout << "5. Exit\n";
        std::cout << "===========================\n";
        std::cout << "Enter your choice (1-5): ";

        // Get user choice
        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        // Exit the program
        if (choice == 5) {
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        }

        // Validate choice range
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            continue;
        }

        // Get operands
        a = getNumericInput("Enter the first operand: ");
        b = getNumericInput("Enter the second operand: ");

        // Perform operation based on user choice
        double result;
        switch (choice) {
            case 1:
                result = add(a, b);
                std::cout << "Result of addition: " << result << "\n";
                break;
            case 2:
                result = sub(a, b);
                std::cout << "Result of subtraction: " << result << "\n";
                break;
            case 3:
                result = multiply(a, b);
                std::cout << "Result of multiplication: " << result << "\n";
                break;
            case 4:
                if (b != 0) {
                    result = divide(a, b);
                    std::cout << "Result of division: " << result << "\n";
                } else {
                    std::cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            default:
                std::cout << "Error: Unknown choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
