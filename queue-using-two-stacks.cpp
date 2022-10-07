#include <iostream>
#include <stack>

using namespace std;

class myqueue
{
    stack<int> s1, s2;

public:
    void enqueue(int ele) /* Enqueu is costly operation here */
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(ele);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void dequeue()
    {
        if (s1.empty())
        {
            cout << "Empty...\n";
            return;
        }
        s1.pop();
    }
    void print()
    {
        while (!s1.empty())
        {
            cout << s1.top() << "|";
            s1.pop();
        }
    }
};
int main()
{
    myqueue mq;
    mq.enqueue(11);
    mq.enqueue(12);
    mq.enqueue(13);
    mq.enqueue(14);
    mq.enqueue(15);
    mq.dequeue();
    mq.dequeue();
    mq.print();
    return 0;
}