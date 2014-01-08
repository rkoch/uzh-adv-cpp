/*
 * dumb_pointer.h
 *
 *  Created on: 08.01.2014
 *      Author: rko
 */

#ifndef _DUMB_POINTER_H_
#define _DUMB_POINTER_H_

template<typename Object>
class dumb_pointer {

public:
	dumb_pointer(Object *_ptr);
	~dumb_pointer();

	Object& operator*();
	Object* operator->();

private:
	Object* ptr;

};

#endif
