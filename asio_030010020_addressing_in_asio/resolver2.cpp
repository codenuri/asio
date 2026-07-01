#include "net_asio.h"

int main()
{
    asio::io_context io;
	
    asio::ip::tcp::resolver resolver(io);

    auto ret1 = resolver.resolve("isocpp.org",    "http"); // ok
    auto ret2 = resolver.resolve("localhost", 	  "80");   // ok
    auto ret3 = resolver.resolve("104.21.40.206", "80");   // ok

//  auto ret4 = resolver.resolve("http://isocpp.org", "80"); // run-time error. exception
	
	// IPv4/v6 버전의 주소만 얻는 방법
    auto ret5 = resolver.resolve(asio::ip::tcp::v4(), "isocpp.org", "http"); // ok
//  auto ret6 = resolver.resolve(asio::ip::tcp::v6(), "isocpp.org", "http"); // exception   	
}


