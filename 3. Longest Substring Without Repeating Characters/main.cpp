#include <iostream>
#include <string>

class Solution {
public:
	int lengthOfLongestSubstring (const std::string & s)
	{
		/*
			Check if the string is empty and return 0 if so.
		*/
		if (s.size() == 0)
		{
			return 0;
		}
		else
		{
			/*
				If the string is not empty, proceed with checking.
				Set current largest length to 1, since there is guaranteed to be at least 1 character now.
				3 layers of looping are used.
				The loop for 'i' is used to check from the first character in string 's'.
				Initially, the last value to check is the second to last character (the last character would only check for 1 character, so would only give the length of 1).
				If long substrings are found, the loop for 'i' can exit earlier, since there would be no reason to scan for shorter substrings when the longest possible one has already been found.
			*/
			std::size_t largest {1};
			std::cout << "largest = " << largest << std::endl;
			for (std::size_t i {0}; i < s.size () - largest; ++i)
			{
				/*
					Declare a boolean and set to 0.
					Name this 'terminate'.
					'terminate' is designed to flag whether a substring loop has reached a duplicate character and therefore the loops for 'j' and 'k' should exit back to the main 'i' loop.
					Declare a 'length' variable.
					This records the length of the current substring that is extracted and scanned.
					When the substring is processed, 'length' is compared with 'largest' and if it exceeds the value of 'largest' then the value of 'largest' is overwritten with the value of 'length'.
					Declare a variable called 'parsed'.
					This variable starts with the first letter to scan from, which is determined by the current iteration of 'i'.
					In other words, 'parsed' starts with the character that 'i' has currently reached.
					
				*/
				std::cout << "i = " << i << std::endl;
				bool terminate {0};
				std::cout << "terminate = " << terminate << std::endl;
				
				std::size_t length {1};
				std::cout << "length = " << length << std::endl;
				
				std::string parsed {s.at(i)};
				std::cout << "parsed = " << parsed << std::endl;
				
				/*
					Enter the loop for 'j'.
					This always begins one character after the index 'i'.
					As there are two characters being compared, there is no need to compare the same index with itself.
					Each iteration sees 'j' advance one more character towards the end of the string.
					Unlike 'i', j can reach up to the end of the string.
					In theory, a string could contain entirely unique characters.
				*/
				for (std::size_t j {i + 1}; j < s.size(); ++j)
				{
				
					std::cout << "j = " << j << std::endl;
					std::cout << "s char at i: " << s.at(i) << std::endl;
					std::cout << "s char at j: " << s.at(j) << std::endl;
				
					/*
						Enter the loop for 'k'.
						This loop checks each character currently stored in the temporary buffer, 'parsed', against the next character to potentially add, using the 'j' index for string 's'.
						If no duplicates are found, proceed as normal.
						If a duplicate character is found, flag 'terminate' to 1 (true) and exit the loop for 'k' prematurely.
					*/
					for (std::size_t k {0}; k < (j - i); ++k)
					{
					
						std::cout << "k = " << k << std::endl;
						std::cout << "parsed char at k: " << parsed.at (k) << std::endl;
						
						if (s.at (j) == parsed.at (k))
						{
							terminate = 1;
							std::cout << "Duplicate found, breaking from current k loop" << std::endl;
							break;
						}
					}
					std::cout << "Exiting k loop" << std::endl;
					
					std::cout << std::endl;
					
					/*
						If there was a duplicate character in the loop for 'k', exit the loop for 'j' as the longest possible substring at 'i' has already been found.
						
						If the substring has been unique so far, concatenate the character in 's' at index 'j' to the 'parsed' string.
						Follow with incrementing the length of the current substring.
						Check the larget recorded substring length and raise it if this gets exceeded.
						Next, proceed to the next iteration of 'j' and check the next character in 's' as before until the end of the string is reached, or a duplicate character is eventually found.
					*/
					if (terminate == 1)
					{
						std::cout << "parsed = " << parsed << std::endl;
						std::cout << "length = " << length << std::endl;
						std::cout << "Breaking j loop..." << std::endl;
						break;
					}
					else
					{
						parsed.push_back (s.at (j));
						++length;
						std::cout << "Concatenated parsed" << std::endl;
						std::cout << "parsed = " << parsed << std::endl;
						std::cout << "length = " << length << std::endl;
						if (length > largest)
						{
							largest = length;
							std::cout << "New largest length is " << largest << std::endl;
						}
					}
				}
				std::cout << "Exiting j loop" << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}
			/*
				As the std::size_t variable uses the largest possible unsigned integer value on the given machine architecture, it was used to record the positive integer values earlier.
				This is typecasted to a signed integer value in order to allow for the target data type to be returned.
			*/
			return static_cast <int> (largest);
		}
	}
};

void t1 ()
{
	std::string a {"abcabcbb"};
	Solution x;
	x.lengthOfLongestSubstring (a);
}

void t2 ()
{
	std::string a {"bbbbb"};
	Solution x;
	x.lengthOfLongestSubstring (a);
}

void t3 ()
{
	std::string a {"pwwkew"};
	Solution x;
	x.lengthOfLongestSubstring (a);
}

int main ()
{
	t1 ();
	std::cout << std::endl;
	t2();
	std::cout << std::endl;
	t3();
	std::cout << std::endl;

	return 0;
}
