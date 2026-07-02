#include "net_asio.h"

void foo() { log(); }

int main()
{
	asio::io_context io;

	io.run();	// 작업이 없으므로 즉시 반환	

	io.restart();

	asio::post(io, foo);	

	io.run();	

	std::cout << "finish io.run()\n";
}
