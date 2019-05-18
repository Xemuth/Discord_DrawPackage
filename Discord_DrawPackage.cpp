#include <Core/Core.h>
#include "Discord_DrawPackage.h"
#include <Draw/Draw.h>
#include <CtrlLib/CtrlLib.h>
#include <cctype>
using namespace Upp;

void Discord_DrawPackage::drawTest(ValueMap payload){
	String channel  = payload["d"]["channel_id"];
    String userName = payload["d"]["author"]["username"];
    String id = payload["d"]["author"]["id"];
    String discriminator = payload["d"]["author"]["discriminator"];
	Upp::String message = payload["d"]["content"];
	message.Replace(String("!" +prefix +" "),"");
	Cout() <<message <<"\n";
	Vector<String> args = Split(message," ");
	if(message.GetCount() > 0 && args.GetCount() > 1 && isStringisANumber(args[0]) && isStringisANumber(args[1]) ){
		try{
			args[0].Replace("+","");
			args[1].Replace("+","");
			float x =std::stof( args[0].ToStd());
			float y = std::stof(args[1].ToStd());
			String toDraw="";
			if(args.GetCount()>2){
				for(int i = 2; i < args.GetCount(); i++){
					toDraw << ((i !=2)? " ":"" ) + args[i];
				}
			}else{
				toDraw <<  "Test Draw !";
			}
			
			ImageDraw w(x,  y );
			w.DrawRect(0, 0, x, y, SWhite());
			w.DrawText( (x*0.2), (y*0.2) , 320*10 ,toDraw,Roman(((x)+(y))/toDraw.GetCount() )); // il faut adapter la taille du text par rapport à la taille de l'image et à la longueur de celui-ci
		
			PNGEncoder png;
		    Image m = w;
		    png.SaveFile("temp.png", m);
			ptrBot->CreateMessage(channel, "Event " + name +" ; taille du text : " + String(std::to_string( ((x)+(y))/toDraw.GetCount())) );
			ptrBot->SendFile(channel,"", "Draw Test", "temp.png");
		}
		catch(...){
			ptrBot->CreateMessage(channel, "Erreur d'argument !");
		}
	}else{
		ptrBot->CreateMessage(channel, "Erreur d'argument !");
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

	Events.Add([&](ValueMap e){this->drawTest(e);});
}

void Discord_DrawPackage::Event(ValueMap payload){
	for(auto &e : Events){
		e(payload);
	}
}