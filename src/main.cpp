/*
*
* @file 			main.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			‎22 ‎Aralık ‎2020 ‎Salı, ‏‎19:54:20
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include <iostream>
#include "File.hpp"
#include <windows.h>

using namespace std;

int main()
{
	
	SetConsoleOutputCP(65001);
	
	cout << endl;
	
	File* f = new File();
	
	f->readFile();
	
	system("pause");
	
	return 0;
}