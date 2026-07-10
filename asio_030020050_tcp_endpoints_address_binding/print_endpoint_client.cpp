#include "net_asio.h" 
namespace ip = asio::ip;
using asio::ip::tcp;

int main()
{
	asio::io_context io;
	
	tcp::socket s(io, tcp::v4());

	s.connect(tcp::endpoint(ip::make_address("127.0.0.1"), 7777));	

	std::cout << "after connect local  ip/port : " << s.local_endpoint() << '\n';
	std::cout << "after connect remote ip/port : " << s.remote_endpoint() << '\n';
}
