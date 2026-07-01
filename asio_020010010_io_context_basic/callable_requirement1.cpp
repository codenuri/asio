#include "net_asio.h"

void foo() 				  { log(); }
void goo(int a, double d) { log(); }

int main()
{
	asio::io_context io;

	asio::post(io, foo);	// ok
//	asio::post(io, goo);	// error

	asio::post(io, std::bind(goo, 1, 3.4)); // ok 
	asio::post(io, [](){ goo(1, 3.4); } );  // ok

	io.run(); 
}
