#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;


int main()
{

    Stack<int> s = Stack<int>();

    cout << s.empty() << endl; // should return 1
    cout << s.size() << endl; //should return 0
    s.push(1);
    s.push(2);
    cout << s.size() << endl; // should return 2
    int a = s.top();
    cout << a << endl; // 2
    s.pop();
    int b = s.top();
    cout << b << endl; // 1


    
    return 0;

}
