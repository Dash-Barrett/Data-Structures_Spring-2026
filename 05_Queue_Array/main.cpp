#include "QueueArray.hpp"
#include "QueueArray.cpp"

int main(void){
    QueueDLL<int, 10> q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    q.print();

    while(!q.empty()){
        cout << q.dequeue() << endl;
    }

    try{
        q.dequeue();
    }
    catch(out_of_range ex){
        cout << ex.what() << endl;
    }

    return 0;
}