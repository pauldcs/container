/* iterator_traits.hpp
 * By: pducos <pducos@student.42.fr>
 * Created: 31.01.2023
 */

#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

# include <iterator>

namespace ft
{

/* Traits class defining properties of iterators. */
/* generic definition */
template <typename Iterator>
class iterator_traits
{
	public:
 		typedef typename Iterator::iterator_category	iterator_category;
 		typedef typename Iterator::value_type			value_type;
 		typedef typename Iterator::pointer				pointer;
 		typedef typename Iterator::reference			reference;
 		typedef typename Iterator::difference_type		difference_type;
};
/* T* specialization */
template <typename T>
class iterator_traits <T *>
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T *								pointer;
		typedef T &								reference;
		typedef typename std::ptrdiff_t						difference_type;
};
/* const T* specialization */
template <typename T>
class iterator_traits <T const *>
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef T const *						pointer;
		typedef T const &						reference;
		typedef typename std::ptrdiff_t					difference_type;
};

} /* namespace: ft */

#endif /* __ITERATOR_TRAITS_HPP__ */
