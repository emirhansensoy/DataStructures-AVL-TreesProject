#ifndef SIRKETAVL_HPP
#define SIRKETAVL_HPP

#include "NodeSirket.hpp"
#include <string>

class SirketAVL
{
	public:
		NodeSirket *root;
		
		NodeSirket* insert(NodeSirket *alt_Dugum, const int &calisanSayisi, std::string sirketAdi);
		
		NodeSirket* rightRotate(NodeSirket *alt_Dugum);
		
		NodeSirket* leftRotate(NodeSirket *alt_Dugum);
		
		int height(NodeSirket *alt_Dugum)const;
		
		int height()const;
		
		void Ekle(const int &calisanSayisi, std::string sirketAdi);
		
		void Postorder(NodeSirket *alt_Dugum) const;
		
		void Postorder() const;
		
		bool Ara(NodeSirket *alt_Dugum, const int &calisanSayisi, std::string sirketAdi);
		
		bool Arama(const int &calisanSayisi, std::string sirketAdi);
		
		NodeSirket* sirketAra(NodeSirket *alt_Dugum, const int &calisanSayisi, std::string sirketAdi);
		
		NodeSirket* sirketBul(const int &calisanSayisi, std::string sirketAdi);
		
		bool sirketSearchBool(NodeSirket *alt_Dugum, std::string sirketAdi);
		
		bool sirketSearchBool(std::string sirketAdi);
		
		NodeSirket* sirketGetir(std::string sirketAdi);
		
		bool dengeliMi(NodeSirket *alt_Dugum);
		
		void sirketDengele(NodeSirket* alt_Dugum);
};

#endif