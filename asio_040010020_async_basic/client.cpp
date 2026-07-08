#include "net_asio.h" 
using asio::ip::tcp;
namespace ip = asio::ip;

int main()
{
    asio::io_context io;

    tcp::socket socket(io);
    socket.connect(tcp::endpoint(asio::ip::make_address("127.0.0.1"), 7777));

	//------------------------------------------------------
    std::cout << "start  asio::write\n";
    
	sleep(5s);        
    asio::write(socket, asio::buffer("hello asio"));

    std::cout << "finish asio::write\n";
	//------------------------------------------------------
}
