#include "Stack.h"
#include <string>

/*
 * Stack class implementation
 * --------------------------
 * The Stack is internally managed using a Vector.  This layered design
 * makes the implementation extremely simple, to the point that most
 * methods can be implemented in as single line.
 */
 
 
 void erreur(std::string e) {
    std::cerr << e << std::endl;
}
Stack::Stack() {
   /* Empty */
}

Stack::~Stack() {
   /* Empty */
}

int Stack::size() const {
   return elements.size();
}

bool Stack::isEmpty() const {
   return size() == 0;
}

void Stack::push(std::string value) {
   elements.add(value);
}

std::string Stack::pop() {
   if (isEmpty()) 
   		erreur("pop: Attempting to pop an empty stack");
   std::string top = elements.get(elements.size() - 1);
   elements.remove(elements.size() - 1);
   return top;
}


std::string Stack::peek() const {
   if (isEmpty()) 
   		erreur("peek: Attempting to peek at an empty stack");
   return elements.get(elements.size() - 1);
}

const std::string & Stack::top() {
   if (isEmpty()) 
   		erreur("top: Attempting to read top of an empty stack");
   return elements.get(elements.size() - 1);
}

void Stack::clear() {
   elements.clear();
}

std::string Stack::toString() {
   std::ostringstream os;
    
    os << "{";
    int len = this->size();
    for (int i = 0; i < len; i++) {
        if (i > 0) os << ", ";
        os << elements.get(i);
    }
    os << "}";
    
    return os.str();
    }

