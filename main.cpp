#include "ft/vector.hpp"
#include <limits>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

void test_01(void)
{
	std::list<int> lst;
	std::list<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<int> vct(lst.begin(), lst.end());
	assert(vct.size() == 4);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	assert(vct.size() == 4);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	assert(vct.size() == 8);
	std::cout << "OK" << std::endl;
}

void test_02(void)
{
	ft::vector<int> vct(7);
	ft::vector<int> vct_two(4);
	ft::vector<int> vct_three;
	ft::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	assert(vct.size() == 7);
	assert(vct_two.size() == 4);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);
	assert(vct.size() == 4);
	assert(vct_two.size() == 2);
	assert(vct_three.size() == 7);
	assert(vct_four.size() == 4);

	vct_four.assign(6, 84);
	assert(vct_four.size() == 6);
	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	assert(vct.size() == 5);
	assert(vct_two.size() == 3);

	std::cout << "OK" << std::endl;
}

#define TESTED_NAMESPACE ft

void test_03(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<int> vct(size);
	TESTED_NAMESPACE::vector<int>::iterator it_ = vct.begin();
	TESTED_NAMESPACE::vector<int>::reverse_iterator it(it_);


	it_ = vct.begin();	
	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;

	assert(it_ == it.base());
	assert(it_ != (it + 3).base());

	assert(*(it.base() + 1) == 10);
	assert(*(it - 3) == 15);
	assert(*(it - 3).base() == 20);
	it -= 3;
	assert(*it.base() == 20);

	assert(*(it) == 15);
	assert(*(it).base() == 20);
	assert(*(it - 0) == 15);
	assert(*(it - 0).base() == 20);
	assert(*(it - 1).base() == 25);
	std::cout << "OK" << std::endl;
}

void test_04(void)
{
		const int size = 5;
	TESTED_NAMESPACE::vector<int> vct(size);
	TESTED_NAMESPACE::vector<int>::reverse_iterator it(vct.rbegin());
	TESTED_NAMESPACE::vector<int>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);

	it = vct.rbegin();
	ite = vct.rbegin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	//it->m();
	//ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	//(*it).m();
	//(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;
}

int main(void)
{
	test_01();
	test_02();
	test_03();
}
