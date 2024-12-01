//
// Created by ChuKhanhhh on 13/10/24.
//
#include <iostream>
#include "Date.h"

#include "../Common/Common.h"

// Method to validate year
bool Date::isValidateYear(const int &year) {
    return year > 1;
}

bool Date::isValidateMonth(const int &m) {
    return 1 <= m && 12 >= m;
}

bool Date::isValidDate(const Date &date) {
    if (!isValidateYear(date.year)) return false;
    if (!isValidateMonth(date.month)) return false;

    // Nếu là năm nhuận, tháng 2 có 29 ngày
    int maxDaysInMonth = date.daysInMonth[date.month - 1];
    if (isLeapYear(date.year) && date.month == 2) {
        maxDaysInMonth = 29; // February in leap year
    }

    return date.day >= 1 && date.day <= maxDaysInMonth;
}

Date Date::createDate(const std::string &title) {
    Date dateObj;
    std::cout << "Nhập " << title << ":\n";

    std::cout << "\nNhập ngày (dd): ";
    std::cin >> dateObj.day;

    std::cout << "\nNhập tháng (mm): ";
    std::cin >> dateObj.month;

    std::cout << "\nNhập năm (yyyy): ";
    std::cin >> dateObj.year;

    // Check if the date is valid
    if (!isValidDate(dateObj)) {
        std::cout << "Ngày không hợp lệ. Vui lòng nhập lại.\n";
    } else {
        std::cout << "Ngày hợp lệ: " << dateObj.day << "/" << dateObj.month << "/" << dateObj.year << std::endl;
    }
    return dateObj;
}

bool Date::isEndDateGreaterThanStartDate(const Date &startDate, const Date &endDate) {
    // Compare years
    if (endDate.year > startDate.year) {
        return true;
    } else if (endDate.year == startDate.year) {
        // Compare months if years are equal
        if (endDate.month > startDate.month) {
            return true;
        } else if (endDate.month == startDate.month) {
            // Compare days if months are equal
            return endDate.day > startDate.day;
        }
    }
    return false; // Return false if endDate is not greater than startDate
}

// Lấy ngày trong tháng
int Date::getDaysInMonth(const int month, const int year) {
    // Array with the number of days in each month (non-leap year)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // If it's February and a leap year, set days to 29
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return daysInMonth[month - 1];
}

Date Date::addDaysToDateManual(const Date &originalDate, const int daysToAdd) {
    int day = originalDate.day;
    int month = originalDate.month;
    int year = originalDate.year;

    // Add the days
    day += daysToAdd;

    // Adjust the day, month, and year based on the added days
    while (true) {
        // Get the number of days in the current month
        const int daysInCurrentMonth = getDaysInMonth(month, year);

        // If the day exceeds the days in the current month, adjust the day and month
        if (day > daysInCurrentMonth) {
            day -= daysInCurrentMonth; // Decrease the day
            month++; // Increase the month

            // If the month exceeds 12, reset to January and increase the year
            if (month > 12) {
                month = 1;
                year++;
            }
        } else {
            break; // Day is valid, exit the loop
        }
    }

    // Return the new Date object
    return Date(day, month, year);
}

Date Date::addMonthsToDateManual(const Date &originalDate, const int monthsToAdd) {
    int day = originalDate.day;
    int month = originalDate.month;
    int year = originalDate.year;

    // tháng hiện tại cộng với số tháng muộn công thêm
    month += monthsToAdd;

    while (month > 12) {
        month -= 12;
        year++; // Increment year for each overflow
    }

    int daysInNewMonth = getDaysInMonth(month, year);
    if (day > daysInNewMonth) {
        day = daysInNewMonth; // Adjust day to last valid day of the month
    }

    return Date(day, month, year);
}

int Date::getTotalDays(const Date &date) {
    int totalDays = 0;

    // Add days for all the years before the current year
    for (int i = 1; i < date.year; ++i) {
        totalDays += (isLeapYear(i) ? 366 : 365);
    }

    // Add days for all the months in the current year
    for (int i = 1; i < date.month; ++i) {
        totalDays += getDaysInMonth(i, date.year);
    }

    // Add days for the current month
    totalDays += date.day;

    return totalDays;
}

// Hàm tính số ngày thừa giữa hai ngày
int Date::calculateExcessDays(const Date &startDate, const Date &endDate) {
    return getTotalDays(endDate) - getTotalDays(startDate);
}

int Date::calculateMonthsBetweenDates(const Date& startDate, const Date& endDate) {
    // Kiểm tra xem ngày kết thúc có trước ngày bắt đầu không
    if (endDate.year < startDate.year || (endDate.year == startDate.year && endDate.month < startDate.month) ||
        (endDate.year == startDate.year && endDate.month == startDate.month && endDate.day < startDate.day)) {
        std::cout << "End date must be greater than start date!" << std::endl;
        return -1;  // Trả về lỗi nếu ngày kết thúc nhỏ hơn ngày bắt đầu
        }

    int monthsDifference = 0;

    // Tính số tháng giữa các năm
    monthsDifference += (endDate.year - startDate.year) * 12;

    // Tính số tháng giữa tháng bắt đầu và tháng kết thúc
    monthsDifference += endDate.month - startDate.month;

    // Nếu ngày kết thúc trước ngày bắt đầu trong tháng, giảm đi 1 tháng
    if (endDate.day < startDate.day) {
        monthsDifference--;
    }

    return monthsDifference;
}

std::string Date::convertDateToString(const Date &date) {
    // Tạo chuỗi cho ngày và tháng với 2 chữ số
    const std::string dayStr = (date.day < 10) ? "0" + std::to_string(date.day) : std::to_string(date.day);
    const std::string monthStr = (date.month < 10) ? "0" + std::to_string(date.month) : std::to_string(date.month);

    // Chuyển đổi năm thành chuỗi
    const std::string yearStr = std::to_string(date.year);

    // Ghép chuỗi với định dạng dd/mm/yyyy
    return dayStr + "/" + monthStr + "/" + yearStr;
}

Date Date::convertStringToDate(const std::string &stringDate) {
    if (10 != stringDate.length() || stringDate[2] != '/' || stringDate[5] != '/') {
        // std::count << "Bắt buộc format của string là DD/MM/YYYY";
        return {0, 0, 0};
    }

    const Date date(stringToInt(stringDate, 0, 2),stringToInt(stringDate, 3, 2), stringToInt(stringDate, 6, 4));
    if(!isValidDate(date)) {
        // std::cout << "Ngày không hợp lệ. Vui lòng nhập lại.\n";
        return {0, 0, 0};
    }
    return date;
}

