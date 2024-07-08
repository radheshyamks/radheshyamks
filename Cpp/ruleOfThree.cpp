#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cmath>
#include <cstring>

using namespace std;

class ruleOfThree{
    private:
        int* p_;
    public:
        explicit ruleOfThree(int*p=nullptr):p_(p){
            std::cout<<"Constructor\n";
        }
        // I. Destructor
        virtual ~ruleOfThree(){
            std::cout<<"Destructor\n";
            if(this->p_!=nullptr){
                std::cout<<"deallocated the memory\n";
                delete[] p_;
            }
        }
        // II. Copy constructor
        ruleOfThree(ruleOfThree& obj){
            std::cout<<"Copy Constructor\n";
            if(this != &obj){
                if(this->p_!=nullptr && obj.p_!=nullptr){
                    this->p_ = new int;
                    *this->p_ = *obj.p_;
                }
            }
        }
        // III. copy assignment operator;
        ruleOfThree& operator=(const ruleOfThree& obj){
            if(this != &obj){
                if(this->p_!=nullptr && obj.p_!=nullptr){
                    *this->p_ = *obj.p_;
                }
                if(this->p_==nullptr && obj.p_!=nullptr){
                    this->p_ = new int;
                    *this->p_ = *obj.p_;
                }
            }            
        }
        int get_val(){
            return *this->p_;
        }
};

int main(int argc,char*argv[], char** env){
    int* p = new int(20);
    ruleOfThree obj1(p);
    ruleOfThree obj2(obj1);
    std::cout<<obj1.get_val()<<"\n";
    std::cout<<obj2.get_val()<<"\n";
    return 0;
}