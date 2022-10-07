#include <iostream>
using namespace std;

class mystack
{
    int top1, top2, *arr, size;

public:
    mystack(int n)
    {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int);
    void push2(int);
    int pop1();
    int pop2();
    int peek1();
    int peek2();
    bool isEmpty1();
    bool isEmpty2();
};

bool mystack::isEmpty1()
{
    if (top1 == -1)
        return true;
    else
        return false;
}

bool mystack::isEmpty2()
{
    if (top2 == size)
        return true;
    else
        return false;
}
int mystack::pop1()
{
    int ret;
    if (top1 == -1)
    {
        cout << "underflow;;\n";
        return -1;
    }
    ret = arr[top1--];
    return ret;
}

int mystack::pop2()
{
    int ret;
    if (top2 == size)
    {
        cout << "underflow..\n";
        return -1;
    }
    ret = arr[top2++];
    return ret;
}

void mystack::push1(int ele)
{
    if (top1 >= top2)
        cout << "Overflow happening...\n";
    else
        arr[++top1] = ele;
}

void mystack::push2(int ele)
{
    if (top2 <= top1)
        cout << "Overflow happening...\n";
    else
        arr[--top2] = ele;
}

int mystack::peek1()
{
    if (isEmpty1())
    {
        cout << "Empty stack..\n";
        return -1;
    }
    else
    {
        return arr[top1];
    }
}
int mystack::peek2()
{
    if (isEmpty2())
    {
        cout << "Empty stack..\n";
        return -1;
    }
    else
    {
        return arr[top2];
    }
}

int main()
{
    mystack my(10);
    my.push1(1);
    my.push2(2);
    my.push1(3);
    my.push2(10);
    my.push2(9);
    my.push2(8);
    my.push2(7);
    cout << my.peek1() << endl;
    cout << my.peek2() << endl;
    return 0;
}