//
// Created by ChuKhanhhh on 16/11/24.
//

#include "Reader.h"

bool Reader::isValidateEmail(const std::string& email) {
    const size_t length = email.length();

    // Check email length
    if (isBlank(email) || length >= 256) { // Assuming 256 is the max size for an email
        return false; // Email is invalid if empty or too long
    }

    // Find the position of '@'
    const int atPos = email.find(SPECIAL_EMAIL);
    if (atPos == 0 || atPos == length - 1) {
        return false; // '@' must exist, and it cannot be at the start or end
    }

    // Find the position of the last '.'
    const int dotPos = email.find_last_of(DOT);
    if (dotPos < atPos || dotPos == length - 1) {
        return false; // '.' must exist after '@' and cannot be at the end
    }

    return true; // Email is valid
}

bool Reader::isValidateSex(const std::string &sex) {

    // Nếu độ dài bằng 0 hoặc lớn hơn kích thước tối đa, không hợp lệ
    if (isBlank(sex) || sex.size() >= MAX_SIZE) {
        return false;
    }

    // Kiểm tra giá trị "Nam" hoặc "Nữ"
    return (sex == FEMALE || sex == MALE);
}

bool Reader::isValidNationId(const std::string &nationId) {
    // Kiểm tra độ dài có phải là 9 không
    if (nationId.size() != 9) {
        return false;
    }

    // Kiểm tra từng ký tự trong chuỗi xem có phải là chữ số hay không
    for (int i = 0; i < 9; ++i) {
        if (!isdigit(nationId[i])) {
            return false; // Nếu có ký tự nào không phải là số, trả về false
        }
    }

    // Nếu tất cả đều là số và độ dài là 9, trả về true
    return true;
}

bool Reader::isValidReader(const Reader &reader) {
    if(isBlank(reader.code)) {
        std::cout << "\nBắt buộc phải nhập lại mã độc giả. Mã không được để trống." << std::endl;
        return false;
    }

    if(isBlank(reader.fullName)) {
        std::cout << "\nBắt buộc phải nhập lại tên độc giả. Tên không được để trống." << std::endl;
        return false;
    }
    if(!isValidNationId(reader.idNumber)) {
        std::cout << "\nBắt buộc phải nhập lại CMND độc giả. Bắt buộc nhập 9 kí tự và toàn là số" << std::endl;
        return false;
    }
    if(!Date::isValidateYear(reader.dateOfBirth)) {
        std::cout << "\nBắt buộc phải nhập lại năm sinh độc giả. Bị sai format. Bắt buộc nhập YYYY" << std::endl;
        return false;
    }
    if(!isValidateSex(reader.gender)) {
        std::cout << "\nBắt buộc phải nhập lại giới tính độc giả. Nếu là Nam nhập M, nếu là Nữ Nhập F." << std::endl;
        return false;
    }
    if(!isValidateEmail(reader.email)) {
        std::cout << "\nBắt buộc phải nhập lại email của độc giả. Bị sai format. Ví dụ: a@gmail.com" << std::endl;
        return false;
    }
    if(!Date::isValidDate(reader.issueDate)) {
        std::cout << "Ngày tạo thẻ không hợp lệ. Vui lòng nhập lại.\n";
        return false;
    }

    if(!Date::isValidDate(reader.expiryDate)) {
        std::cout << "Ngày hết hạn thẻ không hợp lệ. Vui lòng nhập lại.\n";
        return false;
    }

    const std::string issueDateString = Date::convertDateToString(reader.issueDate);
    const std::string expiryDateString = Date::convertDateToString(reader.expiryDate);

    if (!Date::isEndDateGreaterThanStartDate(reader.issueDate, reader.expiryDate)) {
        printf("Ngày hết hạn thẻ %s phải lớn hơn ngày mượn thẻ %s.\n", issueDateString.c_str(), expiryDateString.c_str());
        return false;
    }

    if(Date::calculateMonthsBetweenDates(reader.issueDate, reader.expiryDate) < 48) {
        const Date next48Month = Date::addMonthsToDateManual(reader.issueDate, 48);
        printf("Ngày hết hạn thẻ %s phải từ 48 tháng kể từ ngày lập thẻ %s. Ngày hết hạn thẻ phải lớn hơn %s \n", issueDateString.c_str(), expiryDateString.c_str(), Date::convertDateToString(next48Month).c_str());
        return false;
    }
    return true;
}

void Reader::addReaderToArray(const Reader &reader) {
    if(index > MAX_SIZE) {
        std::cout << "Reader list is full. Cannot add more readers.\n";
        return;
    }

    if(!isValidReader(reader)) {
        return;
    }

    if(isBlank(readers[0].code)) {
        index = 0;
    }

    readers[index] = reader;
    index++;
}

void Reader::printReader(const Reader &reader) {
    std::cout << "Mã độc giả: " << reader.code << "\n";
    std::cout << "Tên tác giả: " << reader.fullName << "\n";
    std::cout << "CCCD: " << reader.idNumber << "\n";
    std::cout << "Ngày sinh: " << reader.dateOfBirth << "\n";
    std::cout << "Giới tính: " << reader.gender
            << " (" << (reader.gender == MALE ? "Nam" : "Nữ")
            << " )" << std::endl << "\n";
    std::cout << "Email: " << reader.email << "\n";
    std::cout << "Địa chỉ: " << reader.address << "\n";
    std::cout << "Ngày lập thẻ: " << Date::convertDateToString(reader.issueDate).c_str() << "\n";
    std::cout << "Ngày hết hạn thẻ: " << Date::convertDateToString(reader.expiryDate).c_str() << "\n\n";
}

void Reader::displayAllReaders() {
    for (int i = 0; i < index; ++i) {
        printf("\nThông tin độc giả thứ [%d] trong hệ thống là: ", index);
        printReader(readers[index]);
    }
}

