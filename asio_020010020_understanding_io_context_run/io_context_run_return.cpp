#include "net_asio.h"

void foo() { log(); }

int main()
{
	asio::io_context io;

	asio::post(io, foo);	
	asio::post(io, foo);	
	asio::post(io, foo);	

	auto ret = io.run();

	std::cout << ret << '\n'; // 3
}
