/*
*
* @file 			NodeCalisan.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			‎23 ‎Aralık ‎2020 ‎Çarşamba, ‏‎20:42:32
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include "NodeCalisan.hpp"
#include <iostream>

using namespace std;

NodeCalisan::NodeCalisan(int year, string id, NodeCalisan *left = NULL, NodeCalisan *right = NULL)
{
	this->year = year;
	this->id = id;
	this->left = left;
	this->right = right;
	time = (2020 - year);
	height = 0;
}