#pragma once
#include "Codec.h"
#include "msg.pb.h"

struct RequestInfo
{
	int cmd;
	string	clientID;
	string	serverID;
	string	sign;
	string	data;
};

class Request:
	public Codec
{
public:
	Request();

	Request(string encstr);

	Request(RequestInfo *info);

	void initMessage(string encstr);

	void initMessage(RequestInfo *info);

	string encodeMsg();

	void*decodeMsg();

	~Request();

private:
	string m_encStr;
	RequestMsg m_msg;
};

