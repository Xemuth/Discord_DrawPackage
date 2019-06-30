#include "GraphBuilder.h"
#include <Core/Core.h>
#include <cctype>
#include <string> 

#define IMAGECLASS WowImg
#define IMAGEFILE <GraphBuilder/wow.iml>
#include <Draw/iml.h>
using namespace Upp;


void GraphDotCloud::SimpleExample(){
			//	isAlpha(true);
				ShowGraphName(false);
				ShowLegendsOfCourbes(true);
				ShowValueOfDot(true);
				
				ActivateMaxDatePadding(true);
				SetMaxDatePadding(13);
				
				SetActivatedSpecifiedLowestAxisY(true);
				SetSpecifiedLowestStartingNumberAxisY(2000);
				/*		
				SetActivatedSpecifiedHighestAxisY(true);
				SetSpecifiedHighestStartingNumberAxisY(8000);
				*/
				
				//newGraph.SetAlphaColor(Color(10,10,10));
				//newGraph.SetMainColor(Blue());
				AddCourbe(Courbe("Clement", ValueTypeEnum::DATE, ValueTypeEnum::INT,Red()));
				AddCourbe(Courbe("Felix", ValueTypeEnum::DATE, ValueTypeEnum::INT,Blue()));
				AddCourbe(Courbe("Hugo", ValueTypeEnum::DATE, ValueTypeEnum::INT,Green()));
				AddCourbe(Courbe("Brendan", ValueTypeEnum::DATE, ValueTypeEnum::INT,Brown()));
				AddCourbe(Courbe("Pierre", ValueTypeEnum::DATE, ValueTypeEnum::INT,Magenta()));
				
				((*this))[0].ShowDot(true);
				((*this))[1].ShowDot(true);
				(*this)[2].ShowDot(true);
				(*this)[3].ShowDot(true);
				Cout() << "Fin Paramétrage"<<"\n";
				
			/*	(*this)[0].SetLinked(false);
				(*this)[1].SetLinked(false);
				(*this)[2].SetLinked(false);
				(*this)[3].SetLinked(false);*/
			//	(*this)[4].ShowDot(false);
				(*this)[0].AddDot(Dot(Value(Date(2019,3,1)),Value(2600),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,6,27)),Value(2900),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,6,28)),Value(2950),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,6,29)),Value(3000),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,6,30)),Value(3015),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,1)),Value(3100),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,2)),Value(3115),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,3)),Value(3240),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,4)),Value(3200),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,5)),Value(3121),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,6)),Value(3001),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,7)),Value(2954),&(*this)[0]));
				(*this)[0].AddDot(Dot(Value(Date(2019,7,8)),Value(2900),&(*this)[0]));

				(*this)[1].AddDot(Dot(Value(Date(2019,6,27)),Value(2200),&(*this)[1]));
				(*this)[1].AddDot(Dot(Value(Date(2019,6,28)),Value(2300),&(*this)[1]));
				(*this)[1].AddDot(Dot(Value(Date(2019,6,29)),Value(2500),&(*this)[1]));
				(*this)[1].AddDot(Dot(Value(Date(2019,7,8)),Value(2600),&(*this)[1]));

				(*this)[2].AddDot(Dot(Value(Date(2019,6,30)),Value(2702),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,1)),Value(2780),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,2)),Value(2689),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,3)),Value(2692),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,4)),Value(2741),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,5)),Value(2799),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,6)),Value(2823),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,7)),Value(2894),&(*this)[2]));
				(*this)[2].AddDot(Dot(Value(Date(2019,7,8)),Value(2927),&(*this)[2]));

				
				(*this)[3].AddDot(Dot(Value(Date(2019,6,27)),Value(2600),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,6,28)),Value(2945),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,6,29)),Value(3174),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,6,30)),Value(3019),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,7,1)),Value(2987),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,7,4)),Value(2988),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,7,5)),Value(3014),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,7,6)),Value(3060),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,7,7)),Value(3050),&(*this)[3]));
				(*this)[3].AddDot(Dot(Value(Date(2019,7,8)),Value(3084),&(*this)[3]));

				
				(*this)[4].AddDot(Dot(Value(Date(2019,6,13)),Value(1600),&(*this)[4]));
				(*this)[4].AddDot(Dot(Value(Date(2019,7,5)),Value(1628),&(*this)[4]));
				
				Cout() << "Fin création"<<"\n";
				String test = GetInformation();
				Cout() <<  test <<"\n";
				
			//	PNGEncoder png;
			//	png.SaveFile("temp.png", newGraph.DrawGraph());
				
			//ptrBot->CreateMessage(channel, newGraph.GetInformation() );
			//	ptrBot->SendFile(channel,"", newGraph.GetGraphName(), "temp.png");
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
void Graph::DrawEllispeAlphaFriendly(Draw& img,int xDebut,int yDebut, int RadiusX , int RadiusY,Color color,bool AlphaCall){
	if(color.GetR()==1&&color.GetG()==1&&color.GetB()==1) color = this->MainColor;
	if(alphaMode && !AlphaCall){
		DrawEllispeAlphaFriendly(((ImageDraw*)&img)->Alpha(),xDebut,yDebut,RadiusX,RadiusY,AlphaColor,true);
	}
	img.DrawEllipse(xDebut,yDebut,RadiusX,RadiusY,color);
}

