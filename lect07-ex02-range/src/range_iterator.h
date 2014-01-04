/*
 * range_iterator.h
 *
 *  Created on: 04.01.2014
 *      Author: rko
 */

#ifndef RANGE_ITERATOR_H_
#define RANGE_ITERATOR_H_

#include <exception>
#include <stdexcept>
#include <iterator>

template<typename T>
class range_iterator {

	typedef typename std::iterator_traits<T>::value_type value_type;
	typedef typename std::iterator_traits<T>::pointer pointer;
	typedef typename std::iterator_traits<T>::reference reference;

public:
	range_iterator(T b, T e)
			: begin(b), end(e), cur_pos(b) {
	}

	range_iterator(const range_iterator& org)
			: begin(org.begin), end(org.end), cur_pos(org.cur_pos) {

	}

	range_iterator& operator++() {
		if (cur_pos == end) {
			throw std::out_of_range("Iterator overflow");
		}
		cur_pos++;

		return *this;
	}

	range_iterator operator++(int) {
		range_iterator tmp(*this);
		operator++();
		return tmp;
	}

	range_iterator& operator--() {
		if (cur_pos == begin) {
			throw std::out_of_range("Iterator underflow");
		}
		cur_pos--;

		return *this;
	}

	range_iterator operator--(int) {
		range_iterator tmp(*this);
		operator--();
		return tmp;
	}

	value_type operator*() {
		return *cur_pos;
	}

	pointer operator->() {
		return &*cur_pos;
	}

	bool operator==(range_iterator<T>& itr) {
		return (begin == itr.begin) && (end == itr.end) && (cur_pos == itr.cur_pos);
	}

	bool operator!=(range_iterator<T>& itr) {
		return !operator==(itr);
	}

private:

	const T begin, end;
	T cur_pos;

};

#endif /* RANGE_ITERATOR_H_ */
