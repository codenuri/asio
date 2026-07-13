#include <generator>
#include <iostream>

std::generator<int> foo()
{
	std::cout << "	foo #1\n";
	co_yield 1;

	std::cout << "	foo #2\n";
	co_yield 2;	
}

int main()
{
	for( auto n : foo() )	
	{						
		std::cout << "[main]: coroutine 반환값 : " << n << '\n';
	}
}