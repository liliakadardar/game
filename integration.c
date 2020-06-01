#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personne.c"
#include "background.c"
#include "update_score.c"
#include "vie.c"
#include "obstacle.c"
#include "temps.c"
#include "ennemi.c"
//#include "collision.c"
//#include "enigme.c"


/*************************************************************  INTEGRATION  *************************************************************/


int main(int argc, char *argv[])
{

/*declarations des variables */

//menu m;
background bg; temps t;
score s; vie v; int valeur_score=20;
personnage p; obstacle o1,o2,o3; //collision c;
int touche=1; 
int sens=0;
// les Enigmes 
//enigme e1,e2,e3,e4,e5,e6;
int done=0; // lorsqu'on clique sur le clavier 

// Ennemis 
ennemi en1,en2;
/*int ennemi1=0;
int ennemi2=0;
int ennemi3=0;
int ennemi4=0;
int ennemi5=0;
int ennemi6=0;*/


/*
int i=0;// Quand  le menu est dans son etat initiale : pas de clic sur aucun des boutons. 
//JEU 
int i=1; // lorsqu'on commence le jeu



	/* Declaration des SDLs */

SDL_Surface *ecran=NULL;
SDL_Rect *position_ecran;
SDL_Event event; 


/*---------------------------------------------------------------- INITIALISATION ---------------------------------------------------------------- */ 

// fenetre et ecran

 SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
 TTF_Init();
 SDL_EnableKeyRepeat(100,100); //Fonctions de la SDL permettant d'initialiser la fenêtre

    ecran = SDL_SetVideoMode(1600,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF); 
    SDL_WM_SetCaption("Land Of Gargoyls", NULL);


// les fonctions 

//initialiser_menu(&m);
initialiser_background(&bg);
initialiser_personnage(&p);
initialiser_temps(&t);
initialiser_vie(&v);
initialiser_score(valeur_score,&s);

initialiser_obstacle1(&o1);
initialiser_obstacle2(&o2);
initialiser_obstacle3(&o3);

initialiser_ennemi1(&en1);
initialiser_ennemi2(&en2);
//initialiser_enigme(&e1);
//enigme
//
//initialiser_enigme(&e2);

/*
 // init ennemi 
  // l'ennemi 3andha nafess el .h au faite mais l'initialisation bich tetbadel khater el image..
initialiser_ennemi(&en2);
initialiser_ennemi(&en3);
initialiser_ennemi(&en4);
initialiser_ennemi(&en5);
initialiser_ennemi(&en6);*/





/*---------------------------------------------------------------- DISPLAY ----------------------------------------------------------------*/

// la boucle du jeu 
 while (!done)
{ 
SDL_Rect positionchamp; SDL_Surface *champignon=NULL;
positionchamp.x=50;
positionchamp.y=200;

/*if (i==0) // lorsqu'on est dans le menu
	{afficher_menu(m,ecran);}

if (i==1) // lorsq'on est dans le jeu
	{*/
afficher_background(bg,ecran); 
afficher_personnage(p,ecran);
afficher_obstacle1(o1,ecran);
afficher_obstacle2(o2,ecran);
afficher_obstacle3(o3,ecran);
afficher_score(valeur_score,s,ecran);

afficher_vie(v,ecran);
afficher_ennemi1(en1,ecran);
afficher_ennemi2(en2,ecran);

//afficher_enigme(e1,ecran);
afficher_temps(&t,ecran);
// affichage de l'ennemi avec des conditions
/*
if (ennemi1==0)
{affiche_ennemi(&en1,ecran);}
 if (ennemi2==0)
{affiche_ennemi(&en2,ecran);}
 if (ennemi3==0)
{affiche_ennemi(&en3,ecran);}
 if (ennemi4==0)
{affiche_ennemi(&en4,ecran);}
 if (ennemi5==0)
{affiche_ennemi(&en5,ecran);}
 if (ennemi6==0)
{affiche_ennemi(&en6,ecran);}*/

// enigmeeeeeeeeeeeeeeeeeeeeeeeeee
// ici y a une condition 3al enigme bich yaffichi ou yaffichi el temps d'enigme pas encore resolu 
	//}


/*---------------------------------------------------------------- INPUT + UPDATE ----------------------------------------------------------------*/


int clic=0;
 // variable que lorsqu'on clique sur la touche elle nous indique le sens 
    
        while(SDL_PollEvent(&event))
        {
		
            switch(event.type)
            {
                case SDL_QUIT:
                done=1;
                break;

                //les touches de clavier 
                case SDL_KEYDOWN: // touches enfoncées
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:  // echape 
                    done = 1;
                    break;

                    case SDLK_LEFT: // Flèche droite
                     clic=1;
                    break;

                    case SDLK_RIGHT: // Flèche gauche
                        clic=2;
                    break;

                    case SDLK_UP: // Flèche bas 
                        clic=3;
                    break;

                    case SDLK_DOWN: // Flèche haut
                        clic=4;
                    break;
                    
                    // Touche d'attaque clic sur "espace"
                    case SDLK_SPACE: 
                    clic=5;
                    break; 
                    // Touche pour slide:glisser clic sur "0"
                    case SDLK_RETURN: 
                    clic=6;
                    break; 

                    // option pour le joueur
                    case SDLK_c: // touche permettant aux joeurs de se redonner 3 coeurs
                        
                        break;
                    case SDLK_z: // touche permettant aux joeurs de se donner 10 pièces
                        break;
                   
                   }
                break;

                    // touche de la sourie 
                
                case SDL_MOUSEBUTTONDOWN :

                if(event.button.button == SDL_BUTTON_LEFT)
                    { clic=1;}
                else if(event.button.button == SDL_BUTTON_RIGHT)
                    {clic=2;}
                    
		        else if (event.button.button== SDL_BUTTON_WHEELUP)
		          {clic=3;}
                else if (event.button.button == SDL_BUTTON_WHEELDOWN)
		          {clic=4;}
              
			     break;
                 }   
              

}     
  /*---------------------------------------------------------------- UPDATE ----------------------------------------------------------------*/
      
if (clic!=0)
//if ((p.position_personnage.x)>800) 
{
scrolling_bg(clic,&bg);
scroll_ennemi(clic,&en1);
scroll_ennemi2(clic,&en2);
scroll_obstacle(clic,&o1);
scroll_obstacle2(clic,&o2);
scroll_obstacle3(clic,&o3);

deplacement_clavier(&p,clic);
deplacement_sourie(&p,clic); 

}
printf("%d\n",p.position_personnage.x );
update_score (&valeur_score,s,&p);
printf("score :%d\n",valeur_score);
gestion_vies (&v,&p);



/*animation_droite (&en1);
SDL_Delay(80);
animation_droite2 (&en2);
SDL_Delay(80);*/


/*
if (check_collision( c.pers.position_personnage, c.enn->position_entite )==1)
{
c.pers.position_personnage.x--;

printf("%d\n",c.enn->position_entite.x );*/
//printf("colision \n");
//animation_fail(&p);



/*--------FLIP------*/
SDL_Flip (ecran);
}

/*----------------------------------------------------------------  FIN  ----------------------------------------------------------------*/
free_temps(&t,ecran);
free_score( s);
 vie_freevie(v ) ;


// liberation SDL
TTF_Quit();
SDL_Quit();
   
 return EXIT_SUCCESS;
}


