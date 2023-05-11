#include <iostream>
#include "set.h"
#include <random>

bool test1(Set &test_set) {
    int seed = 1001;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<int> dstr(1, 1000);
    int a[100];
    for (int i = 0; i < 10; i++) {
        a[i] = dstr(rnd);
        set_insert(test_set, a[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (!set_contains(test_set, a[i])) return false;
        if (set_contains(test_set, -a[i])) return false;
    }
    return true;
}

bool test2(Set &test_set) {
    int seed = 1001;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<int> dstr(1, 1000);
    int a[100];
    for (int i = 0; i < 10; i++) {
        a[i] = dstr(rnd);
        set_insert(test_set, a[i]);
    }

    for (int i = 0; i < 5; i++) {
        set_remove(test_set, a[i]);
        set_remove(test_set, -a[i]);
        if (set_contains(test_set, a[i])) return false;
        if (set_contains(test_set,-a[i])) return false;
    }

    for (int i = 5; i < 10; i++) {
        if (!set_contains(test_set, a[i])) return false;
    }

    return true;

}


int main() {
    Set set = set_new();
    Set &test_set = set;

    // проверка пустоты пустого множества
    if (set_is_empty(test_set)) std::cout << "1: CORRECT" << std::endl;
    else std::cout << "1: FAILED" << std::endl;

    // работает ли вставка и поиск
    if (test1(test_set)) std::cout << "2: CORRECT" << std::endl;
    else std::cout << "2: FAILED" << std::endl;

    // проверка непустоты непустого множества
    if (!set_is_empty(test_set)) std::cout << "3: CORRECT" << std::endl;
    else std::cout << "3: FAILED" << std::endl;

    // проверка выбора элемента
    if (set_contains(test_set, set_example(test_set))) std::cout << "4: CORRECT" << std::endl;
    else std::cout << "4: FAILED" << std::endl;

    // проверка пустоты очищенного множества
    set_erase(test_set);     
    if (set_is_empty(test_set)) std::cout << "5: CORRECT" << std::endl;
    else std::cout << "5: FAILED" << std::endl;

    // проверка удаления элементов
    if (test2(test_set)) std::cout << "6: CORRECT" << std::endl;
    else std::cout << "6: FAILED" << std::endl;

    return 0;
}