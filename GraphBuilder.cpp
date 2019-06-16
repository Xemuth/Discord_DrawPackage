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
				
				GraphDotCloud newGraph(1200,700,"Evolution de truc par rapport à machin","Date", "Rank");
				//newGraph.isAlpha(true);
				newGraph.ShowLegendsOfCourbes(true);
				//newGraph.SetAlphaColor(Color(10,10,10));
				//newGraph.SetMainColor(Blue());
				newGraph.AddCourbe(Courbe("Clement", ValueTypeEnum::DATE, ValueTypeEnum::INT,Red()));
				newGraph.AddCourbe(Courbe("Felix", ValueTypeEnum::DATE, ValueTypeEnum::INT,Blue()));
				newGraph[0].AddDot(Dot(Value(Date(2019,6,27)),Value(2900),&newGraph[0]));
				newGraph[0].AddDot(Dot(Value(Date(2019,6,28)),Value(2950),&newGraph[0]));
				newGraph[0].AddDot(Dot(Value(Date(2019,6,29)),Value(3000),&newGraph[0]));
				
				newGraph[1].AddDot(Dot(Value(Date(2019,6,27)),Value(2200),&newGraph[1]));
				newGraph[1].AddDot(Dot(Value(Date(2019,6,28)),Value(2300),&newGraph[1]));
				newGraph[1].AddDot(Dot(Value(Date(2019,6,29)),Value(2500),&newGraph[1]));
				
				//graphicalImage myGraph(500,500,White());
				//myGraph.drawByValueMap(data);
				String test = newGraph.GetInformation();
				Cout() << "Info : "<< test <<"\n";
				newGraph.DrawGraph();

				ptrBot->CreateMessage(channel, newGraph.GetTranslationResult() );
				ptrBot->SendFile(channel,"", "Draw Test", "temp.png");
				
			//	ptrBot->CreateMessage(channel, test);
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
void Graph::isAlpha(bool b){this->alphaMode=b;}
Font Graph::GetGraphFont(){return GraphFont;}
void Graph::SetGraphFont(Font _font){GraphFont = _font;}
int Graph::GetGraphTikeness(){return GraphTikeness;}
int Graph::GetGraphFontSize(){return GraphFontSize;}
void Graph::SetGraphTikeness(int _tikeness){GraphTikeness = _tikeness;}
void Graph::SetGraphFontSize(int _FontSize){GraphFontSize = _FontSize;}
Color Graph::GetMainColor(){return MainColor;}
Color Graph::GetAlphaColor(){return AlphaColor;}
void Graph::SetMainColor(Color _MainColor){MainColor = _MainColor;}
void Graph::SetAlphaColor(Color _AlphaColor){AlphaColor = _AlphaColor;}

String Graph::GetInformation(){
	String information="";

	
	information << "------------Graph Information-----------" <<"\n";
	information << "Graph name : " <<this->graphName <<"\n";
	information << "Graph Size : X -> " <<this->sz.cx  << " Y -> " << this->sz.cy <<"\n";
	information << "Displayed : " << " AxisNames -> " << showAxisNames << " GraphName -> " << showGraphName <<"\n";
	information << "Graph Axis Names : X -> " <<  this->XName << " Y -> " << this->YName <<"\n";
	information << "Graph AlphaMode active : " <<  this->alphaMode <<"\n";
	information << "Graph FontSize and Tikeness : " << " FontSize -> " << GraphFontSize << " Tikeness -> " << GraphTikeness <<"\n";
	information << "Graph Font : " << GraphFont.GetFaceName() <<"\n";
	information << "Graph Color : " << " MainColor -> {" << MainColor.GetR() <<","<< MainColor.GetG() << "," << MainColor.GetB() <<"}" << " AlphaColor -> {"<< AlphaColor.GetR() <<","<< AlphaColor.GetG() << "," << AlphaColor.GetB() <<"}\n";   
		
	return information;
}

