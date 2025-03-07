#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
#include <vector>
using namespace std;


int main()
{

    Heap<int> heap;
    // vector<int> v({4,5,7,3,9,8});
    // for (size_t i = 0; i < v.size(); i ++) {
    //     h.push(v[i]);
    // }
    heap.push(0);
	heap.push(10);
	heap.push(5);
    heap.print();
	cout << heap.top() << endl;
	heap.pop();
	// EXPECT_EQ(5, heap.top());
    cout << heap.top() << endl; // 5
	heap.pop();
	// EXPECT_EQ(10, heap.top()); // 10
    cout << heap.top() << endl;
    
    

    // for (size_t i = 0; i < v.size(); i ++) {
    //     h.pop();
    //     h.print();
    // }
    // h.pop();

    
    return 0;

}