void Graph::DrawImageAlphaFriendly(Draw& img,int xDebut,int yDebut,const Image& value,bool AlphaCall){
	if(alphaMode && !AlphaCall){
		DrawImageAlphaFriendly(((ImageDraw*)&img)->Alpha(),xDebut,yDebut,value,true);
	}
	img.DrawImage(xDebut,yDebut,value);
}
int Courbe::objectCount=0;
int Dot::objectCount=0;

String ResolveValueTypeEnum(ValueTypeEnum type){
	if(type == ValueTypeEnum::INT){
		return "int";
	}else if(type == ValueTypeEnum::DATE){
		return "Date";	
	}
	return "int";
}

/***********************************************/
// Class GraphDotCloud 
/***********************************************/
void GraphDotCloud::SetActivatedSpecifiedLowestAxisX(bool b){IntStartAtLowestSpecifiedNumberAxisX = b;}
bool GraphDotCloud::IsActivatedSpecifiedLowestAxisX(){return IntStartAtLowestSpecifiedNumberAxisX;}
void GraphDotCloud::SetActivatedSpecifiedHighestAxisX(bool b){IntStartAtHighestSpecifiedNumberAxisX = b;}
bool GraphDotCloud::IsActivatedSpecifiedHighestAxisX(){return IntStartAtHighestSpecifiedNumberAxisX;}

void GraphDotCloud::SetActivatedSpecifiedLowestAxisY(bool b){IntStartAtLowestSpecifiedNumberAxisY = b;}
bool GraphDotCloud::IsActivatedSpecifiedLowestAxisY(){return IntStartAtLowestSpecifiedNumberAxisY;}
void GraphDotCloud::SetActivatedSpecifiedHighestAxisY(bool b){IntStartAtHighestSpecifiedNumberAxisY = b;}
bool GraphDotCloud::IsActivatedSpecifiedHighestAxisY(){return IntStartAtHighestSpecifiedNumberAxisY;}

void GraphDotCloud::SetSpecifiedLowestStartingNumberAxisX(int _number){ SpecifiedLowestStartingNumberAxisX = _number;}
int GraphDotCloud::GetSpecifiedLowestStartingNumberAxisX(){return SpecifiedLowestStartingNumberAxisX;}
void GraphDotCloud::SetSpecifiedHighestStartingNumberAxisX(int _number){ SpecifiedHighestStartingNumberAxisX = _number;}
int GraphDotCloud::GetSpecifiedHighestStartingNumberAxisX(){return SpecifiedHighestStartingNumberAxisX;}

void GraphDotCloud::SetSpecifiedLowestStartingNumberAxisY(int _number){ SpecifiedLowestStartingNumberAxisY = _number;}
int GraphDotCloud::GetSpecifiedLowestStartingNumberAxisY(){return SpecifiedLowestStartingNumberAxisY;}
void GraphDotCloud::SetSpecifiedHighestStartingNumberAxisY(int _number){ SpecifiedHighestStartingNumberAxisY = _number;}
int GraphDotCloud::GetSpecifiedHighestStartingNumberAxisY(){return SpecifiedHighestStartingNumberAxisY;}

