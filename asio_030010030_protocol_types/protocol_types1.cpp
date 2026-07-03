#include "net_asio.h"

int main()
{
	auto s1 = socket(AF_INET,  SOCK_STREAM, IPPROTO_TCP);  // IPv4 주소를 사용, TCP 방식 통신용 소켓
	auto s2 = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);  // IPv6 주소를 사용, TCP 방식 통신용 소켓
	auto s3 = socket(AF_INET,  SOCK_DGRAM,  IPPROTO_UDP);  // IPv4 주소를 사용, UDP 방식 통신용 소켓
	auto s4 = socket(AF_INET6, SOCK_DGRAM,  IPPROTO_UDP);  // IPv6 주소를 사용, UDP 방식 통신용 소켓

	closesocket(s1);
	closesocket(s2);
	closesocket(s3);
	closesocket(s4);
}
