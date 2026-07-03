#include "net_asio.h"

int main()
{
	// 지금 까지의 예제 코드 - 완전한 이름(qualified name) 사용
	asio::io_context io1;
	asio::ip::tcp::socket   s1( io1, asio::ip::tcp::v4());	
	asio::ip::tcp::endpoint e1( asio::ip::make_address("127.0.0.1"), 7777);	


	// 다음 강의 부터 사용하는 코딩 스타일
	namespace ip = asio::ip; // asio::ip      대신 "ip"  사용 	namespace 문법
	using asio::ip::tcp;	 // asio::ip::tcp 대신 "tcp" 사용	using alias 문법

	asio::io_context io2;	// asio 자체는 생략 안됨

	tcp::socket   s2( io2, tcp::v4());	
	tcp::endpoint e3( ip::make_address("127.0.0.1"), 7777);	
}
