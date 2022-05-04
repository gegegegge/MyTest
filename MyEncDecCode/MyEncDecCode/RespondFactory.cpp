#include "RespondFactory.h"

//½âÂë
RespondFactory::RespondFactory(string enc)
{
	m_flag = false;
	m_encStr = enc;
}

//±àÂë
RespondFactory::RespondFactory(ResponseInfo *info)
{
	m_flag = true;
	m_info = info;
}

Codec* RespondFactory::createCodec()
{
	Codec* codec = NULL;
	if (m_flag == true)
	{
		codec = new Response(m_info);
	}
	else
	{
		codec = new Response(m_encStr);
	}
	return codec;
}

RespondFactory::~RespondFactory()
{
}