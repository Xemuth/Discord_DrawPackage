#include <Core/Core.h>
#include "GraphBuilder.h"
#include <Draw/Draw.h>
#include <CtrlLib/CtrlLib.h>
#include <cctype>
#include <string> 

using namespace Upp;

void Discord_DrawPackage::drawTest(ValueMap payload){
	String channel  = payload["d"]["channel_id"];
    String id = payload["d"]["author"]["id"];
	Upp::String message = payload["d"]["content"];
	message.Replace(String("!" +prefix +" "),"");
	Cout() <<message <<"\n";
	Vector<String> args = Split(message," ");
	if( args.GetCount() > 2 &&  args[0].Compare("draw")==0 && isStringisANumber(args[1]) && isStringisANumber(args[2]) ){
		try{
			args[1].Replace("+","");
			args[2].Replace("+","");
			float x =std::stof( args[1].ToStd());
			float y = std::stof(args[2].ToStd());
			String toDraw="";
			if(args.GetCount()>3){
				for(int i = 3; i < args.GetCount(); i++){
					toDraw << ((i !=2)? " ":"" ) + args[i];
				}
			}else{
				toDraw <<  "Test Draw !";
			}
			
			ImageDraw w(x,  y );
			w.DrawRect(0, 0, x, y, SWhite());
			w.DrawText( (x*0.2), (y*0.2) , 320*10 ,toDraw,Roman((((((x)+(y))/2) )/(toDraw.GetCount() * 0.8) ))); // il faut adapter la taille du text par rapport à la taille de l'image et à la longueur de celui-ci
		
			PNGEncoder png;
		    Image m = w;
		    png.SaveFile("temp.png", m);
			ptrBot->CreateMessage(channel, "Event " + name +" ; taille du text : " + String(std::to_string( ((x)+(y))/toDraw.GetCount())) );
			ptrBot->SendFile(channel,"", "Draw Test", "temp.png");
		}
		catch(...){
			ptrBot->CreateMessage(channel, "Erreur d'argument !");
		}
	}
}

void Discord_DrawPackage::DrawGraph(ValueMap payload){
	String channel  = payload["d"]["channel_id"];
	Upp::String message = payload["d"]["content"];
	message.Replace(String("!" +prefix +" "),"");
	Cout() << message <<"\n";
	Vector<String> args = Split(message," ");
	if(args.GetCount() >0 &&  args[0].Compare("graph")==0){
		float x=  500.0f;
		float y=  500.0f;
		ImageDraw w(x,  y );
		w.DrawRect(0, 0, x, y, SWhite());
		w.DrawLine((x*0.05),(y*0.05),(x*0.05),(y*0.95),2,SGray());
		w.DrawLine((x*0.05),(y*0.95),(x*0.95),(y*0.95),2,SGray());
		
		String toDraw="";
		if(args.GetCount()>1){
		for(int i = 1; i < args.GetCount(); i++){
			toDraw << ((i !=1)? " ":"" ) + args[i];
		}
		}else{
			toDraw <<  "Test Draw !";
		}
		
		w.DrawText((x/2),(y*0.1),toDraw,StdFont(20),SGray());
		PNGEncoder png;
	    Image m = w;
	    png.SaveFile("temp.png", m);
		ptrBot->CreateMessage(channel, "Event " + name  );
		ptrBot->SendFile(channel,"", "Draw Test", "temp.png");
	}
}

