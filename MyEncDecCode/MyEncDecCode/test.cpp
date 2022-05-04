#include "Codec.h"
#include "Request.h"
#include "Response.h"

//����(��̬,��������ʱ,����ָ��ָ���������)
string encodeMsg(Codec* codec)
{
	return codec->encodeMsg();
}
//����(��̬,��������ʱ,����ָ��ָ���������)
void* decodeMsg(Codec* codec)
{
	return codec->decodeMsg();
}

int main()
{
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.clientID = "OnePiecce";
	reqInfo.serverID = "Luffy";
	reqInfo.data = "��Ҫ��Ϊ������������";
	reqInfo.sign = "hahaha";
	Request req(&reqInfo);
	//����
	string reqmsg = encodeMsg(&req);
	//����
	Request req1(reqmsg);
	RequestMsg* reqMsg = (RequestMsg*)decodeMsg(&req1);
	cout << "cmdType:" << reqMsg->cmdtype()
		<< " ,clientID:" << reqMsg->clientid()
		<< " ,serverID:" << reqMsg->serverid()
		<< " ,data:" << reqMsg->data()
		<< " ,sign:" << reqMsg->sign()
		<< endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	ResponseInfo resInfo;
	resInfo.status = false;
	resInfo.seckeyID = 123;
	resInfo.clientID = "diao666";
	resInfo.serverID = "ҮҮҮ";
	resInfo.data = "���";
	Response res(&resInfo);
	//����
	string resmsg = encodeMsg(&res);
	//����
	Response res1(resmsg);
	RespondMsg* resMsg = (RespondMsg*)decodeMsg(&res1);
	cout << "status:" << resMsg->rv()
		<< ",seckeyID:" << resMsg->seckeyid()
		<< ",clientID:" << resMsg->clientid()
		<< ",serverID:" << resMsg->serverid()
		<< ",data:" << resMsg->data()
		<< endl;

	return 0;
}