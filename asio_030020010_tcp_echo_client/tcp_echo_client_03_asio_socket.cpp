// asio 라이브러리가 제공하는 클래스(대략적인 개념을 위한 코드)
template<typename Protocol>
class basic_stream_socket
{
    int    sockfd = invalid_socket; // linux
    SOCKET sockfd = INVALID_SOCKET; // windows
public:
    // #1. 생성자에서 io_context 와 연결과 가능한 경우 native socket 생성
    basic_stream_socket(io_context& io, Protocol protocol)
    {
        // io_context 와 연결,  native socket 도 생성
        sockfd = ::socket(...);
    }
    basic_stream_socket(io_context& io)
    {
        // io_context 와 연결, 아직 native socket은 생성 안됨
    }

    // #2. native socket handle에 대한 RAII
    ~basic_stream_socket()
    {
        if (sockfd != invalid_socket)
        {
            // Linux   : ::close(sockfd)
            // Windows : ::closesocket(sockfd)
        }
    }

    // #3. socket 관련 기본 함수에 대한 wrapper 멤버 함수
    //     => 내부적으로 C Socket API 를 다시 호출
    void connect(...) { ::connect(sockfd, ...); }
    std::size_t write_some(...) { return ::send(sockfd, ...); }
    std::size_t read_some(...)  { return ::recv(sockfd, ...); }

    // #4. ASIO 핵심 기능: io_context 와 연동되는 비동기 I/O
	// => async_connect(), async_write_some(), async_read_some()    
};
class tcp
{
public:

	typedef basic_stream_socket<tcp> socket;
    //...
};
int main()
{
    asio::io_context io;
	
    tcp::socket s(io, tcp::v4());

	s.connect(...);
	s.write_some(...);
	s.read_some(...);
}
