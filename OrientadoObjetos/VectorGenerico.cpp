#include <iostream>

template <typename T>
class Vector
{
private:
    int tam;
    int capacidad;
    T array[];

public:
    Vector(int tamInicial) : tam(0), capacidad(2 * tamInicial)
    {
        array[capacidad];
    }
    Vector()
    {
        Vector(50);
    }

    void addEnd(T elem)
    {
        if (tam + 1 == capacidad)
        {
            T nuevoVector[2 * capacidad];
            for (int i = 0; i < tam; i++)
            {
                nuevoVector[i] = array[i];
            }
            array[capacidad * 2];
            for (int i = 0; i < tam; i++)
            {
                array[i] = nuevoVector[i];
            }
            capacidad *= 2;
        }
        array[tam] = elem;
        tam++;
    }

    void printVector()
    {
        std::cout << '[';
        for (int i = 0; i < tam; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << ']' << std::endl;
    }
};

int main()
{
    Vector<int> *vec = new Vector<int>(0);
    vec->addEnd(7);
    vec->addEnd(9);
    vec->addEnd(10);
    vec->printVector();
}
