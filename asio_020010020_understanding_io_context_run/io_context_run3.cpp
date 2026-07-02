#include "net_asio.h"

void foo(const std::error_code& e) { log(); }

int main()
{
	asio::io_context io;

	asio::steady_timer t(io, 5s);

	t.async_wait(foo);

	io.run();	// 1. Q 에 작업이 없지만, 비동기 타이머 요청이 
				//    남아 있으므로 io.run() 반환 안됨
				// 2. 타이머 완료후, foo() 실행이 종료되면
				//    io.run() 반환

	std::cout << "main: finish io.run()\n";
}
