#ifndef HW2_GENERATOR_H
#define HW2_GENERATOR_H

#include <iostream>
#include <vector>

class Generator {
private:

    std::vector<char> &_binary_alphabet;
    std::vector<char> &_dnk_alphabet;

public:

    std::string binary_short_text;
    std::string binary_long_text;
    std::string short_text;
    std::string long_text;

    Generator(
            std::vector<char> &binary_alphabet,
            std::vector<char> &dnk_alphabet);

    void Run();

    std::string GetShortBinaryPattern(size_t length);

    std::string GetShortDNKPattern(size_t length);

    std::string GetLongBinaryPattern(size_t length);

    std::string GetLongDNKPattern(size_t length);
};


#endif //HW2_GENERATOR_H
