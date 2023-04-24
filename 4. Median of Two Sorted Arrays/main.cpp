#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <functional>

class Solution
{
public:
	
	std::vector <int> merge_v (const std::vector <int> & v1, const std::vector <int> & v2)
	{
		/*
			Declare vector of integers "v3".
			This is used to store the contents of the other two vectors.
			The for loop cycles through all the elements in both v1 and v2.
			Upon each iteration, whichever smallest value is added to v3, and then iterate to find the next number in the respective vector in order to avoid adding it again by mistake.
			When all of v1's and v2's values have been added, exit the loop and return the new vector.
		*/
		std::vector <int> v3 {};
		for (std::size_t i {0}, j {0}; i < v1.size() || j < v2.size(); )
		{
			/*
				Define the flags to determine whether to filter v1 or v2 when checking for numbers to add.
				This is determined by whether either vector has already been wholly added to the new vector v3.
				If neither have been wholly added yet, allow both vectors to be scanned for the next smallest available number.
			*/
			bool v1_a {0};
			i < v1.size() ? v1_a = 1 : v1_a = 0;
			bool v2_a {0};
			j < v2.size() ? v2_a = 1 : v2_a = 0;
			
			/*
				Enumerator to decide which vector to use to add to v3.
				Default is 0 for "none".
				This will change to one of the existing vectors depending on the outcome.
			*/
			enum decision {none = 0, v1_add = 1, v2_add = 2};
			decision verdict {none};
			
			/*
				Check if v1 and v2 can both be scanned for the next smallest available number.
				If v1's next smallest number is greater than v2's, flag to add v2's element.
				Otherwise, add v1's.
				If only one vector remains, flag to add for the remaining vector's next element.
			*/
			if (v1_a == 1)
			{
				if (v2_a == 1)
				{
					if (v1.at(i) > v2.at(j))
					{
						verdict = v2_add;
					}
					else
					{
						verdict = v1_add;
					}
				}
				else
				{
					verdict = v1_add;
				}
			}
			else if (v2_a == 1)
			{
				verdict = v2_add;
			}
			
			/*
				Determine which vector to use to copy the next element to vector v3.
				This should be whichever the next smallest available number is.
			*/
			if (verdict == v1_add)
			{
				v3.push_back (v1.at(i));
				++i;
			}
			else if (verdict == v2_add)
			{
				v3.push_back (v2.at(j));
				++j;
			}
		}
		return v3;
	}

	double findMedianSortedArrays (std::vector <int> & nums1, std::vector <int> & nums2)
	{
		/*
			Declare a new vector of integers.
			Use the member method "merge_v" and pass through the existing vectors as arguments.
		*/
		std::vector <int> n3 {Solution::merge_v (nums1, nums2)};
		
		/*
			Decide if the resulting vector is the size of an even number.
			The calculation for the median differs for even numbered sequences to odd numbered.
		*/
		bool even_size
		{
			(n3.size() % 2 == 0)
			?
				static_cast <bool> (1)
			:
				static_cast <bool> (0)
		};
		
		/*
			Declare "t1", which is the index for the first target number in vector "n3".
			"t1" is used in both odd and even numbers.
			"t1" is already correct for odd numbered sequences.
			For even numbered sequences, the value for "t1" is actually the value for "t2", so "t1" is copied over to "t2" and then "t1" is decremented by 1.
			
		*/
		std::size_t t1
		{
			static_cast <std::size_t> ( std::floor (n3.size() / 2) )
		};
		
		/*
			For even numbers, copy the index of "t1" to "t2".
			Decrement "t1" by one.
			Then get the numbers from "n3", the new vector, at both the respective indices.
			Convert these values to double floating point values.
			Add them together, then divide by 2.
			Return the median value.
		*/
		if (even_size == 1)
		{
			std::size_t t2 {t1};
			--t1;
			double median
			{
				static_cast <double> (n3.at(t1))
				+
				static_cast <double> (n3.at(t2))
			};
			median /= 2;
			return median;
		}
		/*
			For odd numbers, get the integer from "n3" using the index "t1".
			Typecast to a double floating point value and return this value.
		*/
		else
		{
			return static_cast <double> ( n3.at(t1) );
		}
	}
};

void t1 ()
{
	std::vector <int> v1 {1, 3};
	std::vector <int> v2 {2};
	Solution a;
	a.findMedianSortedArrays (v1, v2);
}

void t2 ()
{
	std::vector <int> v1 {1, 2};
	std::vector <int> v2 {3, 4};
	Solution a;
	a.findMedianSortedArrays (v1, v2);
}

int main ()
{
	std::cout << std::endl;
	std::cout << std::endl;
	
	t1 ();
	t2 ();
	
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
