
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include <stdbool.h>



#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 800

#define FRAMES_PER_SECOND 30
#define NUM_FRAMES 2

#define FRAME_DELAY (1000 / FRAMES_PER_SECOND)

int main()
{

SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    char nom[30];
    printf("Veuillez taper votre nom:");
    scanf("%s",nom);
    SDL_Surface* screen = NULL;
   int partage=0;
    background c,g;
    background1 c1,c2;


    
int afficherGuide=0;


  int tempsEcoule;
 int tempsAffiche = 1; 
    c.walk_right_permission = 1;
    c.walk_left_permission =1;
    c.is_running_right = 0;
    c.is_running_left = 0;
    c.acceleration=1.0f;
    c.start_time=0;
    c.elapsed_time=0;
    Uint32 start_time = SDL_GetTicks();
    Uint32 current_time = SDL_GetTicks();
    
    
    
 
    c.shift_pressed = 0;
 
    
   int current_frame = 0;
c1.walk_right_permission = 1;
    c1.walk_left_permission =1;
    c1.is_running_right = 0;
    c1.is_running_left = 0;
    c1.acceleration=1.0f;
    c1.start_time=0;
    c1.elapsed_time=0;
    
    c1.shift_pressed = 0;
    
    
    c2.walk_right_permission = 1;
    c2.walk_left_permission =1;
    c2.is_running_right = 0;
    c2.is_running_left = 0;
    c2.acceleration=1.0f;
    c2.start_time=0;
    c2.elapsed_time=0;
    c2.shift_pressed = 0;
    
    SDL_Init(SDL_INIT_EVERYTHING);

    
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("rayengame", NULL);

	int tempspb=0,tempsab=0;
	int vb=1;


    initbackground (&c);
initbackgroundg (&g);


c1.menu2=NULL ;
c1.menu2 = IMG_Load("back.png");
c2.menu3=NULL ;
c2.menu3= IMG_Load("back.png");
initcamera (&c1);
initcameramultiplayer (&c2);


    musique(1);

    SDL_Rect button_rect = { 100, 50, 0, 0 };
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface* button_surface = TTF_RenderText_Solid(TTF_OpenFont("font.ttf", 40),"Show Scores",textColor);
    button_rect.w = button_surface->w;
    button_rect.h = button_surface->h;

   SDL_Rect button_rect1 = { 1300, 750, 0, 0 };
    SDL_Color textColor1 = {255, 255, 255};
    SDL_Surface* button_surface1 = TTF_RenderText_Solid(TTF_OpenFont("font.ttf", 50),"Guide",textColor1);
    button_rect1.w = button_surface1->w;
    button_rect1.h = button_surface1->h;
SDL_Rect button_rect2 = { 100, 750, 0, 0 };
    SDL_Color textColor2 = {255, 255, 255};
    SDL_Surface* button_surface2 = TTF_RenderText_Solid(TTF_OpenFont("font.ttf", 40),"back",textColor2);
    button_rect2.w = button_surface2->w;
    button_rect2.h = button_surface2->h;
   
SDL_Rect control;
control.x=750;
control.y=0;
control.h=800;
control.w=1500;
 TTF_Font *font = TTF_OpenFont("font.ttf", 30);
if (!font) {
    printf("Erreur chargement police : %s\n", TTF_GetError());
    return 1;
}
Animation myanimation;
if (!init_animation(&myanimation)) {
        printf("Failed to initialize animation.\n");
        SDL_Quit();
        return 1;
    }
 myanimation.pos.x=600;
myanimation.pos.y=90;    



   


    int boucle = 1;
float xxx=510;
float yyy=75;
float aaa=1080;
int ccc=5;
int xp=10;
int yp=565;



    SDL_Event event;


    background back;


    boutton ques,red,ice,enm,redp,enmp;
Uint8 *keystates = SDL_GetKeyState(NULL);

	


   


   
    
    

 

	initialiser_ques(&ques,500,0);
	initialiser_red(&red,xxx,yyy);
	initialiser_ice(&ice,580,65);
	initialiser_enm(&enm,xxx+20,75);
	initialiser_redp(&redp,xp,yp);
	initialiser_enmp(&enmp,xp+20,yp);
	
	


    


    while (boucle == 1)
    {
	    Uint32 currentTime = SDL_GetTicks();
Uint32 tempsEcoule = (currentTime - start_time) / 1000;
      
         
  
        afficher_background(screen,c);

   
      afficher_animation(myanimation, screen);
        
        SDL_BlitSurface(button_surface, NULL, screen, &button_rect);
 SDL_BlitSurface(button_surface1, NULL, screen, &button_rect1);	
SDL_BlitSurface(button_surface2, NULL, screen, &button_rect2);		
 if(partage){
                              SDL_BlitSurface(c1.menu2,&c1.camera1,screen,NULL);
                             SDL_BlitSurface(c2.menu3,&c2.camera1,screen,&control);
}
if (afficherGuide) {
    afficher_background1(screen, g);  
} 
afficherTemps(screen, font, tempsEcoule);
	SDL_Flip(screen);
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_FreeSurface(c.menu1);
                    SDL_FreeSurface(c1.menu2);
                     SDL_FreeSurface(c2.menu3);
                    SDL_Quit();
                    boucle= 0;
                case SDL_MOUSEBUTTONDOWN:
                 if (event.button.x >= button_rect1.x && event.button.x < button_rect1.x + button_rect1.w &&
    event.button.y >= button_rect1.y && event.button.y < button_rect1.y + button_rect1.h) {
    afficherGuide = 1;  
}
                  
                   break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        
                          case SDLK_p:                      
                           partage=1;
                           break;
                        case SDLK_a:
                        partage = 0;
                        break;
                         case SDLK_b:
                     afficherGuide= 0;
                        break;
                         case SDLK_g:
                     afficherGuide= 1;
                        break;
                        case SDLK_ESCAPE:
                        boucle=0;
                        break;
                        case SDLK_RIGHT:
                       if (!c.is_running_left) {
                            
                            c.is_running_right = 1;
                            }
                       
                        if (!c2.is_running_left && partage==1) {
                	    
                	    c2.is_running_right = 1;
                	    }
                	    
                            break;
                            
                       case SDLK_d:
                        if (!c1.is_running_left) {
                            
                            c1.is_running_right = 1;
                            }
                            break;
                          
                	   
                            
                            
                           
                        case SDLK_LEFT:
                	    if (!c.is_running_right) {
                	    
                	    c.is_running_left = 1;
                	    }
                	    
                           
                          if (!c2.is_running_right && partage==1) {
                	    
                	    c2.is_running_left = 1;
                	    }
                	    
                            break;



                            case SDLK_q:
                	    if (!c1.is_running_right) {
                	    
                	    c1.is_running_left = 1;
                	    }
                	    
                            break;
                        case SDLK_LSHIFT:
                        	c.shift_pressed = 1;
                        	c.start_time = SDL_GetTicks();
                        	c.acceleration=1.0f;
                            break;
                        case SDLK_DOWN :
                                scrollingdown (&c);
                                 scrollingdown1 (&c2);
                            break;
                        case SDLK_UP :
                                scrollingup (&c);
                                scrollingup1 (&c2);
                                
                                
                            break;
                        case SDLK_z :
                                scrollingup1 (&c1);
                            break;
                         case SDLK_s :
                                scrollingdown1 (&c1);
                        default:
                            break;
                    }
                    
                            
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                      
                           c.is_running_right = 0;
                           c2.is_running_right = 0;
                            break;
                         case SDLK_d:                      
                           c1.is_running_right = 0;
                        break;
                        case SDLK_LEFT:
                      
                           c.is_running_left = 0;
                           c2.is_running_left = 0;
                            break;
                        case SDLK_q:                      
                           c1.is_running_left = 0;
                        break;

                        case SDLK_LSHIFT:
			    c.shift_pressed = 0;
                            c.acceleration=1.0f;
                            c1.shift_pressed = 0;
                            c1.acceleration=1.0f;
                            c2.shift_pressed = 0;
                            c2.acceleration=1.0f;
                            break; 
                  case SDLK_RSHIFT:
			    c.shift_pressed = 0;
                            c.acceleration=1.0f;
                            c1.shift_pressed = 0;
                            c1.acceleration=1.0f;
                            c2.shift_pressed = 0;
                            c2.acceleration=1.0f;
                            break;  
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
     
	if(c.walk_right_permission == 1)
	{
 	if (c.is_running_right) {
            scrolling_right (&c);
        }
        }
      if(c1.walk_right_permission == 1)
	{
 	if (c1.is_running_right) {
            scrolling_right1 (&c1);
        }
        }

if(c2.walk_right_permission == 1)
	{
 	if (c2.is_running_right) {
            scrolling_right1 (&c2);
        }
        }

        if(c.walk_left_permission == 1)
        {
	if (c.is_running_left) {
	scrolling_left (&c);
	}

	}
if(c1.walk_left_permission == 1)
        {
	if (c1.is_running_left) {
	scrolling_left1 (&c1);
	}

	}

if(c2.walk_left_permission == 1)
        {
	if (c2.is_running_left) {
	scrolling_left1 (&c2);
	}

	}
   

if(c.acceleration>=1.0f)
	{
	  c.elapsed_time = SDL_GetTicks() - c.start_time;
	  if (c.elapsed_time < 3000) {
	  float new_K = (c.elapsed_time / 750) * 0.5f + 1.0f;
	  if (new_K <= 3.0f && new_K > c.acceleration) {
	    c.acceleration = new_K;
	    }
	  } else {
	     c.acceleration = 3.0f;
	    }
	  }
	 
	if(c2.acceleration>=1.0f)
	{
	  c2.elapsed_time = SDL_GetTicks() - c2.start_time;
	  if (c2.elapsed_time < 3000) {
	  float new_K = (c2.elapsed_time / 750) * 0.5f + 1.0f;
	  if (new_K <= 3.0f && new_K > c2.acceleration) {
	    c2.acceleration = new_K;
	    }
	  } else {
	     c2.acceleration = 3.0f;
	    }
	  }
if(c1.acceleration>=1.0f)
	{
	  c1.elapsed_time = SDL_GetTicks() - c1.start_time;
	  if (c1.elapsed_time < 3000) {
	  float new_K = (c1.elapsed_time / 750) * 0.5f + 1.0f;
	  if (new_K <= 3.0f && new_K > c1.acceleration) {
	    c1.acceleration = new_K;
	    }
	  } else {
	     c1.acceleration = 3.0f;
	    }
	  }
	ccc=ccc*(-1);
   
        
        afficher_btn(screen, redp);
	afficher_btn(screen, ques);
	afficher_btn(screen,red);
	afficher_btn(screen,ice);
	afficher_btn(screen,enm);
	afficher_btn(screen,enmp);
	
		
        SDL_Flip(screen);
	
	aaa=xxx+10;
	initialiser_enm(&enm,aaa,75);
	afficher_btn(screen,enm);
	
	
	
	if (keystates[SDLK_RIGHT]) {
    if (xxx >= 1120 || (xxx >= 575 && xxx<=600 && yyy > 60)) {
        initialiser_red(&red, xxx, yyy);
    } else {
        xxx=xxx+1;
        initialiser_red(&red, xxx, yyy);
    }
	if(xp>=500){
	initialiser_redp(&redp,xp,yp);}
	else{
	xp=xp+10;
	initialiser_redp(&redp,xp,yp);
	initialiser_enmp(&enmp,xp+20,500);}
	
}
	if (keystates[SDLK_LEFT]) {
		if(xxx<=505 || (xxx<=600 && yyy>60 && xxx>=575)){
		initialiser_red(&red,xxx,yyy);
			}
		else{
		xxx=xxx-1;
                initialiser_red(&red,xxx,yyy);
            		}
	if(xp<=2){
	initialiser_redp(&redp,xp,yp);
	}
	else{	
	xp=xp-10;
	initialiser_redp(&redp,xp,yp);
	initialiser_enmp(&enmp,xp+20,500);
	}}
	if (keystates[SDLK_UP]) {
		if (yyy<=0){
		initialiser_red(&red,xxx,yyy);
		}
		else{
		yyy=yyy-1;
                initialiser_red(&red,xxx,yyy);
            		}
	yp=yp-10;
	initialiser_redp(&redp,xp,yp);
	initialiser_enmp(&enmp,xp+20,500);
	}
	if (keystates[SDLK_DOWN]) {
		if(yyy>=75 || (yyy>=60 && (xxx>575 && xxx<600))){
		initialiser_red(&red,xxx,yyy);
		}
		else{
		yyy=yyy+1;
                initialiser_red(&red,xxx,yyy);
            		}
	if(yp>=565){
	initialiser_redp(&redp,xp,yp);
	}
	else{
		yp=yp+10;
	initialiser_redp(&redp,xp,yp);
	initialiser_enmp(&enmp,xp+20,500);
	}}	


        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
		case SDL_KEYDOWN:
		
		
		
		if (event.key.keysym.sym == SDLK_ESCAPE) {
		boucle=0;
            		}
		break;
                case SDL_QUIT:
                    boucle = 0;
                    break;
               
              

                default:
                    break;
            }
	}
	}
        return 0;}
