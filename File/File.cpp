//
// Created by ChuKhanhhh on 21/11/24.
//

#include "File.h"
#include <fstream>
#include "../Common/Common.h"

#include "../Reader/Reader.h"

std::string File::getFullPath(const File &file) {
    return file.pathFile + file.fileName + "." + file.type;
}

File File::findFileByType(const FileType &type) {
    // Create a default File object with corresponding type
    switch (type) {
        case READER:
            return File("Reader", DEFAULT_SAVE_FILE, DEFAULT_TYPE_FILE, READER);
        case BOOK:
            return File("Book", DEFAULT_SAVE_FILE, DEFAULT_TYPE_FILE, BOOK);
        case BORROWING:
            return File("BorrowingBook", DEFAULT_SAVE_FILE, DEFAULT_TYPE_FILE, BORROWING);
        case SLIP_RETURN:
            return File("SlipReturnBook", DEFAULT_SAVE_FILE, DEFAULT_TYPE_FILE, SLIP_RETURN);
        default:
            std::cout << "Unknown file type requested: " << type << std::endl;
            return File("", "", "", UNKNOWN);
    }
}

void File::createFile(const std::string &fullPath) {
    // Ensure the directory exists (create it if necessary)
    std::filesystem::create_directories(fullPath);

    // Attempt to open the file in the default directory
    std::ofstream fileOfstream(fullPath);
}


void File::exportToFile(const FileType &type) {
    File file = findFileByType(type);
    if (UNKNOWN == file.categoryFile) return;
    std::string fullPath = getFullPath(file);
    std::ofstream fileOfstream(fullPath);

    if (!fileOfstream.is_open()) {
        std::cout << "Error: Unable to open file " << file.pathFile <<
                ". Creating a new file in the default directory.\n";
        createFile(fullPath);
    }

    switch (type) {
        case READER: {
            fileOfstream << "Code,Full Name,ID Number,Date of Birth,Gender,Email,Address,Issue Date,Expiry Date\n";
        }
        default: std::cout << "Lỗi: Không thể xuất file bằng type " << type << std::endl;
    }

    fileOfstream.close();
    std::cout << "Xuất file thành công: " << file.fileName << std::endl << "\n";
}

void File::readDataFromFile(const FileType &type) {
    File file = findFileByType(type);
    if (UNKNOWN == file.categoryFile) return;
    std::string fullPath = getFullPath(file);
    std::ofstream fileOfstream(fullPath);

    if (!fileOfstream.is_open()) {
        createFile(fullPath);
    }

    switch (type) {
        case READER: {
            fileOfstream << "Code,Full Name,ID Number,Date of Birth,Gender,Email,Address,Issue Date,Expiry Date\n";
        }
        break;
        case BOOK: {
            // fileOfstream << "Code,Full Name,ID Number,Date of Birth,Gender,Email,Address,Issue Date,Expiry Date\n";
        }
        break;
        case BORROWING: {
            // fileOfstream << "Code,Full Name,ID Number,Date of Birth,Gender,Email,Address,Issue Date,Expiry Date\n";
        }
        break;
        case SLIP_RETURN: {
            // fileOfstream << "Code,Full Name,ID Number,Date of Birth,Gender,Email,Address,Issue Date,Expiry Date\n";
        }
        break;
        default: std::cout << "Lỗi: Không thể xuất file bằng type " << type << std::endl;
    }

    fileOfstream.close();
    std::cout << "Đọc dữ liệu từ File: " << file.fileName << " Thành công." << std::endl << "\n";
}
