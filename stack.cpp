#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
    stack<int> mystack;
    int i;
    // push 
    for(i=0;i<=10;i++)
        mystack.push(i);
    // size
    printf("The size of the stack is %d.\n", mystack.size());
    // top & empty
    while(!mystack.empty())
    {
        printf("The top of the stack is %d.\n", mystack.pop());
        mystak.pop();
    }
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}


