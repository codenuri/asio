#include "net_asio.h"

int main()
{
	// #1.
	try
	{
		auto a1 = asio::ip::make_address("abc");
	}
	catch (const asio::system_error& e)
	{
		std::cerr << "error: " << e.what() << '\n';
	}

	// #2.
	asio::error_code ec;
	auto a2 = asio::ip::make_address("abc", ec);

	if (ec)
		std::cerr << "error: " << ec.message() << '\n';
	else
		std::cout << "address: " << a2 << std::endl;
}
