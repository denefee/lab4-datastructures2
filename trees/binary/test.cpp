#include <iostream>
#include <random>

int main() {
    int seed = 1003;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<int> dstr(1, 1000000);

    for (int i = 0; i < 3; i++) {
        std::cout << dstr(rnd);
    }

        
    return 0;
}