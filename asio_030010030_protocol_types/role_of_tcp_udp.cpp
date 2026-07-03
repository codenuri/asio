#include "net_asio.h"

int main()
{
	asio::io_context io;

	asio::ip::tcp::socket   s1(io, asio::ip::tcp::v4());	
	asio::ip::tcp::acceptor a1(io);
	asio::ip::tcp::resolver r1(io);	
	
	asio::ip::udp::socket   s2(io, asio::ip::udp::v6());
	asio::ip::udp::resolver r2(io);

	asio::ip::tcp::endpoint e1;	
	asio::ip::udp::endpoint e2;

	asio::ip::basic_endpoint<asio::ip::tcp> e3;	// e1 과 동일 타입
	asio::ip::basic_endpoint<asio::ip::udp> e4;	// e2 와 동일 타입
}