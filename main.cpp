#include <iostream>
#include "algorithms.h"
#include "generator.h"
#include <vector>

void ShortBinaryAlphabet(Generator &generator, std::string &short_binary_text, std::vector<char> &binary_alphabet) {
    std::cout << "short binary" << '\n';

    std::cout << '\n' << "naive algorithm" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetShortBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += NaiveAlgorithmTime(short_binary_text, pattern, binary_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP standard" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetShortBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPStandardTime(short_binary_text, pattern, binary_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP refined" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetShortBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPRefinedTime(short_binary_text, pattern, binary_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }
}

void ShortDNKAlphabet(Generator &generator, std::string &short_dnk_text, std::vector<char> &dnk_alphabet) {
    std::cout << '\n' << "short dnk" << '\n';

    std::cout << '\n' << "naive algorithm" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetShortDNKPattern(size);

        for (int i = 0; i < 10; i++) {
            res += NaiveAlgorithmTime(short_dnk_text, pattern, dnk_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP standard" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetShortDNKPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPStandardTime(short_dnk_text, pattern, dnk_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP refined" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetShortDNKPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPRefinedTime(short_dnk_text, pattern, dnk_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }
}

void LongBinaryAlphabet(Generator &generator, std::string &long_binary_text, std::vector<char> &binary_alphabet) {
    std::cout << '\n' << "long binary" << '\n';

    std::cout << '\n' << "naive algorithm" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetLongBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += NaiveAlgorithmTime(long_binary_text, pattern, binary_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP standard" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetLongBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPStandardTime(long_binary_text, pattern, binary_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP refined" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetLongBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPRefinedTime(long_binary_text, pattern, binary_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }
}

void LongDNKAlphabet(Generator &generator, std::string &long_dnk_text, std::vector<char> &dnk_alphabet) {
    std::cout << '\n' << "long binary" << '\n';

    std::cout << '\n' << "naive algorithm" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetLongDNKPattern(size);

        for (int i = 0; i < 10; i++) {
            res += NaiveAlgorithmTime(long_dnk_text, pattern, dnk_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP standard" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetLongBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPStandardTime(long_dnk_text, pattern, dnk_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }

    std::cout << '\n' << "KMP refined" << '\n';
    for (size_t size = 100; size <= 3000; size += 100) {
        int res = 0;

        auto pattern = generator.GetLongBinaryPattern(size);

        for (int i = 0; i < 10; i++) {
            res += KMPRefinedTime(long_dnk_text, pattern, dnk_alphabet).first;
        }

        res /= 10;

        std::cout << res << ',';
    }
}

int main() {

    std::vector<char> binary_alphabet = {'a', 'b'};
    std::vector<char> dnk_alphabet = {'a', 'b', 'c', 'd'};

    Generator generator(binary_alphabet, dnk_alphabet);

    generator.Run();

    auto pattern = generator.GetLongBinaryPattern(100);

    auto short_binary_text = generator.binary_short_text;
    auto short_dnk_text = generator.short_text;
    auto long_binary_text = generator.binary_long_text;
    auto long_dnk_text = generator.long_text;

    for (size_t size = 100; size <= 3000; size += 100) {
        std::cout << size << ',';
    }

    // short binary
    ShortBinaryAlphabet(generator, short_binary_text, binary_alphabet);

    // short dnk
    ShortDNKAlphabet(generator, short_dnk_text, dnk_alphabet);

    // long binary
    LongBinaryAlphabet(generator, long_binary_text, binary_alphabet);

    // long dnk
    LongDNKAlphabet(generator, long_dnk_text, dnk_alphabet);

    return 0;
}