#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;
	
	// #1. socket 객체 생성
	tcp::socket s(io);
		
	// #2. socket 의 connect() 함수를 호출하여 서버에 연결
	tcp::endpoint ep(ip::make_address("127.0.0.1"), 7777);
	s.connect(ep);		
		
	// #3. 서버에 데이터(메시지) 전송
	std::string msg = "hello asio";
	asio::write(s, asio::buffer(msg));
		
	// #4. 서버에서 보낸 데이터(메시지) 수신
	std::array<char, 1024> buf;
	std::size_t n = s.read_some(asio::buffer(buf));

	// #5. 수신한 데이터(메시지) 출력
	std::cout << "echo: " << std::string_view(buf.data(), n) << '\n';
}
