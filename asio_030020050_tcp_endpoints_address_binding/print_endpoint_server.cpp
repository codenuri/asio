#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	tcp::acceptor acceptor(io, tcp::v4());
	acceptor.bind(tcp::endpoint(tcp::v4(), 7777));	// "0.0.0.0:7777"
	acceptor.listen();

	// #1. 대기 소켓의 local IP/PORT 출력
	std::cout << "listen socket local ip/port : " << acceptor.local_endpoint() << '\n';

	while(true)
	{
		tcp::socket s(io);
		acceptor.accept(s);

		// #2. 연결된 소켓의 local IP/PORT, remote IP/PORT 출력
		std::cout << "accepted socket local  ip/port : " << s.local_endpoint() << '\n';
		std::cout << "accepted socket remote ip/port : " << s.remote_endpoint() << '\n';
	}
}


