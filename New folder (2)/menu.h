#ifndef MENU_H
#define MENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_H 1500
#define SCREEN_W 1000
#define FRAMES_PER_SECOND 30
#define NUM_FRAMES 2
#define FRAME_DELAY (1000 / FRAMES_PER_SECOND)

typedef struct
{
SDL_Surface *img[2];
SDL_Rect pos;
int p;
}boutton;
typedef struct
{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface *img[1];
int photo;
}backg;
void initialiser_red(boutton *oui,int f,int ff);
void initialiser_ques(boutton *ques, int f,int ff);
void afficher_btn(SDL_Surface *screen,boutton btn);
void afficher_back(SDL_Surface *screen,backg b);
void liberer_button(boutton * btn);
void liberer_back(backg * back);
void initialiser_ice(boutton *oui,int f,int ff);
void initialiser_enm(boutton *oui,int f,int ff);
void initialiser_redp(boutton *oui,int f,int ff);
void initialiser_backmenu(backg *back);
void initialiser_enmp(boutton *oui,int f,int ff);
struct background
{
	SDL_Rect camera;
	int shift_pressed;
	SDL_Surface *menu1;
	int walk_right_permission;
	int walk_left_permission;
	int is_running_right;
	int is_running_left;
	float acceleration;
	Uint32 start_time ;
	Uint32 elapsed_time ;
}; 
typedef struct background background;
typedef struct 
{
	SDL_Rect camera1;
	int shift_pressed;
	SDL_Surface *menu2;
	SDL_Surface *menu3;
	int walk_right_permission;
	int walk_left_permission;
	int is_running_right;
	int is_running_left;
	float acceleration;
	Uint32 start_time ;
	Uint32 elapsed_time ;
} background1; 
typedef struct {
    char name[20];
    int score;
} Score;
typedef struct 
{
SDL_Surface *anim[100];
SDL_Rect pos;


}Animation;



void musique(int stage);


void initbackground ( background* c);
void initbackgroundg ( background* c);
void afficher_background(SDL_Surface *screen,background c);
void afficher_background1(SDL_Surface *screen,background c);
void scrolling_right(background* c);
void scrolling_left(background* c);
void scrollingup (background* c);
void scrollingdown (background* c);
void afficherTemps(SDL_Surface *ecran, TTF_Font *font, Uint32 tempsEcoule);
void initcamera ( background1* c);
void initcameramultiplayer ( background1* c);
void scrolling_right1(background1* c);
void scrolling_left1(background1* c);
void scrollingup1 (background1* c);
void scrollingdown1 (background1* c);
void liberer_animation( Animation* anim);
int init_animation( Animation* anim) ;
void afficher_animation(Animation anim,SDL_Surface* screen) ;



#endif

