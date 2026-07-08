#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

void on_read(const asio::error_code& ec, std::size_t bytes_transferred)
{
	std::cout << "called on_read\n";
}

int main()
{
	asio::io_context io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
	std::cout << "server: listening on 7777\n";
	tcp::socket s(io);
	acceptor.accept(s);

	std::array<char, 1024> buf;
	//----------------------------------------------
	std::cout << "start  async_read_some()\n";
	
	s.async_read_some(asio::buffer(buf), on_read);
	
	std::cout << "finish async_read_some()\n";
	//----------------------------------------------
	io.run();
}
