#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

// cumleyi kelimelere bolmeye yarıyor
template <class Container>
void split(const std::string& str, Container& cont)
{
    std::stringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}

int main()
{
    stringstream strstream;
    strstream << "bu cumle gecen icinde ayni gecen  kelimelerin en buyugu hangi kelime bul";
    string cumle = strstream.str();  //cümle string olarak alındı
	std::vector<std::string> kelime; //kelimeler vektorde tutulacak
    split(cumle, kelime);		
	map<string, int> kelimeListe;  //hem kelime hem de sayısını tutmak icin oluşturulan map
	bool kontrol = true;
	for(int i=0; i < kelime.size() ; i++)
	{
		//vektorden gelen kelime map de varsa sayısı arttırılır
		std::map<std::string, int>::iterator it = kelimeListe.find(kelime[i]);
		while(it != kelimeListe.end() )
		{
			it->second = it->second +1;
			kontrol=false;
			break;
		}

		//vektorden gelen kelime map de yoksa mape eklenir
		if(kontrol)
		{
			kelimeListe.insert(std::make_pair(kelime[i],1));	
		}
		kontrol =true;
	}

	// en cok kullanılan kelimeyi bulmak icin
	string en_cok_kullanılan ;
	int sayi = 0;
	std::map<std::string, int>::iterator it = kelimeListe.begin();
	while(it != kelimeListe.end())
	{
		if (it ->second > sayi) {
			en_cok_kullanılan = it->first;
			sayi = it->second;
		}
		it++;
	}

    cout <<  "en cok gecen kelime -" << en_cok_kullanılan  << "-dir."<< endl;

	return 0;
}