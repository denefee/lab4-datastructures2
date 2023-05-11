#include <iostream>
#include <chrono>
#include "DynamicArray.h"
#include <random>
#include <fstream>

bool search(DynamicArray& da, int val) {
	int hash_code = hash_function(val, da.capacity);
	if ((da.elements)[hash_code] == nullptr) {
		return false;
	}
	else {
		auto cur = (da.elements)[hash_code];
		while (cur != nullptr) {
			if (cur->data == val) return true;
			cur = cur->link;
		}
		return false;
	}
}

void print(DynamicArray& da) {
	for (int i = 0; i < da.capacity; ++i) {
		std::cout <<"hash: " <<  i << std::endl;
		if (da.elements[i] != nullptr) {
			auto cur = da.elements[i];
			while (cur != nullptr) {
				cout << cur->data << " ";
				cur = cur->link;
			}
		}
		std::cout << std::endl;
	}
}

void cheack_add() {
	std::ofstream fin1;
	std::ofstream fin2;
	fin1.open("n_data.txt");
	fin2.open("time_data.txt");
	auto data = new_array(50);
	int counter = 50;
	unsigned seed = 1001;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, 1000000);
	for (; counter < 10000000; counter += 50) {
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < 50; i++) {
			push_back(data, dstr(rng));
		}
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		fin1 << counter << '\n';
		std::cout << counter << '\n';
		fin2 << time_span.count() << '\n';
	}
}

// максимальная длина списка
void check_remove() {
	std::ofstream fin1;
	std::ofstream fin2;
	fin1.open("n_data.txt");
	fin2.open("time_data.txt");
	auto data = new_array(50);
	int counter = 50;
	unsigned seed = 573;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, 1000000);
	for (; counter < 10000000; counter += 50) {
		for (int i = 0; i < 100; i++) {
			push_back(data, dstr(rng));
		}
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < 50; i++) {
			remove(data, dstr(rng));
		}
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		fin1 << counter << '\n';
		std::cout << counter << '\n';
		fin2 << time_span.count() << '\n';
	}
}

void check_search() {
	std::ofstream fin1;
	std::ofstream fin2;
	fin1.open("n_data.txt");
	fin2.open("time_data.txt");
	auto data = new_array(50);
	int counter = 50;
	unsigned seed = 573;
	std::default_random_engine rng(seed);
	std::uniform_int_distribution <unsigned> dstr(0, 1000000);
	for (; counter < 10000000; counter += 50) {
		for (int i = 0; i < 50; i++) {
			push_back(data, dstr(rng));
		}
		auto temp = dstr(rng);
		auto begin = std::chrono::steady_clock::now();
		for (int i = 0; i < 100; ++i) search(data, temp);
		auto end = std::chrono::steady_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		fin1 << counter << '\n';
		std::cout << counter << '\n';
		fin2 << time_span.count() << '\n';
	}
}

bool test1() {
	auto arr = new_array(3);
	push_back(arr, 3);
	push_back(arr, 6);
	push_back(arr, 9);
	push_back(arr, 12);
	push_back(arr, 60);
	push_back(arr, 30);
	push_back(arr, 33);
	remove(arr, 12);
	return 0 == search(arr, 12);
}

bool test2() {
	auto arr = new_array(3);
	push_back(arr, 3);
	push_back(arr, 6);
	push_back(arr, 9);
	push_back(arr, 12);
	push_back(arr, 60);
	push_back(arr, 30);
	push_back(arr, 33);
	remove(arr, 9);
	return 0 == search(arr, 9);
}


bool test3() {
	auto arr = new_array(3);
	push_back(arr, 3);
	push_back(arr, 6);
	push_back(arr, 9);
	push_back(arr, 12);
	push_back(arr, 60);
	push_back(arr, 30);
	push_back(arr, 33);
	remove(arr, 9);
	return 1 == search(arr, 3);
}


bool test4() {
	auto arr = new_array(3);
	push_back(arr, 3);
	push_back(arr, 6);
	push_back(arr, 9);
	push_back(arr, 12);
	push_back(arr, 60);
	push_back(arr, 30);
	push_back(arr, 33);
	remove(arr, 45);
	return 0 == search(arr, 45);
}


int main() {
	//check_remove();
	cout << test1() << test2() << test3() << test4();
}
