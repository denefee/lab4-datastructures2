#include <iostream>
#include <chrono>
#include "AVL-set.h"
#include <random>
#include <fstream>

int main() {
    std::ofstream file1("contain-rand.txt");
    std::ofstream file2("contain-sort.txt");

    Set new_set = set_new();
    Set &set = new_set;

    int seed = 1003;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<int> dstr(0, 100000);

    for (int i = 0; i < 100000; i++) {
        set_insert(set, i);

        auto begin1 = std::chrono::steady_clock::now();
        for (int j = 0; j < 25; j++) {
            set_contains(set, dstr(rnd));
        }
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 = std::chrono::duration_cast<std::chrono::nanoseconds>((end1 - begin1)/25);
        file1 << time_span1.count() << '\n';

        auto begin2 = std::chrono::steady_clock::now();
        for (int j = 0; j < 25; j++) {
            set_contains(set, i);
        }
        auto end2 = std::chrono::steady_clock::now();
        auto time_span2 = std::chrono::duration_cast<std::chrono::nanoseconds>((end2 - begin2)/25);
        file2 << time_span2.count() << '\n';
    }

    file1.close();
    file2.close();
    set_erase(set);

    return 0;
}