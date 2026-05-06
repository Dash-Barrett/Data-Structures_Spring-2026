#include "HashMap.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main(void){
    HashMap<int, char>* map = new HashMap<int, char>();
    
    int keys[] = {14, 1, 27, 22, 33, 34, 48, 41, 59, 5};
    char values[] = {76, 59, 72, 68, 55, 69, 54, 53, 74, 97};
    
    for(int i = 0; i < 10; i++){
        map->insert(keys[i], values[i]);
        if(i%2){
            map->remove(keys[i]);
        }
    }
    string code;
    for(int i = 0; i < 10; i++){
        try{
            code += map->search(keys[i]);
        }
        catch(exception& e){
            continue;
        }
    }
    
    cout << code << endl;
    delete map;
    return 0;
}