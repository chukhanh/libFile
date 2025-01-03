//
// Created by ChuKhanhhh on 13/10/24.
//

#ifndef DATE_H
#define DATE_H

// struct Date
struct Date {
    int year{};
    int month{};
    int day{};
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Constructor
    Date() : day(0), month(0), year(0) {}
    Date(const int d, const int m, const int y) : day(d), month(m), year(y) {}

    // Method to check if a year is a leap year
    static bool isLeapYear(const int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Kiểm tra Date
    static bool isValidDate(const Date &date);

    //Kiểm tra năm
    static bool isValidateYear(const int &year);

    // Kiểm tra tháng
    static bool isValidateMonth(const int &m);

    // Tạo ngày
    static Date createDate(const std::string &title);

    // Hàm cộng thêm số ngày vào ngày đã nhập
    static Date addDaysToDateManual(const Date &originalDate, int daysToAdd);

    // Lấy ngày trong tháng
    static int getDaysInMonth(int month, int year);

    // Hàm cộng thêm số tháng vào ngày đã nhập
    static Date addMonthsToDateManual(const Date &originalDate, int monthsToAdd);

    // Hàm tính số ngày từ 01/01/0000
    static int getTotalDays(const Date &date);

    // Kiểm tra endDate có lớn hơn startDate không
    static bool isEndDateGreaterThanStartDate(const Date &startDate, const Date &endDate);

    // Hàm tính số ngày thừa giữa hai ngày
    static int calculateExcessDays(const Date &startDate, const Date &endDate);

    // Hàm tính số tháng thừa giữa hai ngày
    static int calculateMonthsBetweenDates(const Date &startDate, const Date &endDate);

    // Convert Date to String
    static std::string convertDateToString(const Date &date);

    // Convert String to Date
    static Date convertStringToDate(const std::string &stringDate);
};


#endif //DATE_H
