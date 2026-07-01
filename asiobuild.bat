cls

@if "%~1"=="" (
    echo usage: asiobuild source.cpp
    exit /b 1
)


@echo [101mbuilding "%*" [0m

@g++ -std=c++20 -I C:/asio-1.36.0/include -I ./..  %*  -lws2_32 -lmswsock -lwinpthread -o "%~n1.exe"

@if %ERRORLEVEL% EQU 0 (
	@echo [101mrunning  "%~n1.exe" [0m
	"%~n1.exe"
	@del "%~n1.exe"
)
