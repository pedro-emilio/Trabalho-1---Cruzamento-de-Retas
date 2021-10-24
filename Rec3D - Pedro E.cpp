#include <iostream>
#include <math.h>

/*
Faculdade de Medicina de Ribeirão Preto - Universidade de São Paulo (FMRP-USP)
Fundamentos de Informática em Biomecânica
Trabalho 1 - Cruzamento de Retas
Discentes: Pedro Emilio Andrade Martins    N°USP - 11812500
Docente: Paulo Santiago
*/

int main ()
{
	float C1[3];		//Coordenadas da Camera 1
	float pC1[3];		//Projeção da Camera 1
	float C2[3];		//Coordenadas da Camera 2
	float pC2[3];		//Projeção da Camera 2
	float mr1_XY, mr1_XZ, mr1_ZY, mr2_XY, mr2_XZ, mr2_ZY;		//Coeficientes Angulares
	float br1_XY, br1_XZ, br1_ZY, br2_XY, br2_XZ, br2_ZY;		//Coeficientes Lineares
	float X1, X2, X3, Y1, Y2, Y3;								//Pontos de Intersecção
	float REC3D_X, REC3D_Y, REC3D_Z;							//Média entre os Pontos de Intersecção
	float real_X, real_Y, real_Z;								//Posição real do objeto
	float erro_X, erro_Y, erro_Z, erro_abs_X, erro_abs_Y, erro_abs_Z, erro_t;		//Erros

	printf("Insira o valor da coordenada X para a camera 1: ");
	scanf("%f", &C1[0]);
	printf("Insira o valor da coordenada Y para a camera 1: ");
	scanf("%f", &C1[1]);
	printf("Insira o valor da coordenada Z para a camera 1: ");
	scanf("%f", &C1[2]);
	
	printf("\n\nAgora insira o valor da coordenada X para a camera 2: ");
	scanf("%f", &C2[0]);
	printf("Insira o valor da coordenada Y para a camera 2: ");
	scanf("%f", &C2[1]);
	printf("Insira o valor da coordenada Z para a camera 2: ");
	scanf("%f", &C2[2]);
	
	printf("\n\nAgora, insira o valor da coordenada X para a projecao da camera 1: ");
	scanf("%f", &pC1[0]);
	printf("Insira o valor da coordenada Y para projeçao da  camera 1: ");
	scanf("%f", &pC1[1]);
	printf("Insira o valor da coordenada Z para a projecao da camera 1: ");
	scanf("%f", &pC1[2]);
	
	printf("\n\nDesta vez, insira o valor da coordenada X para a projecao da camera 2: ");
	scanf("%f", &pC2[0]);
	printf("Insira o valor da coordenada Y para projeçao da  camera 2: ");
	scanf("%f", &pC2[1]);
	printf("Insira o valor da coordenada Z para a projecao da camera 2: ");
	scanf("%f", &pC2[2]);
	
	printf("\n\nPara finalizar, insira o valor real da coordenada X do objeto: ");
	scanf("%f", &real_X);
	printf("Insira o valor real da coordenada Y do objeto: ");
	scanf("%f", &real_Y);
	printf("Insira o valor real da coordenada Z do objeto: ");
	scanf("%f", &real_Z);
	
	//Coeficientes Angulares
	mr1_XY = (pC1[1] - C1[1])/(pC1[0] - C1[0]);
	mr1_XZ = (pC1[2] - C1[2])/(pC1[0] - C1[0]);
	mr1_ZY = (pC1[1] - C1[1])/(pC1[2] - C1[2]);
	mr2_XY = (pC2[1] - C2[1])/(pC2[0] - C2[0]);
	mr2_XZ = (pC2[2] - C2[2])/(pC2[0] - C2[0]);
	mr2_ZY = (pC2[1] - C2[1])/(pC2[2] - C2[2]);
	
	printf("\n***Resultados Obtidos:***\n\n");
	printf("Coef. Angular \t Plano XY \t Plano XZ \t Plano ZY\n");
	printf("_________________________________________________________________________________\n");
	printf("mr1\t\t %.3f \t\t %.3f \t\t %.3f\n",mr1_XY, mr1_XZ, mr1_ZY);
	printf("mr2\t\t %.3f \t %.3f \t %.3f\n\n\n\n",mr2_XY, mr2_XZ, mr2_ZY);
	
	
	//Coenficientes Lineares
	br1_XY = -1 * (mr1_XY * C1[0] - C1[1]);
	br1_XZ = -1 * (mr1_XZ * C1[0] - C1[2]);
	br1_ZY = -1 * (mr1_ZY * C1[2] - C1[1]);
	br2_XY = -1 * (mr2_XY * C2[0] - C2[1]);
	br2_XZ = -1 * (mr2_XZ * C2[0] - C2[2]);
	br2_ZY = -1 * (mr2_ZY * C2[2] - C2[1]);
	
	printf("Coef. Linear \t Plano XY \t Plano XZ \t Plano ZY\n");
	printf("_________________________________________________________________________________\n");
	printf("br1\t\t %.3f \t %.3f \t %.3f\n",br1_XY, br1_XZ, br1_ZY);
	printf("br2\t\t %.3f \t %.3f \t %.3f\n\n\n\n",br2_XY, br2_XZ, br2_ZY);
	
	
	//Intersecção em X
	X1 = (-(mr2_XY*C2[0]) + C2[1] + (mr1_XY*C1[0]) - C1[1]) / (mr1_XY - mr2_XY);
	X2 = (-(mr2_XZ*C2[0]) + C2[2] + (mr1_XZ*C1[0]) - C1[2]) / (mr1_XZ - mr2_XZ);
	X3 = (-(mr2_ZY*C2[2]) + C2[1] + (mr1_ZY*C1[2]) - C1[1]) / (mr1_ZY - mr2_ZY);
	
	//Intersecção em Y
	Y1 = (mr1_XY*X1) - (mr1_XY*C1[0]) + C1[1];
	Y2 = (mr1_XZ*X2) - (mr1_XZ*C1[0]) + C1[2];
	Y3 = (mr1_ZY*X3) - (mr1_ZY*C1[2]) + C1[1];
	
	printf("Coordenada \t Plano XY \t Plano XZ \t Plano ZY\n");
	printf("_________________________________________________________________________________\n");
	printf("X\t\t %.3f \t %.3f \t %.3f\n",X1, X2, X3);
	printf("Y\t\t %.3f \t %.3f \t %.3f\n\n\n\n",Y1, Y2, Y3);
	
	
	//Dados Finais
	REC3D_X = (X1 + X2)/2;
	REC3D_Y = (Y1 + Y3)/2;
	REC3D_Z = (Y2 + X3)/2;
	
	erro_X = real_X - REC3D_X;
	erro_Y = real_Y - REC3D_Y;
	erro_Z = real_Z - REC3D_Z;
	
	erro_abs_X = fabs(erro_X);
	erro_abs_Y = fabs(erro_Y);
	erro_abs_Z = fabs(erro_Z);
	
	erro_t = (erro_abs_X + erro_abs_Y + erro_abs_Z)/3;
	
	printf("\t\tPlano X \t\t Plano Y \t\t Plano Z\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("REC3D\t\t %.3f \t\t %.3f \t\t %.3f\n",REC3D_X, REC3D_Y, REC3D_Z);
	printf("Real\t\t %.3f \t\t %.3f \t\t %.3f\n",real_X, real_Y, real_Z);
	printf("Erro\t\t %.3f \t\t\t %.3f \t\t\t %.3f\n",erro_X, erro_Y, erro_Z);	
	printf("Erro Absoluto\t %.3f \t\t\t %.3f \t\t\t %.3f\n",erro_abs_X, erro_abs_Y, erro_abs_Z);
	printf("Erro Total \t\t\t\t %.3f",erro_t);
	
}
