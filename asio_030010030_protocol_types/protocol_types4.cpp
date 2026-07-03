#include "net_asio.h"

template<typename Protocol> 
void asio_socket_constructor(Protocol p) {}

class tcp 
{
	int family_;

	// 핵심 #1. 생성자는 private. 외부에서 객체 안됨
	tcp(int family) : family_(family) {}
public:

	// 핵심 #2. 객체를 만들기 위한 static 멤버 함수 제공
	static tcp v4() { return tcp(AF_INET); } 
	static tcp v6() { return tcp(AF_INET6); } 
};

int main()
{
//	tcp t(AF_INET); // error

	tcp t = tcp::v4(); // ok

	asio_socket_constructor(t);
	asio_socket_constructor(tcp::v4()); 
}

