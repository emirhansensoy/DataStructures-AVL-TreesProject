#ifndef CALISANAVL_HPP
#define CALISANAVL_HPP

#include "NodeCalisan.hpp"
#include <string>

class CalisanAVL
{
	public:
		NodeCalisan *root;
		
		NodeCalisan* insert(NodeCalisan *alt_Dugum, const int &yeni, std::string adSoyad);
		
		NodeCalisan* rightRotate(NodeCalisan *alt_Dugum);
		
		NodeCalisan* leftRotate(NodeCalisan *alt_Dugum);
		
		int height(NodeCalisan *alt_Dugum)const;
		
		int height()const;
		
		void Ekle(const int &yeni, std::string adSoyad);
		
		void Postorder(NodeCalisan *alt_Dugum);
		
		void Postorder();
};

#endif