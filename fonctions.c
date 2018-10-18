
// fonctions pour jeu

//
// fonction getState V1
//
void getState(int i, int j, int* etat)
{

if(i==0 && j==0) { *etat = 8; }
else if(i==NBL-1 && j==0) { *etat = 9; }
else if(i==NBL-1 && j==NBC-1) { *etat = 7; }
else if(i==0 && j==NBC-1) { *etat = 6; }
else if(i==0 && j>0 && j<NBC-1 ) { *etat = 4; }
else if(i==NBL-1 && j>0 && j<NBC-1) { *etat = 5; }
else if(i<NBL-1 && i>0 && j==NBC-1) { *etat = 3; }
else if(j==0 && i>0 && i<NBL-1) { *etat = 2; }
else if(i>0 && i<NBL-1 && j>0 && j<NBC-1) { *etat = 1; }
else { *etat = 0; printf("!!!erreur : AUCUN etat!!!"); }	

printf("Get state pour i=%d ,j=%d :\n etat=%d\n", i, j, *etat);
}

//
// fin fonction getState V1
//

//
// Debut fonction getProx V2
//

int getProx(int i, int j, int etat, int gridCopy[][NBL])
{

int proxim = 0;

if (etat==0)
{
		proxim = 0;

	printf("!!! prox pour AUCUN\n");

}
else if (etat==1)
{
		proxim = 
	(
		gridCopy[i-1][j-1] 
	+ 	gridCopy[i-1][j] 
	+ 	gridCopy[i-1][j+1] 
	+ 	gridCopy[i][j-1] 
	+ 	gridCopy[i][j+1] 
	+ 	gridCopy[i+1][j-1] 
	+ 	gridCopy[i+1][j] 
	+ 	gridCopy[i+1][j+1]
	);

	printf("prox pour C\n");

}
else if (etat==2)
{
		proxim = 
	(  
	 	gridCopy[i-1][j] 
	+ 	gridCopy[i-1][j+1]  
	+ 	gridCopy[i][j+1]  
	+ 	gridCopy[i+1][j] 
	+ 	gridCopy[i+1][j+1]
	);

	printf("prox pour T\n");
}
else if (etat==3)
{
		proxim = 
	(
		gridCopy[i-1][j-1] 
	+ 	gridCopy[i-1][j]  
	+ 	gridCopy[i][j-1]  
	+ 	gridCopy[i+1][j-1] 
	+ 	gridCopy[i+1][j]  
	);

	printf("prox pour B\n");
}
else if (etat==4)
{
		proxim = 
	(  
	 	gridCopy[i][j-1] 
	+ 	gridCopy[i][j+1] 
	+ 	gridCopy[i+1][j-1] 
	+ 	gridCopy[i+1][j] 
	+ 	gridCopy[i+1][j+1]
	);

	printf("prox pour L\n");
}
else if (etat==5)
{
		proxim = 
	(
		gridCopy[i-1][j-1] 
	+ 	gridCopy[i-1][j] 
	+ 	gridCopy[i-1][j+1] 
	+ 	gridCopy[i][j-1] 
	+ 	gridCopy[i][j+1]  
	);

	printf("prox pour R\n");
}
else if (etat==8)
{
		proxim = 
	(   
	+ 	gridCopy[i][j+1]  
	+ 	gridCopy[i+1][j] 
	+ 	gridCopy[i+1][j+1]
	);

	printf("prox pour TL\n");
}
else if (etat==9)
{
		proxim = 
	(  
	 	gridCopy[i-1][j] 
	+ 	gridCopy[i-1][j+1]  
	+ 	gridCopy[i][j+1]   
	);

	printf("prox pour TR\n");
}
else if (etat==6)
{
		proxim = 
	(   
	 	gridCopy[i][j-1]  
	+ 	gridCopy[i+1][j-1] 
	+ 	gridCopy[i+1][j]  
	);

	printf("prox pour BL\n");
}
else if (etat==7)
{
		proxim = 
	(
		gridCopy[i-1][j-1] 
	+ 	gridCopy[i-1][j]  
	+ 	gridCopy[i][j-1]  
	);

	printf("prox pour BR\n");
}
else
{
	printf("!!! erreur d'etat dans getprox");
}

printf("Get prox pour i=%d ,j=%d :\n gridCopy=%d, ,\n etat=%d, prox=%d\n\n", i, j, gridCopy[i][j], etat, proxim);


return proxim;

}

//
// Fin de la fonction getProx V2
//

