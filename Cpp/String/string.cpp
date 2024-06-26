#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdint> 
using namespace std;

class String{
    private:
        char* str_;
        uint32_t len;
    public:
        String(){
            str_ = nullptr;
            len = 0; 
        };
        // string()=delete;
        String(const char* p){
            if(!p) return;
            this->len = strlen(p);
            this->str_ = new char[this->len+1];
            strcpy(this->str_, p);
        }
        char* getval(void){
            return this->str_;
        }
        //copy constructor
        String(const String& other){
            if(!other.str_)return;
            this->len = other.len;
            this->str_ = new char[this->len+1];
            strcpy(this->str_,other.str_);
        }
        // string(char p[]):str_{p}{}
        // assignment operator overloading
        String& operator=(const String& other){
            if(this!=&other){
                this->len = other.len;
                if(!this->str_){
                    this->str_ = new char[this->len+1];
                    strcpy(this->str_, other.str_);
                }else{
                    delete[] this->str_;
                    this->str_ = new char[this->len+1];
                    strcpy(this->str_,other.str_);
                }
            }
            return *this;
            // this->str_ = other.str_;
        }
        uint32_t lenth(){
            return this->len;
        }
        String& operator=(const char* str){
            uint32_t len = strlen(str);
            this->len = len;
            if(!this->str_){
                this->str_ = new char[len+1];
            }else{
                delete[] this->str_;
                this->str_ = new char[len+1];
                strcpy(this->str_, str);
            }
            return *this;
        }
        ~String(){
            if(!str_)return;
            delete[] str_;
        }
        // move constructor
        String(String&& src){
            if(!src.str_)return;
            this->str_ = src.str_;
            src.str_ = nullptr;
        }
        // move assignment operator
        String& operator=(String&& src){
            if(this != &src){
                uint32_t len = src.len;
                // this->str_ = new char[len+1];
                this->str_ = src.str_;
                // strcpy(this->str_, src.str_);
                // delete[] src.str_;
                src.str_ = nullptr;
            }
            return *this;
        }
        // move assignment operator
        // String& operator=(const char&& s){
        //     return s;
        // }
        friend std::ostream& operator<<(std::ostream& out, const String& s_);
};
std::ostream& operator<<(std::ostream& out, const String& s_){
    out<<s_.str_<<"\n";
    return out;
}

int main(int argc, char* argv[], char** env){
    // printf("%s\n", "Hello Geeks");
    String s = "Hello";
    String s1 = "Bye";
    // it will call copy assignment constructor
    // String s2 = s1;
    String s2 = "Hello this is Me!!!!!";
    // std::cout<<s2.getval()<<"\n";
    std::cout<<s2;
    std::cout<<s2.lenth()<<'\n';
    s2 = "Hi How are you!!!";
    std::cout<<s2;
    // std::cout<<s2.getval()<<"\n";
    std::cout<<s.lenth()<<'\n';
    std::cout<<s1.lenth()<<'\n';
    std::cout<<s2.lenth()<<'\n';
    // it will call assignment operator
    s2 = s;
    std::cout<<s2.getval()<<"\n";
    // move constructor
    String s3(std::move(s1));
    std::cout<<"s3: "<<s3;
    s3 = std::move("Radheshyam kumar Sing");
    std::cout<<s3;
    return EXIT_SUCCESS;
}