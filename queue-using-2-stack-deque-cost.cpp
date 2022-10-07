#include <iostream>
#include <stack>

using namespace std;
class Myqueue
{
    stack<int> s1, s2;

public:
    void enqueue(int);
    void Dequeue();
    void print();
};
void Myqueue::print()
{
    while (!s1.empty())
    {
        cout << s1.top() << "|";
        s1.pop();
    }
    cout << endl;
}
void Myqueue::enqueue(int ele)
{
    s1.push(ele);
}
void Myqueue::Dequeue()
{
    cout << "In Dequeue::" << s1.top() << endl;
    if (s1.empty())
    {
        cout << "Queue is empty...\n";
        return;
    }

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    Myqueue mq;
    mq.enqueue(11);
    mq.enqueue(12);
    mq.enqueue(13);
    mq.enqueue(14);
    cout << "After insertion..\n";
    // mq.print();

    mq.Dequeue();
    mq.Dequeue();
    cout << "After deletion..\n";
    mq.print();
    return 0;
}