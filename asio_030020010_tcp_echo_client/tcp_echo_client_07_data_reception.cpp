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
	std::size_t n1 = asio::write(s, asio::buffer(msg));


	// #3. 서버에서 보내준 데이터 수신
//	char buf[1024];

	std::array<char, 1024> buf;

//	std::size_t n2 = asio::read(s, asio::buffer(buf, msg.size()));	// 1
	std::size_t n2 = s.read_some(  asio::buffer(buf));				// 2


	std::cout << "echo: " << std::string_view(buf.data(), n2) << '\n';
}
