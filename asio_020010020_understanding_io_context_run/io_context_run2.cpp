#include "net_asio.h"

void foo() { log_and_sleep(5s); }

int main()
{
	asio::io_context io;

	asio::post(io, foo);	

	std::jthread t( [&io]{ io.run(); }); // 새로운 스레드가 foo 실행

	std::this_thread::sleep_for(300ms);
	
	io.run(); // 1. 이 순간 Q는 비어 있지만 다른 스레드가 foo() 실행중
			  //    이므로 io.run() 은 반환되지 않고 대기
			  // 2. 다른 스레드가 실행중인 foo() 가 종료되면
			  //  	io.run() 반환

	std::cout << "main: finish io.run()\n";
}
