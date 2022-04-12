#include <iostream>
using namespace std;
int top = -1;
 
bool IsFull(int capacity){
    if(top >= capacity - 1){
        return true;
    }else{
        return false;
    }
}
bool IsEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
 
void Push(int stack[], int value, int capacity){
    if(IsFull(capacity) == true){
        cout<<"ngan da day!";
    }else{
        ++top;
        stack[top] = value;
    }
}
 
void Pop(){
    if(IsEmpty() == true){
        cout<<"ngan con trong!";
    }else{
        --top;
    }
}
 
 
int Top(int stack[]){
    return stack[top];
}
 
int Size(){
    return top + 1;
}
 
int main(){
    int capacity = 4; 
    int top = 6; 
    int stack[capacity];
    Push(stack, 3, capacity); 
   	cout<<"kich thuoc ngan xep hien tai la:"<< Size()<<endl;;
    Push(stack, 2, capacity);
    Push(stack, 9, capacity);
    cout<<"kich thuoc ngan xep hien tai la:"<< Size()<<endl;;
    Push(stack, 5, capacity); 
    cout<<"phan tu tren cung la:"<< Top(stack)<<endl;
    for(int i = 0 ; i < 3;i++)
        Pop();
    cout<<"kich thuoc ngan xep hien tai la:"<< Size()<<endl;
    Pop();  
}
