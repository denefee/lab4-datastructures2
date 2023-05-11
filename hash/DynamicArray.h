#include "LinkedList.h"

struct DynamicArray {
	LinkedList** elements = nullptr;
	unsigned capacity = 0, size = 0;
};

DynamicArray new_array(unsigned capacity) {
	LinkedList** arr = new LinkedList*[capacity];
	for (unsigned i = 0; i < capacity; i++) {
		arr[i] = nullptr;
	}
	return DynamicArray{ arr, capacity, 0 };
}
DynamicArray& push_back(DynamicArray& da, int val);
void erase(DynamicArray& data) {
	delete data.elements;
	data.elements = nullptr;
	data.capacity = 0;
	data.size = 0;
}

DynamicArray& rehash(DynamicArray& da){
	auto temp_arr = new_array(da.capacity * 2);
	for (unsigned i = 0; i < da.capacity; i++) {
		if ((da.elements)[i] != nullptr) {
			auto cur = (da.elements)[i];
			while (cur != nullptr) {
				push_back(temp_arr, cur->data);
				cur = cur->link;
			}

		}
	}
	delete da.elements;
	da = { temp_arr.elements, temp_arr.capacity, temp_arr.size};
	return da;
}

int hash_function(int x, int size) {
	return x%size;
}

DynamicArray& push_back(DynamicArray& da, int val) {
	int hash_code = hash_function(val, da.capacity);
	if ((da.elements)[hash_code] == nullptr) {
		(da.elements)[hash_code] = push(nullptr, val);
		++da.size;
	}
	else {
		push((da.elements)[hash_code], val);
	}
	if (da.size >= 0.8 * da.capacity) rehash(da);
	return da;
}

DynamicArray& remove(DynamicArray& da, int val) {
	int hash_code = hash_function(val, da.capacity);
	if ((da.elements)[hash_code] == nullptr) {
		return da;
	}
	else {
		(da.elements)[hash_code] = remove_from_head((da.elements)[hash_code], val);
		if ((da.elements)[hash_code] == nullptr) --da.size;
	}
}