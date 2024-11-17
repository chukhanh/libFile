//
// Created by ChuKhanhhh on 16/11/24.
//

#ifndef READER_H
#define READER_H
#include <iostream>

#include "../Common/Common.h"
#include "../Date/Date.h"

// Struct to store reader card information
struct Reader {
    std::string code; // Reader Code
    std::string fullName; // Full name
    std::string idNumber; // National ID or passport number
    int dateOfBirth; // Date of birth
    std::string gender; // Gender
    std::string email; // Email address
    std::string address; // Residential address
    Date issueDate; // Card issue date
    Date expiryDate; // Card expiry date (48 months from the issue date)

    static Reader readers[MAX_SIZE];  // Array of Reader objects
    static int index;

    // Constructor to initialize the Reader
    Reader::Reader(const std::string &readerCode, const std::string &name, const std::string &id,
                   const int &dob, const std::string &gen, const std::string &email, const std::string &addr,
                   const Date &issue, const Date &expiry)
        : code(readerCode), fullName(name), idNumber(id), dateOfBirth(dob), gender(gen),
          email(email), address(addr), issueDate(issue), expiryDate(expiry) {

        addReaderToArray(*this);
    }

    // Kiểm tra email từ chuỗi
    static bool isValidateEmail(const std::string &email);

    // Kiểm tra giới tính từ chuỗi
    static bool isValidateSex(const std::string &sex);

    // Kiểm tra giá trị nhập vào của CMND
    static bool isValidNationId(const std::string &nationId);

    // Kiểm tra thông tin Reader
    static bool isValidReader(const Reader &reader);

    // thêm Reader vào mảng
    static void addReaderToArray(const Reader &reader );

};


#endif //READER_H
