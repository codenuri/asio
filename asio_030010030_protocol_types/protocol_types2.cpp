#include "net_asio.h"

class protocol 
{
	int family;	// 주소 종류
	int type;	// 소켓 타입
	int proto;	// protocol
public:
	protocol(int af, int type, int proto ) 
		: family(af), type(type), proto(proto) {}
};

void socket(protocol p) {}

int main()
{
	protocol tcp(AF_INET,  SOCK_STREAM, IPPROTO_TCP);
	protocol udp(AF_INET,  SOCK_DGRAM,  IPPROTO_UDP);

	socket(tcp); // ok
	socket(udp); // ok
}



// template<typename protocol>
// class endpoint {};

// endpoint<tcp> ep1; // error
// endpoint<udp> ep2; // error