void Discord_DrawPackage::testVraiGraph(ValueMap payload){
	String channel  = payload["d"]["channel_id"];
	Upp::String message = payload["d"]["content"];
	message.Replace(String("!" +prefix +" "),"");
	Cout() <<"Events Test vrai graph : "  <<message <<"\n";
	Vector<String> args = Split(message," ");
	if(args.GetCount() >0 &&  args[0].Compare("test")==0){
				Cout() << "je crée le graph" <<"\n";
				
				GraphDotCloud newGraph(500,500,"test Graph","Date", "Rank");
				
				newGraph.AddCourbe(Courbe("Clement", ValueTypeEnum::DATE, ValueTypeEnum::INT,Red()));
				newGraph.AddCourbe(Courbe("Felix", ValueTypeEnum::DATE, ValueTypeEnum::INT,Red()));
				newGraph[0].AddDot(Dot(Value(Date(2019,6,27)),Value(2900),&newGraph[0]));
				newGraph[0].AddDot(Dot(Value(Date(2019,6,28)),Value(2950),&newGraph[0]));
				newGraph[0].AddDot(Dot(Value(Date(2019,6,29)),Value(3000),&newGraph[0]));
				
				newGraph[1].AddDot(Dot(Value(Date(2019,6,27)),Value(2600),&newGraph[1]));
				newGraph[1].AddDot(Dot(Value(Date(2019,6,28)),Value(2650),&newGraph[1]));
				newGraph[1].AddDot(Dot(Value(Date(2019,6,29)),Value(2700),&newGraph[1]));
				
				//graphicalImage myGraph(500,500,White());
				//myGraph.drawByValueMap(data);
				String test = newGraph.GetInformation();
				Cout() << "Info : "<< test <<"\n";
				ptrBot->CreateMessage(channel, test);
			/*if (FileExists("./example.json")){
				FileIn in("./example.json");
				if(in){
					String e="";
					in.Seek(0);
					while(!in.IsEof())
						e+=in.GetLine();
				
					ValueMap data = ParseJSON(e);
				
				}	
			}*/
	}
}


bool Discord_DrawPackage::isStringisANumber(Upp::String stringNumber){
	if (std::isdigit(stringNumber[0]) || (stringNumber.GetCount() > 1 && (stringNumber[0] == '+')))
    {
        for (int i = 1 ; i < stringNumber.GetCount(); ++i)
            if (!std::isdigit(stringNumber[i]))
                return false;

        return true;
    }
    return false;
}
	
Discord_DrawPackage::Discord_DrawPackage(Upp::String _name, Upp::String _prefix){
	name = _name;
	prefix = _prefix;

	EventsMap.Add([&](ValueMap e){this->drawTest(e);});
	EventsMap.Add([&](ValueMap e){this->DrawGraph(e);});
	EventsMap.Add([&](ValueMap e){this->testVraiGraph(e);});
}

void Discord_DrawPackage::Events(ValueMap payload){
	for(auto &e : EventsMap){
		e(payload);
	}
}

/***********************************************/
// Class Graph 
/***********************************************/
void Graph::SetGraphName(Upp::String _GraphName){this->graphName = _GraphName;}
Upp::String Graph::GetGraphName(){return this->graphName;}
void Graph::DefineSize(Size _sz){this->sz = _sz;} //Size value can be acced from size.cx / size.cy
Size Graph::GetSize(){return this->sz;} //Return size of Graph (size representing Size of Image would get generated by DrawGraph method)
void Graph::DefineXName(String _XName){this->XName = _XName;}
void Graph::DefineYName(String _YName){this->YName = _YName;}
String Graph::GetXName(){return this->XName;}
String Graph::GetYName(){return this->YName;}
void Graph::ShowAxisNames(bool b){this->showAxisNames = b;}
void Graph::ShowGraphName(bool b){this->showGraphName=b;}

String Graph::GetInformation(){
	String information="";

	
	information << "------------Graph Information-----------" <<"\n";
	information << "Graph name : " <<this->graphName <<"\n";
	information << "Graph Size : X -> " <<this->sz.cx  << " Y -> " << this->sz.cy <<"\n";
	information << "Graph Axis Names : X -> " <<  this->XName << " Y -> " << this->YName <<"\n";

	return information;
}

int Courbe::objectCount=0;
int Dot::objectCount=0;

String ResolveValueTypeEnum(ValueTypeEnum type){
	if(type == ValueTypeEnum::INT){
		return "int";
	}else if(type == ValueTypeEnum::DATE){
		return "Date";	
	}
}

