#include "net_asio.h"

void foo() { log_and_sleep(1s); }
void goo(const asio::error_code& e) { log(); }

int main()
{
	asio::io_context io;

	asio::steady_timer t(io, 3s);

//	t.wait();			
	t.async_wait(goo);	

	asio::post(io, foo);

	io.run(); 
}
