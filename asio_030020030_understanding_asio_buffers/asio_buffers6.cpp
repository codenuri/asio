#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;
	
	tcp::socket s(io);	
	s.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 7777));	
		
	char mbuf[32] = {0};
	const char cbuf[32] = {0};      

	asio::write(s, asio::buffer(mbuf)); // ok
	asio::write(s, asio::buffer(cbuf)); // ok
	asio::read(s,  asio::buffer(mbuf)); // ok
	asio::read(s,  asio::buffer(cbuf)); // error


	std::array<asio::const_buffer, 2> arr = { asio::buffer(mbuf), asio::buffer(cbuf) };

	asio::write(s, arr);	// 버퍼 2개의 내용을 전송	
}
