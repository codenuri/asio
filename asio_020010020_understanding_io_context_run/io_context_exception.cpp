#include "net_asio.h"

void foo() { throw std::exception(); }

int main()
{
	asio::io_context io;

	asio::post(io, foo);	

	try
	{
		io.run();	
	}
	catch( std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
