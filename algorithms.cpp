#include "algorithms.h"
#include "utilities.h"
#include <chrono>
#include <string>
#include <vector>

using std::string;

/// Наивный алгоритм нахождения всех вхождений.
/// \param text - текст.
/// \param mask - шаблон поиска.
/// \param alphabet - алфавит.
/// \return Пару количества операций сравнения и вектора индексов вхождений.
std::pair<int, std::vector<size_t>> NaiveAlgorithmTime(const string &text,
                                                          const string &mask,
                                                          const std::vector<char> &alphabet) {
    size_t num_of_op = 0;
    std::vector<size_t> result;
    size_t text_length = text.length();
    size_t mask_length = mask.length();
    for (size_t i = 0; i <= text_length - mask_length; ++i) {
        bool found = true;
        for (size_t j = 0; j < mask_length; ++j) {
            ++num_of_op;
            if (text[i + j] != mask[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            result.push_back(i);
        }
    }
    return {num_of_op, result};
}

/// Алгоритм КМП в его стандартном виде.
/// \param text - текст.
/// \param mask - шаблон поиска.
/// \param alphabet - алфавит.
/// \return Пару количества операций сравнения и вектора индексов вхождений.
std::pair<int, std::vector<size_t>> KMPStandardTime(const string &text,
                                                       const string &mask,
                                                       const std::vector<char> &alphabet) {
    size_t num_of_op = 0;
    std::vector<size_t> result;
    size_t text_length = text.size();
    size_t mask_length = mask.size();
    auto standardBr = getStandardBr(mask);
    num_of_op = standardBr.first;
    auto* br = standardBr.second;
    size_t i = 0;
    size_t j = 0;
    while (i < text_length) {
        if (++num_of_op && text[i] == mask[j]) {
            ++i;
            ++j;
        } else {
            j == 0 ? ++i : (j = br[j - 1]);
        }
        if (j == mask_length) {
            result.push_back(i - j);
            j = br[j - 1];
        }
    }
    delete[] br;
    return {num_of_op, result};
}

/// Алгоритм КМП с уточнёнными гранями.
/// \param text - текст.
/// \param mask - шаблон поиска.
/// \param alphabet - алфавит.
/// \return Пару количества операций сравнения и вектора индексов вхождений.
std::pair<int, std::vector<size_t>> KMPRefinedTime(const string &text,
                                                      const string &mask,
                                                      const std::vector<char> &alphabet) {
    size_t num_of_op = 0;
    std::vector<size_t> result;
    size_t text_length = text.size();
    size_t mask_length = mask.size();
    auto refinedBr = getRefinedBR(mask);
    num_of_op = refinedBr.first;
    auto* brs = refinedBr.second;
    size_t i = 0;
    size_t j = 0;
    while (i < text_length) {
        if (text[i] == mask[j]) {
            ++i;
            ++j;
        } else {
            j == 0 ? ++i : (j = brs[j - 1]);
        }
        if (j == mask_length) {
            result.push_back(i - j);
            j = brs[j - 1];
        }
    }
    delete[] brs;
    return {num_of_op, result};
}