/***********************************************/
// Class GraphDotCloud 
/***********************************************/
String GraphDotCloud::ToJson(){
	return "Supposed to Be Json";
}

String GraphDotCloud::GetInformation(){
	String information=Graph::GetInformation();

	information << "Type of graph : " << this->TypeOfGraph() <<"\n";
	information << "------------Courbes information-----------" <<"\n";
	information << "Courbes number : " << this->courbes.GetCount() <<"\n";
	for(Courbe &c : courbes){
		information << c.GetInformation();	
	}
	information << "----------------------------------------" <<"\n";
	return information;
}

String GraphDotCloud::TypeOfGraph(){ //Return type of graph
	return graphType;
}
 
ImageDraw GraphDotCloud::DrawGraph(){ //Used to return an ImageDraw representing the graph
	
	return ImageDraw(sz);
}

//Data Manipulation
void GraphDotCloud::AddCourbe(Courbe c){
	courbes.Add(c);
}

void GraphDotCloud::RemoveCourbe(Courbe &c){//This one use address to find the right courbe
	int i =0;
	for(Courbe &r : courbes){
		if (&r == &c){
			courbes.Remove(i);	
			break;
		}
		i++;
	}
}

void GraphDotCloud::RemoveCourbe(int i){
	courbes.Remove(i);	
}

Courbe& GraphDotCloud::operator[](int iterator){ //allowing to access to courbe stocked in AllCourbes
	return courbes[iterator];
}

//Bunch of constructor
GraphDotCloud::GraphDotCloud(int _XSize,int _YSize){
	Size _sz;
	_sz.cy = _YSize;
	_sz.cx = _XSize;
	sz = _sz;
}
GraphDotCloud::GraphDotCloud(int _XSize,int _YSize,String _GraphName){
	Size _sz;
	_sz.cy = _YSize;
	_sz.cx = _XSize;
	sz = _sz;
	graphName = _GraphName;
}
GraphDotCloud::GraphDotCloud(int _XSize,int _YSize,String _GraphName, String _XName, String _YName){
	Size _sz;
	_sz.cy = _YSize;
	_sz.cx = _XSize;
	sz = _sz;
	graphName = _GraphName;
	XName= _XName;
	YName= _YName;
}
GraphDotCloud::GraphDotCloud(Size _sz,String _GraphName, String _XName, String _YName){
	sz = _sz;
	graphName = _GraphName;
	XName= _XName;
	YName= _YName;
}
GraphDotCloud::GraphDotCloud(Size _sz,String _GraphName){
	sz = _sz;
	graphName = _GraphName;
}
GraphDotCloud::GraphDotCloud(Size _sz){
	sz = _sz;
}

//params
void GraphDotCloud::ShowLegendsOfCourbes(bool b){
	showLegendsOfCourbes=b;
}
void GraphDotCloud::ShowValueOfDot(bool b){
	showValueOfDot=b;
}
void GraphDotCloud::SignIt(bool b){
	signIt=b;
}


/***********************************************/
// Class Courbe 
/***********************************************/
void Courbe::LinkDot(bool b){ //Enable or not linking on dot
	this->linkDot = b;
}

void Courbe::ValueToShow(LabelValueToShow _labelToShow){ //Define axis label to show
	labelToShow = _labelToShow;
}

Dot& Courbe::operator[](int iterator){
	return dots[iterator];
}

Dot& Courbe::AddDot(Dot d){
	dots.Add(d);	
}

void Courbe::removeDot(int iterator){
	dots.Remove(iterator);
}

void Courbe::removeDot(Dot &dot){
	int i =0;
	for(Dot &r : dots){
		if (&r == &dot){
			dots.Remove(i);	
			break;
		}
		i++;
	}
}

