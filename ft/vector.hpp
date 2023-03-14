/*---                                                    2799873660 12730 ft/vector.hpp  ---*/
/*---                                                                                    ---*/
/*---                                                                                    ---*/
/*---                                           Created: Feb 16 23:24:42 2023 by pducos  ---*/
/*---                                           Updated: Feb 17 00:24:33 2023 by pducos  ---*/

#ifndef __FT_VECTOR_HPP__
# define __FT_VECTOR_HPP__

# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "reverse_iterator.hpp"
# include "equal.hpp"
# include "type_traits.hpp"
# include <memory>
# include <limits>
# include <assert.h>

# include <iostream>

namespace ft
{

template <typename T, typename Allocator = std::allocator<T> >
class vector
{
    public:
	/*------------------------------------------------------------*/
	/*--- Member types                                         ---*/
	/*------------------------------------------------------------*/

		typedef T											value_type;
    	typedef Allocator									allocator_type;
        typedef typename allocator_type::const_pointer		const_pointer;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_reference	const_reference;
        typedef typename allocator_type::reference			reference;
        typedef value_type const*							const_iterator;
        typedef value_type *								iterator;
        typedef reverse_iterator<const_iterator> 			const_reverse_iterator;
        typedef reverse_iterator<iterator> 					reverse_iterator;
        typedef typename iterator_traits<iterator>::difference_type	difference_type;
	    typedef size_t 										size_type;
	
	/*------------------------------------------------------------*/
	/*--- Private members                                      ---*/
	/*------------------------------------------------------------*/

	private:
		Allocator 	_allocator;
    	pointer 	_begin;
    	pointer 	_end;
    	size_type	_capacity;	

	/*------------------------------------------------------------*/
	/*--- Construct/copy/destroy                               ---*/
	/*------------------------------------------------------------*/
	
	public:
		/* Constructs an empty container, with no elements. */
		vector()
			: _allocator()
			, _begin(0)
			, _end(0)
			, _capacity(0)
		{ }

		explicit vector(Allocator const &alloc)
			: _allocator(alloc)
			, _begin(0)
			, _end(0)
			, _capacity(0)
		{ }

     

		/* Constructs a container with n elements.
		 * Each element is a copy of value.
		 */
		explicit vector(
			size_type n,
			value_type const &value,
			Allocator const &alloc = Allocator())
			: _allocator(alloc)
			, _begin(0)
			, _end(0)
			, _capacity(0)
		{ 
			while(n--)
				push_back(value);
		}

		explicit vector(size_type n) 
			: _allocator()
			, _begin(0)
			, _end(0)
			, _capacity(0)
    	{
			while(n--)
				push_back(value_type());
		}
     
	
		/* Constructs a container with as many elements as the
		 * range [first,last), with each element constructed
		 * from its corresponding element in that range,
		 * in the same order.
		 */
		template <class InputIterator>
		vector(
			InputIterator first,
			InputIterator last,
			Allocator const &alloc = Allocator(),
			typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = 0)
			: _allocator(alloc)
			, _begin(0)
			, _end(0)
			, _capacity(0)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		/* Constructs a container with a copy of each of the
		 * elements in x, in the same order.
		 */
		vector(vector const &x)
			: _allocator(x._allocator)
			, _begin(0)
			, _end(0)
			, _capacity(0)
		{
			value_type const *it = x.begin();
			
			reserve(x.size());
			while (it != x.end())
				push_back(*it++);
		}

		/* destructor */
		~vector()
		{
			clear();
			if (_capacity) {
				_allocator.deallocate(_begin, _capacity);
				_begin = 0;
				_end = 0;
				_capacity = 0;
			}
		}

		/* Assigns new contents to the container,
		 * replacing its current contents, and modifying
		 * its size accordingly.
		 */
		vector &operator=(vector const &x)
		{
			if (this != &x)
				assign(x.begin(), x.end());
			return *this;
		}

		/* the new contents are elements constructed from
		 * each of the elements in the range between first
		 * and last, in the same order.
		 */
		template <class InputIterator>
		void assign(
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			clear();
			while (first != last)
				push_back(*first++);
		}

		/* the new contents are n elements, each initialized to
		 * a copy of val.
		 */
		void assign(size_type n, value_type const &u)
		{
			clear();
        	resize(n, u);
		}

		/* Returns a copy of the allocator object associated with
		 * the vector.
		 */
		allocator_type get_allocator() const { return _allocator; }

