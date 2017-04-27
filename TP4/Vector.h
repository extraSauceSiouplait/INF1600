/*
 * File: vector.h
 * --------------
 * This file exports the Vector class, which provides an efficient, safe,
 * convenient replacement for the array type in C++.
 */

#ifndef _vector_h
#define _vector_h

#include <iterator>
#include <iostream>
#include <sstream>
#include <string>

/*
 * Class: Vector<std::string>
 * ------------------------
 * This class stores an ordered list of values similar to an array.  It
 * supports traditional array selection using square brackets, but also
 * supports inserting and deleting elements.  It is similar in function to
 * the STL vector type, but is simpler both to use and to implement.
 */

class Vector {
    
public:
    
    Vector();
    
    /*
     * Constructor: Vector
     * Usage: Vector<std::string> vec;
     *        Vector<std::string> vec(n, value);
     * ---------------------------------------
     * Initializes a new vector.  The default constructor creates an empty
     * vector.  The second form creates an array with n elements, each of which
     * is initialized to value; if value is missing, the elements are
     * initialized to the default value for the type.
     */
    
    Vector(int n, std::string  value);
    
    /*
     * Destructor: ~Vector
     * -------------------
     * Frees any heap storage allocated by this vector.
     */
    
    virtual ~Vector();
    
    /*
     * Method: size
     * Usage: int nElems = vec.size();
     * -------------------------------
     * Returns the number of elements in this vector.
     */
    
    int size() const;
    
    /*
     * Method: isEmpty
     * Usage: if (vec.isEmpty()) ...
     * -----------------------------
     * Returns true if this vector contains no elements.
     */
    
    bool isEmpty() const;
    
    /*
     * Method: clear
     * Usage: vec.clear();
     * -------------------
     * Removes all elements from this vector.
     */
    
    void clear();
    
    /*
     * Method: get
     * Usage: std::string val = vec.get(index);
     * --------------------------------------
     * Returns the element at the specified index in this vector.  This method
     * signals an error if the index is not in the array range.
     */
    
    const std::string & get(int index) const;
    
    /*
     * Method: set
     * Usage: vec.set(index, value);
     * -----------------------------
     * Replaces the element at the specified index in this vector with a new
     * value.  The previous value at that index is overwritten.  This method
     * signals an error if the index is not in the array range.
     */
    
    bool set(int index, const std::string & value);
    
    /*
     * Method: insert
     * Usage: vec.insert(0, value);
     * ----------------------------
     * Inserts the element into this vector before the specified index.  All
     * subsequent elements are shifted one position to the right.  This method
     * signals an error if the index is outside the range from 0 up to and
     * including the length of the vector.
     */
    
    bool insert(int index, std::string value);
    
    /*
     * Method: remove
     * Usage: vec.remove(index);
     * -------------------------
     * Removes the element at the specified index from this vector.  All
     * subsequent elements are shifted one position to the left.  This method
     * signals an error if the index is outside the array range.
     */
    
    bool remove(int index);
    
    /*
     * Method: add
     * Usage: vec.add(value);
     * ----------------------
     * Adds a new value to the end of this vector.  To ensure compatibility
     * with the vector class in the Standard Template Library, this method is
     * also called push_back.
     */
    
    bool add(std::string value);
    bool push_back(std::string value);
    
    /*
     * Method: toString
     * Usage: string str = vec.toString();
     * -----------------------------------
     * Converts the vector to a printable string representation.
     */
    
    std::string toString();
   
private:
    
    /*
     * Implementation notes: Vector data structure
     * -------------------------------------------
     * The elements of the Vector are stored in a dynamic array of the
     * specified element type.  If the space in the array is ever exhausted,
     * the implementation doubles the array capacity.
     */
    
    /* Instance variables */
    
    std::string *elements;        /* A dynamic array of the elements   */
    int capacity;               /* The allocated size of the array   */
    int count;                  /* The number of elements in use     */
    
    /* Private methods */
    
    void expandCapacity();
    
    
};

#endif