void Graph::DrawFlecheAlphaFriendly(Draw& img,int xDebut,int yDebut,int xFin,int yFin,DirectionLabel direction,int tickness,Color color,bool fillWithColor,bool AlphaCall){
	if(tickness==-1) tickness = this->GraphTikeness;
	if(color.GetR()==1&&color.GetG()==1&&color.GetB()==1) color = this->MainColor;
	if(alphaMode && !AlphaCall){
		DrawFlecheAlphaFriendly(((ImageDraw*)&img)->Alpha(),xDebut,yDebut,xFin,yFin,direction,tickness,AlphaColor,fillWithColor,true);
	}
	img.DrawLine(xDebut,yDebut,xFin,yFin,tickness,color);
	float rapportX=((sz.cx+sz.cy)/(sz.cx*0.15));
	float rapportY=((sz.cx+sz.cy)/(sz.cy*0.15));
	if(direction == DirectionLabel::BAS){
		if(fillWithColor){
			yFin = yFin +(yFin*0.02);
			Vector<Point> p;
			p << Point((xFin +rapportX),(yFin -rapportY)) << Point((xFin-rapportX),(yFin -rapportY)) << Point(xFin,yFin);
			img.DrawPolygon(p,color);
		}else{
			img.DrawLine(xFin,yFin,(xFin +(rapportX)),(yFin -(rapportY)),tickness+1,color);
			img.DrawLine(xFin,yFin,(xFin -(rapportX)),(yFin -(rapportY)),tickness+1,color);
		}

	}else if(direction == DirectionLabel::HAUT){
		if(fillWithColor){
			yFin = yFin -(yFin*0.02);
			Vector<Point> p;
			p << Point((xFin +rapportX),(yFin +rapportY)) << Point((xFin -rapportX),(yFin +rapportY)) << Point(xFin,yFin);
			img.DrawPolygon(p,color);
		}else{
			img.DrawLine(xFin,yFin,(xFin +(rapportX)),(yFin +(rapportY)),tickness+1,color);
			img.DrawLine(xFin,yFin,(xFin -(rapportX)),(yFin +(rapportY)),tickness+1,color);
		}
	}else if(direction == DirectionLabel::GAUCHE){
		if(fillWithColor){
			xFin =xFin -(xFin *0.01);
			Vector<Point> p;
			p << Point((xFin +rapportY),(yFin -rapportX)) << Point((xFin +rapportY),(yFin +rapportX)) << Point(xFin,yFin);
			img.DrawPolygon(p,color);
		}else{
			img.DrawLine(xFin,yFin,(xFin +(rapportY)),(yFin -(rapportX)),tickness+1,color);
			img.DrawLine(xFin,yFin,(xFin +(rapportY)),(yFin +(rapportX)),tickness+1,color);
		}
	}else if(direction == DirectionLabel::DROITE){
		if(fillWithColor){
			xFin =xFin +(xFin *0.01);
			Vector<Point> p;
			p << Point((xFin -rapportY),(yFin -rapportX)) << Point((xFin -rapportY),(yFin +rapportX)) << Point(xFin,yFin);
			img.DrawPolygon(p,color);
		}else{		
			img.DrawLine(xFin,yFin,(xFin -(rapportY)),(yFin -(rapportX)),tickness+1,color);
			img.DrawLine(xFin,yFin,(xFin -(rapportY)),(yFin +(rapportX)),tickness+1,color);
		}
	}
}

void Graph::DrawTextAlphaFriendly(Draw& img,int xDebut,int yDebut,String TextToDraw,int angle,Font font,Color color,bool AlphaCall){
	if(font.GetHeight()==1) font = this->GraphFont;
	if(color.GetR()==1&&color.GetG()==1&&color.GetB()==1) color = this->MainColor;
	if(alphaMode && !AlphaCall){
		DrawTextAlphaFriendly(((ImageDraw*)&img)->Alpha(),xDebut,yDebut,TextToDraw,angle,font,AlphaColor,true);
	}
	img.DrawText(xDebut,yDebut,angle,TextToDraw,font,color);
}

