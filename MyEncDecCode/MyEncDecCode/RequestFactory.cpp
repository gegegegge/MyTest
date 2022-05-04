#include "RequestFactory.h"

//½âÂë
RequestFactory::RequestFactory(string enc)
{
	m_flag = false;
	m_encStr = enc;
}

//±àÂë
RequestFactory::RequestFactory(RequestInfo* info)
{
	m_flag = true;
	m_info = info;
}

Codec* RequestFactory::createCodec()
{
	Codec* codec = NULL;
	if (m_flag == true)
	{
		codec = new Request(m_info);
	}
	else
	{
		codec = new Request(m_encStr);
	}
	return codec;
}

RequestFactory::~RequestFactory()
{
}