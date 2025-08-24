// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>  // For standard exceptions like std::runtime_error
#include <exception>  // For std::exception base class
#include <string>

// Custom exception class derived from std::exception
class CustomException : public std::exception {
public:
    CustomException(const std::string& message) : msg_(message) {}
    // Override what() to return error message
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

bool do_even_more_custom_application_logic()
{
    // TODO Complete: Throw any standard exception
    throw std::runtime_error("Error in even more custom application logic.");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}

void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        // Wrapping this call in a try-block to catch standard exceptions
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "[std::exception caught in do_custom_application_logic] Message: " << e.what() << std::endl;
    }

    // Throw a custom exception derived from std::exception
    throw CustomException("Custom exception thrown from do_custom_application_logic.");

    std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den)
{
    // Throw a standard exception for divide-by-zero
    if (den == 0.0f) {
        throw std::invalid_argument("Division by zero attempted.");
    }

    return (num / den);
}

void do_division() noexcept
{
    float numerator = 10.0f;
    float denominator = 0;

    try {
        // Wrapping divide call to catch only std::invalid_argument
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[std::invalid_argument caught in do_division] Message: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;
    // Function calls that may throw exceptions
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException& ce) {
        // Custom exception handler at top level
        std::cout << "[CustomException caught in main] Message: " << ce.what() << std::endl;
    }
    catch (const std::exception& e) {
        // Standard exception catch for unhandled std exceptions
        std::cout << "[std::exception caught in main] Message: " << e.what() << std::endl;
    }
    catch (...) {
        // Catch all handler for any unknown or unexpected exceptions
        std::cout << "[Unknown exception caught in main]" << std::endl;
    }

    std::cout << "Program completed gracefully." << std::endl;
    return 0;
}