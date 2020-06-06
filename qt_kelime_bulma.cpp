#include "kelime.h"
#include <QtGui/QApplication>
#include <qDebug>


int main()
{
	//QApplication a(argc, argv);
	QString cumle = "O pikap bu pikap şu pikap";
	QList<QString> kelimeListe = cumle.split(" ");
	QMap<QString, int> map;
	bool kontrol =true;

	for(int i = 0 ; i<kelimeListe.size(); i++)
	{	
		QMap<QString, int>::const_iterator it= map.find(kelimeListe[i]);
		while (it != map.end() && it.key() == kelimeListe[i]) {
			int value = it.value() + 1;
			map.insert(kelimeListe[i],value);
			kontrol = false;
			break;
		}
		if(kontrol)
		{	
			map.insert(kelimeListe[i],1);
		}
		kontrol= true;	
	}

	QString en_cok_gecen_kelime;
	int sayi=0;
	QMap<QString, int>::const_iterator it = map.constBegin();
	while (it != map.constEnd()) {
		if(sayi<it.value())
		{
			en_cok_gecen_kelime = it.key();
			sayi= it.value();
		}
		it++;
	}

	qDebug()<< "en cok gecen kelime " + en_cok_gecen_kelime + "dir ve " + QString::number(sayi) + " defa gecmistir.";

	return 0;
}