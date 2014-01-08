/*
 * smart_pointer.cpp
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#include "smart_pointer.h"

template<typename Object>
smart_pointer<Object>::smart_pointer()
		: ptr(0), ref_cnt(new RefCounter()) {
}

template<typename Object>
smart_pointer<Object>::smart_pointer(Object *_ptr)
		: ptr(_ptr), ref_cnt(new RefCounter()) {
	ref_cnt->touch();
}

template<typename Object>
smart_pointer<Object>::smart_pointer(const smart_pointer<Object> &obj)
		: ptr(obj.ptr), ref_cnt(obj.ref_cnt) {
	ref_cnt->touch();
}

template<typename Object>
smart_pointer<Object>::~smart_pointer() {
	ref_cnt->rm();

	if (ref_cnt->counter <= 0) {
		delete ref_cnt;
		delete ptr;
	}
}

template<typename Object>
Object& smart_pointer<Object>::operator*() {
	return *ptr;
}

template<typename Object>
Object* smart_pointer<Object>::operator->() {
	return ptr;
}

template<typename Object>
smart_pointer<Object>& smart_pointer<Object>::operator=(const smart_pointer<Object> &obj) {
	if (this != &obj) {
		// remove old ref
		ref_cnt->rm();
		if (ref_cnt->counter <= 0) {
			delete ref_cnt;
			delete ptr;
		}

		// add new ref
		ptr = obj.ptr;
		ref_cnt = obj.ref_cnt;
		ref_cnt->touch();
	}

	return *this;
}

// Debugging purposes
template<typename Object>
int smart_pointer<Object>::ref_counter() {
	return ref_cnt->counter;
}
