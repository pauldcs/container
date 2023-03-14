/* reverse_iterator.hpp
 * By: pducos <pducos@student.42.fr>
 * Created: 02.02.2023
 */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{

template <typename Iter>
class reverse_iterator
{
	private:
		Iter _current;

	public:
	/*------------------------------------------------------------*/
	/*--- Member types                                         ---*/
	/*------------------------------------------------------------*/
		typedef Iter   iterator_type;

    	typedef typename iterator_traits<Iter>::iterator_category iterator_category;
    	typedef typename iterator_traits<Iter>::value_type        value_type;
    	typedef typename iterator_traits<Iter>::pointer           pointer;
    	typedef typename iterator_traits<Iter>::reference         reference;
    	typedef typename iterator_traits<Iter>::difference_type   difference_type;

	/*------------------------------------------------------------*/
	/*--- Member functions                                     ---*/
	/*------------------------------------------------------------*/

		/* Default constructor. The underlying iterator is value-initialized.
		 * Operations on the resulting iterator have defined behavior if and only
		 * if the corresponding operations on a value-initialized Iter also have
		 * defined behavior.
		 */
		reverse_iterator(void) : _current() { }

		/*  The underlying iterator is initialized with x */
		explicit reverse_iterator(iterator_type x) : _current(x) { }		

		/* The underlying iterator is initialized with that of other */
		template <class U>
		reverse_iterator(const reverse_iterator<U> &other) : _current(other.base()) { }

		/* destroys the iterator */
		virtual ~reverse_iterator(void) { };

		/* The underlying iterator is assigned the value of the underlying iterator of other,
		 * i.e. other.base()
		 */
		template< class U >
		reverse_iterator& operator=(const reverse_iterator<U>& other) {
			_current = other.base();
			return *this;
		}

		/* Returns the underlying base iterator.
		 * That is std::reverse_iterator(it).base() == it. */
		iterator_type base() const { return _current; }

		/* Equivalent to Iter tmp = current; return *--tmp; */
		reference operator*() const { Iter tmp = _current; return *--tmp; }

		/* Equivalent to return std::addressof(operator*()); */
		pointer operator->() const { return &**this; }

		/* Returns a reference to the element at specified relative location. */
		reference operator[]( difference_type n ) const { return *(*this + n); };

		/* Increments or decrements the iterator.
		 * Inverse operations are applied to the underlying operator because of
		 * the reverse order.
		 */
		reverse_iterator 	&operator++()                      { --_current; return *this; }
		reverse_iterator 	&operator--()                      { ++_current; return *this; }
		reverse_iterator 	operator++(int)                    { reverse_iterator tmp(*this); --_current; return tmp; }
		reverse_iterator 	operator--(int)                    { reverse_iterator tmp(*this); ++_current; return tmp; }
		reverse_iterator 	operator+(difference_type n) const { return reverse_iterator(_current - n); }
		reverse_iterator 	operator-(difference_type n) const { return reverse_iterator(_current + n); }
		reverse_iterator 	&operator+=(difference_type n)     { _current -= n; return *this; }
		reverse_iterator 	&operator-=(difference_type n)     { _current += n; return *this; }
};
	
/*------------------------------------------------------------*/
/*--- Non member functions                                 ---*/
/*------------------------------------------------------------*/

/* Compares the underlying iterators.
 * Inverse comparisons are applied in order to take into account
 * that the iterator order is reversed.
 */
template <class Iterator1, class Iterator2>
bool operator==(
	const ft::reverse_iterator<Iterator1> &lhs,
    const ft::reverse_iterator<Iterator2> &rhs
) { return lhs.base() == rhs.base(); }

template <class Iterator1, class Iterator2>
bool operator!=(
	const ft::reverse_iterator<Iterator1> &lhs,
    const ft::reverse_iterator<Iterator2> &rhs
) { return lhs.base() != rhs.base(); }

template <class Iterator1, class Iterator2>
bool operator<(
	const ft::reverse_iterator<Iterator1> &lhs,
    const ft::reverse_iterator<Iterator2> &rhs
){ return lhs.base() > rhs.base(); }

template <class Iterator1, class Iterator2>
bool operator<=(
	const ft::reverse_iterator<Iterator1> &lhs,
	const ft::reverse_iterator<Iterator2> &rhs
) { return lhs.base() >= rhs.base(); }

template <class Iterator1, class Iterator2>
bool operator>(
	const ft::reverse_iterator<Iterator1> &lhs,
    const ft::reverse_iterator<Iterator2> &rhs
) { return lhs.base() < rhs.base();  }

template <class Iterator1, class Iterator2>
bool operator>=(
	const ft::reverse_iterator<Iterator1> &lhs,
    const ft::reverse_iterator<Iterator2> &rhs
) { return lhs.base() <= rhs.base(); }

/* Returns the iterator it incremented by n. */
template <class Iter>
reverse_iterator<Iter> operator+(
	typename reverse_iterator<Iter>::difference_type n,
    const reverse_iterator<Iter> &it
) { return reverse_iterator<Iter>(it + n); }

/* Returns the distance between two iterator adaptors. */
template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
	const reverse_iterator<Iterator1>& lhs,
    const reverse_iterator<Iterator2>& rhs
) { return rhs.base() - lhs.base(); }

} /* namespace: ft */

#endif /* __REVERSE_ITERATOR_HPP__ */
