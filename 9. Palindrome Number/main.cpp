#include <cstdlib>
#include <limits>

class s
{
public:
	bool f (const int & x)
	{
	
		/* */
	
		/*
			Check the number if it is negative.
			A sign will make the numeric value non-palindromic, since a minus sign ('-') only appears on one side.
			Also check if there is only one positive digit.
			A single digit number that is positive reads the same forwards as it does backwards, so this qualifies as palindromic.
		*/
		if (x < 0)
		{
			return 0;
		}
		else if (x < 10)
		{
			return 1;
		}
		
		/*
			Create a variable to store the length of the integer variable.
			Also create a temporary copy of the number.
			Then loop through the copied number and divide by 10 at regular intervals, incrementing the length at each iteration of this loop.
			Note that leading zeroes are not included, as they are not stored in the decimal integer format.
		*/
		std::size_t len {0};
		for (int y {x}; y >= 1; y /= 10)
		{
			++len;
		}
		
		/*
			Now that the number of digits is known, an array can be created to store the digits in order that they appear.
			Loop through the number as before, except instead of counting the number of digits, this time get the units for each iteration and copy to the array element for each index.
			The array elements appear in reverse order, but this is of no issue.
		*/
		int arr [len] {};
		for (int y {x}, i {0}; y >= 1; y /= 10, ++i)
		{
			arr[i] = y % 10;
		}
		
		/*
			Calculate the midpoint.
			Generate variables for the next left and right digits from the midpoint.
			Note that for odd numbered lengths of digits, the midpoint is the index calculated and therefore offset 1 to the right and 1 to the left.
			For even numbered lengths, the calculation gives the number to the right already, so subtract by one to get the left number.
			Also find the greatest possible value for the std::size_t data type.
			For signed integer values, 0 - 1 gives -1, but size_t is unsigned, meaning that the value instead loops back to the maximum possible value.
		*/
		std::size_t midpoint {len / 2};
		std::size_t left {};
		std::size_t right {};
		std::size_t st_limit {std::numeric_limits<std::size_t>::max()};
		if (len % 2 == 0)
		{
			left = midpoint - 1;
			right = midpoint;
		}
		else
		{
			left = midpoint - 1;
			right = midpoint + 1;
		}
		
		/*
			Use the index of the left number and copy to a temporary variable.
			Do the same with the right number.
			Keep within bounds of the array and exit when the temporary index variables refer to areas outside the array.
			Both indices should both exceed the limit at the same time.
			Iterate with decrementing "l" (point to the next number of the left) and increment "r" (point to the next number on the right).
			If the values on the right and left are the same in the current loop's iteration, proceed to the next iteration within the loop.
			If they are different, there is no palindrome and return false.
		*/
		for (std::size_t l {left}, r {right}; l < st_limit && r < len; --l, ++r)
		{
			if ((arr[l] < arr[r]) || (arr[l] > arr[r]))
			{
				return 0;
			}
		}
		
		/*
			The processing is complete and the number is found to be a palindrome.
			Return 1 to give true.
		*/
		return 1;
		
		/* */
	}
};

void t1()
{
	s a;
	a.f (121);
}

void t2()
{
	s a;
	a.f (-121);
}

void t3()
{
	s a;
	a.f (10);
}

int main ()
{
	t1();
	t2();
	t3();
	return 0;
};
