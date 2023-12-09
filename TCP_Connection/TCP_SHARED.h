#ifndef REMADE_SEA_BATTLE_TCP_SHARED_H
#define REMADE_SEA_BATTLE_TCP_SHARED_H

#ifdef _WIN32
#define _WIN32_WINNT _WIN32_WINNT_WIN7
	#include <winsock2.h> //for all socket programming
	#include <ws2tcpip.h> //for getaddrinfo, inet_pton, inet_ntop
	#include <stdio.h> //for fprintf, perror
	#include <unistd.h> //for close
	#include <stdlib.h> //for exit
	#include <string.h> //for memset
    #include <iostream>
	void OSInit( void )
	{
		WSADATA wsaData;
		int WSAError = WSAStartup( MAKEWORD( 2, 0 ), &wsaData );
		if( WSAError != 0 )
		{
			fprintf( stderr, "WSAStartup errno = %d\n", WSAError );
			exit( -1 );
		}
	}
	void OSCleanup( void )
	{
		WSACleanup();
	}
	#define perror(string) fprintf( stderr, string ": WSA errno = %d\n", WSAGetLastError() )
#else

#include <sys/socket.h> //for sockaddr, socket, socket
#include <sys/types.h> //for size_t
#include <netdb.h> //for getaddrinfo
#include <netinet/in.h> //for sockaddr_in
#include <arpa/inet.h> //for htons, htonl, inet_pton, inet_ntop
#include <errno.h> //for errno
#include <stdio.h> //for fprintf, perror
#include <unistd.h> //for close
#include <stdlib.h> //for exit
#include <string.h> //for memset
#include <iostream>
#endif
#include <sstream>
#include "nlohmann/json.hpp"
#include "../Player_Related/Game_Player.h"


namespace SBN
{
class TCP_SHARED
{
public:
    TCP_SHARED(const std::string port_addr,const std::string device_addr) : port_addr(port_addr.c_str()), device_addr(device_addr.c_str()) {}
    ~TCP_SHARED()=default;
            struct MSG
                   {
                        int MSG_Type=0;
                        int x=0;
                        int y=0;
                        bool bool_recvd=false;
                        std::string message;
                   };
              enum MSG_TYPE
                   {
                        Init_Message,   //0     //initialization
                        Directd_Message,//1     //DIRECTCHAT received from OPONENT
                        Your_Turn,      //2      //Transfer the turn to the other party
                        Attack_received,//3      //attack received format: "AT,y.x"
                        Tile_Info,      //4      //RECV tile info from opponent TI,y.x.true/false
                        Game_Over       //5     //Game over send by or to
                   };
               MSG default_message();
       std::string serialize_Tostring(MSG msgPacket);
               MSG deserialize_ToMSG(std::string  str);
       std::string recv(int internet_socket);
              void send(int internet_socket,std::string StringData_ToBe_send);

protected:
               int number_of_bytes_received;
               int number_of_bytes_send;
               const char * port_addr ="24042";
               const char * device_addr ="127.0.0.1";
};
}
             using MSG_TYPE = SBN::TCP_SHARED::MSG_TYPE;
             using MSG_STRUCT = SBN::TCP_SHARED::MSG;
#endif //REMADE_SEA_BATTLE_TCP_SHARED_H
