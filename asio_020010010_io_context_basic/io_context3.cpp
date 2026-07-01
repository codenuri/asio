#include "net_asio.h"

void foo() { log_and_sleep(1s); }
void goo() { log_and_sleep(1s); }

int main()
{
    asio::io_context io;

	for( int i = 0; i < 5; i++ ) 
	{
		asio::post(io, foo);
   	 	asio::post(io, goo);
	}

	std::jthread t1( [&io](){ io.run(); } );
	std::jthread t2( [&io](){ io.run(); } );

	io.run();	
}
