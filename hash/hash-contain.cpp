#include <iostream>
#include <chrono>
#include "Set.h"
#include <random>
#include <fstream>

int main() {
    std::ofstream file("contain.txt");

    Set new_set = set_new();
    Set &set = new_set;

    int seed = 1003;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<int> dstr(0, 100000);

    for (int i = 0; i < 100000; i+=2) {
        set_insert(set, i);
        set_insert(set, i+1);
        auto begin = std::chrono::steady_clock::now();
        for (int j = 0; j < 25; j++) {
            set_contains(set, dstr(rnd));
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>((end - begin)/25);
        file << time_span.count() << '\n';
    }

    file.close();
    set_erase(set);

    return 0;
}