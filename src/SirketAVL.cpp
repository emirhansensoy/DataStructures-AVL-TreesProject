/*
*
* @file 			SirketAVL.cpp
* @description 		Program, önceden hazırlanmış veri.txt dosyasını okuyup, okunan sayılarla AVL ağaçları oluşturarak listeler üzerinde istenilen işlemleri yapar ve AVL ağaçlarının son halini ekranana yazdırır.
* @course 			Veri Yapıları 2.Öğretim C Grubu
* @assignment		Veri Yapıları 2.Ödev
* @date 			24 ‎Aralık ‎2020 ‎Perşembe, ‏‎13:09:46
* @author 			Emirhan Şensoy - emirhan.sensoy@ogr.sakarya.edu.tr
*
*/

#include "NodeSirket.hpp"
#include "CalisanAVL.hpp"
#include "SirketAVL.hpp"
#include <iostream>
#include <string>

using namespace std;

NodeSirket* SirketAVL::insert(NodeSirket *alt_Dugum, const int &calisanSayisi, string sirketAdi)
{
	if(alt_Dugum == NULL)
	{
		alt_Dugum = new NodeSirket(sirketAdi, NULL, NULL);
		
		return alt_Dugum;
	}
	else if(calisanSayisi < alt_Dugum->employeeNo)
	{
		alt_Dugum->left = insert(alt_Dugum->left, calisanSayisi, sirketAdi);
		
		if(height(alt_Dugum->left) - height(alt_Dugum->right) == 2)
		{
			if(calisanSayisi < alt_Dugum->left->employeeNo)//Sol sol
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
	else if(calisanSayisi >= alt_Dugum->employeeNo)
	{
		alt_Dugum->right = insert(alt_Dugum->right, calisanSayisi, sirketAdi);
		
		if(height(alt_Dugum->right) - height(alt_Dugum->left) == 2)
		{
			if(calisanSayisi >= alt_Dugum->right->employeeNo)//Sag sag
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
	
	//Yukseklik guncelleniyor.
	alt_Dugum->height = height(alt_Dugum);
	
	return alt_Dugum;	
}

NodeSirket* SirketAVL::rightRotate(NodeSirket *alt_Dugum) 
{ 
	NodeSirket *tmp = alt_Dugum->left; 
	alt_Dugum->left = tmp->right; 		  
	tmp->right = alt_Dugum; 
	
	//Yukseklikler guncelleniyor. 
	alt_Dugum->height = height(alt_Dugum); 
	tmp->height = max(height(tmp->left), alt_Dugum->height);
	
	return tmp;
}

NodeSirket* SirketAVL::leftRotate(NodeSirket *alt_Dugum) 
{ 
	NodeSirket *tmp = alt_Dugum->right; 
	alt_Dugum->right = tmp->left;
	tmp->left = alt_Dugum;
	
	//Yukseklikler guncelleniyor.
	alt_Dugum->height = height(alt_Dugum); 
	tmp->height = max(height(tmp->right), alt_Dugum->height);
	
	return tmp;
}

int SirketAVL::height(NodeSirket *alt_Dugum)const
{
	if(alt_Dugum == NULL)
	{
		return -1;
	}	
	
	return  max(height(alt_Dugum->left), height(alt_Dugum->right));
}

int SirketAVL::height()const
{
	return height(root);
}

void SirketAVL::Ekle(const int &calisanSayisi, string sirketAdi)
{
	root = insert(root, calisanSayisi, sirketAdi);
}

void SirketAVL::Postorder(NodeSirket *alt_Dugum) const
{
	if(alt_Dugum != NULL)
	{
		Postorder(alt_Dugum->left);
		Postorder(alt_Dugum->right);
		cout << alt_Dugum->id << endl;
		alt_Dugum->calisanlar->Postorder();
		cout << endl << endl;
	}
}

void SirketAVL::Postorder() const
{
	Postorder(root);
}

bool SirketAVL::Ara(NodeSirket *alt_Dugum, const int &calisanSayisi, string sirketAdi)
{
	if(alt_Dugum == NULL)
	{
		return false;
	}
	if(alt_Dugum->id == sirketAdi)
	{
		return true;
	}
	if(calisanSayisi <= alt_Dugum->employeeNo)
	{
		return Ara(alt_Dugum->left, calisanSayisi, sirketAdi);
	}
	if(calisanSayisi > alt_Dugum->employeeNo)
	{
		return Ara(alt_Dugum->right, calisanSayisi, sirketAdi);
	}
}

bool SirketAVL::Arama(const int &calisanSayisi, string sirketAdi)
{
	return Ara(root, calisanSayisi, sirketAdi);
}

NodeSirket* SirketAVL::sirketAra(NodeSirket *alt_Dugum, const int &calisanSayisi, string sirketAdi)
{
	if(alt_Dugum->id == sirketAdi)
	{
		return alt_Dugum;
	}
	if(calisanSayisi <= alt_Dugum->employeeNo)
	{
		return sirketAra(alt_Dugum->left, calisanSayisi, sirketAdi);
	}
	if(calisanSayisi > alt_Dugum->employeeNo)
	{
		return sirketAra(alt_Dugum->right, calisanSayisi, sirketAdi);
	}
}

NodeSirket* SirketAVL::sirketBul(const int &calisanSayisi, string sirketAdi)
{
	return sirketAra(root, calisanSayisi, sirketAdi);
}

NodeSirket* SirketAVL::sirketGetir(string sirketAdi)
{
	for(int i = 0; i < 100; i++)
	{
		if(sirketBul(i,sirketAdi)->id == sirketAdi)
		{
			return sirketBul(i,sirketAdi);
		}
	}
}

bool SirketAVL::sirketSearchBool(NodeSirket *alt_Dugum, string sirketAdi)
{
	for(int i = 0; i < 100; i++)
	{
		if(Arama(i,sirketAdi) == true)
		{
			return true;
		}
	}
	
	return false;
}

bool SirketAVL::sirketSearchBool(string sirketAdi)
{
	return sirketSearchBool(root, sirketAdi);
}

bool SirketAVL::dengeliMi(NodeSirket *alt_Dugum)
{
	if(alt_Dugum != NULL)
	{
		if(alt_Dugum->left != NULL)
		{
			if(alt_Dugum->left->employeeNo > alt_Dugum->employeeNo)
			{
				return 1;
			}
		}
		if(alt_Dugum->right != NULL)
		{
			if(alt_Dugum->right->employeeNo < alt_Dugum->employeeNo)
			{
				return 1;
			}
		}
		
		dengeliMi(alt_Dugum->left);
		dengeliMi(alt_Dugum->right);
		
	}
}

void SirketAVL::sirketDengele(NodeSirket* alt_Dugum)
{
	if(alt_Dugum->left != NULL)
	{
		if(alt_Dugum->left->employeeNo > alt_Dugum->employeeNo)
		{
			NodeSirket *t1;
			NodeSirket *t2;
			NodeSirket *t3;
			NodeSirket *t4;
			
			t1 = alt_Dugum->right;
			t2 = alt_Dugum->left->left;
			t3 = alt_Dugum->left->right;
			t4 = alt_Dugum;
			
			alt_Dugum->left->right = NULL;
			alt_Dugum = alt_Dugum->left;
			alt_Dugum->right = t1;
			alt_Dugum->left = t4;
			alt_Dugum->left->left = t2;
			alt_Dugum->left->right = t3;
			alt_Dugum->height = max(height(alt_Dugum->left), height(alt_Dugum->right));
		}
	}
	
	if(alt_Dugum->right != NULL)
	{
		if(alt_Dugum->right->employeeNo < alt_Dugum->employeeNo)
		{
			NodeSirket *t1;
			NodeSirket *t2;
			NodeSirket *t3;
			NodeSirket *t4;
	
			t1 = alt_Dugum->left;
			t2 = alt_Dugum->right->left;
			t3 = alt_Dugum->right->right;
			t4 = alt_Dugum;
			
			alt_Dugum->right->left = NULL;
			alt_Dugum = alt_Dugum->right;
			alt_Dugum->left = t1;
			alt_Dugum->right = t4;
			alt_Dugum->right->left = t2;
			alt_Dugum->right->right = t3;
			alt_Dugum->height = max(height(alt_Dugum->left), height(alt_Dugum->right));
		}
	}
}