void GraphDotCloud::ShowLegendsOfCourbes(bool b){showLegendsOfCourbes=b;}
void GraphDotCloud::ShowValueOfDot(bool b){showValueOfDot=b;}
void GraphDotCloud::SignIt(bool b){signIt=b;} 
void GraphDotCloud::ShowValueOnAxis(bool b){ValueOnAxis = b;}

void GraphDotCloud::SetMaxDatePadding(int _padding){SpecifiedMaxDatePadding = _padding;}
int GraphDotCloud::GetMaxDatePadding(){return SpecifiedMaxDatePadding;}
void GraphDotCloud::ActivateMaxDatePadding(bool b){UseMaxDatePadding =b;}

void GraphDotCloud::DrawValueOnAxisAlphaFriendly(Draw& img,float X,float Y,float paddingX,float paddingY,bool AlphaCall){
	if(alphaMode && !AlphaCall){
		DrawValueOnAxisAlphaFriendly(((ImageDraw*)&img)->Alpha(),X,Y,paddingX,paddingY,true);
	}
	//First we do it to X axis
	if(XValueType == ValueTypeEnum::INT){
	/*	int xPadding = GetXPaddingInteger();
		int unit=  xPadding/10;
		int min = (IntStartAtLowestSpecifiedNumberAxisX)? SpecifiedLowestStartingNumberAxisX : xMin.Get<int>();
		for(int e = 0; e < 11 ; e++){
			float x = ResolveX(Value(min));
			if(e!=10 && e !=0) DrawLineAlphaFriendly(img,X -((X*0.10)+(paddingX*x)),Y*0.09,X -((X*0.10)+(paddingX*x)),Y*0.10);
			DrawTextAlphaFriendly(img,X*0.05,Y -((Y*0.11)+(paddingX*x)),Format(min),70*10);
			min += unit;
		}	*/
		//TODO
	}else if(XValueType == ValueTypeEnum::DATE){
		int numberOfDays = xMax.Get<Date>() - xMin.Get<Date>();
		int decrmented = numberOfDays -1; //this used to be on the for loop (defining it before prevent calculation at each iteration)
		Date unit= static_cast<Date>( xMin.Get<Date>());
		for (int e = 0; e < numberOfDays; e++){
			float x = ResolveX(Value(unit));
			DrawLineAlphaFriendly(img,(X*0.10)+(paddingX*x),(Y*0.89),(X*0.10)+(paddingX*x),(Y*0.91),-1,Color(1,1,1),AlphaCall);
			DrawTextAlphaFriendly(img,(X*0.107)+(paddingX*x),(Y*0.91),Format(unit),320*10,StdFont(GraphFontSize-2),Color(1,1,1),AlphaCall);
			unit++;
		}
	}
	if(YValueType == ValueTypeEnum::INT){
		int yPadding = GetYPadding();
		int unit=  yPadding/10;
		int demiUnit = unit/2;
		int min = (IntStartAtLowestSpecifiedNumberAxisY)? SpecifiedLowestStartingNumberAxisY : yMin.Get<int>();
		for(int e = 0; e < 11 ; e++){
			float y = ResolveY(Value(min));
			if(e!=10 && e !=0) DrawLineAlphaFriendly(img,X*0.09,Y -((Y*0.10)+(paddingY*y)),X*0.10,Y -((Y*0.10)+(paddingY*y)),-1,Color(1,1,1),AlphaCall);
			DrawTextAlphaFriendly(img,X*0.02,Y -((Y*0.11)+(paddingY*y)),String(std::to_string(min)),0,StdFont(GraphFontSize +1),Color(1,1,1),AlphaCall);
			min += demiUnit;
			y = ResolveY(Value(min));
			if(e!=10){
				DrawLineAlphaFriendly(img,X*0.09,Y -((Y*0.10)+(paddingY*y)),X*0.095,Y -((Y*0.10)+(paddingY*y)),-1,Color(1,1,1),AlphaCall);
				DrawTextAlphaFriendly(img,X*0.02,Y -((Y*0.11)+(paddingY*y)),String(std::to_string(min)),0,StdFont(GraphFontSize -2),Color(1,1,1),AlphaCall);
			}
			min += demiUnit;
		}	
	}else if(YValueType == ValueTypeEnum::DATE){	
		//TODO
	}
	
}

