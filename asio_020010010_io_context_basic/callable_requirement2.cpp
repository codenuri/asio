#include "net_asio.h"

void foo( const asio::error_code& ec)        { log(); }
void goo( const asio::error_code& ec, int a) { log(); }

int main()
{
	asio::io_context io;
	asio::steady_timer t(io, 3s);
	
	t.async_wait(foo); // ok
//	t.async_wait(goo); // error

	t.async_wait(std::bind(goo, _1, 3)); 
	t.async_wait([](const std::error_code& ec) { goo(ec, 3);});

	io.run(); 
}

