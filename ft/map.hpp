/*---                                                            1049552192 560 map.hpp  ---*/
/*---                                                                                    ---*/
/*---                                                                                    ---*/
/*---                                           Created: Feb  5 11:39:20 2023 by pducos  ---*/
/*---                                           Updated: Feb  9 21:28:06 2023 by pducos  ---*/

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "pair.hpp"
# include "iterator_traits.hpp"
# include "equal.hpp"
# include "reverse_iterator.hpp"
# include "less.hpp"
# include <memory>
namespace ft {

template <
    class Key,
    class T,
    class Compare = less<Key>,
    class Allocator = std::allocator<pair<const Key, T> >
>
class map {

    public:

	/*------------------------------------------------------------*/
	/*--- Member types                                         ---*/
	/*------------------------------------------------------------*/

        typedef Key                                           key_type;
        typedef T                                             mapped_type;
        typedef pair<const Key, T>                            value_type;
        typedef Compare                                       key_compare;
        typedef Allocator                                     allocator_type;
        typedef typename Allocator::reference                 reference;
        typedef typename Allocator::const_reference           const_reference;
        typedef size_t                                        size_type;
        typedef typename Allocator::pointer                   pointer;
        typedef typename Allocator::const_pointer             const_pointer;
        //typedef typename iterator_traits<iterator>::difference_type  difference_type;
        //typedef implementation defined iterator; // See 23.1
        //typedef implementation defined const_iterator; // See 23.1
        //typedef ft::reverse_iterator<iterator>                reverse_iterator;
        //typedef ft::reverse_iterator<const_iterator>          const_reverse_iterator;  

    /*------------------------------------------------------------*/
	/*--- Construct/copy/destroy                               ---*/
	/*------------------------------------------------------------*/

        /* Constructs an empty container, with no elements. */
        explicit map(
            key_compare		const &comp = key_compare(),
            allocator_type	const &alloc = allocator_type());

        /* Constructs a container with as many elements as the range [first,last),
         * with each element constructed from its corresponding element in that range.
         */
        template <class InputIterator> 
        map(
            InputIterator	first,
            InputIterator	last,
            key_compare		const &comp = key_compare(),
            allocator_type	const &alloc = allocator_type());

        /* Constructs a container with a copy of each of the elements in x. */
        map(map const &x);

        /* This destroys all container elements, and deallocates all the storage
         * capacity allocated by the map container using its allocator.
         */
        ~map(void);

        /* Copies all the elements from x into the container,
         * changing its size accordingly.
         */
        map &operator=(map const &x);

	/*------------------------------------------------------------*/
	/*--- Iterators                                            ---*/
	/*------------------------------------------------------------*/

        /* Returns an iterator referring to the first element in the map container. */
        iterator		begin(void);
        const_iterator	begin(void) const;

        /* Returns an iterator referring to the past-the-end element in the map container. */
        iterator		end(void);
        const_iterator	end(void) const;

        /* Returns a reverse iterator pointing to the last element in the
         * container (i.e., its reverse beginning).
         */
        reverse_iterator		rbegin(void);
        const_reverse_iterator	rbegin(void) const;

        /* Returns a reverse iterator pointing to the theoretical element right
         * before the first element in the map container (which is considered its
         * reverse end).
         */
        reverse_iterator		rend(void);
        const_reverse_iterator	rend(void) const;

        /* Returns whether the map container is empty (i.e. whether its size is 0). */
        bool empty(void) const;

        /* Returns the number of elements in the map container. */
        size_type size(void) const;

        /* Returns the maximum number of elements that the map container can hold. */
        size_type max_size(void) const;

	/*------------------------------------------------------------*/
	/*--- Element access                                       ---*/
	/*------------------------------------------------------------*/

        /* If k matches the key of an element in the container,
         * the function returns a reference to its mapped value.
         */
        mapped_type &operator[](key_type const &k);

        /* Returns a reference to the mapped value of the element identified with key k. */
        mapped_type			&at(key_type const &k);
        mapped_type const	&at(key_type const &k) const;

	/*------------------------------------------------------------*/
	/*--- Modifiers                                            ---*/
	/*------------------------------------------------------------*/

        /* Extends the container by inserting new elements, effectively increasing
         * the container size by the number of elements inserted.
         */
        pair<iterator,bool>	insert(value_type const &val);
        iterator			insert(iterator position, value_type const &val);
        
		template <class InputIterator>
        void 				insert(InputIterator first, InputIterator last);

        /* Removes from the map container either a single element or
         * a range of elements ([first,last)).
         */
        void		erase(iterator position);
        size_type	erase(key_type const &k);
        void		erase(iterator first, iterator last);

        /* Exchanges the content of the container by the content of x, which is
         * another map of the same type. Sizes may differ.
         */
        void swap(map& x);

        /* Removes all elements from the map container (which are destroyed),
         * leaving the container with a size of 0.
         */
        void clear(void);

	/*------------------------------------------------------------*/
	/*--- Observers                                            ---*/
	/*------------------------------------------------------------*/

        /* Returns a copy of the comparison object used by the container
         * to compare keys.
         */
        key_compare key_comp(void) const;

        /* Returns a comparison object that can be used to compare two elements to
         * get whether the key of the first one goes before the second.
         */
        value_compare value_comp(void) const;

	/*------------------------------------------------------------*/
	/*--- Operations                                           ---*/
	/*------------------------------------------------------------*/

        /* Searches the container for an element with a key equivalent to k and
         * returns an iterator to it if found, otherwise it returns an
         * iterator to map::end.
         */
        iterator 		find(key_type const &k);
        const_iterator	find(key_type const &k) const;

        /* Searches the container for elements with a key equivalent to k
         * and returns the number of matches.
         */
        size_type count(key_type const &k) const;

        /* Returns an iterator pointing to the first element in the container whose
         * key is not considered to go before k (i.e., either it is equivalent or
         * goes after).
         */
        iterator		lower_bound(key_type const &k);
        const_iterator	lower_bound(key_type const &k) const;

        /* Returns an iterator pointing to the first element in the container
         * whose key is considered to go after k.
         */
        iterator		upper_bound(key_type const &k);
        const_iterator	upper_bound(key_type const &k) const;

        pair<const_iterator,const_iterator>	equal_range(key_type const &k) const;
        pair<iterator,iterator>				equal_range(key_type const &k);

	/*------------------------------------------------------------*/
	/*--- Allocator                                            ---*/
	/*------------------------------------------------------------*/

        allocator_type get_allocator(void) const;
};

} /* namespace: ft */

#endif /* __MAP_HPP__ */