String GraphDotCloud::ToJson(){
	return "Supposed to Be Json";
}

String GraphDotCloud::GetInformation(){
	String information=Graph::GetInformation();

	information << "Type of graph : " << this->TypeOfGraph() <<"\n";
	information << "Legends showed : " << showLegendsOfCourbes << "\n";
	information << "Dot Value Showed : " << showValueOfDot << "\n";
	information << "Graph signed  : " << signIt << "\n";
	information << "ValueShowedOnAxis : "<< ValueOnAxis <<"\n";
	information << "X Axis specified hightest Range : " << IntStartAtHighestSpecifiedNumberAxisX << String( IntStartAtHighestSpecifiedNumberAxisX? (" Value -> " + GetSpecifiedHighestStartingNumberAxisX()):"" ) << "\n";
	information << "X Axis specified lowest Range : " << IntStartAtLowestSpecifiedNumberAxisX <<  String( IntStartAtLowestSpecifiedNumberAxisX? (" Value -> " + GetSpecifiedLowestStartingNumberAxisX()):"" ) << "\n";
	String buffer="";
	if(IntStartAtHighestSpecifiedNumberAxisY) buffer << " Value -> " <<  String(std::to_string(GetSpecifiedHighestStartingNumberAxisY()));
	information << "Y Axis specified hightest Range : " << IntStartAtHighestSpecifiedNumberAxisY << buffer << "\n";
	buffer="";
	if(IntStartAtLowestSpecifiedNumberAxisY) buffer << " Value -> " <<  String(std::to_string(GetSpecifiedLowestStartingNumberAxisY()));
	information << "Y Axis specified lowest Range : " << IntStartAtLowestSpecifiedNumberAxisY <<buffer << "\n";
	information << "Graph number date showed : " << ((UseMaxDatePadding)? AsString(SpecifiedMaxDatePadding) : "none") <<"\n";;
	information << "Value gap : Xmax->" << GetHighestValueX().ToString() << " Xmin->" << GetLowestValueX().ToString() << " Ymax->" <<GetHighestValueY().ToString() <<" Ymin->"<<GetLowestValueY().ToString() <<"\n";
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
 
const ImageDraw& GraphDotCloud::DrawGraph(){ //Used generate temp.png 
	float x=  sz.cx;
	float y=  sz.cy;
	float xLegend= sz.cx;
	if(showLegendsOfCourbes) xLegend= x*0.90; //Using only 80% of the image to draw Graph, last 20 % will be to draw legends
	
	if(alphaMode){
		img.Alpha().DrawRect(0, 0, x, y,GrayColor(0));
	}else{
		img.DrawRect(0, 0, x, y,White());	
	}
	//img.DrawImage(0,0,WowImg::Cat());
	DrawFlecheAlphaFriendly(img,(xLegend*0.09),(y*0.91),(xLegend*0.09),(y*0.10),DirectionLabel::HAUT);
	DrawFlecheAlphaFriendly(img,(xLegend*0.09),(y*0.91),(xLegend*0.90),(y*0.91),DirectionLabel::DROITE);
	float courbePadding=0.07;
	float YAxisHelper=0.20;
	StartTranslation();		//Here I must describe and calcul the xf equivalent of value contened in dot;
							//It mean I will have to loop through every dot find the lowest and max value and do
							//A translation to our graph
	AjustTranslation();
	float paddingAxisX = (xLegend*0.90)- (xLegend*0.10);
	float paddingAxisY = (y*0.90)- (y*0.10);
	
	if(ValueOnAxis)DrawValueOnAxisAlphaFriendly(img,xLegend,y,paddingAxisX,paddingAxisY);
	bool first =false;
	bool dontLink = false;
	float BufferResolverX = 0.0;
	float BufferResolverY = 0.0;
	for(Courbe &c : this->courbes){
		first =true;
		if(showLegendsOfCourbes){
			DrawLineAlphaFriendly(img,(x*0.87),(y*YAxisHelper),(x* 0.90),(y*YAxisHelper),GraphTikeness*2,c.GetColor());
			DrawTextAlphaFriendly(img,(x*0.91),(y*(YAxisHelper -0.02 )),c.GetName(),0,StdFont(GraphFontSize*1.5));
			YAxisHelper += courbePadding;
		}
		if(TranslationDone){ //Just looking if translation have been done
			
			for(Dot d : c.GetDots()){
				if(!OutThePerimeterX(d.GetXVal()) && !OutThePerimeterY(d.GetYVal())){
					float resolverX = ResolveX(d.GetXVal());
					float resolverY = ResolveY(d.GetYVal());
					if(resolverY !=-1 && resolverX !=-1){
						if(c.DotIsShowed())DrawEllispeAlphaFriendly(img,(((xLegend*0.10) + ( paddingAxisX * resolverX))) , (y- ((y*0.10)+(paddingAxisY*resolverY))) ,10,10,c.GetColor());
						if(!first && c.IsLinked()&& !dontLink)DrawLineAlphaFriendly(img,(((xLegend*0.10) + ( paddingAxisX * resolverX)))+3 , (y- ((y*0.10)+(paddingAxisY*resolverY)))+3,(((xLegend*0.10) + ( paddingAxisX * BufferResolverX)))+3 , (y- ((y*0.10)+(paddingAxisY*BufferResolverY)))+3,this->GetGraphTikeness(),c.GetColor());
						if(showValueOfDot)DrawTextAlphaFriendly(img,(((xLegend*0.11) +(paddingAxisX * resolverX))),(y- ((y*0.11)+(paddingAxisY*resolverY))),d.GetYVal().ToString(),0,StdFont(GetGraphFontSize() -3).Bold(true));
					}
					first=false;
					BufferResolverX =resolverX;
					BufferResolverY =resolverY;
					dontLink=false;
				}else{
					dontLink = true;
				}
			}
		}
	}
	
	if (showAxisNames){
		DrawTextAlphaFriendly(img,(xLegend*0.92),(y*0.89),XName,0,StdFont(GraphFontSize *1.5));
		DrawTextAlphaFriendly(img,(xLegend*0.07),(y*0.04),YName,0,StdFont(GraphFontSize *1.5));
	}
	if(showGraphName){
		DrawTextAlphaFriendly(img,(xLegend*0.40),(y*0.07),graphName,0,StdFont(GraphFontSize *1.5));
	}
	if(signIt){
		if(showLegendsOfCourbes){
			DrawImageAlphaFriendly(img,(xLegend*0.93),(y*0.93),WowImg::SmartUppBot);
			DrawImageAlphaFriendly(img,0,(y*0.94),WowImg::UltimatePP);
		}else{
			DrawImageAlphaFriendly(img,(xLegend*0.83),0,WowImg::UltimatePP);
			DrawImageAlphaFriendly(img,(xLegend*0.83),(y*0.06),WowImg::SmartUppBot);
		}
			
	}
	return img;
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
		int iMax = static_cast<int>(xMax.Get<int>());
		iMax += iMax *0.02;
		int iMin = static_cast<int>(xMin.Get<int>());
		iMin -= iMin *0.02;
		xMax = Value(iMax);
		xMin = Value(iMin);
	}else if(XValueType == ValueTypeEnum::DATE){
		Date dMax = static_cast<Date>(xMax.Get<Date>());
		Date dMin =  static_cast<Date>(xMin.Get<Date>());
		dMax++;
		dMin--;
		xMax = Value(dMax);
		xMin = Value(dMin);
	}
	if(YValueType == ValueTypeEnum::INT){
		int iMax = static_cast<int>(yMax.Get<int>());
		iMax += iMax *0.05;
		int iMin = static_cast<int>(yMin.Get<int>());
		iMin -= iMin *0.05;
		yMax = Value(iMax);
		yMin = Value(iMin);		
	}else if(YValueType == ValueTypeEnum::DATE){	
		Date dMax = static_cast<Date>(yMax.Get<Date>());
		Date dMin =  static_cast<Date>(yMin.Get<Date>());
		dMax++;
		dMin--;
		yMax = Value(dMax);
		yMin = Value(dMin);
	}
	return TranslationDone;
}

