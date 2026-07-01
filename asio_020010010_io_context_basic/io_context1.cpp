#include "net_asio.h"

void foo() { log(); }
void goo() { log(); }

int main()
{
    asio::io_context io;

	asio::post(io, foo);
    asio::post(io, goo);
	asio::post(io, [](){ log(); } );

    std::cout << "-----------------\n";

	io.run();
	
    std::cout << "-----------------\n";
}

