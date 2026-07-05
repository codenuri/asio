#include "net_asio.h" 

struct const_buffer
{
	const void* data;
	std::size_t size;

	const_buffer(const void* d, std::size_t s) : data(d), size(s) {}
};

struct mutable_buffer
{
	void* data;
	std::size_t size;

	mutable_buffer(void* d, std::size_t s) : data(d), size(s) {}

	// mutable_buffer => const_buffer 의 
	// 암시적 변환 허용을 위한 변환 연산자
	operator const_buffer() const { return const_buffer(data, size); }
};

mutable_buffer asio_buffer(std::string& s)
{
	return mutable_buffer(s.data(), s.size());
}

const_buffer asio_buffer(const std::string& s)
{
	return const_buffer(s.data(), s.size());
}

int main()
{
	std::string       ms = "hello asio"; // mutable string
	const std::string cs = "hello asio"; // const   string

	mutable_buffer mb1 = asio_buffer(ms);
	const_buffer   cb1 = asio_buffer(cs);

	const_buffer   cb2 = asio_buffer(ms); // ok.    반환 값은 mutable_buffer 이지만, const_buffer로 암시적 변환이 허용됨
//	mutable_buffer mb2 = asio_buffer(cs); // error. 반환 값은 const_buffer,		   mutable_buffer로 암시적 변환이 허용되지 않음
}
