#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "fonctions.h"
#include "fonctions.c"





int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *ecran = NULL;

	ecran = SDL_SetVideoMode(ECRANL, ECRANH, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 122, 122, 122));
	SDL_Event event;
	SDL_Rect position;

	int i = 0, j = 0, etat=0, prox = 0, nbTours = GEN, continuer=1, clic = 0;
	int gridStatus[NBC][NBL]= {{0},{0}};
	int gridCopy[NBC][NBL]= {{0},{0}};

// grille de bloc en surface sdl
    SDL_Surface ***map = {NULL};
    map = malloc ( sizeof(*map) * NBC);
    for(i=0;i<NBC;i++){
    map[i] = malloc (sizeof (**map) * NBL);}

// Creation et positionnement de la grille de bloc
	for(i=0 ; i<NBC ; i++)
	{
		for(j=0 ; j<NBL ; j++)
		{
		position.x = i*BS + i;
		position.y = j*BS + j;
			map[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, BS, BS, 32, 50, 0, 0, 0);
			SDL_BlitSurface(map[i][j], 0, ecran, &position);
		}
	}

	SDL_Flip(ecran);

// MENU

	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT :
				continuer=0;
				break;

			case SDL_KEYDOWN :
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE :
						continuer=0;
						break;

					case SDLK_RETURN :
//
// LANCEMENT tour de generation

	for(i=0 ; i<NBC ; i++)
	{
		for(j=0 ; j<NBL ; j++)
		{
			gridCopy[i][j] = gridStatus[i][j];

		}
	}

while(nbTours!=0)
{
	for(i=0 ; i<NBC ; i++)
	{
		for(j=0 ; j<NBL ; j++)
		{
			getState(i, j, &etat);
			prox=getProx(i, j, etat, gridCopy);
			if(gridCopy[i][j] == 0)
			{
				if(prox==2){gridStatus[i][j]=0;}else if(prox==3){gridStatus[i][j]=1;}else{gridStatus[i][j]=0;}
			}
			else if(gridCopy[i][j] == 1)
				{
				if(prox==2){gridStatus[i][j]=1;}else if(prox==3){gridStatus[i][j]=1;}else{gridStatus[i][j]=0;}
			}
		}
	}

	for(i=0 ; i<NBC ; i++)
	{
		for(j=0 ; j<NBL ; j++)
		{
			gridCopy[i][j] = gridStatus[i][j];

		}
	}

//Rafraichissement écran en fonction de gridstatus
// 


	for(i=0 ; i<NBC ; i++)
	{
		for(j=0 ; j<NBL ; j++)
		{
		position.x = i*BS + i;
		position.y = j*BS + j;

			if (gridStatus[i][j]==0) 
			{
//			map[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, BS, BS, 32, 50, 0, 0, 0);
			SDL_FillRect(map[i][j], NULL, SDL_MapRGB(map[i][j]->format, 122, 0, 122));
			SDL_BlitSurface(map[i][j], 0, ecran, &position);
 			}
			else if (gridStatus[i][j]==1) 	
			{
//			map[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, BS, BS, 32, 50, 0, 0, 0);
			SDL_FillRect(map[i][j], NULL, SDL_MapRGB(ecran->format, 0, 200, 2));
			SDL_BlitSurface(map[i][j], 0, ecran, &position);
			} 
			else 
			{
			printf("erreur lecture etat case %d ; %d", i, j); 
			}
		printf("etat case %d ; %d : %d\n", i, j, gridStatus[i][j]);
		}		
	}



	SDL_Flip(ecran);
	SDL_Delay(TMPS);
	nbTours--;


} // ferme le while tour de gen

 nbTours=GEN;

					break;



} //fermeture switch KEYDOWN

			case SDL_MOUSEMOTION:

   			 if (clic=1) // Si on déplace la souris et que le bouton gauche de la souris est enfoncé

				if(gridStatus[event.button.x/(BS + 1)][event.button.y / (BS + 1)] == 1)
				{
					gridStatus[event.button.x / (BS + 1)][event.button.y / (BS + 1)] = 0;
				}

				else if(gridStatus[event.button.x/(BS + 1)][event.button.y / (BS + 1)] == 0)
				{
					gridStatus[event.button.x / (BS + 1)][event.button.y / (BS + 1)] = 1;

				}

   				 break;

			case SDL_MOUSEBUTTONUP: // On désactive le booléen qui disait qu'un bouton était enfoncé

       				 clic = 0;

   					 break;


		        case SDL_MOUSEBUTTONDOWN :

				clic=1;
			
				if(gridStatus[event.button.x/(BS + 1)][event.button.y / (BS + 1)] == 1)
				{
					gridStatus[event.button.x / (BS + 1)][event.button.y / (BS + 1)] = 0;
				}

				else if(gridStatus[event.button.x/(BS + 1)][event.button.y / (BS + 1)] == 0)
				{
					gridStatus[event.button.x / (BS + 1)][event.button.y / (BS + 1)] = 1;

				}




            			break;

		} // fermeture switch event

//Rafraichissement écran en fonction de gridstatus
// 


	for(i=0 ; i<NBC ; i++)
	{
		for(j=0 ; j<NBL ; j++)
		{
		position.x = i*BS + i;
		position.y = j*BS + j;

			if (gridStatus[i][j]==0) 
			{
//			map[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, BS, BS, 32, 50, 0, 0, 0);
			SDL_FillRect(map[i][j], NULL, SDL_MapRGB(map[i][j]->format, 122, 0, 122));
			SDL_BlitSurface(map[i][j], 0, ecran, &position);
 			}
			else if (gridStatus[i][j]==1) 	
			{
//			map[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, BS, BS, 32, 50, 0, 0, 0);
			SDL_FillRect(map[i][j], NULL, SDL_MapRGB(ecran->format, 0, 200, 2));
			SDL_BlitSurface(map[i][j], 0, ecran, &position);
			} 
			else 
			{
			printf("erreur lecture etat case %d ; %d", i, j); 
			}
		printf("etat case %d ; %d : %d\n", i, j, gridStatus[i][j]);
		}		
	}

SDL_Flip(ecran);

} // fermeture while externe



// FIN
//



// liberation memoire et quitter SDL


for(i=0 ; i < NBC ; i++){
     for(j=0 ; j < NBL ; j++){
           SDL_FreeSurface(map[i][j]);
     }
}
free(map);


	SDL_Delay(5000);

	SDL_Quit;
}

