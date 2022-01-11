#include"MyQQapi.h"


MyQQApi::MyQQApi ()
{

	hdll = LoadLibrary ("MyQQApi.DLL");
	Api_SendMsgEx = (_SendMsgEx)GetProcAddress (hdll, "Api_SendMsgEx");
	Api_OutPut = (_OutPut)GetProcAddress (hdll, "Api_OutPut");
}

MyQQApi::~MyQQApi ()
{
	FreeLibrary (hdll);
}

void MyQQApi::SendMsgEx (text BotQQ, int namebat, int type, text group, text QQ, text msg, int id) {


	if (Api_SendMsgEx == NULL) {
		MessageBoxA (GetForegroundWindow (), "动态链接库指定命令\" Api_SendMsgEx\"不存在", "提示", 0);
		return;
	}
	else
	{
		Api_SendMsgEx (BotQQ, namebat, type, group, QQ, msg, id);
	}

}
//void MyQQApi::Api_OutPut (text msg) {
//
//
//
//	if (OutPut == NULL) {
//		MessageBoxA (GetForegroundWindow (), "动态链接库指定命令\"Api_OutPut\"不存在", "提示", 0);
//		return;
//	}
//	else
//	{
//		OutPut (msg);
//	}
//
//	return;
//}




MyQQApi::Output MyQQApi::OutPut () {


	return Output ();
}

MyQQApi::Output MyQQApi::OutPut (text msg) {

	
	return Output ();
}