#include "SLList.hpp"
#include <string>
using namespace std;

int main(void){

    SLList<string> list;
    list.push_front("abc");
    list.push_front("def");
    list.push_front("123");
    list.push_front("wow");

    list.print();

    return 0;
}