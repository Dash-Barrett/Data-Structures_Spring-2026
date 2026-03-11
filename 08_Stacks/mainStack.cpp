#include "Stack.hpp"
#include "Stack.cpp"
using namespace StackArray;

int main(void){
    Stack<char> stack;

    int i = 0;
    while(i < 26){
        stack.push(i + 'A');
        i++;
        cout << "Current Top: " << stack.top() << endl;
    }
    stack.print();

    while(!stack.empty()){
        cout << stack.pop() << endl;
    }

    return 0;
}