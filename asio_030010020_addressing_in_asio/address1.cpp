#include "net_asio.h"

int main()
{
	asio::ip::address_v4 a1 = asio::ip::make_address_v4("127.0.0.1");
	asio::ip::address_v6 a2 = asio::ip::make_address_v6("::1");

	asio::ip::address a3 = asio::ip::make_address("127.0.0.1"); // IPv4
	asio::ip::address a4 = asio::ip::make_address("::1");		// IPv6

	std::cout << a1 << '\n';
	std::cout << a2 << '\n';
	std::cout << a3 << '\n';
	std::cout << a4 << '\n';
}
