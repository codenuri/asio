#include "net_asio.h"

class session 
{
    int buffer = 100;
public:
    session()  { std::cout << "session()\n";  }
    ~session() { std::cout << "~session()\n"; }

    void do_read()
    {
        std::cout << "start  do_read\n";
        sleep(5s);
        buffer = 10;
        std::cout << "finish do_read\n";
    }
	void start()
    {
//		do_read();

      	std::thread t( [this]() { do_read();} );
      	t.detach();
    }	
};

int main()
{
    {
        auto sp = std::make_shared<session>(); // session 객체 생성

        sp->start();

    }   // <= session 객체 파괴

    getchar(); // 종료 방지
}
