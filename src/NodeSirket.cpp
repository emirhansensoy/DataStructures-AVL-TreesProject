/*
*
* @file 			NodeSirket.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			24 ‎Aralık ‎2020 ‎Perşembe, ‏‎00:59:12
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include "NodeSirket.hpp"
#include <iostream>

using namespace std;

NodeSirket::NodeSirket(string id, NodeSirket *left = NULL, NodeSirket *right = NULL)
{
	this->id = id;
	this->left = left;
	this->right = right;
	employeeNo = 0;
	height = 0;
}