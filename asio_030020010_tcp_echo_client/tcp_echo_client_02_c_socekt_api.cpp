// C Socket API 를 사용한 tcp echo client 의 기본 구조 
// => 설명을 위한 코드, 컴파일 안됨.

int main()
{
	// #1. 소켓 생성
	auto sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 이후 네트워크 통신 관련 작업을 수행하는 
	// 대부분의 함수(C 기반 Socket API)는 인자로 sockfd 전달
	
	// #2. 서버에 접속
	connect(sockfd, 서버주소와 포트번호);

	// #3. 서버에 데이터 전달
	send(sockfd, 전송할데이타);

	// #4. 서버에서 오는 데이터 수신
	recv(sockfd, 수신할 버퍼);

	// #5. 소켓 닫기
	close(sockfd);		// linux
	closesocket(sockfd);// windows
}