#include "net_asio.h"

void foo() { log(); }

void do_long_task(asio::io_context& io, auto handler)
{ 		
	// 1. 새로운 스레드를 생성해서 복잡한 작업 수행 하고
	//    주 스레드는 즉시 반환
	std::thread( [&io, handler = std::move(handler)] {

		sleep(3s); // 시간이 오래 걸리는 복잡한 작업 수행
		
		asio::post(io, handler); // 작업 종료를 전달

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

