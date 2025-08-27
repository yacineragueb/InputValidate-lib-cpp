# 📚 clsInputValidate Library (C++)

A small **C++ utility library** that provides helper methods for validating user input (numbers, dates, ranges, etc.).  
It also integrates with the [clsDate library](https://github.com/yacineragueb/Date-lib-cpp) to validate and compare dates.

This project is perfect for learning **Object-Oriented Programming (OOP)** in C++ and for building reusable libraries.

---

## 🚀 Features

- ✅ Validate if a number is between two values (supports `short`, `int`, `float`, `double`).  
- ✅ Validate if a `clsDate` is between two given dates.  
- ✅ Read and validate integer input from the user.  
- ✅ Read and validate double input from the user.  
- ✅ Support for retrying input with custom error messages.  
- ✅ Date validation using `clsDate`.

---

## 💻 Example Usage

```cpp
#include <iostream>
#include "clsInputValidate.h"

int main() {
    int number = clsInputValidate::ReadIntNumber("Invalid input, try again: ");
    std::cout << "You entered: " << number << std::endl;

    int bounded = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter a number between 1 and 10: ");
    std::cout << "Number in range: " << bounded << std::endl;

    double d = clsInputValidate::ReadDblNumber("Invalid double, try again: ");
    std::cout << "You entered: " << d << std::endl;

    double bounded2 = clsInputValidate::ReadDblNumberBetween(0.5, 5.5, "Enter a double between 0.5 and 5.5: ");
    std::cout << "Double in range: " << bounded2 << std::endl;

    // Validate Dates
    clsDate from(1, 1, 2023);
    clsDate to(31, 12, 2023);
    clsDate test(15, 6, 2023);

    if (clsInputValidate::IsDateBetween(test, from, to))
        std::cout << "Date is within range!" << std::endl;
    else
        std::cout << "Date is out of range!" << std::endl;

    return 0;
}
```

---

## 🛠️ Requirements: 
- A C++ compiler (GCC, Clang, MSVC, etc.)
