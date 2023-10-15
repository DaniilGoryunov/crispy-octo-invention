#include "src/three.hpp"

int main() {
    Three s{'1', '0', '2', '0', '0'};
    Three t = {'1'};
    std::cout << "Summ: " << s + t << '\n';
    std::cout << "Diff: " << s - t << '\n';

    return 0;
}