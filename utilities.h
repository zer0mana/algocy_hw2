#ifndef HW2_UTILITIES_H
#define HW2_UTILITIES_H

#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<size_t, size_t*> getStandardBr(const std::string& mask);

std::pair<size_t, size_t*> getRefinedBR(const std::string& mask);

class Automaton {
private:
    size_t final_pos;
    size_t now_pos = 0;
    size_t num_of_op;
    std::vector<std::unordered_map<char, size_t>> tb;

public:
    Automaton(const std::string &mask, const std::vector<char> &alphabet);

    bool operator()(char symbol);

    size_t getNumOfOp() const;
};

#endif
