#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	tcp::acceptor acceptor(io, tcp::v4());
	acceptor.bind(tcp::endpoint(tcp::v4(), 7777));
	acceptor.listen();
	std::cout << "server: listening on 7777\n";


	while(true) 
	{
		tcp::socket s(io);
		acceptor.accept(s);	
		std::cout << "server: client connected\n";

		std::array<char, 1024> buf;
		std::size_t n = s.read_some(asio::buffer(buf));
		asio::write(s, asio::buffer(buf.data(), n));
	}

}
