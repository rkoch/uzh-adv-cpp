/*
 * main.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include <iostream>
#include <vector>

/*
 * Returns a function object that encapsulates member function f of type T. The member function returns a value of type S and, optionally,
 * can take one parameter of type A. The function object returned by this function expects a pointer to an object as its (first) argument for
 * operator(). A similar function, mem_fun_ref generates the same function but expecting a reference to an object as (first) argument instead.
 * Function objects are objects whose class defines member function operator(). This member function allows the object to be used with the same
 * syntax as a regular function call. Several standard algorithms and adaptors are designed to be used with function objects.
 */

struct B {
	virtual void print() = 0;
};

struct D1: public B {
	void print() {
		std::cout << "I'm a D1" << std::endl;
	}
};

struct D2: public B {
	virtual void print() {
		std::cout << "I'm a D2" << std::endl;
	}
};

int main(int argc, char **argv) {
	std::vector<B*> vec;

	vec.push_back(new D1);
	vec.push_back(new D2);
	vec.push_back(new D2);
	vec.push_back(new D1);

	for_each(vec.begin(), vec.end(), std::mem_fun(&B::print));

	return 0;
}
