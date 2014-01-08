/*
 * smart_pointer.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef _SMART_POINTER_H_
#define _SMART_POINTER_H_

struct RefCounter {
	int counter;
	RefCounter(): counter(0) {}
	void touch() {
		counter++;
	}
	void rm() {
		counter--;
	}
};

template<typename Object>
class smart_pointer {

public:
	smart_pointer();
	smart_pointer(Object *_ptr);
	smart_pointer(const smart_pointer<Object> &obj);
	~smart_pointer();

	Object& operator*();
	Object* operator->();
	smart_pointer<Object>& operator=(const smart_pointer<Object> &obj);

	// Proxy method to return the current ref counter (for debugging purposes)
	int ref_counter();

private:
	Object* ptr;
	RefCounter* ref_cnt;

};

#endif
