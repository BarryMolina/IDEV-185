//
// Created by Barry Molina on 5/15/21.
//

#ifndef MOLINA_MIDTERM_INPUTERROR_H
#define MOLINA_MIDTERM_INPUTERROR_H


// Custom exception class thrown when invalid input is detected
class InputError : public std::exception {
private:
    // Store message as string to avoid memory leaks
    std::string errMessage = "";
public:
    // Default constructor
    explicit InputError() {}
    // Constructor takes error message as parameter
    explicit InputError(const std::string &errMessage) : errMessage(errMessage) {}
    // overridden function can be called through reference to exception superclass
    const char* what() const noexcept override {
        return errMessage.c_str();
    }
};


#endif //MOLINA_MIDTERM_INPUTERROR_H
