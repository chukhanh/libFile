#include <iostream>
#include "Common.h"
#include <cctype>

// Hàm tạo giá trị và in ra tiêu đề
void createValue(const std::string& title, std::string& value) {
    std::cout << "\n" << std::endl;
    // Print the title
    std::cout << "Nhập " << title << ": ";

    // Use std::getline to read the entire line into the std::string 'value'
    std::getline(std::cin, value);
}

// Function to create and print a value of type double
void createValue(const std::string (&title), double &value) {
    std::cout << "\n" << std::endl;

    while (true) {
        std::cout << "Nhập " << title << ": ";
        std::cin >> value;

        // Kiểm tra nếu nhập vào không phải là số thực (double)
        if (std::cin.fail()) {
            std::cin.clear(); // Xóa trạng thái lỗi của cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua tất cả các ký tự không hợp lệ
            std::cout << "Giá trị nhập vào không hợp lệ. Vui lòng nhập một số thực.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Loại bỏ các ký tự thừa trong dòng
            break; // Thoát vòng lặp nếu nhập đúng
        }
    }
}

// Function to create and print a value of type int
void createValue(const std::string (&title), int &value) {
    std::cout << "\n" << std::endl;

    while (true) {
        std::cout << "Nhập " << title << ": ";
        std::cin >> value;

        // Kiểm tra nếu nhập vào không phải là số nguyên
        if (std::cin.fail()) {
            std::cin.clear(); // Xóa trạng thái lỗi của cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Bỏ qua tất cả các ký tự đã nhập vào
            std::cout << "Giá trị nhập vào không hợp lệ. Vui lòng nhập một số nguyên.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Loại bỏ ký tự thừa trong dòng
            break; // Thoát vòng lặp nếu nhập đúng
        }
    }
}

bool isBlank(const std::string& str) {
    // Check if the string is empty or contains only whitespace
    return str.empty();
}

int stringToInt(const std::string &str, const int start, const int length) {
    int result = 0;
    for (int i = start; i < start + length; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            // std::count << "Không thể chuyển giá trị trong string này";
            return 0;
        }
        result = result * 10 + (str[i] - '0');
    }
    return result;
}
