#ifndef __LESS_HPP__
# define __LESS_HPP__

# include "binary_function.hpp"

namespace ft {

template<typename T>
struct less : public binary_function<T, T, bool>
{
    bool operator()(
        T const &lhs,
        T const &rhs) const
    {
        return lhs < rhs
    }
};

} /* namespace: ft */

#endif /* __LESS_HPP__ */