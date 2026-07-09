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
        auto self = shared_from_this(); // session 객체가 delete 되지 않게 하기 위해 참조 계수 증가

		// 비동기 수신 요청. 완료되면 do_write() 호출
        socket.async_read_some(asio::buffer(buffer), [this, self](const std::error_code& ec, std::size_t bytes)
            {
                if (!ec) { do_write(bytes); }
            });
    }

    void do_write(std::size_t bytes)
    {
        auto self = shared_from_this();

		// 비동기 전송 요청. 완료되면 do_read() 다시 호출 ( 2개 함수가 무한히 반복 )
		// => R/W 작업에서 에러 발생(클라이언트 닫힘등)시 더이상의 비동기 요청이 없으므로 종료
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
        acceptor.async_accept( [this](const std::error_code& ec, tcp::socket socket) {

						if (!ec)
						{
							// client 가 접속한 경우
							// 1. session 객체를 생성후 start() 호출
							// 2. 수명 관리를 위해 std::shared_ptr 사용
							std::make_shared<session>(std::move(socket))->start();
						}

						do_accept();
							// 다시 비동기 accept 요청
					});
    }
};

int main()
{
    try
    {
        asio::io_context io;

        async_echo_server server(io, 7777);

        io.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

