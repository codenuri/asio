#include "net_asio.h"

int main()
{
	// #1. 관례적으로 사용되는 코딩 스타일
	asio::ip::tcp::endpoint ep1(asio::ip::make_address("127.0.0.1"), 7777);

	// #2. 아래 3줄은 모두 "0.0.0.0:7777" 을 가지는 endpoint 객체 생성
	asio::ip::tcp::endpoint ep2(asio::ip::make_address("0.0.0.0"), 7777);
	asio::ip::tcp::endpoint ep3(asio::ip::address_v4::any(), 7777);
	asio::ip::tcp::endpoint ep4(asio::ip::tcp::v4(), 7777); // tcp 강의에서 자세히 설명

	// #3. IP 주소와 Port 번호를 얻는 방법
	asio::ip::address   addr = ep4.address();
	asio::ip::port_type port = ep4.port();

	// #4. std::cout 으로 출력 가능
	std::cout << ep4 << '\n';
}

