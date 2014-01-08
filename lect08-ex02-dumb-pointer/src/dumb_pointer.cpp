/*
 * dumb_pointer.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include "dumb_pointer.h"

template<typename Object>
dumb_pointer<Object>::dumb_pointer(Object *_ptr)
		: ptr(_ptr) {
}

template<typename Object>
dumb_pointer<Object>::~dumb_pointer() {
	delete ptr;
}

template<typename Object>
Object& dumb_pointer<Object>::operator*() {
	return *ptr;
}

template<typename Object>
Object* dumb_pointer<Object>::operator->() {
	return ptr;
}
