#ifndef _GraphBuilder_GraphBuilder_h_
#define _GraphBuilder_GraphBuilder_h_
#include <SmartUppBot/SmartBotUpp.h>
#include <CtrlLib/CtrlLib.h>

using namespace Upp;

class Discord_DrawPackage: public DiscordModule{
	private:
		//Events discord
		void drawTest(ValueMap payload);
		void DrawGraph(ValueMap payload);
		void testVraiGraph(ValueMap payload);
		
		//Method of class used to generate the graph 
	//	void SaveGraph(graphicalImage &myImage,String fileName="temp.png");
	
		bool isStringisANumber(String stringNumber);
		
	public:
		
		Discord_DrawPackage(Upp::String _name, Upp::String _prefix);
		void Events(ValueMap payload);
	
};


//Virtual Class, supposed to be inherrited to new graph type
class Graph{
	protected:
		String graphName=""; //name of graph 
		String XName=""; //Name of X axis
		String YName=""; //Name of Y axis
		Size sz;
		
		bool showAxisNames =true;
		bool showGraphName =true;
	public: 
		virtual String ToJson()=0;
		virtual String GetInformation() =0; //Here we force Override in inherited class
											//This func used to print information about the
											//graph
	
		virtual void SetGraphName(Upp::String _GraphName);
		virtual Upp::String GetGraphName();
		
		virtual void DefineSize(Size _sz); //Size value can be acced from size.cx / size.cy
		virtual Size GetSize(); //Return size of Graph (size representing Size of Image would get generated by DrawGraph method)
		
		virtual void DefineXName(String _XName);
		virtual void DefineYName(String _YName);
		virtual String GetXName();
		virtual String GetYName();
		
		virtual void ShowAxisNames(bool b);
		virtual void ShowGraphName(bool b);
};

/***********************************************/
// Oject used to Represent DotCloud graph 
/***********************************************/
class Courbe;
class Dot;

enum class LabelValueToShow {XVALUE,YVALUE};
enum class ValueTypeEnum{INT,DATE};
Upp::String ResolveValueTypeEnum(ValueTypeEnum type);

//Not sure if embbed class of Graph into Graph is a good idea
class GraphDotCloud : public Graph, public Upp::Moveable<GraphDotCloud>{
	private:
		const String graphType="DotCloud";
		
		Vector<Courbe> courbes; 
		
		bool showLegendsOfCourbes=false;
		bool showValueOfDot=true;
		bool signIt=true; //This one is here for fun. Signing it with my name ! 
		
	public:
		String ToJson();
		String GetInformation();
		
		String TypeOfGraph(); //Return type of graph
		ImageDraw DrawGraph(); //Used to return an ImageDraw representing the graph
		
		//Data Manipulation
		void AddCourbe(Courbe c);
		void RemoveCourbe(Courbe &c);
		void RemoveCourbe(int i);
		
		Courbe& operator[](int iterator); //allowing to access to courbe stocked in AllCourbes
		
		//Bunch of constructor
		GraphDotCloud(int _XSize,int _YSize);
		GraphDotCloud(int _XSize,int _YSize,String _GraphName);
		GraphDotCloud(int _XSize,int _YSize,String _GraphName, String _XName, String _YName);
		GraphDotCloud(Size _sz,String _GraphName, String _XName, String _YName);
		GraphDotCloud(Size _sz,String _GraphName);
		GraphDotCloud(Size _sz);
		
		//params
		void ShowLegendsOfCourbes(bool b);
		void ShowValueOfDot(bool b);
		void SignIt(bool b);
};
 
//this class is here to handle Vector of Dot 
class Courbe : public Upp::Moveable<Courbe>{
	private :
		LabelValueToShow labelToShow = LabelValueToShow::XVALUE; // Define Label to show
		int id; //Here to know Id Of this courbe
		
		String name=""; //Name of the courbe
		Color color=Black(); //Color of the Courbe
		
		ValueTypeEnum XValueType =ValueTypeEnum::DATE; //Representing of value Type
		ValueTypeEnum YValueType =ValueTypeEnum::INT; //Representing of value Type
		
		Vector<Dot> dots; //All dot
	protected:
		bool ShowValueLabel = true; //Show label for each dot
		bool linkDot = true; //protected to allow mother class to access it
	public:
		static int objectCount;//Here to know how many Courbe is On while using graph
		void LinkDot(bool b); //Enable or not linking on dot
		void ValueToShow(LabelValueToShow _labelToShow); //Define axis label to show
		
		Dot& AddDot(Dot d);
		
		Dot& operator[](int iterator);
		void removeDot(int iterator);
		void removeDot(Dot &dot);
		
		String GetInformation();
		int GetId();
		String const GetName() const;
		void SetName(Upp::String _name);
		const Vector<Dot>& GetDots() const;
		
		void SetColor(Color _c);
		Color const GetColor() const;
		
		ValueTypeEnum GetXValueType();
		ValueTypeEnum GetYValueType();
		//Bunch of constructor
		Courbe(const Courbe& c);
		Courbe(String _Name, ValueTypeEnum _XValueType, ValueTypeEnum _YValueType,Color _color);
		Courbe(String _Name, ValueTypeEnum _XValueType, ValueTypeEnum _YValueType);
		Courbe(String _Name);
		
		~Courbe();
};

class Dot : public Upp::Moveable<Dot>{
	private:
		int id;
		Courbe * parent;
		Value XValue;
		Value YValue;		
	public:
		static int objectCount;
		void SetXValue(Value _XValue);
		void SetYValue(Value _YValue);
		String GetInformation();
		int GetId();
		
		Dot(Value _XValue,Value _YValue,Courbe* _parent);
		~Dot();
};




/***********************************************/
// End of Courbe graph
/***********************************************/

Graph* ConstructGraphFromJSON(ValueMap &json); //This is supposed to return graph object from a complete Json
		


#endif
