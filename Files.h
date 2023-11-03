#pragma once
#include <iostream>
#include <fstream>
#include "Viewer.h"

using namespace std;

void infile_theater(Theater theater, int sizesesion, int sizeviewer)
{
	int len = sizeof(Theater);
	fstream out;
	out.open("Theater.dat", ios::out | ios::binary);
	if (!out)
	{
		cout << "\n\tНе удалось открыть файл" << endl;
		return;
	}
	out.write((char*)&theater, len);
	out.write((char*)&sizesesion, sizeof(int));
	out.write((char*)&sizeviewer, sizeof(int));
	out.close();
}

void infile_session(Session tmpSess[], int sizesession)
{
	fstream out;
	out.open("Session.dat", ios::out | ios::binary);
	if (!out)
	{
		cout << "\n\tНе удалось открыть файл!" << endl;
		return;
	}
	int len = sizeof(Session);
	for (int i = 0; i < sizesession; i++)
	{
		out.write((char*)&tmpSess[i], len);
	}
	out.close();
}

void infile_viewer(Viewer tmpv[], int sizeviewer)
{
	fstream out;

	out.open("Viewer.dat", ios::out | ios::binary);
	if (!out)
	{
		cout << "\n\tНе удалось открыть файл" << endl;
		return;
	}
	int len = sizeof(Viewer);
	for (int i = 0; i < sizeviewer; i++)
	{
		out.write((char*)&tmpv[i], len);
	}
	out.close();
}

void inputfile_all(Theater theater, Session* sess[], Session tmpSess[], int sizesession, Viewer* v[], Viewer tmpv[], int sizeviewer)
{
	infile_theater(theater, sizesession, sizeviewer);
	for (int i = 0; i < sizesession; i++)
	{
		tmpSess[i] = *sess[i];
	}
	infile_session(tmpSess, sizesession);
	for (int i = 0; i < sizeviewer; i++)
	{
		tmpv[i] = *v[i];
	}
	infile_viewer(tmpv, sizeviewer);
	cout << "\n\tЗаписано" << endl;
}

void outfile_theater(Theater& theater, int* sizesession, int* sizeviewer)
{
	int len = sizeof(Theater);

	fstream in;

	in.open("Theater.dat", ios::in);
	if (!in)
	{
		cout << "\n\tНе удалось открыть файл" << endl;
		return;
	}
	in.read((char*)&theater, len);
	in.read((char*)sizesession, sizeof(int));
	in.read((char*)sizeviewer, sizeof(int));
	in.close();
}

void outfile_session(Session tmpSess[],int* sizesession)
{
	int len = sizeof(Session);
	fstream in;
	in.open("Session.dat", ios::in);
	if (!in)
	{
		cout << "\n\tНе удалось открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < *sizesession; i++)
	{
		in.read((char*)&tmpSess[i], len);
	}
	in.close();
}

void outfile_viewer(Viewer tmpv[], int* sizeviewer)
{
	int len = sizeof(Viewer);

	fstream in;

	in.open("Viewer.dat", ios::in);

	if (!in)
	{
		cout << "\n\tНе удалось открыть файл" << endl;
		return;
	}
	for (int i = 0; i < *sizeviewer; i++)
	{
		in.read((char*)&tmpv[i], len);
	}
	in.close();

}


void outfile_all(Theater& theater, Session* sess[], Session tmpSess[], Viewer* v[], Viewer tmpv[], int* sizesession, int* sizeviewer)
{
	outfile_theater(theater, sizesession, sizeviewer);
	outfile_session(tmpSess, sizesession);
	for (int i = 0; i < *sizesession; i++)
	{
		*sess[i] = tmpSess[i];
	}
	outfile_viewer(tmpv, sizeviewer);
	for (int i = 0; i < *sizeviewer; i++)
	{
		*v[i] = tmpv[i];
	}
	cout << "\n\tВыгрузка завершена" << endl;
}


void startnewday(Session* sess[], int sizesession, Viewer* v[], int sizeviewer)
{
	for (int i = 0; i < sizesession; i++)
	{
		sess[i] = new Session();
	}
	for (int i = 0; i < sizeviewer; i++)
	{
		v[i] = new Viewer();
	}
}









