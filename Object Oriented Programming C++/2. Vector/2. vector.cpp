#include <iostream>

class Vector
{
    int size;
    int *arr;
public:
    Vector()
    {
        this->size=0;
        this->arr=NULL;
    }
    void push(int element)
    {
        this->arr = (int*)(realloc(this->arr, sizeof(int) * (size + 1)));
        this->arr[size++] = element;
    }
    int pop()
    {
        int x = this->arr[size-1];
        this->arr = (int*)realloc(this->arr, sizeof(int)*(--size));
        return x;
    }
    void printVector()
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout<<this->arr[i]<<std::endl;
        }
    }
};

int main()
{
    Vector v1;
    v1.push(1);
    v1.push(2);
    v1.push(3);
    v1.push(4);
    v1.push(5);

    v1.printVector();

    std::cout<<v1.pop();

    return 0;
}
