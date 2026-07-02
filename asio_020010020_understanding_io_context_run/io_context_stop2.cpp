#include "net_asio.h"

void foo() { log_and_sleep(2s);}

int main()
{
	asio::io_context io;

	asio::post(io, foo);	
	asio::post(io, foo);	
	asio::post(io, foo);	

	std::jthread t( [&io]{ io.run(); std::cout << "finish thread\n";});
	
	sleep(1500ms);
	io.stop();	

	std::cout << "main: io.stop\n";

	// jthread 이므로 자동으로 t.join()
}