	/*------------------------------------------------------------*/
	/*--- Iterators                                            ---*/
	/*------------------------------------------------------------*/

		/* Returns an iterator pointing to the first element in the
		 * vector.
		 */
		iterator 		begin() 		{ return _begin; }
		const_iterator 	begin() const 	{ return _begin; }

		/* Returns an iterator referring to the past-the-end element
		 * in the vector container.
		 */
		iterator 		end()			{ return _end; }
		const_iterator 	end() const 	{ return _end; }

		/* Returns a reverse iterator pointing to the last element
		 * in the vector (i.e., its reverse beginning).
		 */
		reverse_iterator rbegin()             { return reverse_iterator(end());       }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		/* Returns a reverse iterator pointing to the theoretical
		 * element preceding the first element in the vector
		 * (which is considered its reverse end).
		 */
		reverse_iterator rend()             { return reverse_iterator(begin());       }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	/*------------------------------------------------------------*/
	/*--- Capacity                                             ---*/
	/*------------------------------------------------------------*/
	
		size_type size() const 		{ return static_cast<size_type>(_end - _begin); }
		size_type capacity() const 	{ return _capacity; }

		/* Returns the maximum number of elements that the vector can hold. */
		size_type max_size() const { return allocator_type().max_size(); }

		/* Resizes the container so that it contains n elements. */
		void resize(
			size_type n,
			value_type elem = value_type())
		{
			while (size() > n)
				pop_back();
			while (size() < n)
				push_back(elem);
		}

		bool empty() const { return size() == 0; }

		/* Requests that the vector capacity be at least enough to
		 * contain n elements.
		 */
		void reserve(size_type n)
		{
			assert(n < max_size());

			if (n <= _capacity)
				return ;

			size_type 	len = size();
			pointer  	ptr = _allocator.allocate(n);
			
			if (_capacity)
			{
				size_type i = _capacity;
				while (i--)
				{
					_allocator.construct(ptr + i, *(_begin + i));		
					_allocator.destroy(ptr + i);
				} 	
				_allocator.deallocate(_begin, _capacity);
			}
			_capacity = n;
			_begin = ptr;
			_end = ptr + len;
		}

	/*------------------------------------------------------------*/
	/*--- Element access                                       ---*/
	/*------------------------------------------------------------*/

		reference 		operator[](size_type n) 		{ return _begin[n]; }
		const_reference operator[](size_type n) const 	{ return _begin[n]; }

		/* Returns a reference to the element at position n in the vector. */
		const_reference at(size_type n) const
		{
			if (n >= size())
        	    throw std::out_of_range("index out of range");
        	return _begin[n];
		}

		reference 		at(size_type n)
		{
			if (n >= size())
        	    throw std::out_of_range("index out of range");
        	return _begin[n];
		}

		/* Returns a reference to the first element in the vector. */
		reference 		front() 		{ assert(!empty()); return *_begin; }
		const_reference front() const 	{ assert(!empty()); return *_begin; }

		/* Returns a reference to the last element in the vector. */
		reference 		back()			{ assert(!empty()); return *(_end - 1); }
		const_reference back() const 	{ assert(!empty()); return *(_end - 1); }

	/*------------------------------------------------------------*/
	/*--- Modifiers                                            ---*/
	/*------------------------------------------------------------*/

		/* Adds a new element at the end of the vector, after its current
		 * last element. The content of val is copied (or moved) to the
		 * new element.
		 */
		void push_back(value_type const &x)
		{
			if (size() == _capacity)
				reserve(size() + 1);
			_allocator.construct(_end++, x);
		}

		/* Removes the last element in the vector, effectively reducing
		 * the container size by one.
		 */
		void pop_back() { assert(!empty()); _allocator.destroy(--_end); }

		/* The vector is extended by inserting new elements before the
		 * element at the specified position, effectively increasing
		 * the container size by the number of elements inserted.
		 */
		iterator insert(iterator position, value_type const &x)
		{
			/* check if 'position' is in this vector */
			assert(position <= _end
				&& position >= _begin);

			size_type offset = position - _begin;
			reserve(size() + 1);
			
			iterator end_ptr 	= _end;
			iterator start_ptr 	= _begin + offset;
			
			while (end_ptr != start_ptr) {
				--end_ptr;
				_allocator.construct(end_ptr + 1, *end_ptr);
				_allocator.destroy(end_ptr);
			}
			_allocator.construct(end_ptr, x);
			_end++;
			return (end_ptr);
		}