void GraphDotCloud::AjustTranslation(){ //Ajust translation allow graph to recalculate is YMax/YMin based on XMax/YMax
	yMax = Value();
	yMin = Value();
	for(Courbe &c : this->courbes){
		if (c.GetXValueType() == XValueType && c.GetYValueType() == YValueType){
			for(Dot d : c.GetDots()){
				if(!OutThePerimeterX( d.GetXVal())){
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
	}
	if(YValueType == ValueTypeEnum::INT){
		int iMax = static_cast<int>(yMax.Get<int>());
		iMax += iMax *0.05;
		int iMin = static_cast<int>(yMin.Get<int>());
		iMin -= iMin *0.05;
		yMax = Value(iMax);
		yMin = Value(iMin);		
	}else if(YValueType == ValueTypeEnum::DATE){	
		Date dMax = static_cast<Date>(yMax.Get<Date>());
		Date dMin =  static_cast<Date>(yMin.Get<Date>());
		dMax++;
		dMin--;
		yMax = Value(dMax);
		yMin = Value(dMin);
	}
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


Value GraphDotCloud::GetLowestValueX(){
	if(XValueType == ValueTypeEnum::INT){
		return ((IntStartAtLowestSpecifiedNumberAxisX)? Value(GetSpecifiedLowestStartingNumberAxisX()):xMin);
	}else if(XValueType == ValueTypeEnum::DATE){
		if(UseMaxDatePadding){
			Date d = static_cast<Date>(xMax.Get<Date>());
			d.Set( d.Get()-SpecifiedMaxDatePadding);
			return Value(d);
		}
		return xMin;
	}
	return Value();
}

Value GraphDotCloud::GetLowestValueY(){
	if(YValueType == ValueTypeEnum::INT){
		return ((IntStartAtLowestSpecifiedNumberAxisY)? Value(GetSpecifiedLowestStartingNumberAxisY()):yMin);
	}else if(YValueType == ValueTypeEnum::DATE){
		if(UseMaxDatePadding){
			Date d = static_cast<Date>(yMax.Get<Date>());
			d.Set( d.Get() -SpecifiedMaxDatePadding);
			return Value(d);
		}
		return yMin;
	}	
	return Value();
}
Value GraphDotCloud::GetHighestValueX(){
	if(XValueType == ValueTypeEnum::INT){
		return ((IntStartAtHighestSpecifiedNumberAxisX)? Value(GetSpecifiedHighestStartingNumberAxisX()):xMax);
	}else if(XValueType == ValueTypeEnum::DATE){
		return xMax;
	}	
	return Value();
}
Value GraphDotCloud::GetHighestValueY(){
	if(YValueType == ValueTypeEnum::INT){
		return ((IntStartAtHighestSpecifiedNumberAxisY)? Value(GetSpecifiedHighestStartingNumberAxisY()):yMax);
	}else if(YValueType == ValueTypeEnum::DATE){
		return yMax;
	}	
	return Value();
}

float GraphDotCloud::ResolveX(Value xToResolve){
	if (TranslationDone){
		if(XValueType == ValueTypeEnum::INT){
			Cout() << "Value to resolve : " << xToResolve.Get<int>()<<"\n";
			if(!OutThePerimeterX(xToResolve)){  
				float padding =  GetXPadding().Get<int>(); //Here I apply Lowest/Highest if set true
				float result = (padding -(GetHighestValueX().Get<int>() - xToResolve.Get<int>()))/padding;
				return result;
			}
			return -1;
		}else if(XValueType == ValueTypeEnum::DATE){
			if(!OutThePerimeterX(xToResolve)){
				float padding =  GetXPadding().Get<int>();
				padding++;
				float result = (padding -( GetHighestValueX().Get<Date>().Get() - xToResolve.Get<Date>().Get()))/padding;
				return result;
			}
			return -1;
		}
	}
	return -1;
}

bool GraphDotCloud::OutThePerimeterX(Value xToResolve){
	if(XValueType == ValueTypeEnum::INT){
		return (xToResolve.Get<int>() < GetLowestValueX().Get<int>() || xToResolve.Get<int>() > GetHighestValueX().Get<int>());
	}else if(XValueType == ValueTypeEnum::DATE){
		return (xToResolve.Get<Date>() < GetLowestValueX().Get<Date>() || xToResolve.Get<Date>() > GetHighestValueX().Get<Date>());
	}
	return false;
}

bool GraphDotCloud::OutThePerimeterY(Value xToResolve){
	if(YValueType == ValueTypeEnum::INT){
		return (xToResolve.Get<int>() < GetLowestValueY().Get<int>() || xToResolve.Get<int>() > GetHighestValueY().Get<int>());
	}else if(YValueType == ValueTypeEnum::DATE){
		return (xToResolve.Get<Date>() < GetLowestValueY().Get<Date>() || xToResolve.Get<Date>() > GetHighestValueY().Get<Date>());
	}
	return false;
}

Value GraphDotCloud::GetYPadding(){
	if(YValueType == ValueTypeEnum::INT){
		return GetHighestValueY().Get<int>()-GetLowestValueY().Get<int>(); //Here I apply Lowest/Highest if set true
	}else if(YValueType == ValueTypeEnum::DATE){
		return GetHighestValueY().Get<Date>()-GetLowestValueY().Get<Date>(); //Here I apply Lowest/Highest if set true
	}
	return Value();
}

Value GraphDotCloud::GetXPadding(){
	if(XValueType == ValueTypeEnum::INT){
		return GetHighestValueX().Get<int>()-GetLowestValueX().Get<int>(); //Here I apply Lowest/Highest if set true
	}else if(XValueType == ValueTypeEnum::DATE){
		return GetHighestValueX().Get<Date>()-GetLowestValueX().Get<Date>(); //Here I apply Lowest/Highest if set true
	}
	return Value();
}

float GraphDotCloud::ResolveY(Value yToResolve){
	if(TranslationDone){
		if(YValueType == ValueTypeEnum::INT){
			if(!OutThePerimeterY(yToResolve)){
				float padding = GetYPadding().Get<int>(); //Here I apply Lowest/Highest if set true
				float result = (padding -(GetHighestValueY().Get<int>()- yToResolve.Get<int>()))/padding;
				return result;
			}
			return -1;
		}else if(YValueType == ValueTypeEnum::DATE){
			if(!OutThePerimeterY(yToResolve)){
				float padding =  GetYPadding().Get<int>();
				padding++;
				float result = (padding -(GetHighestValueY().Get<Date>().Get() - yToResolve.Get<Date>().Get()))/padding;
				return result;
			}
			return -1;
		}
	}
	return -1;
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
GraphDotCloud::GraphDotCloud(int _XSize,int _YSize):img(_XSize,_YSize){
	Size _sz;
	_sz.cy = _YSize;
	_sz.cx = _XSize;
	sz = _sz;
	;
}
GraphDotCloud::GraphDotCloud(int _XSize,int _YSize,String _GraphName):img(_XSize,_YSize){
	Size _sz;
	_sz.cy = _YSize;
	_sz.cx = _XSize;
	sz = _sz;
	graphName = _GraphName;
}
GraphDotCloud::GraphDotCloud(int _XSize,int _YSize,String _GraphName, String _XName, String _YName):img(_XSize,_YSize){
	Size _sz;
	_sz.cy = _YSize;
	_sz.cx = _XSize;
	sz = _sz;
	graphName = _GraphName;
	XName= _XName;
	YName= _YName;
}
GraphDotCloud::GraphDotCloud(Size _sz,String _GraphName, String _XName, String _YName):img(_sz.cx,_sz.cy){
	sz = _sz;
	graphName = _GraphName;
	XName= _XName;
	YName= _YName;
}
GraphDotCloud::GraphDotCloud(Size _sz,String _GraphName):img(_sz.cx,_sz.cy){
	sz = _sz;
	graphName = _GraphName;
}
GraphDotCloud::GraphDotCloud(Size _sz):img(_sz.cx,_sz.cy){
	sz = _sz;
}



/***********************************************/
// Class Courbe 
/***********************************************/

void Courbe::ValueToShow(LabelValueToShow _labelToShow){ //Define axis label to show
	labelToShow = _labelToShow;
}

Dot& Courbe::operator[](int iterator){
	return dots[iterator];
}

Dot& Courbe::AddDot(Dot d){
	return dots.Add(d);	
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
	information <<"    IsLinked : " << this->linked <<"\n";   
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

void Courbe::SetLinked(bool b){
		linked =b;
}
bool Courbe::IsLinked(){
	return linked;
}
void Courbe::ShowDot(bool b){
	showDot = b;
}
bool Courbe::DotIsShowed(){
	return showDot;
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
