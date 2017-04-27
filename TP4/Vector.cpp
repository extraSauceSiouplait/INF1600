
#include "Vector.h"

/* Implementation section */

void error(std::string e) {
    std::cerr << e << std::endl;
}

/*
 * Implementation notes: Vector constructor and destructor
 * -------------------------------------------------------
 * The constructor allocates storage for the dynamic array and initializes
 * the other fields of the object.  The destructor frees the memory used
 * for the array.
*/

Vector::Vector() {
    count = capacity = 0;
    elements = NULL;
}

Vector::Vector(int n, std::string value) {
    count = capacity = n;
    elements = (n == 0) ? NULL : new std::string[n];
    for (int i = 0; i < n; i++) {
        elements[i] = value;
    }
}

Vector::~Vector() {
    if (elements != NULL) delete[] elements;
}

/*
 * Implementation notes: Vector methods
 * ------------------------------------
 * The basic Vector methods are straightforward and should require no
 * detailed documentation.
 */

int Vector::size() const {
    return count;
}

bool Vector::isEmpty() const {
    return count == 0;
}

void Vector::clear() {
    if (elements != NULL) delete[] elements;
    count = capacity = 0;
    elements = NULL;
}

const std::string & Vector::get(int index) const {
    if (index < 0 || index >= count){
        error("get: index out of range");
    }
    return elements[index];
}

bool Vector::set(int index, const std::string & value) {
    if (index < 0 || index >= count) {
        error("set: index out of range");
        return false;
    }
    elements[index] = value;
    return true;
}

/*
 * Implementation notes: insert, remove, add
 * -----------------------------------------
 * These methods must shift the existing elements in the array to make room
 * for a new element or to close up the space left by a deleted one.
 */

bool Vector::insert(int index, std::string value) {
    if (count == capacity) expandCapacity();
    if (index < 0 || index > count) {
        error("insert: index out of range");
        return false;
    }
    for (int i = count; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    count++;
    return true;
}

bool Vector::remove(int index) {
    if (index < 0 || index >= count){
        error("remove: index out of range");
        return false;
    }
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    count--;
    return true;
}

bool Vector::add(std::string value) {
    return insert(count, value);
}

bool Vector::push_back(std::string value) {
    return insert(count, value);
}

std::string Vector::toString() {
    std::ostringstream os;
    
    os << "{";
    int len = this->size();
    for (int i = 0; i < len; i++) {
        if (i > 0) os << ", ";
        os << this->get(i);
    }
    os << "}";
    
    return os.str();
}


/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This function doubles the array capacity, copies the old elements into
 * the new array, and then frees the old one.
 */

void Vector::expandCapacity() {
    capacity = std::max(1, capacity * 2);
    std::string *array = new std::string[capacity];
    for (int i = 0; i < count; i++) {
        array[i] = elements[i];
    }
    if (elements != NULL) delete[] elements;
    elements = array;
}
