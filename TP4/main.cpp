
#include "Stack.h"
#include "Vector.h"

int main (int argc, char ** argv) {
    
    Vector v;
    
    v.add ("1");
    v.add ("2");
    v.add ("3");
    
    std::cout << v.toString() << std::endl;
    
    Stack s;
    s.push("4");
    s.push("5");
    s.push("6");
    s.push("7");
    s.push("8");
    s.push("9");
    s.push("10");
    s.pop();
    s.pop();
    std::cout << s.toString() << std::endl;
    return 0;
}