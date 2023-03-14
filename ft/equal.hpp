/* equal.hpp
 * By: pducos <pducos@student.42.fr>
 * Created: 03.02.2023
 */

#ifndef __EQUAL_HPP__
# define __EQUAL_HPP__

#include <algorithm>

namespace ft 
{

/* Returns true if the range [first1, last1] is equal to the range
 * [first2, first2 + (last1 - first1)), and false otherwise.
 * The elements are compared using operator== (or pred).
 */
template <class InputIt1, class InputIt2>
bool equal(
	InputIt1 first1,
	InputIt1 last1,
    InputIt2 first2
) {
	while (first1!=last1) {
		if (!(*first1 == *first2)) return false;
		++first1; ++first2;
	}
	return true;
}
/* Version 2 */
template <class InputIt1,
         class InputIt2,
         class BinaryPredicate>
bool equal(
	InputIt1 first1,
    InputIt1 last1,
    InputIt2 first2,
    BinaryPredicate p
) {
	while (first1!=last1) {
		if (!p(*first1,*first2)) return false;
		++first1; ++first2;
	}
	return true;
}

} /* namespace: ft */

#endif /* __EQUAL_HPP__ */
