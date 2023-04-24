#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

class Solution {
public:

	std::string longestPalindrome (const std::string & s)
	{

    	/* */
		
		/*
			Check if the provided string is empty.
			Return an empty string.
			
			If the string is 1 character long, return the provided string.
			
			If the length is greater than 1 character then proceed with checking for palindromes.
		*/
		if (s.empty ())
		{
			return std::string {};
		}
		else if (s.size() == 1)
		{
			return s;
		}
		else
		{
			/*
				Declare the palindrome string, "target", which is later returned.
				To start with, initialise to the first character in string "s" because it is at least 2 characters long and any character will suffice for now.
				Check for uniform string with identical characters.
				
			*/
			std::string target {s.at(0)};
			bool uniform_str
			{
				std::all_of
				(
					s.cbegin(),
					s.cend(),
					[& target]
					(const char & ch)
					-> bool
					{
						return (std::string {ch}) == target;
					}
				)
			};
			
			if (uniform_str == 1)
			{
				return s;
			}
		
			/*
				Declare a constant to determine the maximum possibe value of the size_t data type.
				This is used because size_t is unsigned, meaning that as soon as a value reaches -1, it becomes the maximum value instead.
				

				
				Afterwards, start the main loop with "i".
				This loop starts with the index of the first character of "s" and then progresses through the string to the next character at each iteration.
				Because at least 2 characters need to be checked and compared for each iteration of "i", the final character in "s" does not need to be a placeholder, since there are no trailing characters to compare against.
				Also, the first character in "s" may be the same as the second, which would qualify as a palindrome (e.g. "aabc") because they would read the same forwards and backwards.
			*/
			const std::size_t t_minus1 {std::numeric_limits<std::size_t>::max()};
			for (std::size_t i {0}; i < s.size() - 1; ++i)
			{
				/*
					Declare a buffer, which starts with the character that the index "i" currently seeks.
					This is used to temporarily store characters to check for palindromes and this is reset for each iteration of "i" in the major loop.
					
					Also declare two boolean variables.
					When a palindrome is found, flag whether this happens when the substring reached an even number of characters or an odd number.
					By default, since only one charater exists in the "buffer" variable so far, there is no match yet, so default to false for both booleans.
					
					The minor loop sees three new unsigned integer variables, "j", "k" and "l".
					"j" is the counter of loops and is used to monitor the current iteration number.
					"j" is also used to determine whether the loop has cycled through an even or odd number of times as this affects the booleans as well as which side of the character indexed by "i" to check next.
					"k" is used to determine the next character to seek to the left of "i".
					If "i" is already at the beginning of "s", "k" will become the "t_minus1" value and will not be used.
					When "k" reaches "t_minus1", it has reached beyond the beginning of string "s" and the loop will end when it would next seek index "k" in string "s".
					k < t_minus1 is used because all values are positive.
					"t_minus1" is the next value below 0, which is the maximum value of the size_t data type.
					
					"m" indexes the next character to the right of "i".
					When this index reaches beyond the limit of string "s", there is a conditional that monitors whether this would be out of boundaries.
					The loop can safely terminate before string "s" at index "m" is accessed when "m" exceeds the length of string "s".
					
					Increment "j" at each loop iteration.
					"k" and "m" are changed separately at different times during the loop.
				*/
				std::string buffer {s.at(i)};
				bool even_match {0};
				bool odd_match {0};
				for (std::size_t j {0}, k {i - 1}, m {i + 1}; k < t_minus1 || m < s.size(); ++j)
				{
					/*
						Declare a boolean to determine whether a palindrone has just been found in the current iteration of "j".
						Check if "j" is an even number or an odd number.
						If even, check if "m" is still within bounds of "s".
						If odd, check if "k" is still within bounds of "s".
						For the respective character to the right or left, add to the buffer substring.
						Declare a new string called "rb".
						This is used to store the contents of "buffer" and is then reversed.
						Do "buffer" and "rb" match?
						If so, depending on "j"'s value, flag for a match for an even-numbered character substring or for an odd number of characters.
						
						If "j" is even and "m" is out of bounds, the loop safely terminates as "m" would otherwise lead to an out of bounds error.
						The same applies to "k" if "j" is odd.
						In these cases, the default option is for the loop to terminate.
						The largest palindrome found so far across all iterations of "i" is preserved, so if the next largest palindrome was found in this iteration of "i", it remains in memory, even if the minor loop for "j" cannot continue because it has reached the end of the string to the left or right, or that no reverse matches were found for two conescutive iterations of "j".
						
						If the loop finds no reverse string matches twice in a row then the loop for "j" will terminate.
					*/
					bool fresh_match {0};
					std::string rb {}; 
					if (m < s.size() && (j % 2 == 0) )
					{
						buffer += s.at(m);
						rb = buffer;
						std::reverse (rb.begin(), rb.end());
						buffer == rb ? even_match = 1 : even_match = 0;
						even_match == 1 ? fresh_match = 1 : fresh_match = 0;
						++m;
					}
					else if (k < t_minus1)
					{
						
						buffer = s.at(k) + buffer;
						rb = buffer;
						std::reverse (rb.begin(), rb.end());
						buffer == rb ? odd_match = 1 : odd_match = 0;
						odd_match == 1 ? fresh_match = 1 : fresh_match = 0;
						--k;
					}
					else
					{
						break;
					}
					
					/*
						Here are two conditionals.
						Check if the flag for matching left and right characters has been set to true.
						If so, proceed to check if this new palindrome exceeds the length of the current largest palindrome.
						If so, overwrite the pre-existing largest palindrome with the new one. 
					*/
					if (fresh_match == 1)
					{
						if (buffer.size() > target.size())
						{
							target = buffer;
						}
					}
					
					/*
						Check if no matches have occurred twice in a row.
						If so, terminate the loop as the possibility of finding a palindrome is now eliminated for the current index at "i".
					*/
					if ( (j > 0) && (even_match == 0) && (odd_match == 0) )
					{
						break;
					}
				}
			}
			/*
				Give the largest palindrome substring found in "s".
			*/
			return target;
		}
		
    	/* */

	}
};

void t1 ()
{
	std::string a {"babad"};
	Solution x;
	x.longestPalindrome (a);
}

void t2 ()
{
	std::string a {"cbbd"};
	Solution x;
	x.longestPalindrome (a);
}

void t33 ()
{
	std::string a {"aacabdkacaa"};
	Solution x;
	x.longestPalindrome (a);
}

void t88 ()
{
	std::string a {"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"};
	Solution x;
	x.longestPalindrome (a);
}

int main ()
{
	t1();
	t2();
	t33();
	t88();
	return 0;
}
