#ifndef _Discord_DrawPackage_Discord_DrawPackage_h_
#define _Discord_DrawPackage_Discord_DrawPackage_h_
#include <SmartUppBot/SmartBotUpp.h>
#include <CtrlLib/CtrlLib.h>

using namespace Upp;
class graphicalImage;

class Discord_DrawPackage: public DiscordModule{
	private:
		//Events discord
		void drawTest(ValueMap payload);
		void DrawGraph(ValueMap payload);
		void testVraiGraph(ValueMap payload);
		
		//Method of class used to generate the graph 
		void SaveGraph(graphicalImage &myImage,String fileName="temp.png");
	
		bool isStringisANumber(String stringNumber);
		
	public:
		
		Discord_DrawPackage(Upp::String _name, Upp::String _prefix);
		void Events(ValueMap payload);
	
};

class graphicalImage{
	private:
		ImageDraw myGraph;
		
		ValueMap Definition;
		ValueMap Data;
		
		ImageDraw& drawGraphFromData();	
		
		int ID=0;
	
	public:
		graphicalImage(int x,int y, Color background);
		ValueMap getValueMap();
		
		ImageDraw& drawByValueMap(ValueMap theGraph);
		
		ImageDraw& removeCourbe(String courbeName);
		ImageDraw& removeCourbe(int Id);
		
		ImageDraw& AddCourbe(ValueMap courbeName);
		
		int getLastId();
		
};

class GraphCourbe : public graphicalImage{


};




#endif
