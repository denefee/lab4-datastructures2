struct LinkedList {
	int data;
	LinkedList* link;
};

LinkedList* push(LinkedList* current, int data) {
	if (nullptr == current) {
		return new LinkedList{ data, nullptr };
	}
	LinkedList* temp = current;
	while (temp->link != nullptr) {
		temp = temp->link;
	}
	LinkedList* new_link = new LinkedList{ data, nullptr };
	temp->link = new_link;
	return new_link;
}

LinkedList* remove_from_head(LinkedList* const head, int x) {
	auto cur = head;
	if (head->data == x) {
		delete head;
		return nullptr;
	}
	LinkedList* prev = nullptr;
	while (cur->data != x) {
		if (cur->link == nullptr) {
			return head;
		}
		prev = cur;
		cur = cur->link;
	}
	prev->link = cur->link;
	delete cur;
	return head;
}

void erase(LinkedList* const head) {
	LinkedList* current = head;
	while (current->link != nullptr) {
		LinkedList* temp_link = current->link;
		current->link = nullptr;
		delete current;
		current = temp_link;
	}
	delete current;
}