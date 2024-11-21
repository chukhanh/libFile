//
// Created by ChuKhanhhh on 21/11/24.
//

#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "../Common/Common.h"

struct File {
    std::string fileName; // Tên File
    std::string pathFile; // Full path to the file
    std::string type; // loại file
    std::string categoryFile; // File dành cho loại danh mục

    static File files[MAX_SIZE];
    static int index;

    // Parameterized Constructor
    File(const std::string &name = "", const std::string &path = "", const std::string &type = "",
         const std::string &categoryFile = "")
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
        files[0] = File("Reader.txt", "File/", "txt", "Reader");
        index = 0;
        std::cout << "Default file initialized!" << std::endl;
    }


    // xuất data ra File theo type
    static void exportToFile(const std::string &type);

    // Kiếm file theo thể loại Reader, Book, etc
    static File findFileByType(const std::string &type);
};
#endif //FILE_H
