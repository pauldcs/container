#ifndef __BINARY_FUNCTION_HPP__
# define __BINARY_FUNCTION_HPP__

namespace ft {

template<
    typename _Arg1,
    typename _Arg2,
    typename _Result
>
struct binary_function
{
    typedef _Arg1     first_argument_type; 
    typedef _Arg2     second_argument_type;
    typedef _Result   result_type;
};

} /* namespace: ft */

#endif /* __BINARY_FUNCTION_HPP__ */