void Graph::DrawLineAlphaFriendly(Draw& img, int xDebut,int yDebut,int xFin,int yFin,int tickeness,Color color,bool AlphaCall){
	if(tickeness==-1) tickeness = this->GraphTikeness;
	if(color.GetR()==1&&color.GetG()==1&&color.GetB()==1) color = this->MainColor;
	if(alphaMode && !AlphaCall){
		DrawLineAlphaFriendly(((ImageDraw*)&img)->Alpha(),xDebut,yDebut,xFin,yFin,tickeness,AlphaColor,true);
	}
	img.DrawLine( xDebut, yDebut, xFin, yFin,tickeness,color);
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
 
bool GraphDotCloud::DrawGraph(){ //Used generate temp.png 
	float x=  sz.cx;
	float y=  sz.cy;
	float xLegend= sz.cx;
	if(showLegendsOfCourbes) xLegend= x*0.80; //Using only 80% of the image to draw Graph, last 20 % will be to draw legends
	ImageDraw w(x, y);
	
	if(alphaMode){
		w.Alpha().DrawRect(0, 0, x, y,GrayColor(0));
	}else{
		w.DrawRect(0, 0, x, y,White());	
	}

	DrawFlecheAlphaFriendly(w,(xLegend*0.10),(y*0.90),(xLegend*0.10),(y*0.10),DirectionLabel::HAUT);
	DrawFlecheAlphaFriendly(w,(xLegend*0.10),(y*0.90),(xLegend*0.90),(y*0.90),DirectionLabel::DROITE);
	
	float courbePadding=0.07;
	float YAxisHelper=0.40;
	StartTranslation();
	
		for(Courbe &c : this->courbes){
			if(showLegendsOfCourbes){
				DrawLineAlphaFriendly(w,(x*0.75),(y*YAxisHelper),(x* 0.82),(y*YAxisHelper),GraphTikeness*2,c.GetColor());
				DrawTextAlphaFriendly(w,(x*0.84),(y*(YAxisHelper - 0.03)),c.GetName(),0,StdFont(GraphFontSize*1.5));
				YAxisHelper += courbePadding;
			}
			
			//Here I must describe and calcul the xf equivalent of value contened in dot;
			//It mean I will have to loop through every dot find the lowest and max value and do
			//A translation to our graph
			for(Dot d : c.GetDots()){
					
			}
		}

	if (showAxisNames){
		DrawTextAlphaFriendly(w,(xLegend*0.5),(y*0.95),XName);
		DrawTextAlphaFriendly(w,(xLegend*0.05),(y*0.5),YName,90*10);
	}
	if(showGraphName){
		DrawTextAlphaFriendly(w,(xLegend/2),(y*0.1),graphName,0,StdFont(GraphFontSize *1.5));
	}
	PNGEncoder png;
	png.SaveFile("temp.png", w);
	return true;
}

void GraphDotCloud::DefineXValueType(ValueTypeEnum _xValue){
	XValueType = _xValue;
}

void GraphDotCloud::DefineYValueType(ValueTypeEnum _yValue){
	YValueType = _yValue;
}

ValueTypeEnum GraphDotCloud::GetXValueType(){
	return XValueType;
}

ValueTypeEnum GraphDotCloud::GetYValueType(){
	return YValueType;
}


bool GraphDotCloud::StartTranslation(){
	for(Courbe &c : this->courbes){
		if (c.GetXValueType() == XValueType && c.GetYValueType() == YValueType){
			for(Dot d : c.GetDots()){
				if(XValueType == ValueTypeEnum::INT){
					if((xMax.IsVoid() && xMax.Get<int>() < d.GetXVal().Get<int>())||(!xMax.IsVoid() && xMax.Get<int>() < d.GetXVal().Get<int>())) xMax = Value(d.GetXVal().Get<int>());
					if((xMin.IsVoid())||(!xMin.IsVoid() && xMin.Get<int>() > d.GetXVal().Get<int>())) xMin = Value(d.GetXVal().Get<int>());
				}else if(XValueType == ValueTypeEnum::DATE){
					if((xMax.IsVoid() && xMax.Get<Date>() < d.GetXVal().Get<Date>())||(!xMax.IsVoid() && xMax.Get<Date>() < d.GetXVal().Get<Date>())) xMax = Value(d.GetXVal().Get<Date>());
					if((xMin.IsVoid())||(!xMin.IsVoid() && xMin.Get<Date>() > d.GetXVal().Get<Date>())) xMin = Value(d.GetXVal().Get<Date>());
				}
				
				if(YValueType == ValueTypeEnum::INT){
					if((yMax.IsVoid() && yMax.Get<int>() < d.GetYVal().Get<int>())||(!yMax.IsVoid() && yMax.Get<int>() < d.GetYVal().Get<int>())) yMax = Value(d.GetYVal().Get<int>());
					if((yMin.IsVoid())||(!yMin.IsVoid() && yMin.Get<int>() > d.GetYVal().Get<int>())) yMin = Value(d.GetYVal().Get<int>());
				}else if(YValueType == ValueTypeEnum::DATE){
					if((yMax.IsVoid() && yMax.Get<Date>() < d.GetYVal().Get<Date>())||(!yMax.IsVoid() && yMax.Get<Date>() < d.GetYVal().Get<Date>())) yMax = Value(d.GetYVal().Get<Date>());
					if((yMin.IsVoid())||(!yMin.IsVoid() && yMin.Get<Date>() > d.GetYVal().Get<Date>())) yMin = Value(d.GetYVal().Get<Date>());
				}
			}
		}
	}
	TranslationDone = (!yMax.IsVoid() && !xMax.IsVoid() && !xMin.IsVoid() && !yMin.IsVoid());
	Cout() << "Translation Result : " << TranslationDone <<"\n";
	if(XValueType == ValueTypeEnum::INT){
		Cout() << "xMax value : " << xMax.Get<int>() <<"\n";
		Cout() << "xMin value : " << xMin.Get<int>() <<"\n";
	}else if(XValueType == ValueTypeEnum::DATE){
		Cout() << "xMax value : " << xMax.ToString() <<"\n";
		Cout() << "xMin value : " << xMin.ToString() <<"\n";
	}
	if(YValueType == ValueTypeEnum::INT){
		Cout() << "yMax value : " << yMax.Get<int>() <<"\n";
		Cout() << "yMin value : " << yMin.Get<int>() <<"\n";
	}else if(YValueType == ValueTypeEnum::DATE){
		Cout() << "yMax value : " << yMax.ToString() <<"\n";
		Cout() << "yMin value : " << yMin.ToString() <<"\n";
	}
	return TranslationDone;
}

String GraphDotCloud::GetTranslationResult(){
	String result ="";
	result << "Translation Result : " << TranslationDone <<"\n";
	if(XValueType == ValueTypeEnum::INT){
		result << "  xMax value : " << xMax.Get<int>() <<"\n";
		result << "  xMin value : " << xMin.Get<int>() <<"\n";
	}else if(XValueType == ValueTypeEnum::DATE){
		result << "  xMax value : " << xMax.ToString() <<"\n";
		result << "  xMin value : " << xMin.ToString() <<"\n";
	}
	if(YValueType == ValueTypeEnum::INT){
		result << "  yMax value : " << yMax.Get<int>() <<"\n";
		result << "  yMin value : " << yMin.Get<int>() <<"\n";
	}else if(YValueType == ValueTypeEnum::DATE){
		result << "  yMax value : " << yMax.ToString() <<"\n";
		result << "  yMin value : " << yMin.ToString() <<"\n";
	}
	return result;
}


float GraphDotCloud::ResolveX(Value xToResolve){
	if (TranslationDone){
		
	}
}

float GraphDotCloud::ResolveY(Value yToResolve){
	if(TranslationDone){
			
	}
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
	information <<"    Courbe name : " << this->name <<"\n";
	information <<"    Courbe color : " << "{" << this->color.GetR() <<","<< this->color.GetG() << "," << this->color.GetB() <<"}\n";
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

Value Dot::GetYVal(){
	return YValue;	
}

Value Dot::GetXVal(){
	return XValue;
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
	//objectCount--;
}
