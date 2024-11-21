//
// Created by ChuKhanhhh on 21/11/24.
//

#include "File.h"
#include <fstream>

#include "../Reader/Reader.h"

std::string File::getFullPath(const File &file) {
    return file.pathFile + file.fileName;
}

void File::exportToFile(const std::string &type) {
    File file = findFileByType(type);
    std::ofstream fileOfstream(file.pathFile);

    if (!fileOfstream.is_open()) {
        std::cout << "Lỗi: Không thể mở file " << file.pathFile << std::endl;
        return;
    }

    switch (type) {
        case "Reader": {
            fileOfstream << "Code,Full Name,ID Number,Date of Birth,Gender,Email,Address,Issue Date,Expiry Date\n";
            for (int i = 0; i < index; ++i) {
                const Reader &reader = Reader::readers[i];
                fileOfstream << reader.code << ","
                        << reader.fullName << ","
                        << reader.idNumber << ","
                        << reader.dateOfBirth << ","
                        << reader.gender << ","
                        << reader.email << ","
                        << reader.address << ","
                        << Date::convertDateToString(reader.issueDate) << ","
                        << Date::convertDateToString(reader.expiryDate) << "\n";
            }
            break;
        }
        default: std::cout << "Lỗi: Không thể xuất file bằng type " << type << std::endl;
    }

    fileOfstream.close();
    std::cout << "Xuất file thành công: " << file.fileName << std::endl << "\n";
}

File File::findFileByType(const std::string &type) {
    File file;
    for (int i = 0; i < index; ++i) {
        if (type == files[i].type) {
            file = files[i];
            break;
        }
    }
    return file;
}
