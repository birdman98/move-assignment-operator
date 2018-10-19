#include <iostream>
#include <utility>

class DynamicArray {

    int size;
    int element;
    int* arrayPtr;

public:

    DynamicArray(const int &size_, const int &element_) :
            size(size_),
            element(element_){

        arrayPtr=new int[size];

        for(int i=0; i<size;++i){

            arrayPtr[i]=element;
        }
    }

    void getInfo(){

        std::cout<<this->element<<"\n";
        std::cout<<this->size<<"\n";
        std::cout<<this->arrayPtr<<"\n";
    }

    ~DynamicArray(){

        delete[] arrayPtr;
    }

    DynamicArray& operator=(DynamicArray &&objectToMove){

        int temp=this->size;
        this->size=objectToMove.size;
        objectToMove.size=temp;

        temp=this->element;
        this->element=objectToMove.element;
        objectToMove.element=temp;

        int* tempPtr=this->arrayPtr;
        this->arrayPtr=objectToMove.arrayPtr;
        objectToMove.arrayPtr=tempPtr;

        return *this;

    }
};



int main() {

    DynamicArray array_1(5, 69);
    DynamicArray array_2(4, 70);


    array_1.getInfo();
    std::cout<<"\n\n";
    array_2.getInfo();

    array_1 = std::move(array_2);

    array_1.getInfo();
    std::cout<<"\n\n";
    array_2.getInfo();


    return 0;
}