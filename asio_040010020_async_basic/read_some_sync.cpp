#include "net_asio.h" 

namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));
	std::cout << "server: listening on 7777\n";
	tcp::socket s(io);
	acceptor.accept(s);

	std::array<char, 1024> buf;
	//---------------------------------------------
	std::cout << "start  read_some()\n";

	std::size_t n = s.read_some(asio::buffer(buf));

	std::cout << "finish read_some()\n";
	//---------------------------------------------
}
