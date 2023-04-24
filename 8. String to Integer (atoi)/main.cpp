#include <string>
#include <cctype>
#include <sstream>
#include <limits>

class Solution
{
public:
	int myAtoi (const std::string & s)
	{
		
		/* */
		
		if (s.empty())
		{
			return 0;
		}
		
		std::string buffer {};
		bool lead_space {1};
		bool digit_reach {0};
		bool sign_read {0};
		bool negative {0};
		bool exit_flag {0};
		
		for (std::size_t i {0}; i < s.size(); ++i)
		{
			if (std::isdigit(s.at(i)))
			{
				buffer.push_back(s.at(i));
				if (digit_reach == 0)
				{
					digit_reach = 1;
				}
				if (lead_space == 1)
				{
					lead_space = 0;
				}
			}
			else if ((s.at(i)) == ' ')
			{
				if (lead_space == 1)
				{
					continue;
				}
				else
				{
					exit_flag = 1;
				}
			}
			else if (s.at(i) == '+' && sign_read == 0)
			{
				sign_read = 1;
				if (lead_space == 1)
				{
					lead_space = 0;
				}
				if (digit_reach == 0)
				{
					continue;
				}
				else
				{
					exit_flag = 1;
				}
			}
			else if (s.at(i) == '-' && sign_read == 0)
			{
				sign_read = 1;
				if (lead_space == 1)
				{
					lead_space = 0;
				}
				if (digit_reach == 0)
				{
					negative = 1;
					continue;
				}
				else
				{
					exit_flag = 1;
				}
			}
			else if (!(std::isdigit(s.at(i))))
			{
				exit_flag = 1;
			}
			
			if (exit_flag == 1)
			{
				break;
			}
		}
		
		std::stringstream ss {};
		ss << buffer;
		std::uint32_t usi {};
		ss >> usi;
		std::int32_t si {};
		std::uint32_t i_max
		{
			static_cast <std::uint32_t>
			(
				std::numeric_limits<std::int32_t>::max()
			)
		};
		std::uint32_t i_min
		{
			static_cast <std::uint32_t>
			(
				std::numeric_limits<std::int32_t>::min()
			)
			*
			(-1)
		};

		if (negative == 0)
		{
			if (usi > i_max)
			{
				si = static_cast <std::int32_t> (i_max);
			}
			else
			{
				si = static_cast <std::int32_t> (usi);
			}
		}
		else if (negative == 1)
		{
			if (usi > i_min)
			{
				si = static_cast <std::int32_t> ((i_min) * (-1));
			}
			else
			{
				si = static_cast <std::int32_t> ((usi) * (-1));
			}
		}
		
		return si;
		
		/* */
	}
};

void t1()
{
	Solution a;
	std::string x {"42"};
	a.myAtoi(x);
}

void t2()
{
	Solution a;
	std::string x {"   -42"};
	a.myAtoi(x);
}

void t3()
{
	Solution a;
	std::string x {"4193 with words"};
	a.myAtoi(x);
}

void t4()
{
	Solution a;
	std::string x {"words and 987"};
	a.myAtoi(x);
}

void t5()
{
	Solution a;
	std::string x {"-91283472332"};
	a.myAtoi(x);
}

void t1077()
{
	Solution a;
	std::string x {"+-12"};
	a.myAtoi(x);
}

void t1083()
{
	Solution a;
	std::string x {"  +  413"};
	a.myAtoi(x);
}

int main ()
{
	//t1();
	//t2();
	//t3();
	//t4();
	//t5();
	//t1077();
	t1083();
	return 0;
}
