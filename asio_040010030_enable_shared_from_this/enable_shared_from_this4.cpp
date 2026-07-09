#include "net_asio.h"

class session : public std::enable_shared_from_this<session>
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
	void start(  )
    {
		auto sp = shared_from_this();
					// 기반 클래스인 std::enable_shared_from_this 
					// 에서 상속받는 멤버 함수
		
      	std::thread t( [this, sp]() { do_read();} );
      	t.detach();
    }	
};
int main()
{
    {
        auto sp = std::make_shared<session>(); 

        sp->start();
    } 

    getchar(); 
}

