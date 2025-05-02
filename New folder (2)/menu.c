
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include <stdbool.h>
#define NUM_FRAMES 2

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 800

void initialiser_ques(boutton *oui,int f,int ff)
{
oui->img[0]=IMG_Load("mini.png");
oui->pos.x=f;
oui->pos.y=ff;
oui->pos.h=20;
oui->pos.w=20;
oui->p=0;
}
void initialiser_redp(boutton *oui,int f,int ff)
{
oui->img[0]=IMG_Load("redp.png");
oui->pos.x=f;
oui->pos.y=ff;
oui->pos.h=20;
oui->pos.w=20;
oui->p=0;
}
void initialiser_red(boutton *oui,int f,int ff)
{
oui->img[0]=IMG_Load("red.png");
oui->pos.x=f;
oui->pos.y=ff;
oui->pos.h=20;
oui->pos.w=20;
oui->p=0;
}
void initialiser_enm(boutton *oui,int f,int ff)
{
oui->img[0]=IMG_Load("enm.png");
oui->pos.x=f;
oui->pos.y=ff;
oui->pos.h=20;
oui->pos.w=20;
oui->p=0;
}
void initialiser_enmp(boutton *oui,int f,int ff)
{
oui->img[0]=IMG_Load("enmp.png");
oui->pos.x=f;
oui->pos.y=ff;
oui->pos.h=20;
oui->pos.w=20;
oui->p=0;
}
void initialiser_ice(boutton *oui,int f,int ff)
{
oui->img[0]=IMG_Load("ice.png");
oui->pos.x=f;
oui->pos.y=ff;
oui->pos.h=20;
oui->pos.w=20;
oui->p=0;
}

void initialiser_backmenu(backg *back) {
    back->photo = 0;
    back->img[0] = IMG_Load("background.png");
       
    
    back->pos1.x = 0;
    back->pos1.y = 0;
}
void afficher_btn(SDL_Surface *screen,boutton btn)
{
SDL_BlitSurface(btn.img[btn.p],NULL,screen,&btn.pos);
}
void afficher_back(SDL_Surface *screen,backg b)
{
SDL_BlitSurface(b.img[0],NULL,screen,&b.pos1);
}


void liberer_button(boutton * btn)
{
SDL_FreeSurface(btn->img[0]);


}
void liberer_back(backg * back)
{
SDL_FreeSurface(back->img[0]);
}
void afficher_background(SDL_Surface *screen,background c)
{
SDL_BlitSurface(c.menu1,&c.camera,screen,NULL);
}
void afficher_background1(SDL_Surface *screen,background c)
{
SDL_BlitSurface(c.menu1,&c.camera,screen,NULL);
}





void initbackground ( background* c)
{
    c->menu1 = IMG_Load("back.png");
    c->camera.x=0;
    c->camera.y=100;
    c->camera.h=800;
    c->camera.w=1500;
    
}
void initbackgroundg ( background* c)
{
    c->menu1 = IMG_Load("guide.jpeg");
    c->camera.x=-220;
    c->camera.y=-130;
    c->camera.h=1080;
    c->camera.w=1584;
    
}
void scrolling_right (background* c)
{
	if(!c->shift_pressed)
        {
        c->camera.x+=10;
        }
        
        if(c->shift_pressed)
        {
        c->camera.x=c->camera.x+10*(int)c->acceleration;
        }
        
        if (c->camera.x >=7500)
        {
            c->camera.x=7500;
        }
}

void scrolling_left(background* c)
{
	
    	if(!c->shift_pressed)
        {
        c->camera.x-=10;
        }
        
        if(c->shift_pressed)
        {
        c->camera.x=c->camera.x-10*(int)c->acceleration;
        }
        
    if (c->camera.x <= 10)
    {
        c->camera.x = 0;
    }
}
void scrollingdown (background* c)
{
        c->camera.y+=40;
        if (c->camera.y >=120)
        {
            c->camera.y=120;
        }
}
void scrollingup (background* c)
{
        c->camera.y-=40;
        if (c->camera.y <=10)
        {
            c->camera.y=10;
        }
}
void musique(int stage)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Music *musique; 
    char nom_musique[40];
    sprintf(nom_musique,"musiques/%d.mp3",stage); 
    musique = Mix_LoadMUS(nom_musique); 
    Mix_PlayMusic(musique, -1);
    Mix_VolumeMusic(128);
}

void afficherTemps(SDL_Surface *ecran, TTF_Font *font, Uint32 tempsEcoule){
    if (!font || !ecran) return;
    
    char tempsTexte[20];
    int minutes = tempsEcoule / 60;
    int secondes = tempsEcoule % 60;
    sprintf(tempsTexte, "Temps: %02d:%02d", minutes, secondes);
    
    SDL_Color blanc = {255, 255, 255, 255};
    SDL_Surface* surfaceTemps = TTF_RenderText_Solid(font, tempsTexte, blanc);
    
    if (surfaceTemps) {
        SDL_Rect position;
        position.x = (ecran->w - surfaceTemps->w) / 2;  // centré horizontalement
        position.y = 10; // en haut de l’écran
        SDL_BlitSurface(surfaceTemps, NULL, ecran, &position);
        SDL_FreeSurface(surfaceTemps);
    }
}

void initcamera ( background1* c)
{
    c->camera1.x=0;
    c->camera1.y=100;
    c->camera1.h=800;
    c->camera1.w=750;
    
}
void initcameramultiplayer ( background1* c)
{
    c->camera1.x=0;
    c->camera1.y=100;
    c->camera1.h=800;
    c->camera1.w=750;
    
}




void scrolling_right1 (background1* c)
{
	if(!c->shift_pressed)
        {
        c->camera1.x+=10;
        }
        
        if(c->shift_pressed)
        {
        c->camera1.x=c->camera1.x+10*(int)c->acceleration;
        }
        
        if (c->camera1.x >=7500)
        {
            c->camera1.x=7500;
        }
}

void scrolling_left1(background1* c)
{
	
    	if(!c->shift_pressed)
        {
        c->camera1.x-=10;
        }
        
        if(c->shift_pressed)
        {
        c->camera1.x=c->camera1.x-10*(int)c->acceleration;
        }
        
    if (c->camera1.x <= 10)
    {
        c->camera1.x = 0;
    }
}
void scrollingdown1 (background1* c)
{
        c->camera1.y+=40;
        if (c->camera1.y >=120)
        {
            c->camera1.y=120;
        }
}
void scrollingup1 (background1* c)
{
        c->camera1.y-=40;
        if (c->camera1.y <=10)
        {
            c->camera1.y=10;
        }
}


int init_animation( Animation* anim) {
    char filename[50];
    for (int i = 0; i < NUM_FRAMES; ++i) {
        
        sprintf(filename, "animation/frame%03d.png", i);
       
        anim->anim[i] = IMG_Load(filename);
        if (!anim->anim[i]) {
            printf("Error loading frame %d: %s\n", i, SDL_GetError());
            return 0; 
        }
    }
    return 1; 
}
void afficher_animation( Animation anim, SDL_Surface* screen) {
    static int i = 0; 

    
    SDL_BlitSurface(anim.anim[i], NULL, screen, &anim.pos);
    SDL_Delay(50);
   
    i++;

    
    if (i == NUM_FRAMES)
        i = 0;
}

void liberer_animation(Animation* anim) {
    for (int i = 0; i < NUM_FRAMES; ++i) {
        SDL_FreeSurface(anim->anim[i]);
    }
}




