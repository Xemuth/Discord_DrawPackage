#include <Core/Core.h>
#include "GraphBuilder.h"
#include <Draw/Draw.h>
#include <CtrlLib/CtrlLib.h>
#include <cctype>
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
	Cout() << message <<"\n";
	Vector<String> args = Split(message," ");
	if(args.GetCount() >0 &&  args[0].Compare("test")==0){
		if (FileExists("./example.json")){
			FileIn in("./example.json");
			if(in){
				String e="";
				in.Seek(0);
				while(!in.IsEof())
					e+=in.GetLine();
				
			
				ValueMap data = ParseJSON(e);
			
				//graphicalImage myGraph(500,500,White());
				//myGraph.drawByValueMap(data);
				
			}	
		}
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