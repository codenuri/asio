#include "net_asio.h"

asio::awaitable<void> foo(asio::io_context& io)
{
	std::cout << "[3]\n";
	
	asio::steady_timer t(io, 5s);

	co_await t.async_wait(asio::use_awaitable);
									
    std::cout << "[4]\n";
}
int main()
{
    asio::io_context io;

	std::cout << "[1]\n";

    asio::co_spawn(io, foo(io), asio::detached);
	
	std::cout << "[2]\n";
    
	io.run();	
}