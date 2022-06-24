//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

using namespace std;

class DeckFileNotFound : public std::exception {
public:
//    std::string s ="Deck File Error: File not found";
//    const char* what () {
////        char const *p = "Deck File Error: File not found";
//        return s.c_str();
//    }

    const char * what() const noexcept override {
        return "Deck File Error: File not found";
    }
};



class DeckFileInvalidSize : public std::exception {
public:
//    std::string s ="Deck File Error: Deck size is invalid";
//    const char* what () {
//        return s.c_str();
//    }

    const char * what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};


class RenterLimitException : public std::exception {
public:
    const char * what() const noexcept override {
        return "No available copies.";
    }
};


struct DeckFileFormatError : public std::exception
{
    std::string err = "Deck File Error: File format error in line ";
    std::string lineNumberStr;
    DeckFileFormatError(std::string& lineNumber) : lineNumberStr(lineNumber) {}
    const char * what() const noexcept override {
        std::string errorMsg = "Deck File Error: File format error in line " + lineNumberStr;
        return errorMsg.c_str();
    }


};




#endif //HW4_EXCEPTION_H
