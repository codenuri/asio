#include "net_asio.h"

class udp 
{
	int family_;
public:
	udp(int family) : family_(family) {}
	
	int protocol() const { return IPPROTO_UDP;}
	int type() const     { return SOCK_DGRAM;}
	int family() const   { return family_; }
};

class tcp 
{
	int family_;	// 주소 종류(AF_INET, AF_INET6, ...)
public:
	tcp(int family) : family_(family) {}

	int protocol() const { return IPPROTO_TCP;}
	int type() const     { return SOCK_STREAM;}
	int family() const   { return family_; }
};




// tcp, udp 가 다른 타입이므로 인자로 받을때는 template 사용
template<typename Protocol> 
void asio_socket_constructor(Protocol p) 
{
	// C socket API 사용시 필요한 데이타
	int type   = p.type();     // 소켓 타입
	int pro    = p.protocol(); // 프로토콜 종류
	int family = p.family();   // 주소체계 종류

	// 위 데이터를 C socket() 함수로 전달
}

template<typename Protocol> class endpoint {};

int main()
{
	tcp t4(AF_INET);
	tcp t6(AF_INET6);
	udp u4(AF_INET);
	udp u6(AF_INET6);

	asio_socket_constructor(t4);
	asio_socket_constructor(u4);
	
	endpoint<tcp> ep1;
	endpoint<udp> ep2;
}