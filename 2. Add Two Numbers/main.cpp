#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
 
struct ListNode
{
	int val;
	ListNode * next;
	ListNode () : val (0), next (nullptr) {}
	ListNode (int x) : val (x), next (nullptr) {}
	ListNode (int x, ListNode * next) : val (x), next (next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode() : val(0), next(nullptr) {}
 *	 ListNode(int x) : val(x), next(nullptr) {}
 *	 ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	
	int ln_val_iter (ListNode * * n)
	{
		std::cout << "n object " << n << " passed into ln_val_iter" << std::endl;
		std::cout << "* n object " << * n << " passed into ln_val_iter" << std::endl;
		if ( (* n) == nullptr)
		{
			return 0;
		}
		else
		{
			int x { (* n) -> val};
			* n = (* n) -> next;
			std::cout << "next = " << * n << std::endl;
			return x;
		}
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode * p1 {l1};
		ListNode * p2 {l2};
		ListNode * p3 { new ListNode };
		ListNode * l3 {p3};
		int remainder {0};
		bool done {0};

		for (std::size_t i {0}; done == 0; ++i)
		{
			std::cout << "i = " << i << std::endl;
			int n1 {ln_val_iter (& p1)};
			int n2 {ln_val_iter (& p2)};
			int sum { n1 + n2 + remainder };
			int units { sum % 10 };
			p3 -> val = units;
			remainder = sum / 10;
			if (p1 != nullptr)
			{
				p3 -> next = new ListNode;
			}
			else if (p2 != nullptr)
			{
				p3 -> next = new ListNode;
			}
			else if (remainder > 0)
			{
				p3 -> next = new ListNode;
			}
			else
			{
				p3 -> next = nullptr;
				done = 1;
			}
			std::cout << "p3 next = " << p3 -> next << std::endl;
			p3 = p3 -> next;
			if (i > 10)
			{
				break;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		done = 0;
		remainder = 0;
		p3 = l3;
		
		for ( ; p3 != nullptr; )
		{
			std::cout << "p3 = " << p3 << std::endl;
			std::cout << "p3 val = " << p3 -> val << std::endl;
			std::cout << "p3 next = " << p3 -> next << std::endl;
			p3 = p3 -> next;
		}
		
		p3 = l3;

		return l3;
	}
};

void t1 ()
{
	ListNode a3 { 3 };
	ListNode b3 { 4 };
	
	ListNode a2 { 4, & a3 };
	ListNode b2 { 6, & b3 };
	
	ListNode a1 { 2, & a2 };
	ListNode b1 { 5, & b2 };
	
	Solution c;
	c.addTwoNumbers (& a1, & b1);
}

void t2 ()
{
	ListNode a;
	ListNode b;
	
	Solution c;
	c.addTwoNumbers (& a, & b);
}

void t3 ()
{
	ListNode a [7];
	for (std::size_t i {0}; i < 7; ++i)
	{
		a[i].val = 9;
		if (i < 6)
		{
			a[i].next = (a + i + 1);
		}
		else
		{
			a[i].next = nullptr;
		}
		a[i].val = 9;
		std::cout << "i = " << i << std::endl;
		std::cout << "a [i] = " << & a[i] << std::endl;
		std::cout << "a [i] val = " << a[i].val << std::endl;
		std::cout << "a [i] next = " << a[i].next << std::endl;
	}
	
	ListNode b [4];
	for (std::size_t i {0}; i < 4; ++i)
	{
		b[i].val = 9;
		if (i < 3)
		{
			b[i].next = (b + i + 1);
		}
		else
		{
			b[i].next = nullptr;
		}
		b[i].val = 9;
		std::cout << "i = " << i << std::endl;
		std::cout << "b [i] = " << & b[i] << std::endl;
		std::cout << "b [i] val = " << b[i].val << std::endl;
		std::cout << "b [i] next = " << b[i].next << std::endl;
	}
	Solution c;
	c.addTwoNumbers (a, b);
}

int main ()
{
	//t1 ();
	//t2 ();
	//t3 ();
	
	
	
	

	return 0;
}
