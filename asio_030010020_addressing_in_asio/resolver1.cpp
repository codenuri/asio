#include "net_asio.h"

int main()
{
    asio::io_context io;

    asio::ip::tcp::resolver resolver(io);
	
    asio::ip::tcp::resolver::results_type rets = 
							resolver.resolve("isocpp.org", "http");

//	for (const asio::ip::basic_resolver_entry<asio::ip::tcp>& e : rets)
    for (const auto& e : rets)
    {
        std::cout << e.host_name()    << ", "
            	  << e.service_name() << ", "
            	  << e.endpoint()     << '\n';
    }
}
