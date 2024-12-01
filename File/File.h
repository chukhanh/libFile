//
// Created by ChuKhanhhh on 21/11/24.
//

#ifndef FILE_H
#define FILE_H
#include <iostream>

enum FileType { READER, BOOK, BORROWING, SLIP_RETURN, UNKNOWN };


struct File {
    std::string fileName; // Tên File
    std::string pathFile; // Full path to the file
    std::string type; // loại file
    FileType categoryFile; // File dành cho loại danh mục

    // Parameterized Constructor
    explicit File(const std::string &name = "", const std::string &path = "", const std::string &type = "",
                  const FileType &categoryFile = UNKNOWN)
        : fileName(name), pathFile(path), type(type), categoryFile(categoryFile) {
    }

    // Function to display file information
    void displayFileInfo() const {
        std::cout << "File Information:" << std::endl;
        std::cout << "Name     : " << fileName << std::endl;
        std::cout << "Path     : " << pathFile << std::endl;
        std::cout << "Type     : " << type << std::endl;
        std::cout << "categoryFile     : " << categoryFile << std::endl;
    }

    // Get full file path
    static std::string getFullPath(const File &file);

    // Tạo default File
    static void initializeDefaultFile() {
        readDataFromFile(READER);
        readDataFromFile(BOOK);
        readDataFromFile(BORROWING);
        readDataFromFile(SLIP_RETURN);
    }

    // xuất data ra File theo type
    static void exportToFile(const FileType &type);

    // đọc giữ liệu từ File
    static void readDataFromFile(const FileType &type);

    // Kiếm File theo type
    static File findFileByType(const FileType &type);

    // Tạo file
    static void createFile(const std::string &fullPath);
};
#endif //FILE_H
