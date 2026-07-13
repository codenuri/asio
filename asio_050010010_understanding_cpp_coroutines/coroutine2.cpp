#include <iostream>
#include <coroutine>

class task
{
public:
    class promise_type
    {
    public:
        task get_return_object() { return task{ std::coroutine_handle<promise_type>::from_promise(*this) }; }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend()   noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
    task(const std::coroutine_handle<promise_type> coro) : coro{ coro } {}

    std::coroutine_handle<promise_type> coro;
};

task foo()
{
    std::cout << "foo #1\n";
    co_await std::suspend_always{};

    std::cout << "foo #2\n";		
	co_await std::suspend_always{};	

    std::cout << "foo #3\n";
}

int main()
{
    task t = foo();		

    std::cout << "main #1\n";

    t.coro.resume();	
    std::cout << "main #2\n";

    t.coro.resume();	
    std::cout << "main #3\n";

    t.coro.resume();

    if (t.coro.done())
    {
        t.coro.destroy();
    }
}