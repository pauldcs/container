/* type_traits.hpp
 * By: pducos <pducos@student.42.fr>
 * Created: 03.02.2023
 */

#ifndef __TYPE_TRAITS_HPP__
# define __TYPE_TRAITS_HPP__

# include <stdint.h>
# include <vector>
namespace ft
{

/* This template is designed to provide compile-time constants as types.*/
template <class Tp, Tp v>
struct integral_constant
{
	static const Tp				value = v;
	typedef	Tp					value_type;
	typedef	integral_constant	type;

	/* Returns the value of the integral_constant */
	operator value_type() const { return value; }
};

template<bool B, class T = void>
struct enable_if { };

template<class T>
struct enable_if<true, T> { typedef T type; };

/* Instantiation of integral_constant to represent the bool value true. */
typedef integral_constant<bool, true>  true_type;
/* Instantiation of integral_constant to represent the bool value false. */
typedef integral_constant<bool, false> false_type;

/* Checks whether T is an integral type. */
template <class T> struct is_integral                   : public false_type { };
template <> struct is_integral <                  bool> : public  true_type { };
template <> struct is_integral <               int16_t> : public  true_type { };
template <> struct is_integral <               int32_t> : public  true_type { };
template <> struct is_integral <               wchar_t> : public  true_type { };
template <> struct is_integral <           signed char> : public  true_type { };
template <> struct is_integral <              long int> : public  true_type { };
template <> struct is_integral <         long long int> : public  true_type { };
template <> struct is_integral <         unsigned char> : public  true_type { };
template <> struct is_integral <    unsigned short int> : public  true_type { };
template <> struct is_integral <          unsigned int> : public  true_type { };
template <> struct is_integral <     unsigned long int> : public  true_type { };
template <> struct is_integral <unsigned long long int> : public  true_type { };

} /* namespace: ft */

#endif /* __TYPE_TRAITS_HPP__ */
