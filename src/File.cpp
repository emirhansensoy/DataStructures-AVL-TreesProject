/*
*
* @file 			File.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			22 ‎Aralık ‎2020 ‎Salı, ‏‎19:54:20
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include "File.hpp"
#include "NodeCalisan.hpp"
#include "NodeSirket.hpp"
#include "CalisanAVL.hpp"
#include "SirketAVL.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

void File::readFile()
{
	int sayac = 0;
	
	SirketAVL *sirketler = new SirketAVL();
	
	ifstream myFile("veri.txt");
	
	int temp = 0;
	
	while(!myFile.eof())
	{
		string sirketAdi;
		string adSoyad;
		int yil;
		
		getline(myFile,line);
		
		string delim = "#";
		
		size_t position = 0;
		
		string kelime;
		
		while ((position = line.find(delim)) != string::npos) 
		{
			kelime = line.substr(0, position);
			
			if(sayac == 0)
			{
				sirketAdi = kelime;
				sayac++;
			}
			else
			{
				adSoyad = kelime;
				sayac = 0;
			}
			
			line.erase(0, position + delim.length());
		}
		yil = stoi(line);
		
		if(temp == 0)
		{
			sirketler->Ekle(0,sirketAdi);
			temp++;
		}
		else if(sirketler->sirketSearchBool(sirketAdi) == 0)
		{
			sirketler->Ekle(0,sirketAdi);
		}
		
		sirketler->sirketGetir(sirketAdi)->calisanlar->Ekle(yil, adSoyad);
		sirketler->sirketGetir(sirketAdi)->employeeNo++;
		
		/*
		if(sirketler->dengeliMi(sirketler->root) == 1)
		{
			sirketler->sirketDengele(sirketler->sirketGetir(sirketAdi));
		}
		*/
	}
	
	sirketler->Postorder();
	
	myFile.close();
}
