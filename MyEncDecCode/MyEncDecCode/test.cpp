#include "Codec.h"
#include "Request.h"
#include "Response.h"

//编码(多态,函数传参时,父类指针指向子类对象)
string encodeMsg(Codec* codec)
{
	return codec->encodeMsg();
}
//解码(多态,函数传参时,父类指针指向子类对象)
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
	reqInfo.data = "我要成为海贼王的男人";
	reqInfo.sign = "hahaha";
	Request req(&reqInfo);
	//编码
	string reqmsg = encodeMsg(&req);
	//解码
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
	resInfo.serverID = "耶耶耶";
	resInfo.data = "你好";
	Response res(&resInfo);
	//编码
	string resmsg = encodeMsg(&res);
	//解码
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