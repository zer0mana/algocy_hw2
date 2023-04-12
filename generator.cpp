#include "generator.h"

Generator::Generator(std::vector<char> &binary_alphabet, std::vector<char> &dnk_alphabet) :
    _binary_alphabet(binary_alphabet),
    _dnk_alphabet(dnk_alphabet) {
    binary_short_text = "";
    binary_long_text = "";
    short_text = "";
    long_text = "";
}

void Generator::Run() {

    srand(time(NULL));

    for (size_t i = 0; i < 10000; ++i) {
        binary_short_text += _binary_alphabet[rand() % 2];
        short_text += _dnk_alphabet[rand() % 4];
    }

    for (size_t i = 0; i < 100000; ++i) {
        binary_long_text += _binary_alphabet[rand() % 2];
        long_text += _dnk_alphabet[rand() % 4];
    }
}

std::string Generator::GetShortBinaryPattern(size_t length) {
    auto pos = rand() % (binary_short_text.size() - length);
    return binary_short_text.substr(pos, length);
}

std::string Generator::GetShortDNKPattern(size_t length) {
    auto pos = rand() % (short_text.size() - length);
    return short_text.substr(pos, length);
}

std::string Generator::GetLongBinaryPattern(size_t length) {
    auto pos = rand() % (binary_long_text.size() - length);
    return binary_long_text.substr(pos, length);
}

std::string Generator::GetLongDNKPattern(size_t length){
    auto pos = rand() % (long_text.size() - length);
    return long_text.substr(pos, length);
}