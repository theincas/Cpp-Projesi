// proje.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>//fatura kesim tarihi icin
#include <string>
#include <iomanip>
#include <cstdlib>//_sleep
#include <thread>
#include <locale.h>
using namespace std;
class Bilgi{
	//time_t tarih = time(NULL);
private:

	string tarih;

	string sirketAd;
	string ad;
	string soyAd;

	string faturaNo;
	int tahakkuk;
	int mansup;

public:
	//yapici fonksiyon ilk deger atama icin kullanilabilir

	Bilgi()
	{
		tarih = "**/**/****";
		sirketAd = " ";
		ad = "";
		soyAd = "";
		faturaNo = "";
		tahakkuk = 0;
		mansup = 0;
	}

	~Bilgi()
	{
		this_thread::sleep_for(chrono::milliseconds(10));
		
		
	}
	
	
	

	void setTarih(string t)
	{
		tarih = t;
	}
	void setSirketAd(string sAd)
	{
		sirketAd = sAd;
	}
	void setAd(string isim)
	{
		ad = isim;
	}
	void setSoyAd(string soyIsim)
	{
		soyAd = soyIsim;
	}
	void setfaturaNo(string fatNo)
	{
		faturaNo = fatNo;
	}
	void setTahakkuk(int tahk)
	{
		tahakkuk = tahk;
	}
	void setMansup(int mans)
	{
		mansup = mans;
	}

	string getTarih()
	{
		return tarih;
	}
	string getSirketAd()
	{
		return sirketAd;
	}
	string getAd()
	{
		return ad;
	}
	string getSoyAd()
	{
		return soyAd;
	}
	string getFaturaNo()
	{
		return faturaNo;
	}
	int getTahakkuk()
	{
		return tahakkuk;
	}
	int getMansup()
	{
		return mansup;
	}
};

class Temel{
protected:
	string tarih, sirketAd, ad, soyAd, faturaNo;
	int mansup, tahakkuk, say = 0;
public:

	void ekle()
	{
		Bilgi bilgi;
		//string tarih, sirketAd, ad, soyAd, faturaNo;
		//int mansup , tahakkuk;
		
		
		fstream dosya;
		//dosya.open("test.txt", ios::out);
		dosya.open("test.txt", ios::app);

		cout << "fatura numarasini giriniz:";
		cin >> faturaNo;
		cout << "fatura kesim tarihini giriniz:(gg/aa/yyyy)";
		cin >> tarih;
		cout << "Sirket adi giriniz:";
		cin >> sirketAd;
		cout << "Musteri adi giriniz:";
		cin >> ad;
		cout << "Musteri soyadi giriniz:";
		cin >> soyAd;
		cout << "Tahakkuk eden tutari giriniz:";//vergi dairesine odemen gereken tutar
		cin >> tahakkuk;
		cout << "Mansup edilen tutari giriniz:";//hesap edilen tutar
		cin >> mansup;

		bilgi.setfaturaNo(faturaNo);
		bilgi.setTarih(tarih);
		bilgi.setSirketAd(sirketAd);
		bilgi.setAd(ad);
		bilgi.setSoyAd(soyAd);
		bilgi.setTahakkuk(tahakkuk);
		bilgi.setMansup(mansup);

		dosya <<setw(15)<< bilgi.getFaturaNo() << setw(20) << bilgi.getTarih() << setw(25) << bilgi.getSirketAd() << setw(18) << bilgi.getAd() << setw(20)
			<< bilgi.getSoyAd() << setw(20) << bilgi.getTahakkuk() << setw(20) << bilgi.getMansup() << endl;
		cout << endl<<endl;
	}
	void listele()
	{
		fstream dosya;
		dosya.open("test.txt", ios::in);
		
		cout<< "Fatura Numarasi" << setw(20) << "Tarih" << setw(25) << "Sirket Adi" << setw(18) << "Isim" << setw(20) << "Soyisim" << setw(20) << "Tahakkuk" << setw(20) << "Mansup"<<endl;
		while (!dosya.eof())
		{
			char veri;
			dosya.get(veri);//verileri okur
			cout << veri;//ekrana yazdirir
			//üstdeki ile ayni islevi görüyor
			/*dosya >> musteri[10].faturaNo >> musteri[10].tarih >> musteri[10].sirketAd >> musteri[10].ad >> musteri[10].soyAd >>
				musteri[10].tahakkuk >> musteri[10].mansup;//dosyadan verileri okur
			cout << musteri[10].faturaNo << "\t" << musteri[10].tarih << "\t" << musteri[10].sirketAd << "\t" << musteri[10].ad << "\t"
				<< musteri[10].soyAd << "\t" << musteri[10].tahakkuk << "\t" << musteri[10].mansup << endl;//ekrana veri yazdirir*/
		}
		dosya.close();
	}

