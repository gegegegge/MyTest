#include "Request.h"
#include "Response.h"
#include "Codec.h"
#include "RequestFactory.h"
#include "RespondFactory.h"
#include "CodecFactory.h"


int main()
{
	// �������ݱ���
	// ׼��������Ϣ
	RequestInfo info{ 1,"client","server","x00911","hello,world" };
	// 1.�������������
	CodecFactory* factory = new RequestFactory(&info);
	// 2.�õ��������
	Codec* codec = factory->createCodec();
	// 3.����
	string str = codec->encodeMsg();
	// ��ӡ���л�����
	cout << "���л������������:" << str << endl;
	// 4.���ٶ���
	delete factory;
	delete codec;

	//�������ݽ���
	// 1.�������������
	factory = new RequestFactory(str);
	// 2.�õ��������
	codec = factory->createCodec();
	// 3.����
	RequestMsg* r1 = (RequestMsg*)codec->decodeMsg();
	//��ӡ����������(����protobuf���л����������ӡ�����л������Ϣ)
	cout <<"cmd:"<<r1->cmdtype()
		<<",clientID:"<<r1->clientid()
		<<",serverID: "<<r1->serverid()
		<<",sign:"<<r1->sign()
		<<",data:"<<r1->data()
		<<endl;
	// 4.���ٶ���
	delete factory;
	delete codec;

	cout << "================================================================================"  << endl;
	
	ResponseInfo resinfo{ 1, 999, "luffy", "zoro", "change world 666 !" };
	factory = new RespondFactory(&resinfo);
	codec = factory->createCodec();
	str = codec->encodeMsg();
	cout << "���л������Ӧ����:" << str << endl;
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