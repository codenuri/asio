#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	tcp::acceptor acceptor(io, tcp::v4());

	acceptor.bind(tcp::endpoint(tcp::v4(), 7777));

	acceptor.listen();

	tcp::socket s(io);
	acceptor.accept(s);	
			// 접속 요청이 없으면 이 코드에서 대기(block)
			// 요청이 오면 s 와 client socket 을 연결

	// 이제 소켓 객체 s 를 사용해서 client 통신
	std::array<char, 1024> buf;
	std::size_t n = s.read_some(asio::buffer(buf));

	asio::write(s, asio::buffer(buf.data(), n));
}
