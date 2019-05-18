#ifndef _Discord_DrawPackage_Discord_DrawPackage_h_
#define _Discord_DrawPackage_Discord_DrawPackage_h_
#include <SmartUppBot/SmartBotUpp.h>

using namespace Upp;
class Discord_DrawPackage: public DiscordModule{
	private:
	
		void drawTest(ValueMap payload);
		
		bool isStringisANumber(Upp::String stringNumber);
	public:
		
		Discord_DrawPackage(Upp::String _name, Upp::String _prefix);
		
		void Event(ValueMap payload);
	
	
};
#endif
