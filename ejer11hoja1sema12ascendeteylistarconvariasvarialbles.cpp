//Ejercicio 9 de la hoja 1 de la semana 12
#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;
using namespace System;

void ingresadatos(int *n, int *codigo, int *credito, int*promedio)
{
	for (int i = 0; i < *n; i++)
	{
		cout << "ingresa codigo " << i + 1 << ": "; cin >> codigo[i];
		cout << "ingrese creditos matriculados " << i + 1 << ": "; cin >> credito[i];
		cout << "ingrese promedio " << i + 1 << ": "; cin >> promedio[i];
	}
}

void ascendentecredito(int *n, int *codigo, int *credito, int*promedio)
{
	int tempcredito; int tempcod; int tempprom;
	for (int i = 0; i < *n - 1; i++)
	{
		for (int j = i + 1; j < *n; j++)
			if (credito[i] > credito[j])
			{
				tempcredito = credito[i];
				credito[i] = credito[j];
				credito[j] = tempcredito;
				tempcod = codigo[i];
				codigo[i] = codigo[j];
				codigo[j] = tempcod;
				tempprom = promedio[i];
				promedio[i] = promedio[j];
				promedio[j] = tempprom;

			}
	}

}

void imprimirasce(int *n, int *codigo, int *credito, int*promedio)
{


	cout << "ordenados ascendente segun creditos" << endl << endl;
	for (int i = 0; i < *n; i++)
		cout << "alumno " << i + 1 << " codigo " << codigo[i] << " credito " << credito[i] << " promedio " << promedio[i] << endl;

}


void decendentepromedio(int *n, int *codigo, int *credito, int*promedio)
{
	int tempcredito; int tempcod; int tempprom;
	for (int i = 0; i < *n - 1; i++)
	{
		for (int j = i + 1; j < *n; j++)
			if (promedio[i] < promedio[j])
			{
				tempcredito = credito[i];
				credito[i] = credito[j];
				credito[j] = tempcredito;
				tempcod = codigo[i];
				codigo[i] = codigo[j];
				codigo[j] = tempcod;
				tempprom = promedio[i];
				promedio[i] = promedio[j];
				promedio[j] = tempprom;

			}
	}
	cout << "ordenados adescendente segun promedio" << endl << endl;
	for (int i = 0; i < *n; i++)
		cout << "alumno " << i + 1 << " codigo " << codigo[i] << " credito " << credito[i] << " promedio " << promedio[i] << endl;
}



void masde15cred(int *n, int *codigo, int *creditos, int*promedio)
{
	int masde15cred = 0;
	cout << "alumnos con mas de 15 creditos: " << endl << endl;
	for (int i = 0; i < *n; i++)
		if (creditos[i] > 15)

			cout << "alumno numero : " << i + 1 << " codigo " << codigo[i] << " creditos " << creditos[i] << endl;
}


void aprobado(int *n, int *codigo, int *creditos, int*promedio)
{
	int aprobados = 0;
	cout << "aprobados nota >=13: " << endl << endl;
	for (int i = 0; i < *n; i++)
		if (promedio[i] >= 13)
			cout << "alumno numero : " << i+1 << " codigo " << codigo[i] << " promedio " << promedio[i] << endl;
}

int main()
{
	int n;
	cout << "ingrese n"; cin >> n;
	while (n <= 0 || n > 50)
	{
		cout << "ingrese n"; cin >> n;
	}
	int*codigo = new int[n];
	int*creditos = new int[n];
	int*promedio = new int[n];
	ingresadatos(&n, codigo, creditos, promedio);
	ascendentecredito(&n, codigo, creditos, promedio);
	imprimirasce(&n, codigo, creditos, promedio);
	decendentepromedio(&n, codigo, creditos, promedio);
	masde15cred(&n, codigo, creditos, promedio);
	aprobado(&n, codigo, creditos, promedio);
	delete[]codigo;
	delete[]creditos;
	delete[]promedio;
	_getch();

}

