#include "net_asio.h"

void foo() { log(); }
void goo() { sleep(3s); }
void hoo() { log_and_sleep(3s); }

int main()
{
	foo();
	goo();
	hoo();
}


