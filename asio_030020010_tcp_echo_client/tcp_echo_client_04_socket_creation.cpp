#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;

	// 서버 주소와 Port 를 담는 endpoint 타입 객체
	tcp::endpoint ep(ip::make_address("127.0.0.1"), 7777);

	// #1. 
	tcp::socket s1(io, tcp::v4()); 
	s1.connect(ep);

	// #2.
	tcp::socket s2(io); 
	s2.open(tcp::v4()); 
	s2.connect(ep);
		
	// #3.
	tcp::socket s3(io);	
	s3.connect(ep);		


	

	// 강의에서 사용하는 코딩 스타일
	tcp::socket s(io);
	s.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 7777));
}

