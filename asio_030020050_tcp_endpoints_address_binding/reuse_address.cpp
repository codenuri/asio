#include "net_asio.h"
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	// tcp::acceptor acceptor(io, tcp::v4());

    // acceptor.set_option(asio::socket_base::reuse_address(true));  

	// acceptor.bind(tcp::endpoint(tcp::v4(), 7777));	
	// acceptor.listen();

	// 아래 한줄이 위 4줄과 동일한 기능 수행 - 앞으로 예제는 아래 한줄 사용
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 7777));


	tcp::socket s(io);
	acceptor.accept(s);
}


