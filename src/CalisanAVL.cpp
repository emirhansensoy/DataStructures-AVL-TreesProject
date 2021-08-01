/*
*
* @file 			CalisanAVL.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			24 ‎Aralık ‎2020 ‎Perşembe, ‏‎01:08:50
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include "NodeCalisan.hpp"
#include "CalisanAVL.hpp"
#include <iostream>
#include <string>

using namespace std;

NodeCalisan* CalisanAVL::insert(NodeCalisan *alt_Dugum, const int &yil, string adSoyad)
{
	if(alt_Dugum == NULL)
	{
		alt_Dugum = new NodeCalisan(yil, adSoyad, NULL, NULL);
		
		return alt_Dugum;
	}
	else if(yil >= alt_Dugum->year)
	{
		alt_Dugum->left = insert(alt_Dugum->left, yil, adSoyad);
		
		if(height(alt_Dugum->left) - height(alt_Dugum->right) == 2)
		{
			if(yil >= alt_Dugum->left->year)//Sol sol
			{
				alt_Dugum = rightRotate(alt_Dugum);
			}
			else//Sol sag
			{
				alt_Dugum->left = leftRotate(alt_Dugum->left); 
				alt_Dugum = rightRotate(alt_Dugum);
			}
		}
	}
	else if(yil < alt_Dugum->year)
	{
		alt_Dugum->right = insert(alt_Dugum->right, yil, adSoyad);
		
		if(height(alt_Dugum->right) - height(alt_Dugum->left) == 2)
		{
			if(yil < alt_Dugum->right->year)//Sag sag
			{
				alt_Dugum = leftRotate(alt_Dugum);
			}
			else//Sag sol
			{
				alt_Dugum->right = rightRotate(alt_Dugum->right); 
				alt_Dugum = leftRotate(alt_Dugum); 
			}
		}
	}
	
	//Yukseklikler guncelleniyor.
	alt_Dugum->height = height(alt_Dugum);	
	
	return alt_Dugum;
}

NodeCalisan* CalisanAVL::rightRotate(NodeCalisan *alt_Dugum) 
{ 
	NodeCalisan *tmp = alt_Dugum->left; 
	
	alt_Dugum->left = tmp->right; 		  
	
	tmp->right = alt_Dugum; 
	
	//Yukseklikler guncelleniyor.
	alt_Dugum->height = height(alt_Dugum); 
	
	tmp->height = max(height(tmp->left),alt_Dugum->height);
	
	return tmp;
} 
NodeCalisan* CalisanAVL::leftRotate(NodeCalisan *alt_Dugum) 
{ 
	NodeCalisan *tmp = alt_Dugum->right; 
	
	alt_Dugum->right = tmp->left;
	
	tmp->left = alt_Dugum;
	
	//Yukseklikler guncelleniyor.
	alt_Dugum->height = height(alt_Dugum);
	
	tmp->height = max(height(tmp->right),alt_Dugum->height);
	
	return tmp;
}

int CalisanAVL::height(NodeCalisan *alt_Dugum)const
{
	if(alt_Dugum == NULL)
	{
		return -1;
	}
	
	return max(height(alt_Dugum->left), height(alt_Dugum->right)) + 1;
}

int CalisanAVL::height()const
{
	return height(root);
}

void CalisanAVL::Ekle(const int &yil, string adSoyad)
{
	root = insert(root,yil,adSoyad);
}

void CalisanAVL::Postorder(NodeCalisan *alt_Dugum)
{
	if(alt_Dugum != NULL)
	{
		Postorder(alt_Dugum->left);
		Postorder(alt_Dugum->right);
		
		cout << alt_Dugum->id << " - " << alt_Dugum->year << " | ";
	}
}

void CalisanAVL::Postorder()
{
	Postorder(root);
}