#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <SDL2/SDL.h>

char* hex="0123456789ABCDEF";
char* ao="_abcdefghijklmno";
char* pz="pqrstuvwxyz";
char* words[]={
"latency","agony","memory","envy","identity","authority","certainty","transparency",
"analogy","conformity","fragility","serenity","tenacity","practicality","humility","epiphany",
"complexity","simplicity","normality","absurdity","anxiety","sobriety","urgency","emergency",
"ability","utility","affinity","concurrency","sympathy","apology","empathy","unity",
"personality","mentality","hostility","expectancy","morality","complacency","hilarity","indignity",
"humanity","fallacy","atrocity","severity","priority","necessity","reality","actuality",
"mobility","possibility","responsibility","availability","camaraderie","policy","ubiquity","conspiracy",
"harmony","family","secrecy","credibility","telepathy","legality","physicality","anonymity",
"reciprocity","immortality","curiosity","notability","plausibility","deniability","vulnerability","security",
"incredulity","integrity","antipathy","solidarity","energy","entropy","gravity","density",
"technology","ecstasy","mimicry","destiny","enmity","amnesty","vanity","tragedy",
"comedy","idolatry","prophecy","agency","divinity","virtuosity","subtlety","delivery",
"liberty","anatomy","contingency","dependency","civility","liability","externality","monopoly",
"society","nobility","democracy","autocracy","similarity","individuality","objectivity","subjectivity",
"serendipity","synchronicity","ideaology","duplicity","obscurity","symbology","ideality","popularity",
"celebrity","notoriety","fatality","brutality","biology","pathology","specificity","generality",
"futility","radicality","rationality","generosity","sensibility","fantasy","anomaly","idiopathy",
"novelty","tendency","formality","rigidity","finality","enemy","immutability","iniquity",
"superficiality","honesty","solidity","fidelity","sensitivity","frigidity","duality","causality",
"anisotropy","familiarity","scarcity","variety","fertility","vitality","primality","centrality",
"frivolity","exclusivity","animosity","hospitality","reflexivity","suitability","selectivity","matrimony",
"accuracy","uniformity","savagery","villainy","privacy","validity","posterity","history",
"irony","originality","ontology","theology","virality","quotability","predictability","dependability",
"stability","equity","generativity","regularity","ambiguity","discrepancy","frequency","modality",
"chronology","autonomy","deformity","dexterity","numerosity","flexibility","nativity","gentility",
"decency","community","naturality","warranty","damnability","cruelty","genealogy","opacity",
"spontaneity","duty","chivalry","regency","majority","minority","anarchy","monarchy",
"ordinality","cardinality","dichotomy","inanity","relativity","positivity","negativity","pity",
"narrativity","naivete","irritabiity","ferocity","apathy","supremacy","polarity","subsidy",
"visibility","ethnicity","morphology","etymology","antiquity","futurology","intimacy","sanity",
"mockery","flattery","psychopathy","sociopathy","safety","morbidity","infancy","maturity",
"monstrosity","presentability","neutrality","potency","insanity","pedantry","diversity","bigotry"};

