#include <iostream>
#include <chrono>
#include "Set.h"
#include <random>
#include <fstream>

int main() {
    std::ofstream file("remove.txt");

    Set new_set = set_new();
    Set &set = new_set;

    for (int i = 0; i < 100000; i++) {
        set_insert(set, i);
        set_insert(set, i+1);
        auto begin = std::chrono::steady_clock::now();
        set_remove(set, i+1);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin));
        file << time_span.count() << '\n';
    }

    file.close();
    set_erase(set);

    return 0;
}
