/*
 * File: stack.h
 * -------------
 * This file exports the Stack class, which implements a collection that
 * processes values in a last-in/first-out (LIFO) order.
 */

#ifndef _stack_h
#define _stack_h

#include "Vector.h"
#include <string>

/*
 * Class: Stack<std::string>
 * -----------------------
 * This class models a linear structure called a stack in which values are
 * added and removed only from one end.  This discipline gives rise to a
 * last-in/first-out behavior (LIFO) that is the defining feature of
 * stacks.  The fundamental stack operations are push (add to top) and pop
 * (remove from top).
 */

class Stack {

public:

/*
 * Constructor: Stack
 * Usage: Stack<ValueType> stack;
 * ------------------------------
 * Initializes a new empty stack.
 */

   Stack();

/*
 * Destructor: ~Stack
 * ------------------
 * Frees any heap storage associated with this stack.
 */

   virtual ~Stack();

/*
 * Method: size
 * Usage: int n = stack.size();
 * ----------------------------
 * Returns the number of values in this stack.
 */

   int size() const;

/*
 * Method: isEmpty
 * Usage: if (stack.isEmpty()) ...
 * -------------------------------
 * Returns true if this stack contains no elements.
 */

   bool isEmpty() const;

/*
 * Method: clear
 * Usage: stack.clear();
 * ---------------------
 * Removes all elements from this stack.
 */

   void clear();

/*
 * Method: push
 * Usage: stack.push(value);
 * -------------------------
 * Pushes the specified value onto this stack.
 */

   void push(std::string value);

/*
 * Method: pop
 * Usage: ValueType top = stack.pop();
 * -----------------------------------
 * Removes the top element from this stack and returns it.  This method
 * signals an error if called on an empty stack.
 */

   std::string pop();

/*
 * Method: peek
 * Usage: ValueType top = stack.peek();
 * ------------------------------------
 * Returns the value of top element from this stack, without removing it. 
 * This method signals an error if called on an empty stack.  For
 * compatibility with the STL classes, this method is also exported under
 * the name top, in which case it returns the value by reference.
 */

   std::string peek() const;
   const std::string & top();

/*
 * Method: toString
 * Usage: string str = stack.toString();
 * -------------------------------------
 * Converts the stack to a printable string representation.
 */

   std::string toString();

/* Private section */

private:
   Vector elements;

};

#endif
