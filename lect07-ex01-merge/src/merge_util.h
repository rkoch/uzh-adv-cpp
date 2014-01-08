/*
 * merge_util.h
 *
 *  Created on: 04.01.2014
 *      Author: rko
 */

#ifndef MERGE_UTIL_H_
#define MERGE_UTIL_H_

namespace nomnom {

	template <typename InputItr1, typename InputItr2, typename OutputItr>
	OutputItr merge(InputItr1 first_begin, InputItr1 first_end, InputItr2 second_begin, InputItr2 second_end, OutputItr target_begin) {
		for (; first_begin != first_end; ++target_begin) {
			if (second_begin == second_end) {
				return std::copy(first_begin, first_end, target_begin);
			}
			if (*second_begin < *first_begin) {
				*target_begin = *second_begin++;
			} else {
				*target_begin = *first_begin++;
			}
		}

		return std::copy(second_begin, second_end, target_begin);
	}

}

#endif /* MERGE_UTIL_H_ */
