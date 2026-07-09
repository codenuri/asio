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

	void start(  )
    {
		std::shared_ptr<session> sp(this);
		
      	std::thread t( [this, sp]() { do_read();} );
      	t.detach();
    }	
};

int main()
{
    {
        auto sp = std::make_shared<session>(); 

        sp->start(  );

    } // <= sp 파괴

    getchar(); 
}
