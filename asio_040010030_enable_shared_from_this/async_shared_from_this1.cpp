#include "net_asio.h" 

class session 
{
    asio::steady_timer timer;
public:
    session(asio::io_context& io) : timer(io) { std::cout << "session()\n"; }
    ~session() { std::cout << "~session()\n"; }

    void start()
    {
        timer.expires_after(5s);

        timer.async_wait( [this](const asio::error_code& ec) { foo(ec); } );
			// 1. 대기 하지 않고, 바로 반환
			// 2. main 으로 돌아가면 sp 파괴되어 session 객체 파괴
			// 3. session 객체가 파괴 되면서, 멤버 데이터인 timer 객체도 같이 파괴
			//    => 타이머의 비동기 요청이 취소 되고 handler 인자로 error 전달
    }

    void foo(const asio::error_code& ec)
    {
        if (ec) std::cout << "error : " << ec.message() << '\n';
        else    std::cout << "ok. foo\n";
    }
};

int main()
{
    asio::io_context io;
    {
        auto sp = std::make_shared<session>(io);
        sp->start();
    }

    io.run(); 
}