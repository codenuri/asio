#include <iostream>

void foo()
{
	std::cout << "foo #1\n";
	std::cout << "foo #2\n";
	std::cout << "foo #3\n";
}
void goo()
{
	std::cout << "goo #1\n";
	return;
	std::cout << "goo #2\n";
}
int main()
{
	foo();	// 함수가 끝까지 실행된후 반환

	goo();	// "goo #1" 까지 실행후 반환

	goo();	// "goo #2" 부터 실행되는 것이 아니라 처음 부터 실행. 
			// 역시 "goo #1" 까지 실행후 반환 - coroutine 아님
			// => 처음이 아닌 "goo #2" 부터 다시 실행되게 할수 없을까 ?
	
}