#include "net_asio.h"

void foo() { log_and_sleep(3s); }

int main()
{
	asio::io_context io;

	asio::post(io, foo);	

	io.run();	// foo() 실행 완료후 io.run() 즉시 반환

	std::cout << "finish io.run()\n";
}
