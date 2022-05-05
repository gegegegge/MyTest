#include "Request.h"
#include "Response.h"
#include "Codec.h"
#include "RequestFactory.h"
#include "RespondFactory.h"
#include "CodecFactory.h"


int main()
{
	// 请求数据编码
	// 准备请求信息
	RequestInfo info{ 1,"client","server","x00911","hello,world" };
	// 1.创建工厂类对象
	CodecFactory* factory = new RequestFactory(&info);
	// 2.得到编码对象
	Codec* codec = factory->createCodec();
	// 3.编码
	string str = codec->encodeMsg();
	// 打印序列化数据
	cout << "序列化后的请求数据:" << str << endl;
	// 4.销毁对象
	delete factory;
	delete codec;

	//请求数据解码
	// 1.创建工厂类对象
	factory = new RequestFactory(str);
	// 2.得到解码对象
	codec = factory->createCodec();
	// 3.解码
	RequestMsg* r1 = (RequestMsg*)codec->decodeMsg();
	//打印解码后的数据(利用protobuf序列化后的类来打印反序列化后的信息)
	cout <<"cmd:"<<r1->cmdtype()
		<<",clientID:"<<r1->clientid()
		<<",serverID: "<<r1->serverid()
		<<",sign:"<<r1->sign()
		<<",data:"<<r1->data()
		<<endl;
	// 4.销毁对象
	delete factory;
	delete codec;

	cout << "================================================================================"  << endl;
	
	ResponseInfo resinfo{ 1, 999, "luffy", "zoro", "change world 666 !" };
	factory = new RespondFactory(&resinfo);
	codec = factory->createCodec();
	str = codec->encodeMsg();
	cout << "序列化后的响应数据:" << str << endl;
	delete factory;
	delete codec;

	factory = new RespondFactory(str);
	codec = factory->createCodec();
	RespondMsg* r2 = (RespondMsg*)codec->decodeMsg();
	cout << "status:" << r2->rv()
		<< ",seckeyID:" << r2->seckeyid()
		<< ",clientID: " << r2->clientid()
		<< ",serverID:" << r2->serverid()
		<< ",data:" << r2->data()
		<< endl;
	delete factory;
	delete codec;

	system("pause");
	return 0;
	}