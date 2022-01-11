#ifndef _MYQQAPI
#define _MYQQAPI
#include<windows.h>
#include<string>

#define string std::string
#define text const char*



class MyQQApi
{
	
	struct Output;
public:


	HMODULE  hdll;
	MyQQApi ();
	~MyQQApi ();

	void SendMsgEx (text BotQQ, int namebat, int type, text group, text QQ, text msg, int id);
	Output OutPut ();
	//Output OutPut (int TextRGB, int BackRGB, text Msg);
	static Output OutPut (text Msg);
	
	static struct Output
	{
		Output operator<<(text Msg) {

			return OutPut (Msg);
		}
		Output operator<<(int Msg) {

			return OutPut (std::to_string (Msg).c_str());
		}

	};
private:

	typedef void (*_OutPut)(text);  _OutPut Api_OutPut;
	typedef void (*_SendMsgEx)(text, int, int, text, text, text, int); _SendMsgEx  Api_SendMsgEx;

};



#endif // _MYQQAPI
