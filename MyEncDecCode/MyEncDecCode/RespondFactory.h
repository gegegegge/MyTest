#pragma once
#include "CodecFactory.h"
#include "Response.h"
#include "Codec.h"

using namespace std;

class RespondFactory:
	public CodecFactory
{
public:
	RespondFactory(string enc);
	RespondFactory(ResponseInfo *info);
	Codec* createCodec();
	~RespondFactory();

private:
	bool m_flag;
	string m_encStr;
	ResponseInfo *m_info;
};

