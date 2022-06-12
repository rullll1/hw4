//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

using namespace std;

class DeckFileNotFound : public std::exception {
public:
    const char* what () {
        char const *p = "Deck File Error: File not found";
        return p;
//        return "Deck File Error: File not found";
    }
};


//class DeckFileFormatError : public std::exception {
//public:
//    const char* what () {
//        char const *p = "Deck File Error: File not found";
//        return p;
////        return "Deck File Error: File not found";
//    }
//};


class DeckFileInvalidSize : public std::exception {
public:
    const char* what () {
        char const *p = "Deck File Error: Deck size is invalid";
        return p;
//        return "Deck File Error: File not found";
    }
};


struct DeckFileFormatError : public std::exception
{
    std::string s;
    DeckFileFormatError(std::string ss) : s(ss) {}
    ~DeckFileFormatError() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};




#endif //HW4_EXCEPTION_H
