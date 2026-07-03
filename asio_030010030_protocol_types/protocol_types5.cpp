#include "net_asio.h"

int main()
{
	asio::io_context io;

	asio::ip::tcp::socket s(io, asio::ip::tcp::v4() );	


	// endpoint : IP 주소 와 Port 번호 보관하는 타입
	asio::ip::tcp::endpoint ep1( asio::ip::make_address("0.0.0.0"), 7777 ); // 일반적인 코드

	asio::ip::tcp::endpoint ep2( asio::ip::tcp::v4(), 7777 ); 
							// 1번째 인자로 주소가 아닌 protocol 전달(주소에 대한 정보는 없음)
							// (AF_INET, SOCK_STREAM, IPPROTO_TCP 정보만 있음)
							// 이 경우 내부적으로 "0.0.0.0" 주소를 사용하기로 약속
}