	void listele(Bilgi sirketler[])//birden fazla kayit icin(overloading)
	{
		cout << "Fatura Numarasi" << setw(20) << "Tarih" << setw(25) << "Sirket Adi" << setw(18) << "Isim" << setw(20) << "Soyisim" << setw(20) << "Tahakkuk" << setw(20) << "Mansup" << endl;
		for (int i = 0; i < sizeof(sirketler); i++)
		{
			if (sirketler[i].getSirketAd()!=" ")
			{
				cout << setw(15) << sirketler[i].getFaturaNo() << setw(20) << sirketler[i].getTarih() << setw(25) << sirketler[i].getSirketAd() << setw(18) << sirketler[i].getAd() << setw(20)
					<< sirketler[i].getSoyAd() << setw(20) << sirketler[i].getTahakkuk() << setw(20) << sirketler[i].getMansup() << endl;
			}
		}
	}
	void ara()
	{
		Bilgi bilgi[50];
		//string tarih, sirketAd, ad, soyAd,faturaNo;
		//int  mansup, tahakkuk,say=0;

		
		fstream dosya;
		string sirAd;
		dosya.open("test.txt", ios::in);

		cout << "Sirket adini giriniz:";
		cin >> sirAd;
		cout << endl;
		
		while (!dosya.eof())
		{
			dosya >> faturaNo >> tarih >> sirketAd;
			if (sirketAd==sirAd)
			{
				dosya >> ad >> soyAd >> tahakkuk >> mansup;
				if (say==0)
				{
					bilgi[say].setfaturaNo(faturaNo);
					bilgi[say].setTarih(tarih);
					bilgi[say].setSirketAd(sirketAd);
					bilgi[say].setAd(ad);
					bilgi[say].setSoyAd(soyAd);
					bilgi[say].setTahakkuk(tahakkuk);
					bilgi[say].setMansup(mansup);
					say++;
				}
				else if (bilgi[say-1].getFaturaNo()!=faturaNo)
				{
					bilgi[say].setfaturaNo(faturaNo);
					bilgi[say].setTarih(tarih);
					bilgi[say].setSirketAd(sirketAd);
					bilgi[say].setAd(ad);
					bilgi[say].setSoyAd(soyAd);
					bilgi[say].setTahakkuk(tahakkuk);
					bilgi[say].setMansup(mansup);
					say++;
				}
			}
			dosya.ignore(78, '\n');
		}
		dosya.close();
		cout << endl<<endl;
		
		listele(bilgi);
		cout << endl<<endl;
	}
};
class Temel2{
public:
	void sil()
	{
		Bilgi bilgi;
		string tarih, sirketAd, ad, soyAd,faturaNo ;
		int  mansup, tahakkuk;

		fstream dosya;

		dosya.open("test.txt",ios::in|ios::out);

		string fatNo;
		cout << "Silinicek faturanin numarasini giriniz:";
		cin >> fatNo;

		while (!dosya.eof())
		{
			dosya >> faturaNo;
			if (faturaNo==fatNo)
			{
				dosya.seekp(dosya.tellg());
				dosya.seekp(-15, ios::cur);
				dosya << string(140, '\b');
				break;
			}
			dosya.ignore(123, '\n');
			
		}
		dosya.close();
		

	}
	void guncelle()
	{
		string tarih, sirketAd, ad, soyAd, faturaNo;
		string fatNo;
		char secim;
		int  mansup, tahakkuk;

		fstream dosya;
		dosya.open("test.txt", ios::in | ios::out);

		cout << "Guncelleme yapilacak fatura`nin numarasini giriniz: ";
		cin >> fatNo;

		cout <<endl<<" 1-Tarih degistirme\n"<<" 2-Sirket adi degistirme\n"<<" 3-Isim degistirme\n"<<" 4-Soyisim degistirme\n"<<" 5-tahakkuk fiyatini degistirme\n"<<" 6-mansup fiyatini degistirme\n" <<"Yapilacak islem seciniz: ";
		cin >> secim;

		switch (secim)
		{
		case '1':
			cout << "Güncel tarihi giriniz (gg/aa/yyyy): ";
			cin >> tarih;
			while (!dosya.eof())
			{
				dosya >> faturaNo;
				if (fatNo == faturaNo)
				{
					dosya.seekp(dosya.tellg());
					//dosya << string(20, '\b');
					//dosya.seekp(-20, ios::cur);
					dosya << setw(20) << tarih;
					break;
				}
				dosya.ignore(123, '\n');
			}
			break;
		case '2':
			cout << "Güncel Sirket adini giriniz: ";
			cin >> sirketAd;
			while (!dosya.eof())
			{
				dosya >> faturaNo;
				if (fatNo == faturaNo)
				{
					
					dosya.seekp(dosya.tellg());

					dosya.seekp(20, ios::cur);
					//dosya << string(20, '\b');
					dosya << setw(25) << sirketAd;
					break;
				}
				dosya.ignore(123, '\n');
			}
			break;
		case '3':
			cout << "Güncel Adinizi giriniz: ";
			cin >> ad;
			while (!dosya.eof())
			{
				dosya >> faturaNo;
				if (fatNo == faturaNo)
				{
					dosya.seekp(dosya.tellg());

					dosya.seekp(45, ios::cur);
					//dosya << string(20, '\b');
					//dosya.seekp(-20, ios::cur);
					dosya << setw(18) << ad;
					break;
				}
				dosya.ignore(123, '\n');
			}
			break;
		case '4':
			cout << "Güncel Soyadinizi giriniz: ";
			cin >> soyAd;
			while (!dosya.eof())
			{
				dosya >> faturaNo;
				if (fatNo == faturaNo)
				{
					dosya.seekp(dosya.tellg());
					dosya.seekp(63, ios::cur);
					//dosya << string(20, '\b');
					//dosya.seekp(-20, ios::cur);
					dosya << setw(20) << soyAd;
					break;
				}
				dosya.ignore(123, '\n');
			}
			break;
		case '5':
			cout << "Güncel tahakkuk eden fiyati giriniz: ";
			cin >> tahakkuk;
			while (!dosya.eof())
			{
				dosya >> faturaNo;
				if (fatNo == faturaNo)
				{
					dosya.seekp(dosya.tellg());
					dosya.seekp(83, ios::cur);
					//dosya << string(20, '\b');
					//dosya.seekp(-20, ios::cur);
					dosya << setw(20) << tahakkuk;
					break;
				}
				dosya.ignore(123, '\n');
			}
			break;
		case '6':
			cout << "Güncel mansup edilen fiyati giriniz: ";
			cin >> mansup;
			while (!dosya.eof())
			{
				dosya >> faturaNo;
				if (fatNo == faturaNo)
				{
					dosya.seekp(dosya.tellg());
					dosya.seekp(103, ios::cur);
					//dosya << string(20, '\b');
					//dosya.seekp(-20, ios::cur);
					dosya << setw(20) << mansup;
					break;
				}
				dosya.ignore(123, '\n');
			}
			break;

		default:
			break;
		}

		
		dosya.close();

	}
};

class Temel3 :public Temel2, public Temel
{
public:
	
	void menu(){
		
		
		while (true)
		{
			cout << "1- Fatura ekle" << setw(40) << "2- Fatura Listele \n" << endl << "3- Fatura Ara" << setw(41) << "4- Fatura Guncelle\n" << endl << "5- Fatura Sil" << setw(31) << "6- Cikis\n" << endl;
			char sec;
			cout << "Bir islem seciniz:";
			cin >> sec;
			cout << endl;
			switch (sec)
			{
				case '1': 
					ekle(); 
					break;
				case '2': 
					listele(); 
					break;
				case '3': 
					ara(); 
					break;
				case '4': 
					guncelle(); 
					break;
				case '5': 
					sil(); 
					break;
				case '6': 
					exit(1);
					break;
					
				default: cout << "Hatali giris yaptiniz"; break;
			}
			
		}
		  
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Temel3 temel3;

	temel3.menu();

	//temel.ekle(); 
	//temel.listele();
	//temel.ara();
	
	//temel2.guncelle();
	//temel2.sil(); 
	return 0;
	
}

