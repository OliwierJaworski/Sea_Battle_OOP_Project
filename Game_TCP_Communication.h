#ifndef REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H
#define REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
{
WSADATA wsaData;

if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
{
fprintf(stderr, "WSAStartup failed.\n");
exit(1);
}

if (LOBYTE(wsaData.wVersion) != 2 ||
HIBYTE(wsaData.wVersion) != 2)
{
fprintf(stderr,"Versiion 2.2 of Winsock is not available.\n");
WSACleanup();
exit(2);
}
#else

#endif

class Game_TCP_Communication
{

};


#endif //REMADE_SEA_BATTLE_GAME_TCP_COMMUNICATION_H

