#include "net_asio.h"

void foo() { log(); }

void do_long_task(asio::io_context& io, auto handler)
{ 		
	auto guard = asio::make_work_guard(io);	// 핵심
	
	std::thread( [&io, handler = std::move(handler), 
						 guard = std::move(guard)] {

		sleep(3s); 
		
		asio::post(io, handler);

		// 1. guard.reset()	명시적으로 호출
		// 2. guard 파괴시 소멸자에서 "reset()"

		} ).detach();	
}

int main()
{
	asio::io_context io;

	do_long_task(io, foo);

	std::cout << "continue main\n";
	io.run();
	std::cout << "finish main\n";
}

