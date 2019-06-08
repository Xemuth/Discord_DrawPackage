#ifndef _GraphBuilder_GraphBuilder_h_
#define _GraphBuilder_GraphBuilder_h_
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


enum class typeGraph : char {Courbe};


template <class T,class K> 
class Graph{
	private:
		template<class E> constexpr dword resolveType(){ return <E>GetValueTypeNo();}
		
		String graphName="";
		String XName="";
		String YName="";
		String GraphName="";
	
		char typeGraphe;
		T XType;
		K YType;		

		/******/		
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
