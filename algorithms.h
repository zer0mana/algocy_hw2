#ifndef HW2_ALGORITHMS_H
#define HW2_ALGORITHMS_H

#include <iostream>
#include <vector>
#include "time.h"

std::pair<int, std::vector<size_t>> NaiveAlgorithmTime(
        const std::string &text,
        const std::string &mask,
        const std::vector<char> &alphabet);

std::pair<int, std::vector<size_t>> KMPStandardTime(
        const std::string &text,
        const std::string &mask,
        const std::vector<char> &alphabet);

std::pair<int, std::vector<size_t>> KMPRefinedTime(
        const std::string &text,
        const std::string &mask,
        const std::vector<char> &alphabet);

std::pair<int, std::vector<size_t>> KMPAutomatonTime(
        const std::string &text,
        const std::string &mask,
        const std::vector<char> &alphabet);

#endif