String Courbe::GetInformation(){
	String information="";
	information <<"    -----Courbe " << String(std::to_string( this->GetId())) <<"-----\n";
	information << "    Courbe name : " << this->name <<"\n";
	information << "    Courbe color : " << this->color.ToString() <<"\n";
	for(Dot &d : dots){
		information << d.GetInformation();	
	}
	return information;
}

int Courbe::GetId(){
	return id;
}

String const Courbe::GetName()const{
	return this->name;
}

void Courbe::SetName(Upp::String _name){
	name = _name;
}
const Vector<Dot>&  Courbe::GetDots()const{
	return this->dots;
}

void Courbe::SetColor(Color _c){
	color = _c;
}
Color const Courbe::GetColor() const{
	return this->color;
}

ValueTypeEnum Courbe::GetXValueType(){
	return XValueType;
}
ValueTypeEnum Courbe::GetYValueType(){
	return YValueType;
}

//Bunch of constructor
Courbe::Courbe(const Courbe& c){
	this->id = objectCount;
	objectCount++;
	this->name = c.GetName();
	this->color =c.GetColor();
	this->dots = Vector<Dot>(c.GetDots(),c.GetDots().GetCount());
}

Courbe::Courbe(String _Name, ValueTypeEnum _XValueType, ValueTypeEnum _YValueType,Color _color){
	this->name = _Name;
	this->XValueType = _XValueType;
	this->YValueType = _YValueType;
	this->color = _color;
	id = objectCount;
	objectCount++;
}

Courbe::Courbe(String _Name, ValueTypeEnum _XValueType, ValueTypeEnum _YValueType){
	this->name = _Name;
	this->XValueType = _XValueType;
	this->YValueType = _YValueType;
	id = objectCount;
	objectCount++;
}

Courbe::Courbe(String _Name){
	this->name = _Name;
	id = objectCount;
	objectCount++;
}

Courbe::~Courbe(){
	objectCount--;	
}

/***********************************************/
// Class Dot
/***********************************************/
void Dot::SetXValue(Value _XValue){
	XValue = _XValue;
}

void Dot::SetYValue(Value _YValue){
	YValue = _YValue;
}
int Dot::GetId(){
	return id;
}

String Dot::GetInformation(){
	String information="";
	information <<"        -----Dot " << String(std::to_string( this->GetId())) <<"-----\n";
	information << "        X Value : " << "Type -> "<< ResolveValueTypeEnum( parent->GetXValueType()) << " Value ->" << XValue.ToString() <<"\n";
	information << "        Y Value : " << "Type -> "<< ResolveValueTypeEnum( parent->GetYValueType()) << " Value ->" << YValue.ToString() <<"\n";
	return information;
}

Dot::Dot(Value _XValue,Value _YValue,Courbe* _parent){
	parent = _parent;
	XValue = _XValue;
	YValue = _YValue;
	id = objectCount;
	objectCount++;
}

Dot::~Dot(){
	objectCount--;
}

//Class Graphical Image
/*
graphicalImage::graphicalImage(int x,int y, Color background): myGraph(x,y){
	myGraph.DrawRect(0,0,x,y,background);
}

ImageDraw& graphicalImage::drawByValueMap(ValueMap theGraph){
	Definition = theGraph["graphDefinition"];
	Data =  theGraph[Definition["GraphType"].ToString()];
	auto numCourbes = Data[String("number" + Definition["GraphType"].ToString()) ];
	if(numCourbes.ToString().GetCount()>0){
		int max = std::stoi(numCourbes.ToString().ToStd());
		for(int e = 0 ;e < max;e++){
			Cout() << "Courbe numero " << e << " : "  <<Data[String(std::to_string(e))] <<"\n";
		}
	}

}

ImageDraw& graphicalImage::removeCourbe(String courbeName){
	
}
ImageDraw& graphicalImage::removeCourbe(int Id){
	
}

ImageDraw& graphicalImage::AddCourbe(ValueMap courbeName){
	
}

int graphicalImage::getLastId(){
}
*/