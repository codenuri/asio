#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	// #1. socket 생성후 서버에 접속
	tcp::socket s(io);
	s.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 7777));

	
	// #2. 서버에 데이터 전송
	std::string msg = "hello asio";

//	std::size_t n = s.write_some( asio::buffer(msg) );

	std::size_t n = asio::write(s, asio::buffer(msg));

}



