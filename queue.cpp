#include <iostream>
#include <cstdio>
 
using namespace std;
 
void Enqueue(char queue[], char element, int& rear, int arraySize) {
    if(rear == arraySize)            
        cout<<"OverFlow"<<endl;
    else {
        queue[rear] = element;    
        rear++;
    }
}
 
 
void Dequeue(char queue[], int& front, int rear) {
    if(front == rear)            
       	cout<<"UnderFlow"<<endl;
    else {
        queue[front] = 0;        
        front++;
    }
}
 
char Front(char queue[], int front) {
    return queue[front];
}
 
 
int main() {
    char queue[20] = {'a', 'b', 'c', 'd', 'e', 'f'};        
    int front = 0, rear = 6;                
    int arraySize = 20;               
    int N = 5;                    
    char ch;
    for(int i = 0;i < N;++i) {
        ch = Front(queue, front);
        Enqueue(queue, ch, rear, arraySize);
        Dequeue(queue, front, rear);
    }
    for(int i = front;i < rear;++i)
        cout<<queue[i]<<endl;
    return 0;
}
