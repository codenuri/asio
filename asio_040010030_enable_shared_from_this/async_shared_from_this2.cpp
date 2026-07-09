#include "net_asio.h" 

class session : public std::enable_shared_from_this<session>
{
    asio::steady_timer timer;
public:
    session(asio::io_context& io) : timer(io) { std::cout << "session()\n"; }
    ~session() { std::cout << "~session()\n"; }

    void start()
    {
        timer.expires_after(5s);

        auto self = shared_from_this();

        timer.async_wait( [this, self](const asio::error_code& ec) { foo(ec); } );
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