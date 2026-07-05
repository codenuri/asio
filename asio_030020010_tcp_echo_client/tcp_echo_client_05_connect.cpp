#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	tcp::socket s(io);
	
	s.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 7777));

	// 서버 접속후 바로 종료되는 코드
}





