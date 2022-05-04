#pragma once
#include "Codec.h"
#include "msg.pb.h"

struct ResponseInfo
{
	int status;
	int seckeyID;
	string clientID;
	string serverID;
	string data;
};

class Response:
	public Codec
{
public:
	Response();

	Response(string encstr);

	Response(ResponseInfo *info);

	void initMessage(string encstr);

	void initMessage(ResponseInfo *info);

	string encodeMsg();

	void* decodeMsg();

	~Response();

private:
	string m_encStr;
	RespondMsg m_msg;
};

