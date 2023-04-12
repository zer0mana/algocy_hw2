#include "utilities.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using std::string;

/// Получает список граней.
/// \param mask - шаблон.
/// \return Пару значений количества значений и динамического массива.
std::pair<size_t, size_t*> getStandardBr(const string& mask) {
    size_t num_of_op = 0;
    auto* br = new size_t[mask.size()];
    br[0] = 0;
    for (size_t i = 1; i < mask.size(); ++i) {
        size_t prev = br[i - 1];
        if (++num_of_op && mask[i] == mask[prev]) {
            br[i] = prev + 1;
        } else if (prev == 0) {
            br[i] = 0;
        } else {
            do {
                prev = br[prev - 1];
            } while (prev > 0 && ++num_of_op && mask[i] != mask[prev]);
            if (++num_of_op && mask[i] == mask[prev]) {
                ++prev;
            }
            br[i] = prev;
        }
    }
    return {num_of_op, br};
}

/// Получает список уточ. граней.
/// \param mask - шаблон.
/// \return Пару значений количества значений и динамического массива.
std::pair<size_t, size_t*> getRefinedBR(const string& mask) {
    auto br_res = getStandardBr(mask);
    size_t num_of_op = br_res.first;
    auto* br = br_res.second;
    auto* brs = new size_t[mask.size()];
    brs[0] = 0;
    for (size_t i = 1; i < mask.size(); ++i) {
        brs[i] = ++num_of_op && mask[br[i]] != mask[i + 1] ? br[i] : brs[br[i] ? br[i] - 1 : 0];
    }
    return {num_of_op, brs};
}

/// Создаёт автомат.
/// \param mask - шаблон.
/// \param alphabet - алфавит.
Automaton::Automaton(
        const string &mask,
        const std::vector<char> &alphabet) {
    final_pos = mask.size();
    tb.resize(final_pos + 1);
    auto standardBr = getStandardBr(mask);
    num_of_op = standardBr.first;
    auto* br = standardBr.second;
    for (size_t i = 0; i < tb.size(); ++i) {
        for (auto symbol : alphabet) {
            if (i <= 0 || !++num_of_op || symbol == mask[i]) {
                tb[i][symbol] = ++num_of_op && symbol == mask[i] ? i + 1 : i;
            } else {
                tb[i][symbol] = tb[br[i - 1]][symbol];
            }
        }
    }
}

/// Конец ли.
/// \param symbol - символ.
/// \return Конец ли
bool Automaton::operator()(char symbol) {
    ++num_of_op;
    now_pos = tb[now_pos][symbol];
    return now_pos == final_pos;
}

/// Возвращает количество операций сравнения.
/// \return Количество операций.
size_t Automaton::getNumOfOp() const {
    return num_of_op;
}
