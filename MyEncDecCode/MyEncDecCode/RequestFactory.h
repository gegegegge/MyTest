#pragma once
#include "CodecFactory.h"
#include "Request.h"
#include "Codec.h"

using namespace std;

class RequestFactory:
	public CodecFactory
{
public:
	RequestFactory(string enc);
	RequestFactory(RequestInfo *info);
	Codec* createCodec();
	~RequestFactory();

private:
	bool m_flag;
	string m_encStr;
	RequestInfo *m_info;
};

