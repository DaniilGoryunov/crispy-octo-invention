#include "solve.hpp"

int number_vowels(std::string & s) {
    int num = 0;
    for (char c : s) {
        bool is_vowel = false;
        for (char v : vowels) {
            if (c == v) {
                num++;
                break;
            }
        }
    }
    return num;
}
