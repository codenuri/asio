#include "net_asio.h"

void foo(const std::error_code& ec) { log();}

int main()
{
	asio::io_context io;

	asio::steady_timer t(io, 3s);

	t.async_wait(foo);

	std::jthread t1( [&io]{ io.run(); std::cout << "finish thread\n";});
	
	sleep(1s);
	io.stop();	
	std::cout << "main: io.stop\n";

	// jthread 이므로 자동으로 t1.join()
}

