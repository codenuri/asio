#include "net_asio.h"

int main()
{
	asio::io_context io;
	asio::ip::tcp::resolver resolver(io);

	try
	{
		auto ret1 = resolver.resolve("abc", "http");
	}
	catch (const asio::system_error& e)
	{
		std::cerr << "error: " << e.what() << '\n';
	}

	asio::error_code ec;
	auto ret2 = resolver.resolve("abc", "http", ec);

	if (ec)
		std::cerr << "error: " << ec.message() << '\n';
	else
	{
		// success resolver.resolve(...)
	}
}