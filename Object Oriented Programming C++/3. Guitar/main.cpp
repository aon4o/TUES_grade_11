#include <iostream>
#include <stdlib.h>
using namespace std;

class guitar_string{
public:
    float width;
    guitar_string(float w){
        this->width = w;
    };
};

class guitar{
    int num_strings;
    guitar_string *strings;
public:
    guitar() {
        num_strings = 0;
        strings = NULL;
    };
    void add_string(guitar_string s){
        try {
            if(this->num_strings != 0) {
                if (s.width <= this->strings[this->num_strings - 1].width) {
                    throw "Every string added should be bigger than the previous one!";
                }
            }
            if (s.width < 0.2 or s.width > 5) {
                throw "The string width cannot be less than 0,2mm or more than 5mm!";
            }
            this->num_strings++;
            this->strings = (guitar_string*)realloc(this->strings, sizeof(guitar_string) * this->num_strings);
            this->strings[(this->num_strings-1)] = s;
        } catch (char const* e) {
            cout << e << endl;
        };
    };
    void print_guitar(){
        cout << "Number of strings : " << this->num_strings << endl;
        for (int i = 0; i < this->num_strings; ++i) {
            cout << "String No." << i+1 << " width = " << this->strings[i].width << endl;
        }
    };
};

int main() {
    guitar g1;
    guitar_string s1 = guitar_string(0.1);
    guitar_string s2 = {0.8};
    guitar_string s3 = {3};
    guitar_string s4 = {2};
    guitar_string s5 = {4};
    guitar_string s6 = {5.1};

    g1.add_string(s1);
    g1.add_string(s2);
    g1.add_string(s3);
    g1.add_string(s4);
    g1.add_string(s5);
    g1.add_string(s6);

    g1.print_guitar();
    return 0;
}
