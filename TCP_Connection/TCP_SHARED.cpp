#include "TCP_SHARED.h"
using namespace SBN;
std::string TCP_SHARED::serialize_Tostring(MSG msgPacket)
{
    std::ostringstream oss;
    nlohmann::json j;
    j["MSG_Type"] = msgPacket.MSG_Type;
    j["x"] = msgPacket.x;
    j["y"] = msgPacket.y;
    j["bool_recvd"] = msgPacket.bool_recvd;
    j["message"] = msgPacket.message;
    oss << j;
    return to_string(j);
}

TCP_SHARED::MSG TCP_SHARED::deserialize_ToMSG(std::string  str)
{
    MSG msg;
    nlohmann::json j= nlohmann::json::parse(str);
    msg.MSG_Type =j["MSG_Type"];
    msg.x = j["x"];
    msg.y = j["y"];
    msg.bool_recvd = j["bool_recvd"];
    msg.message = j["message"];
    return msg;
}
std::string TCP_SHARED::recv(int internet_socket)
{
    number_of_bytes_received = 0;
    char buffer[1000];
    number_of_bytes_received = ::recv(internet_socket, buffer, (sizeof buffer) - 1, 0);
    if (number_of_bytes_received == -1)
    {
        perror("recv");
    } else {
        buffer[number_of_bytes_received] = '\0';
        printf("Received : %s\n", buffer);
    }
    std::string buffered_string =buffer;
    return buffered_string;
}
void TCP_SHARED::send(int internet_socket,std::string StringData_ToBe_send)
{

    number_of_bytes_send = 0;
    std::cout<< "data to be send :" << StringData_ToBe_send <<std::endl;
    number_of_bytes_send = ::send(internet_socket, StringData_ToBe_send.c_str(), StringData_ToBe_send.size(), 0);
    if (number_of_bytes_send == -1)
    {
        perror("send");
    }
}
MSG_STRUCT TCP_SHARED::default_message()
{
    MSG_STRUCT msg;
    msg.MSG_Type=IN;
    msg.bool_recvd= true;
    return msg;
}