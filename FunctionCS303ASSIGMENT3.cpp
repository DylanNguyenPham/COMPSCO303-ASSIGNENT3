#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Recursive Linear Search - Last Occurrence
int linear_search(vector<int>& items, int& target, size_t pos_first) {
	if (pos_first == items.size())
		return -1;

	int index_in_rest = linear_search(items, target, pos_first + 1);

	if (index_in_rest != -1)
		return index_in_rest;
	else if (target == items[pos_first])
		return pos_first;
	else
		return -1;
}

// Insertion Sort for std::list<int>
void insertion_sort(std::list<int>& num_list) {
	if (num_list.empty()) return;

	auto it = std::next(num_list.begin()); // Start from second element
	while (it != num_list.end()) {
		int key = *it;
		auto prev = std::prev(it);
		auto current = it;

		// Find the right position to insert key
		while (current != num_list.begin() && key < *prev) {
			--current;
			if (current != num_list.begin()) --prev;
		}

		// Only insert if not already in place
		auto next_it = std::next(it);
		if (current != it) {
			num_list.erase(it);
			num_list.insert(current, key);
		}

		it = next_it;
	}
}
void print_vector(const vector<int>& v) {
	for (int n : v)
		cout << n << " ";
	cout << endl;
}


void print_list(const list<int>& lst) {
	for (int n : lst)
		cout << n << " ";
	cout << endl;
}