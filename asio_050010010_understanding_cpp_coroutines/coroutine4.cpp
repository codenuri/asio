#include <generator>
#include <iostream>

// 1, 2 를 생성하는 coroutine
std::generator<int> foo()
{
	// => 컴파일러가  추가한 코드 <= 

	std::cout << "	foo #1\n";
	co_yield 1;	// Suspend, 실행 흐름을 멈추고 호출자로 이동(1전달)

	std::cout << "	foo #2\n";
	co_yield 2;	
}

int main()
{
	std::generator<int> g = foo();

	std::cout << "main #1\n";

	auto iter = g.begin();		// 1번째 resume()
	std::cout << *iter << '\n'; // 1 

	std::cout << "main #2\n";
	++iter; // resume() 
	std::cout << *iter << '\n'; // 2 

}