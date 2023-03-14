/* pair.hpp
 * By: pducos <pducos@student.42.fr>
 * Created: 03.02.2023
 */

#ifndef __PAIR_HPP__
# define __PAIR_HPP__

namespace ft 
{

/* std::pair is a class template that provides a way to store two
 * heterogeneous objects as a single unit. A pair is a specific case of
 * a std::tuple with two elements.
 */
template <typename T1, typename T2>
struct pair
{
	/*------------------------------------------------------------*/
	/*--- Member types                                         ---*/
	/*------------------------------------------------------------*/

	typedef T1     first_type;
	typedef T2     second_type;

	/*------------------------------------------------------------*/
	/*--- Member objects                                       ---*/
	/*------------------------------------------------------------*/

	T1     first;
	T2     second;

	/*------------------------------------------------------------*/
	/*--- Member functions                                     ---*/
	/*------------------------------------------------------------*/

	/* Default constructor. Value-initializes both elements of the pair,
	 * first and second. */
	pair()
		: first()
		, second()
	{ }

	/* Initializes first with x and second with y. */
	pair(const T1 &x, const T2 &y)
		: first(x)
		, second(y)
	{ }

	/* Initializes first with p.first and second with p.second. */
	template <class U1, class U2>
	pair(const pair<U1, U2> &p)
		: first(p.first)
		, second(p.second)
	{ }

	/* Copy assignment operator. Replaces the contents with a copy of
	* the contents of other. */
	pair& operator=(const pair &other)
	{
		if (this != &other) {
			first = other.first;
			second = other.second;
		}
		return *this;
	}
};

/*------------------------------------------------------------*/
/*--- Non member functions                                 ---*/
/*------------------------------------------------------------*/

/* Creates a std::pair object, deducing the target type from the types of
 * arguments. */
template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u)
{ return pair<T1, T2>(t, u); }

template <class T1, class T2>
bool operator==(
	const ft::pair<T1, T2> &lhs,
	const ft::pair<T1, T2> &rhs)
{
	return lhs.first == rhs.first
		&& lhs.second == rhs.second;
} 

template <class T1, class T2>
bool operator!=(
	const ft::pair<T1, T2> &lhs,
	const ft::pair<T1, T2> &rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<(
	const ft::pair<T1, T2> &lhs,
	const ft::pair<T1, T2> &rhs)
{
	return lhs.first < rhs.first
        || (!(rhs.first < lhs.first)
			&& lhs.second < rhs.second); 
}

template <class T1, class T2>
bool operator<=(
	const ft::pair<T1, T2> &lhs,
	const ft::pair<T1, T2> &rhs)
{ return !(rhs < lhs); }

template< class T1, class T2 >
bool operator>(
	const ft::pair<T1, T2> &lhs,
	const ft::pair<T1, T2> &rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator>=(
	const ft::pair<T1, T2> &lhs,
	const ft::pair<T1, T2> &rhs)
{ return !(lhs < rhs); }

} /* namespace: ft */

#endif /* __PAIR_HPP__ */
