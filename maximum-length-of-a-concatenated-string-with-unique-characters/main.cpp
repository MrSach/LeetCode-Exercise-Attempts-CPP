#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{
public:
	int maxLength( std::vector <std::string> & arr)
	{
		/*
			Create a new vector of strings for the new concatenated string combinations.
		*/
		std::vector <std::string> concats {};
		
		/*
			Loop through elements in the vector.
			"i" is the location of the primary string to first add as its own combination to the concatenations.
			The string at "i" is then concatenated by other elements after "i", as defined by "j" later.
		*/
		for (std::size_t i {0}; i < arr.size(); ++i)
		{
			/*
				Create buffer vector for storing concatenations for the current iterations.
				This vector is then used to buffer to the "concats" vector, which remains intact after the main loop.
			*/
			std::vector <std::string> buf {arr.at (i)};
			
			/*
				Initialise the dynamic vector sizing for "buf".
				This is necessary as the vector may grow when concatenations are found and added to "buf".
			*/
			std::size_t b_size {buf.size()};
			
			/*
				Loop and check from the next element in the array "arr".
				"j" gives the location of the string to concatenate.
				Using each element after the current one, new concatenations can be found.
				As "buf" also contains concatenated combinations, these new combinations can in turn also be concatenated further, and thus creates even more possible combiations.
			*/
			for (std::size_t j {i + 1}; j < arr.size(); ++j)
			{
				/*
					Recalculate the temporary size buffer for "buf".
					This prevents the loop from prematurely exiting, or looping out of range by accident.
					Remember that this vector size is dynamic as new elements are expected to be added during the loop to concatenate to "buf".
				*/
				b_size = buf.size();
				
				/*
					Loop through entries within the "buf" vector.
					This loop will finish at whatever size "buf" was upon entering during "j"'s current iteration.
					Find each element as given by "j"'s location in "arr" and concatenate to "k"'s location in "buf".
					Create a temporary string called "temp".
					Copy the concatenation result to "temp".
					Add the contents of "temp" as a new element to "buf".
					When the loop for "k" exits, "b_size" can then be recalculated in the next iteration for "j" in  order to accommodate further concatenations to the already concatenated strings.
				*/
				for (std::size_t k {0}; k < b_size; ++k)
				{
					std::string temp {buf.at(k) + arr.at(j)};
					buf.push_back (temp);
				}
			}
			
			/*
				Cycle through each combination in "buf".
				Add the elements to "concats".
				Remember that "buf" is a buffer vector and will fall out of scope after each iteration of "i".
				"concats" will however remain in scope beyond the loop, so the data will be safer in this vector.
				A lambda function has been used here with "concats" captured by reference (write access is required).
				Each element in "buf" is loaded as read-only in this lambda function to reinforce data integrity while buffering.
			*/
			std::for_each
			(
				buf.begin(),
				buf.end(),
				[& concats]
				(const std::string & s)
				-> void
				{
					concats.push_back (s);
				}
			);
		}
		
		/*
			Add empty string as this counts as another combination in itself.
			For this exercise, the total expected number of combinations is 2^n, where n is the number of strings in the array.
		*/
		concats.push_back ("");
		
		/*
			Declare a new vector of strings.
			This vector is designed to accommodate filtered elements from "concats".
		*/
		std::vector <std::string> consolidated {};
		
		/*
			Three layers of looping are used here.
			The loop for "i" is used to cycle through each string in "concats".
			The loop for "j" is used to check for the first character to compare within the current element.
			The loop for "k" is used to check the character given by "j" against the character given by "k".
			If they are the same, then a flag to mark the string as containing duplicate characters is reassigned to be true.
			If a duplicate is found then exit the iterations for the characters and proceed on to check the next element in the string vector.
			Otherwise, if the character checking loops for "j" and "k" finish and no duplicate characters are found then the string element is added to "consolidated".
		*/
		for (std::size_t i {0}; i < concats.size(); ++i)
		{
			bool duplicated {0};
			for (std::size_t j {0}; j < concats.at(i).size(); ++j)
			{
				for (std::size_t k {j + 1}; k < concats.at(i).size(); ++k)
				{
					if (concats.at(i).at(j) == concats.at(i). at(k))
					{
						duplicated = 1;
					}
				}
				if (duplicated == 1)
				{
					break;
				}
				
			}
			if (duplicated == 1)
			{
				break;
			}
			else
			{
				consolidated.push_back (concats.at(i));
			}
		}
		
		/*
			Declare the size of the result.
			This may be reassigned to the largest string found if detected later.
		*/
		std::size_t result {0};
		
		/*
			Cycle through each element in "consolidated".
			If the length of the current element is greater then the greatest value found so far as stored in "result", update "result" to the new record value.
		*/
		for (std::size_t i {0}; i < consolidated.size(); ++i)
		{
			if (consolidated.at(i).size() > result)
			{
				result = consolidated.at(i).size();
			}
		}
		
		/*
			Display the result before returning.
		*/
		std::cout << std::endl;
		
		std::cout << "Longest string length found: " << result << std::endl;
		
		std::cout << std::endl;
		
		return result;
	}
	
	
};

int main ()
{
	std::cout << std::endl;
	Solution test_1;
	std::vector <std::string> arr_1
	{
		{
			"un"
		},
		{
			"iq"
		},
		{
			"ue"
		}
	};
	std::vector <std::string> arr_2
	{
		{
			"cha"
		},
		{
			"r"
		},
		{
			"act"
		},
		{
			"ers"
		}
	};

	std::vector <std::string> arr_3
	{
		{
			"abcdefghijklmnopqrstuvwxyz"
		}
	};
	
	/*
		Verbose report to display the strings with unique characters.
		This is the vector for "consolidated".
	*/
	std::function <void (const std::string &)> display_vector
	{
		[]
		(const std::string & s)
		-> void
		{
			std::cout << s << std::endl;
		}
	};
	
	std::cout << "Array 1: ";
	std::cout << std::endl;
	std::for_each
	(
		arr_1.begin(),
		arr_1.end(),
		display_vector
	);
	std::cout << std::endl;
	
	std::cout << "Array 2: ";
	std::cout << std::endl;
	std::for_each
	(
		arr_2.begin(),
		arr_2.end(),
		display_vector
	);
	std::cout << std::endl;
	
	std::cout << "Array 3: ";
	std::cout << std::endl;
	std::for_each
	(
		arr_3.begin(),
		arr_3.end(),
		display_vector
	);
	std::cout << std::endl;
	
	test_1.maxLength (arr_1);
	test_1.maxLength (arr_2);
	test_1.maxLength (arr_3);
	
	return 0;
}
