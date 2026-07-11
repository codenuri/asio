#include "net_asio.h"
using asio::ip::tcp;
namespace ip = asio::ip;

class session : public std::enable_shared_from_this<session>
{
    tcp::socket socket;
    std::array<char, 1024> buffer;
public:
    session(tcp::socket socket) : socket(std::move(socket)) { std::cout << "session()\n"; }
    ~session() { std::cout << "~session()\n"; }

    void start() { do_read(); }

private:
    void do_read()
    {
        log();
        auto self = shared_from_this(); 
        socket.async_read_some(asio::buffer(buffer), [this, self](const std::error_code& ec, std::size_t bytes)
            {
                if (!ec) { do_write(bytes); }
            });
    }

    void do_write(std::size_t bytes)
    {
        log();
        auto self = shared_from_this();
        asio::async_write(socket, asio::buffer(buffer, bytes), [this, self](const std::error_code& ec, std::size_t)
            {
                if (!ec) { do_read(); }
            });
    }
};

class async_echo_server
{
    tcp::acceptor acceptor;
public:
    async_echo_server(asio::io_context& io, short port) : acceptor(io, tcp::endpoint(tcp::v4(), port))
    {
        std::cout << "server : listenning in " << port << '\n';
        do_accept();
    }

private:
    void do_accept()
    {
        log();
        acceptor.async_accept([this](const std::error_code& ec, tcp::socket socket) {

            if (!ec)
            {
                std::make_shared<session>(std::move(socket))->start();
            }
            do_accept();
            });
    }
};

int main()
{
    try
    {
        asio::io_context io;
        async_echo_server server(io, 7777);

		std::vector<std::thread> v;		
		
		for(int i = 0; i < 3; i++ )
		{
			v.emplace_back([&io]{ io.run();});
		}		
		io.run();

		
		for(auto& t: v)
			t.join();        
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