		void insert(
			iterator position,
			size_type n,
			value_type const &x)
		{
			/* check if 'position' is in this vector */
			assert(position <= _end
				&& position >= _begin);
			
			size_type offset = position - _begin;
			reserve(size() + n);
			
			iterator end_ptr 	= _end;
			iterator start_ptr 	= _begin + offset;
			
			while (end_ptr != start_ptr) {
				end_ptr--;
				_allocator.construct(end_ptr + n, *end_ptr);	
				_allocator.destroy(end_ptr);	
			}
			while (n--)
			{
				_allocator.construct(end_ptr, x);
				end_ptr++;
				_end++;
			}
		}

		template <class InputIterator>
		iterator insert(
			iterator position,
			InputIterator first,
			InputIterator last,
			typename ft::enable_if< !ft::is_integral<InputIterator>::value >::type* = 0)
		{
			/* check if 'position' is in this vector */
			assert(position <= _end
				&& position >= _begin);

			size_type offset 		= position - _begin;
			difference_type dist 	= std::distance(first, last);
			reserve(size() + dist);
			
			iterator end_ptr 	= _end;
			iterator start_ptr 	= _begin + offset;
			
			while (end_ptr != start_ptr) {
				end_ptr--;
				_allocator.construct(end_ptr + dist, *end_ptr);
				_allocator.destroy(end_ptr);
			}
            while (dist--) {
             	 _allocator.construct(start_ptr++, *first++);
				++_end;
			}
			return (end_ptr);
		}

		iterator erase(iterator position)
		{
			erase(position, position + 1);
			return(position);
		}

		/* Removes from the vector either a single element
		 * (position) or a range of elements ([first,last)).
		 */
		iterator erase(
			iterator first,
			iterator last)
		{
			/* check if 'first' to 'last' is in this vector */
			assert(
				first <= _end
				&& first >= _begin
				&& last <= _end
				&& last >= _begin);

			pointer ptr = first;
			while (last != end()) {
				_allocator.destroy(ptr);
				_allocator.construct(ptr, *last);
				ptr++;
				last++;
			}
			while (ptr != _end)
				pop_back();
			return first;
		}

		/* Exchanges the content of the container by the content
		 * of x, which is another vector object of the same type.
		 * Sizes may differ.
		 */
		void swap(vector<value_type, Allocator> &x)
		{
			assert(_allocator == x._allocator);

    	    std::swap(_allocator, x._allocator);
    	    std::swap(_begin,     x._begin);
    	    std::swap(_end,       x._end);
    	    std::swap(_capacity,  x._capacity);
    	}

		/* Removes all elements from the vector (which are destroyed),
		 * leaving the container with a size of 0.
		 */
		void clear() { while(!empty()) pop_back(); }
	
};

/*------------------------------------------------------------*/
/*--- Non member functions                                 ---*/
/*------------------------------------------------------------*/

template <class T, class Allocator>
inline bool operator==(
	const vector<T, Allocator> &x,
	const vector<T, Allocator> &y)
{
	return (x.size() == y.size()
		&& ft::equal(
			x.begin(),
			x.end(),
			y.begin()));
}

template <class T, class Allocator>
inline bool operator!=(
	vector<T, Allocator> const &x,
	vector<T, Allocator> const &y) { return !(x == y); }

template <class T, class Allocator>
inline bool operator<(
	vector<T, Allocator> const &x,
	vector<T, Allocator> const &y)
{
	return ft::lexicographical_compare(
		x.begin(),
		x.end(),
		y.begin(),
		y.end()
	);
}

template <class T, class Allocator>
inline bool operator>(
	vector<T, Allocator> const &x,
	vector<T, Allocator> const &y) { return (y < x); }

template <class T, class Allocator>
inline bool operator>=(
	vector<T, Allocator> const &x,
	vector<T, Allocator> const &y) { return !(x < y); }

template <class T, class Allocator>
inline bool operator<=(
	vector<T, Allocator> const &x,
	vector<T, Allocator> const &y) { return !(y < x); }

template <class T, class Allocator>
void swap(
	vector<T, Allocator> &x,
	vector<T, Allocator> &y) { x.swap(y); }

} /* ft */

#endif /* __FT_VECTOR_HPP__ */
