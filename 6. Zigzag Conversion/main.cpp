#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Solution
{

private:
	/*
		This enumerator is used for the 'zigzag' movement of adding elements to a multi-layered array.
		It uses two directions.
	*/
	enum direction {none = 0, down = 1, up = 2};
public:
	
	std::string convert(const std::string & s, const int numRows)
	{

		/* */
		
		/*
			Check the length of the string.
			If 1 character or less, return the string "s".
			If not, check for uniform character sequence.
		*/
		if (s.size() < 2)
		{
			return s;
		}
		else
		{
			/*
				Check all characters if they are the same.
				If they are, return "s", since a uniform string does not need to be processed.
			*/
			char init {s.at(0)};
			bool uniform
			{
				std::all_of
				(
					s.begin(),
					s.end(),
					[& init]
					(const char & x)
					-> bool
					{
						return x == init;
					}
				)
			};
			if (uniform == 1)
			{
				return s;
			}
		}
		
		/*
			Convert the number of rows from a signed integer to an unsigned integer.
			The number of rows cannot be negative, so there is no reason for the integer to be signed.
			
			Also declare a vector of strings.
			This will be handled much like a 2-dimensional array of character strings.
			
			Declare an instance of the member variable enumerator "direction".
			Initialise to "down", since the algorithm starts from the top and moves downwards to begin with.
		*/
		std::size_t nr { static_cast <std::size_t> (numRows) };
		std::vector <std::string> v (nr, {""});
		Solution::direction d {};
		(nr > 1) ? d = down : d = none;
		
		/*
			Loop through each character in string "s".
			Unsigned integer "i" is the index to the current character sought in "s".
			Unsigned integer "j" monitors the current row number and is used to determine the next row to add to for the vector.
			"j" is either incremented or decremented, depending on the value, the trajectory of "j" and number of rows used.
		*/
		for (std::size_t i {0}, j {0}; i < s.size(); ++i)
		{
			/*
				Add the character at index "i" of "s" to "v" at row "j", where "i" is the index of the character in string "s", "j" is the row to add in vector "v", and vector "v" is the array of strings.
			*/
			v.at(j).push_back(s.at(i));
			
			/*
				Check the current direction given by "direction" "d".
				Increment or decrement "j" according to direction and current position.
				If "j" reaches the first or last row, change direction and cycle through the rows in the opposite direction.
			*/
			if (d == down)
			{
				if (j == (nr - 1))
				{
					--j;
					d = up;
				}
				else
				{
					++j;
				}
			}
			else if (d == up)
			{
				if (j == 0)
				{
					++j;
					d = down;
				}
				else
				{
					--j;
				}
			}
		}
		
		/*
			Now with the two-dimensional array completed, each row needs to be concatenated to a single string.
		*/
		std::string zzs {};
		
		/*
			A lambda function has been used here.
			The function has a void output.
			This is designed to be used with character string inputs.
			This is then designed to loop iteratively by character.
			The characters are read as read-only as the input should not change.
			There is a capture list, since the objective is to concatenate the new string with a single character.
		*/
		std::function <void (const char &)> lf
		{
			[& zzs]
			(const char & ch)
			-> void
			{
				zzs.push_back (ch);
			}
		};
		
		/*
			Declare a second lambda function.
			This also has a void output.
			This function expects a series of strings.
			The loop is designed to input each element of the container as a string for each iteration.
			The strings are declared as read-only in order to protect data integrity.
			As the new string is also required in lambda function "lf", capture the variable "zzs".
			For any nested lambda functions, also capture those.
			In this case, "lf" is captured.
			
		*/
		std::function <void (const std::string &)> lf2
		{
			[& zzs, & lf]
			(const std::string & str)
			-> void
			{
				std::for_each
				(
					str.begin(),
					str.end(),
					lf
				);
			}
		};
		
		/*
			Cycle through each string within vector "v", which contains the output from earlier.
			This is then used to generate the zigzag string using the nested lambda functions.
		*/
		std::for_each
		(
			v.begin(),
			v.end(),
			lf2
		);
		
		/*
			Return the new string.
		*/
		return zzs;

		/* */
	
	}
};

void t1()
{
	const std::string s
	{
		"PAYPALISHIRING"
	};
	const int n
	{
		3
	};
	Solution a;
	a.convert(s, n);
}

void t2()
{
	const std::string s
	{
		"PAYPALISHIRING"
	};
	const int n
	{
		4
	};
	Solution a;
	a.convert(s, n);
}

void t3()
{
	const std::string s
	{
		"A"
	};
	const int n
	{
		1
	};
	Solution a;
	a.convert(s, n);
}

int main()
{
	t1();
	t2();
	t3();
	return 0;
}
