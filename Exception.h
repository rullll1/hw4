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
    std::string s;
    DeckFileFormatError(std::string& ss) : s(ss) {}
    ~DeckFileFormatError() throw () {} // Updated
//    const char* what() const throw() { return s.c_str(); }

    const char * what() const noexcept override {
        return s.c_str();
    }


};




#endif //HW4_EXCEPTION_H
