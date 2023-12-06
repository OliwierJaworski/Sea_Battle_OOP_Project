#include "TCP_SHARED.h"
using namespace SBN;
std::string TCP_SHARED::serialize_Tostring(MSG& msgPacket)
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

TCP_SHARED::MSG TCP_SHARED::deserialize_ToMSG(std::string & str)
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