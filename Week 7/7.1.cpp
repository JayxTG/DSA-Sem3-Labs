#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numQueries;
    cin >> numQueries;

    vector<int> heap;

    for (int i = 0; i < numQueries; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            // Insertion operation
            int value;
            cin >> value;
            heap.push_back(value);
            push_heap(heap.begin(), heap.end(), greater<int>());
        } 
        else if (type == 2) {
            // Deletion operation
            int value;
            cin >> value;
            auto it = find(heap.begin(), heap.end(), value);
            if (it != heap.end()) {
                heap.erase(it);
                make_heap(heap.begin(), heap.end(), greater<int>());
            }
        } 
        else if (type == 3) {
            // Print minimum element
            if (!heap.empty()) {
                cout << heap.front() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
