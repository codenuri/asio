#include "net_asio.h"

int main()
{
	// #1. 일반적인 코딩 관례
	asio::ip::address a1 = asio::ip::make_address("127.0.0.1");
	asio::ip::address a2 = asio::ip::make_address("::1");

	// #2. 특별한 의미의 IP 는 static 멤버 함수 사용 가능
	asio::ip::address a3 = asio::ip::address_v4::loopback(); // 127.0.0.1
	asio::ip::address a4 = asio::ip::address_v6::loopback(); // ::1
	asio::ip::address a5 = asio::ip::address_v4::any(); 	 // 0.0.0.0
	asio::ip::address a6 = asio::ip::address_v6::any(); 	 // ::

	// #3. 문자열형태의 ip 주소를 전달받는 생성자는 제공안함
//	asio::ip::address a7("127.0.0.1"); // error

	// #4. address -> std::string 변환
	std::string s1 = a5.to_string();
	std::string s2 = a6.to_string();

	// #5. IP 주소의 버전 확인
	std::cout << a5.is_v4() << '\n';
	std::cout << a5.is_v6() << '\n';
}