int main(int argc, char *argv[])
{		
		int a,b,c,d=0;
		int e,f,g,h=0;
       void feel_time(){
       	a=(clock()/(256)%256);b=(clock()%256);
		   SDL_Delay(25);
		   c=(clock()/(256))%256;d=(clock()%256);
		   e=(a+1)%256;f=(b+1)%256;
		   g=(c+1)%256;h=(d+1)%256;}
		feel_time();
		
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_CreateWindowAndRenderer(
			0,0,0, &window, &renderer);
		SDL_Rect box;SDL_Rect* boxp=&box;
		SDL_GetDisplayBounds(0,boxp);
		 int width=box.w;
		 int height=box.h;
		 int grid = height/32;
		 int xcels = width/grid;
		 int ycels = height/grid;

		SDL_Color gray= {0x99,0x99,0x99,0xFF};
 	   SDL_Color green= {0x00,0xFF,0x00,0xFF};
 	   SDL_Color black = {0x00,0x00,0x00,0xFF};
		SDL_Color pink = {0xFF,0x99,0x99,0xFF};
		SDL_Color yellow = {0xFF,0xFF,0x00,0xFF};
		SDL_Color purple = {0xFF,0x00,0xFF,0xFF};
		SDL_Color red = {0xFF,0x00,0x00,0xFF};
		SDL_Color orange = {0xFF,0xCC,0x00,0xFF};
		SDL_Color white = {0xFF,0xFF,0xFF,0xFF };
		SDL_Color cyan = {0x00,0xCC,0xFF,0xFF};
		SDL_Color blue = {0x00,0x00,0xFF,0xFF};
		SDL_Color pallet[10]={
		green,gray,pink,yellow,purple,
		red,orange,white,cyan,blue};
		void lite(int index){
			SDL_SetRenderDrawColor(renderer,
   			pallet[index%10].r,pallet[index%10].g,
  	 	    pallet[index%10].b,pallet[index%10].a);}
		void dark(){
			SDL_SetRenderDrawColor(
			renderer,0,0,0,255);}
		void line(int x,int y,int x2,int y2){
				int linewidth=2;
		 	for(int w=linewidth*-1;w<linewidth;w++){
		 		SDL_RenderDrawLine(
					renderer,x+w,y+w,x2+w,y2+w);
				SDL_RenderDrawLine(
					renderer,x-w,y+w,x2-w,y2+w);} }
		int wcel=0;
		int xcel = 0;
		 int ycel = 0;
		 int zcel = 0;
		void etch(char rune){
			int x=xcel*grid+0.125*grid;
			int y=ycel*grid+0.125*grid;
			int size=grid*0.75;
			int x2=x+size/2;int y2=y+size/2;
			int x3=x+size;int y3=y+size;
			void t(){line(x,y,x3,y);}
			void l(){line(x,y,x,y3);}
			void tl(){line(x,y,x2,y2);}
    		void tr(){line(x2,y2,x3,y);}
    		void r(){line(x3,y,x3,y3);}
			void bl(){line(x,y3,x2,y2);}
			void br(){line(x3,y3,x2,y2);}
 	   	void b(){line(x,y3,x3,y3);}
 	 	  switch(rune){
 	 	  	case '_':b();break;
        		case 'a':bl();tr();r();break;
        		case 'b':l();tl();br();b();break;
        		case 'c':bl();tr();b();break;
        		case 'd':l();t();bl();tr();break;
        		case 'e':t();l();b();break;
        		case 'f':t();tl();br();l();break;
        		case 'g':t();l();b();tl();br();break;
        		case 'h':l();r();break;
        		case 'i':t();b();break;
        		case 'j':b();r();break;
        		case 'k':l();bl();tr();b();break;
        		case 'l':l();b();break;
        		case 'm':l();t();r();break;
        		case 'n':l();tl();br();r();break;
        		case 'o':l();t();r();b();break;
        		case 'p':l();tl();t();br();r();break;
        		case 'q':l();t();bl();tr();r();break;
        		case 'r':l();t();break;
        		case 's':t();tl();br();b();break;
        		case 't':t();tr();bl();r();break;
        		case 'u':l();b();r();break;
        		case 'v':l();bl();tr();break;
        		case 'w':l();tl();bl();tr();br();r();break;
        		case 'x':tl();bl();tr();br();break;
        		case 'y':tl();br();r();b();break;
        		case 'z':t();tr();bl();b();break;
        		case '0':t();tl();tr();bl();br();b();break;
        		case '1':tl();tr();br();r();break;
        		case '2':tl();tr();l();bl();break;
        		case '3':tl();tr();bl();br();b();break;
        		case '4':bl();tr();br();r();break;
        		case '5':tl();tr();bl();br();r();break;
        		case '6':tr();bl();break;
        		case '7':tl();tr();bl();break;
        		case '8':l();tl();bl();br();break;
        		case '9':tl();br();break;
        		case 'A':l();tl();bl();tr();br();break;
        		case 'B':tl();tr();br();break;
        		case 'C':tl();tr();bl();br();b();break;
        		case 'D':tl();bl();br();break;
        		case 'E':bl();tr();br();break;
        		case 'F':tl();tr();bl();br();break;
        		default:break;}}
       void cast(int xc,int yc,char* rs,int color){
			char rune=0;xcel=xc;ycel=yc;lite(color);
			while(rune=rs[xcel-xc]){
				etch(rune);xcel++;}}
		
       
       SDL_Event event;
	Uint8 done = 0;
      while(!done){
     	while(SDL_PollEvent(&event)){
		     if(event.type == SDL_QUIT)done = 1;
		     else if ( event.type==SDL_FINGERDOWN){
		     	int y=round(event.tfinger.y* height);
		     	if(y<(height*0.5))feel_time();
		     	else if(y<(height*0.75))
		     		wcel=(wcel+240)%256;
		     	else wcel=(wcel+16)%256;}}
		     	
		dark();SDL_RenderClear(renderer);
		
		cast(0,0,"abcdefg",7);
		cast(0,1,"hijklmnop",7);
		cast(0,2,"qrstuv",7);
		cast(0,3,"wxyz",7);
		
		cast(xcels-4,0,"0123",7);
		cast(xcels-4,1,"4567",7);
		cast(xcels-4,2,"89AB",7);
		cast(xcels-4,3,"CDEF",7);
		
		cast(1,5,words[a],7);
		cast(1,6,words[e],1);
		cast(3,7,words[b],7);
		cast(3,8,words[f],1);
		cast(1,10,words[c],7);
		cast(1,11,words[g],1);
		cast(3,12,words[d],7);
		cast(3,13,words[h],1);
		
		ycel=16;zcel=wcel;
		while(ycel<ycels){
			char* runes=words[zcel];
			xcel=0;
			while(runes[xcel]){
				lite(zcel);etch(runes[xcel]);xcel++;}
			xcel=xcels-2;lite(7);
			etch(hex[zcel/16]);xcel++;
			etch(hex[zcel%16]);
			ycel++;zcel++;
			if(zcel==256)zcel=0;}
		SDL_RenderPresent(renderer);
		SDL_Delay(25);
	 }
    exit(0);
}