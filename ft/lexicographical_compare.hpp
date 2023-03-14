/* map.hpp
 * By: pducos <pducos@student.42.fr>
 * Created: 31.01.2022
 */

#ifndef __LEXICOGRAPHICAL_COMPARE_HPP__
# define __LEXICOGRAPHICAL_COMPARE_HPP__

namespace ft
{

/* Checks if the first range [first1, last1) is lexicographically
 * less than the second range [first2, last2).
 */

/* Elements are compared using operator < */
template< class InputIt1, class InputIt2 >
bool lexicographical_compare(
	InputIt1 first1, InputIt1 last1,
	InputIt2 first2, InputIt2 last2
) {
	for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
	{
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

/* Elements are compared using the given binary comparison function comp */
template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare(
	InputIt1 first1, InputIt1 last1,
	InputIt2 first2, InputIt2 last2, Compare comp
) {
	for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
	{
		if (comp(*first1, *first2)) return true;
		if (comp(*first2, *first1)) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

} /* namespace: ft */

#endif /* __LEXICOGRAPHICAL_COMPARE_HPP__ */