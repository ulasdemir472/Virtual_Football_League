#include <iostream>
#include<vector> //vector yapısından yararlanmak icin kütüphane
#include<ctime> //rand fonksiyonunu kullanmak icin kütüphane
#include<string>
#include<fstream> //dosya kütüphanesi
#include <iomanip> //setw , setfill kullanmak icin kütüphane
using namespace std;
class Takim; //fikstur classının takım classını tanıması için prototip

class Fikstur {  //fikstür oluşturmak için class
private:
	string takim1;
	string takim2;
	int score1;
	int score2;
	int macID;
	int hafta;

public:
	Fikstur(string, string, int, int, int, int, Takim*, Takim*);
	Takim* takim_1; //takim1 in adresini tutar.
	Takim* takim_2; //takim2 nin  adresini tutar.
	void setScore1(int);
	void setScore2(int);
	string getTakim1();
	string getTakim2();
	int getScore1();
	int getScore2();
	int getmacID();
	void displayMessage();
	int getHafta();
};
void Fikstur::displayMessage() {
	cout << "HAFTA:" << hafta << endl << "MAC ID: " << macID << endl << takim1 << " " << "vs" << " " << takim2 << endl;
	cout << "\n";
}
Fikstur::Fikstur(string t1, string t2, int id, int h, int s1, int s2, Takim* a, Takim* b) {
	takim1 = t1;
	takim2 = t2;
	takim_1 = a;
	takim_2 = b;
	score1 = s1;
	score2 = s2;
	macID = id;
	hafta = h;
}
int Fikstur::getmacID() {
	return macID;
}
string Fikstur::getTakim1() {
	return takim1;
}
string Fikstur::getTakim2() {
	return takim2;
}
void Fikstur::setScore1(int s) {
	score1 = s;
}
void Fikstur::setScore2(int s) {
	score2 = s;
}
int Fikstur::getScore1() {
	return score1;
}
int Fikstur::getScore2() {
	return score2;
}
int Fikstur::getHafta() {
	return hafta;
}

class Futbolcu { //futbolcuların özelliklerini taşıyan class
private:
	string isim;
	string soyisim;
	string mevki;
	int yas=0;
	int performans=0;
	int formaNumarasi=0;
public:
	Futbolcu();
	void set_isim(string);
	void set_soyisim(string);
	void setMevki(string);
	void setPerformans(int); //Kullanıcının performans değerini değiştirmesine olanak sağlar
	void setRandomPerformans(); //Rastgele performans değeri atar(30-100 arasında)
	void setFormaNumarasi();
	void setYas();
	string get_isim();
	string get_soyisim();
	string getMevki();
	int getYas();
	int getPerformans();
	int getFormaNumarasi();

};
ifstream dosya2("C:\\Users\\ulasd\\Desktop\\UlasDemir\\OOP PROJE\\isim.txt");//isim.txt dosyasından isimler atanıyor
ifstream dosya3("C:\\Users\\ulasd\\Desktop\\UlasDemir\\OOP PROJE\\soyisim.txt");//soyisim.txt dosyasından soyisim atanır
Futbolcu::Futbolcu() {
	dosya2 >> isim;
	dosya3 >> soyisim;
}
void Futbolcu::set_isim(string name) {
	this->isim = name;
}
void Futbolcu::set_soyisim(string lastName) {
	this->soyisim = lastName;
}
void Futbolcu::setMevki(string mevki) {
	this->mevki = mevki;
}
void Futbolcu::setYas()
{
	//futbolcuya rastgele yaş atanıyor
	int alt_yas = 18, ust_yas = 36;
	yas = (rand() % (ust_yas - alt_yas + 1) + alt_yas);
}
void Futbolcu::setPerformans(int num) {
	if (num >= 30 && num <= 100) {  //futbolcunun performansını değiştirmek için set fonksiyonu
		performans = num;
	}
}
void Futbolcu::setFormaNumarasi()
{
	formaNumarasi = (rand() % 99 + 1); //rastgele forma numarası atanıyor
}
void Futbolcu::setRandomPerformans() { //rastgele performans değeri atanıyor
	int alt_performans_degeri = 30, ust_performans_degeri = 100;
	performans = (rand() % (ust_performans_degeri - alt_performans_degeri + 1) + alt_performans_degeri);
}
string Futbolcu::get_isim() {
	return isim;
}
string Futbolcu::get_soyisim() {
	return soyisim;
}
string Futbolcu::getMevki() {
	return mevki;
}
int Futbolcu::getYas() {
	return yas;
}
int Futbolcu::getPerformans() {
	return performans;
}
int Futbolcu::getFormaNumarasi() {
	return formaNumarasi;
}
class Takim {//takımların özelliklerini içeren class
#pragma region reg1
private:
	string takimAdi;
	string teknikDirektor;
	string takmaAd;
	double ortalamaYas;
	int puan = 0;
	int galibiyet_sayisi = 0;
	int maglubiyet_sayisi = 0;
	int beraberlik_sayisi = 0;
	int atilan_gol = 0;
	int yenilen_gol = 0;
	int averaj = 0;
protected:
	double ortalamaPerformans;
public:
	Futbolcu f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11; //her takım için 11 futbolcu
	Takim(string = "NO INFO", string = "NO INFO", string = "NO INFO"); //default constructor
	void setTakimAdi(string);
	void setTeknikDirektor(string);
	void setTakmaAd(string);
	void setOrtalamaYas();
	void setOrtalamaPerformans();
	void set_Forma_Numarasi();
	void setPuan(int);
	void setGalibiyetSayisi(int);
	void setBeraberlikSayisi(int);
	void setMaglubiyetSayisi(int);
	void setAtilanGol(int);
	void setYenilenGol(int);
	void setAveraj(int);
	string getTakimAdi();
	string getTeknikDirektor();
	string getTakmaAd();
	double getOrtalamaYas();
	double getOrtalamaPerformans();
	double get_defans_ortalama_performans();
	double get_orta_saha_ortalama_performans();
	double get_forvet_ortalama_performans();
	vector<Fikstur> maclar;
	vector<Fikstur>* getFikstur();
	int getPuan();
	int getGalibiyetSayisi();
	int getBeraberlikSayisi();
	int getMaglubiyetSayisi();
	int getAtilanGol();
	int getYenilenGol();
	int getAveraj();
};
Takim::Takim(string name1, string name2, string name3)
{
	setTakimAdi(name1);
	setTeknikDirektor(name2);
	setTakmaAd(name3);
	setOrtalamaYas();
	setOrtalamaPerformans();
	set_Forma_Numarasi();
	f1.setMevki("KALECI");
	f2.setMevki("DEFANS");
	f3.setMevki("DEFANS");
	f4.setMevki("DEFANS");
	f5.setMevki("DEFANS");
	f6.setMevki("ORTA SAHA");
	f7.setMevki("ORTA SAHA");
	f8.setMevki("ORTA SAHA");
	f9.setMevki("ORTA SAHA");
	f10.setMevki("FORVET");
	f11.setMevki("FORVET");
}
void Takim::setTakimAdi(string name) {
	takimAdi = name;
}
void Takim::setTeknikDirektor(string name) {
	teknikDirektor = name;
}
string Takim::getTakimAdi() {
	return takimAdi;
}
string Takim::getTeknikDirektor() {
	return teknikDirektor;
}
void Takim::setTakmaAd(string name) {
	takmaAd = name;
}
string Takim::getTakmaAd() {
	return takmaAd;
}
void Takim::setOrtalamaPerformans()
{
	double toplam = 0;
	double ortalama = 0;
	Futbolcu* futbolcu[11] = { &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 }; //futbolculara ulaşıp performanslarını toplamak için pointer dizi
	for (int j = 0; j < 11; j++)
	{

		futbolcu[j]->setRandomPerformans();
		toplam += futbolcu[j]->getPerformans();
	}
	ortalama = toplam / 11;
	if (ortalama < 60)
	{
		ortalama = 0;
		toplam = 0;
		return setOrtalamaPerformans();
	}
	else {
		ortalamaPerformans = ortalama;
	}
}
void Takim::setOrtalamaYas()
{
	double toplam = 0;
	double ortalama = 0;
	Futbolcu* futbolcu[11]{ &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 };
	for (int j = 0; j < 11; j++)
	{
		futbolcu[j]->setYas();
		toplam += futbolcu[j]->getYas();
	}
	ortalama = toplam / 11;
	if (ortalama < 25)
	{
		ortalama = 0;
		toplam = 0;
		return setOrtalamaYas();
	}
	else {
		ortalamaYas = ortalama;
	}
}
void Takim::set_Forma_Numarasi() {
	Futbolcu* futbolcu[11]{ &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 };
	for (int j = 0; j < 11; j++)
	{
		futbolcu[j]->setFormaNumarasi();
		kontrol:
		for (int a = 0 ; a < j; a++) {

			if (futbolcu[a]->getFormaNumarasi() == futbolcu[j]->getFormaNumarasi()) {
				futbolcu[j]->setFormaNumarasi();
				goto kontrol;
			}
		}
	}
}
double Takim::getOrtalamaYas() {
	return ortalamaYas;
}
double Takim::getOrtalamaPerformans() {
	double toplam = 0;
	double ortalama = 0;
	Futbolcu* futbolcu[11] = { &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 };
	for (int j = 0; j < 11; j++)
	{
		toplam += futbolcu[j]->getPerformans();
	}
	ortalama = toplam / 11;
	return ortalama;
}
double Takim::get_defans_ortalama_performans()
{
	double defans_performans = 0;
	double defans_ortalama = 0;
	int a = 0;
	Futbolcu* futbolcu[11] = { &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 };
	for (int j = 0; j < 11; j++)
	{
		if (futbolcu[j]->getMevki() == "DEFANS")
		{
			a++;
			defans_performans = defans_performans + futbolcu[j]->getPerformans();
		}
	}
	defans_ortalama = defans_performans / a;
	return defans_ortalama;
}
double Takim::get_orta_saha_ortalama_performans()
{
	double orta_saha_performans = 0;
	double orta_saha_ortalama = 0;
	int a = 0;
	Futbolcu* futbolcu[11] = { &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 };
	for (int j = 0; j < 11; j++)
	{
		if (futbolcu[j]->getMevki() == "DEFANS")
		{
			a++;
			orta_saha_performans = orta_saha_performans + futbolcu[j]->getPerformans();
		}
	}
	orta_saha_ortalama = orta_saha_ortalama / a;
	return orta_saha_ortalama;
}
double Takim::get_forvet_ortalama_performans()
{
	double forvet_performans = 0;
	double forvet_ortalama = 0;
	int a = 0;
	Futbolcu* futbolcu[11] = { &f1,&f2,&f3,&f4,&f5,&f6,&f7,&f8,&f9,&f10,&f11 };
	for (int j = 0; j < 11; j++)
	{
		if (futbolcu[j]->getMevki() == "DEFANS")
		{
			a++;
			forvet_performans = forvet_performans + futbolcu[j]->getPerformans();
		}
	}
	forvet_ortalama = forvet_performans / a;
	return forvet_ortalama;
}
vector<Fikstur>* Takim::getFikstur() {
	return &maclar;
}
void Takim::setPuan(int puan)
{
	this->puan = puan;
}
int Takim::getPuan()
{
	return puan;
}
void Takim::setGalibiyetSayisi(int a)
{
	this->galibiyet_sayisi = a;
}
void Takim::setMaglubiyetSayisi(int b)
{
	this->maglubiyet_sayisi = b;
}
void Takim::setBeraberlikSayisi(int c)
{
	this->beraberlik_sayisi = c;
}
void Takim::setAtilanGol(int d)
{
	this->atilan_gol = d;
}
void Takim::setYenilenGol(int e)
{
	this->yenilen_gol = e;
}
void Takim::setAveraj(int f)
{
	this->averaj = f;
}
int Takim::getGalibiyetSayisi()
{
	return galibiyet_sayisi;
}
int Takim::getMaglubiyetSayisi()
{
	return maglubiyet_sayisi;
}
int Takim::getBeraberlikSayisi()
{
	return beraberlik_sayisi;
}
int Takim::getAtilanGol()
{
	return atilan_gol;
}
int Takim::getYenilenGol()
{
	return yenilen_gol;
}
int Takim::getAveraj()
{
	return averaj;
}
#pragma en();dregion reg1
void menu(); //menü fonksiyon tanımı
void takim_skor_olustur(vector<Takim>&); //maçlara skor oluşturmak için fonksiyon
void Fikstur_Olustur(vector<Takim>&); //fikstür oluşturan fonksiyon tanımı

int main() {
	cout << "-------------------------------MENU-------------------------------" << endl;
	menu(); //seçenekleri barındıran menü fonksiyonu
	return 0;
}

void bubbleSort(vector<Takim>& vec) { //puanlara göre sıralayan bubblesort fonksiyonu
	for (size_t i = 0; i < vec.size() - 1; ++i) {
		for (size_t j = 0; j < vec.size() - i - 1; ++j) {
			if (vec.at(j).getPuan() < vec.at(j + 1).getPuan())
			{
				swap(vec.at(j), vec.at(j + 1));
			}
			if (vec.at(j).getPuan() == vec.at(j + 1).getPuan())
			{
				if (vec.at(j).getAveraj() < vec.at(j + 1).getAveraj())
				{
					swap(vec.at(j), vec.at(j + 1));
				}
			}
		}
	}
}
vector<Takim*> takim_liste; //1.takım harici diğer takımları tutmak için vector
vector<Fikstur> fikstur; //oluşturulan maçları fikstur vectoruna atarız
void Fikstur_Olustur(vector<Takim>& takimlar)
{
	string bay_name1 = "bay";
	string bay_name2 = "bay";
	string bay_name3 = "bay";
	Takim bay_takim(bay_name1, bay_name2, bay_name3);
	if (takimlar.size() % 2 != 0)
	{
		takimlar.push_back(bay_takim); //takım silerken veya eklerken takım sayısı tek olursa bay takım eklenir
	}
	int takim_sayisi = takimlar.size();
	int hafta = takim_sayisi - 1;
	int yarim = takim_sayisi / 2;
	int macID = 1;
	vector<Takim>::iterator i = takimlar.begin();
	while (i != takimlar.end()) {
		takim_liste.push_back(&(*i));
		i++;
	}
	takim_liste.erase(takim_liste.begin()); //fikstürün oluşabilmesi için ilk takım silinir.
	int takim_liste_sayi = takim_liste.size();
	for (int h = 0; h < hafta; h++)
	{
		srand((unsigned int)time(NULL));
		cout << "Hafta : " << h + 1 << endl;

		if (takim_liste[h]->getTakimAdi() == bay_name1 || takimlar[0].getTakimAdi() == bay_name1)
		{
			cout << takim_liste[h]->getTakimAdi() << " " << takimlar[0].getTakimAdi() << endl << endl;
		}
		else {
			cout << macID << ") " << takim_liste[h]->getTakimAdi() << " vs " << takimlar[0].getTakimAdi() << endl << endl;
			int c = rand() % 6;//rastgele skor atanır
			int d = rand() % 6;
			Fikstur a(takim_liste[h]->getTakimAdi(), takimlar[0].getTakimAdi(), macID++, h + 1, c, d, takim_liste[h], &takimlar[0]);
			takim_liste[h]->maclar.push_back(a);
			takimlar[0].maclar.push_back(a);
			fikstur.push_back(a);
		}
		for (int i = 1; i < yarim; i++)
		{
			int ilk_takim = (h + i) % takim_liste_sayi;
			int ikinci_takim = (h + takim_liste_sayi - i) % takim_liste_sayi;
			if (takim_liste[ilk_takim]->getTakimAdi() == bay_name1 || takim_liste[ikinci_takim]->getTakimAdi() == bay_name1)
			{
				cout << takim_liste[ilk_takim]->getTakimAdi() << "  " << takim_liste[ikinci_takim]->getTakimAdi() << endl << endl;
			}
			else {
				cout << macID << ") " << takim_liste[ilk_takim]->getTakimAdi() << " vs " << takim_liste[ikinci_takim]->getTakimAdi() << endl << endl;
				int x = rand() % 6;
				int y = rand() % 6;
				Fikstur b(takim_liste[ilk_takim]->getTakimAdi(), takim_liste[ikinci_takim]->getTakimAdi(), macID++, h + 1, x, y, takim_liste[ilk_takim], takim_liste[ikinci_takim]);
				takim_liste[ilk_takim]->maclar.push_back(b);
				takim_liste[ikinci_takim]->maclar.push_back(b);
				fikstur.push_back(b);
			}
		}
	}
	cout << endl;
}

void skor_olustur(vector<Fikstur>* takim_maclar) { //verilen kurallara göre skorlar düzenlenir
	vector<Fikstur>::iterator c = takim_maclar->begin();
	while (c != takim_maclar->end()) {
		int a, b;
		a = c->getScore1();
		b = c->getScore2();
		if (c->takim_1->get_forvet_ortalama_performans() > c->takim_2->get_forvet_ortalama_performans()) {
			a++;
		}
		if (c->takim_2->get_forvet_ortalama_performans() > c->takim_1->get_forvet_ortalama_performans()) {
			b++;
		}
		if (c->takim_1->get_defans_ortalama_performans() > c->takim_2->get_defans_ortalama_performans()) {
			if (b != 0) b--;
		}
		if (c->takim_2->get_defans_ortalama_performans() > c->takim_1->get_defans_ortalama_performans()) {
			if (a != 0) a--;
		}
		if (c->takim_1->get_orta_saha_ortalama_performans() > c->takim_2->get_orta_saha_ortalama_performans()) {
			a++;
			if (b != 0) b--;
		}
		if (c->takim_2->get_orta_saha_ortalama_performans() > c->takim_1->get_orta_saha_ortalama_performans()) {
			b++;
			if (a != 0) a--;
		}
		if (c->takim_1->getOrtalamaPerformans() > c->takim_2->getOrtalamaPerformans()) {
			a++;
		}
		if (c->takim_2->getOrtalamaPerformans() > c->takim_2->getOrtalamaPerformans()) {
			b++;
		}
		c->setScore1(a);
		c->setScore2(b);
		c++;
	}
}
void takim_skor_olustur(vector<Takim>& takimlar)
{
	vector<Takim>::iterator i = takimlar.begin();
	while (i != takimlar.end()) {
		vector<Fikstur>* takim_maclar = i->getFikstur();
		skor_olustur(takim_maclar);
		i++;
	}
}
void menu()
{
	ifstream dosya1("C:\\Users\\ulasd\\Desktop\\UlasDemir\\OOP PROJE\\takimlar.txt");
	vector<Takim> takimlar; //takımları nesneler halinde içeren vector oluşturuluyor
	vector<Takim>::iterator i = takimlar.begin();
	vector<string> takim_adlari;
	vector<string> takma_adlar;
	string takim_adi, td_adi, takma_ad;
	while (!dosya1.eof()) {
		getline(dosya1, takim_adi, '-');
		takim_adlari.push_back(takim_adi);
		getline(dosya1, td_adi, '\n');
		takma_ad = takim_adi.substr(0, 2);
		takma_adlar.push_back(takma_ad);
		takimlar.push_back(Takim(takim_adi, td_adi, takma_ad)); //dosyadan isim cekip,constructor olusturup,takimlar vectorunun içine atar
	}
	for (int a = 0; a < takim_adlari.size(); a++) //takma adlar aynı mı diye kontrol eder aynıysa değiştirir
	{
		for (int b = takma_adlar.size(); b > 0; b--)
		{
			if (takma_ad == takma_adlar.at(b - 1))
			{
				takma_ad = takim_adlari.at(a).substr(0, 3);
				takimlar.at(a).setTakmaAd(takma_ad);
			}
		}
	}
secim:
	string secim;
	cout << "0.)Programi sonlandirmak icin 0 yaziniz." << endl;
	cout << "1.)Takim silmek veya eklemek icin 1 yaziniz." << endl;
	cout << "2.)Takim bilgilerini gormek icin 2 yaziniz.(Takim adi ile) " << endl;
	cout << "3.)Takimlara formasyon atamak icin 3 yaziniz. " << endl;
	cout << "4.)Takim bilgilerini gormek icin 4 yaziniz.(Takma adi ile)" << endl;
	cout << "5.)Fikstur olusturmak icin 5 yaziniz." << endl;
	cin >> secim;
	if (secim == "1")
	{
		system("cls");
		int sec;
		cout << "1.)Takim silmek icin 1 yaziniz." << endl;
		cout << "2.)Takim eklemek icin 2 yaziniz." << endl;
		cout << "3.)Onceki menuye donmek icin 3 yaziniz." << endl;
		cin >> sec;
		if (sec == 1)
		{
			cout << "Guncel takimlar asagidadir." << endl << endl << endl;
			vector<Takim>::iterator i = takimlar.begin(); //takimlar vectorunun içcindekilere iterator yardiimiyla ulasılır
			while (i != takimlar.end()) {
				cout << i->getTakimAdi() << endl;
				i++;
			}
			while (true) {
				string isim;
				cin.ignore();
				cout << "Lutfen silmek istediginiz takimi giriniz: ";
				getline(cin, isim);
				i = takimlar.begin();
				int a = 0;
				while (i != takimlar.end())
				{
					if (i->getTakimAdi() == isim)
						a++;
					i++;
				}
				if (a == 0)
				{
					cout << "Takim bulunamadi."<<"\n\n";
					goto secim;
				}
				i = takimlar.begin();
				while (i != takimlar.end())
				{
					if (isim == i->getTakimAdi()) {
						takimlar.erase(i); //vectorden takim silinir
						cout << "\n\n\nGuncel takimlar asagidadir." << endl << endl;
						i = takimlar.begin();
						while (i != takimlar.end()) {
							cout << i->getTakimAdi() << endl;
							i++;
						}
						cout << endl;
						goto secim;
					}
					i++;
				}

			}
		}
		else if (sec == 2)
		{
			cout << "\n\n\nGuncel takimlar asagidadir." << endl << endl << endl;
			i = takimlar.begin(); //i iteratörü sonda kalmasın diye başa setlenir
			while (i != takimlar.end()) {
				cout << i->getTakimAdi() << endl;
				i++;
			}
			while (true) {
				string takim_adi, td_adi, takma_ad;
			ekle:
				cin.ignore();
				cout << "Lutfen eklemek istediginiz takimin adini giriniz :" << endl;
				getline(cin, takim_adi);
				cout << "Lutfen eklemek istediginiz takimin teknik direktorunu giriniz :" << endl;
				getline(cin, td_adi);
				cout << "Lutfen eklemek istediginiz takimin takma adini giriniz :" << endl;
				getline(cin, takma_ad);
				cout << endl;
			check:
				i = takimlar.begin();
				while (i != takimlar.end()) { //girilen takma ad başka takımınki ile aynı ise değiştirilme talep edilir
					if (takma_ad == i->getTakmaAd()) {
						cout << "Lutfen farkli bir takma ad giriniz:";
						cin >> takma_ad;
						goto check;
					}
					if (takim_adi == i->getTakimAdi() || td_adi == i->getTeknikDirektor())
					{
						cout << "Takim veya teknik direktor zaten bulunmakta!" << "\n\n";
						goto secim;
					}

					i++;
				}
				takimlar.push_back(Takim(takim_adi, td_adi, takma_ad));//yeni eklene takım vectore eklenir
				char karar;
				cout << "Baska takim eklemek ister misiniz(E/H): " << endl;
				cin >> karar;
				if (karar == 'H')
				{
					cout << "\n\n\nGuncel takimlar asagidadir." << endl << endl;
					i = takimlar.begin();
					while (i != takimlar.end()) {
						cout << i->getTakimAdi() << endl;
						i++;
					}
					goto secim;
				}
				else {
					goto ekle;
				}
				i = takimlar.begin();
			}
		}
		else if (sec == 3)
		{
			system("cls");
			goto secim;
		}
		else {
			cout << "Hatali sayi girdiniz." << endl;
			system("cls");
			goto secim;
		}
	}
	else if (secim == "2")
	{
		vector<Takim>::iterator i = takimlar.begin();
		cout << endl;
		int a = 0;
		while (true) {
			kontrol_takim: //tekrar sorma döngüsünün oluşabilmesi için geri dönüş noktası
				string isim;
				while (a < 1) //sadece 1 kere çalışması için
				{
					cin.ignore();
					a++;
				}
				cout << "Lutfen bilgilerini gormek istediginiz takim adini buyuk harfle giriniz(Cikmak icin 0): ";
				getline(cin, isim);
				if (isim == "0")
				{
					system("cls");
					goto secim;
				}
				while (i != takimlar.end())
				{
					if (isim == i->getTakimAdi()) {
						break;
					}
					if (i == takimlar.end()-1)
					{
						cout << "Boyle bir takim bulunmamakta.\n\n";
						i = takimlar.begin();
						goto kontrol_takim;
					}
					i++;
				}
				while (i != takimlar.end()) {
					if (i->getTakimAdi() == isim) {
						cout << "Takim adi: " << i->getTakimAdi() << endl << "Teknik direktor: " << i->getTeknikDirektor() << endl << "Takma ad: " << i->getTakmaAd() << endl << endl << endl;
					}
					i++;
				}
				i = takimlar.begin();
		}
	}
	else if (secim == "3")
	{
		vector<Takim>::iterator i = takimlar.begin();
		while (i != takimlar.end()) {
			cout << "TAKIM ADI: " << i->getTakimAdi() << endl << endl;
			cout << "1) 4 4 2" << endl << "2) 4 2 3 1" << endl << "3) 4 3 3" << endl << "4) 4 1 4 1" << endl << "5) 3 5 2" << endl << "6) 3 4 3" << endl;
			cout << "LUTFEN TAKIMIN DIZILIS FORMASYONUNU SECINIZ : " << endl;
			int sayi;
			cin >> sayi;
			switch (sayi) {//seçime göre futbolculara mevki atanır
			case 1:
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("DEFANS");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("ORTA SAHA");
				i->f10.setMevki("FORVET");
				i->f11.setMevki("FORVET");
				break;
			case 2:
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("DEFANS");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("ORTA SAHA");
				i->f10.setMevki("ORTA SAHA");
				i->f11.setMevki("FORVET");
				break;
			case 3:
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("DEFANS");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("FORVET");
				i->f10.setMevki("FORVET");
				i->f11.setMevki("FORVET");
				break;
			case 4:
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("DEFANS");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("ORTA SAHA");
				i->f10.setMevki("ORTA SAHA");
				i->f11.setMevki("FORVET");
				break;
			case 5:
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("ORTA SAHA");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("ORTA SAHA");
				i->f10.setMevki("FORVET");
				i->f11.setMevki("FORVET");
				break;
			case 6:
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("ORTA SAHA");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("FORVET");
				i->f10.setMevki("FORVET");
				i->f11.setMevki("FORVET");
				break;
			default: //tercih yapılmayan veya yanlış tercih yapılan takıma otomatik 4-4-2 formasyonu atanır
				i->f1.setMevki("KALECI");
				i->f2.setMevki("DEFANS");
				i->f3.setMevki("DEFANS");
				i->f4.setMevki("DEFANS");
				i->f5.setMevki("DEFANS");
				i->f6.setMevki("ORTA SAHA");
				i->f7.setMevki("ORTA SAHA");
				i->f8.setMevki("ORTA SAHA");
				i->f9.setMevki("ORTA SAHA");
				i->f10.setMevki("FORVET");
				i->f11.setMevki("FORVET");
			}
			i++;
		}
		system("cls");
		goto secim;
	}
	else if (secim == "4")
	{
		vector<Takim>::iterator i = takimlar.begin();
		cout << endl;
		while (true)
		{
		takma_ad_secim:
			string takma_ad;
			cout << "Bilgilerini gormek istediginiz takimin takma adini giriniz(Cikmak icin '0') : " << endl;
			cin >> takma_ad;
			if (takma_ad == "0")
			{
				system("cls");
				goto secim;
			}
			while (i != takimlar.end())
			{
				if (takma_ad == i->getTakmaAd()) {
					break;
				}
				if (i == takimlar.end()-1)
				{
					cout << "Boyle bir takim bulunmamakta.\n\n";
					i = takimlar.begin();
					goto takma_ad_secim;
				}
				i++;
			}
			while (i != takimlar.end())
			{
				//futbolculara ulaşmak için pointer dizi
				Futbolcu* futbolcu[11] = { &(i->f1),&(i->f2),&(i->f3),&(i->f4),&(i->f5),&(i->f6),&(i->f7),&(i->f8),&(i->f9),&(i->f10),&(i->f11) };
				if (takma_ad == i->getTakmaAd())
				{
					cout << "Takim adi : " << i->getTakimAdi() << endl;
					cout << "Teknik direktor adi : " << i->getTeknikDirektor() << endl;
					cout << "Takim ortalama yas : " << i->getOrtalamaYas() << endl;
					cout << "Takim ortalama performans : " << i->getOrtalamaPerformans() << endl << endl;
					cout << left << setw(20) << "Ad" << left << setw(20) << "Soyad" << left << setw(20) << "Yas" << left << setw(20) << "Forma NO" << left << setw(20) << "Performans" << left << setw(20) << "Mevki" << endl;
					cout << "------------------------------------------------------------------------------------------------------------" << endl;
					for (int j = 0; j < 11; j++)
					{
						cout << left << setw(20) << futbolcu[j]->get_isim() << left << setw(20) << futbolcu[j]->get_soyisim() << left << setw(20) << futbolcu[j]->getYas() << left << setw(20) << futbolcu[j]->getFormaNumarasi() << left << setw(20) << futbolcu[j]->getPerformans() << left << setw(20) << futbolcu[j]->getMevki() << endl << endl;
					}
					while (true) {
						cout << "Performans degerini degistirmek istediginiz futbolcunun ismini giriniz(Cikmak icin 0):";
						string a;
						cin >> a;
						if (a == "0")
						{
							i = takimlar.begin();
							goto takma_ad_secim;
						}
						cout << "Futbolcunun yeni performansini giriniz:";
						int b;
						cin >> b;
						for (int j = 0; j < 11; j++) {
							if (futbolcu[j]->get_isim() == a) futbolcu[j]->setPerformans(b); //futbolcuya istenilen performans atanır
						}
					}
				}
				else {
					i++;
				}
			}
		}
	}
	else if (secim == "5")
	{
		Fikstur_Olustur(takimlar);
		takim_skor_olustur(takimlar);
		skor_olustur(&fikstur);
	don:
		string sec;
		cout << "\n";
		cout << "---------------------FIKSTUR MENU-------------------------------------\n";
		cout << "0.)Programi sonlandirmak icin 0 yaziniz." << endl;
		cout << "1.)MacID ile mac bilgilerini gormek icin 1 yaziniz.(Cikmak icin 0 yaziniz)" << endl;
		cout << "2.)Bir takima ait fiksturu gormek icin 2 yaziniz.(Cikmak icin 0 yaziniz)" << endl;
		cout << "3.)Her takimin sadece kendi fiksturune skorlariyla beraber erismek icin 3 yaziniz.(Cikmak icin 0 yaziniz)" << endl;
		cout << "4.)Tum fiksturu hafta hafta gormek icin 4 yaziniz." << endl;
		cout << "5.)Oynanan tum maclari hafta hafta skorlariyla beraber goruntulemek icin 5 yaziniz." << endl;
		cout << "6.)Puan durumu icin 6 yaziniz" << endl;
		cin >> sec;
		if (sec == "1")
		{
			system("cls");
		dongu:
			while (true) {
				int q;
				cout << "mac id giriniz(Cikmak icin 0):";
				cin >> q;
				if (q == 0)
				{
					system("cls");
					goto don;
				}
				i = takimlar.begin();
				while (i != takimlar.end()) {
					vector<Fikstur>::iterator p = i->maclar.begin();
					while (p != i->maclar.end()) {
						if (p->getmacID() == q) {
							p->displayMessage();
							cout << endl;
							i = takimlar.begin();
							while (i != takimlar.end()) {
								if (i->getTakimAdi() == p->getTakim1()) {
									vector<Takim>::iterator a = takimlar.begin();
									while (a != takimlar.end())
									{
										if (a->getTakimAdi() == p->getTakim2())
										{
											cout << "Takim adi: " << left << setw(49) << i->getTakimAdi() << "Takim adi: " << a->getTakimAdi() << endl;
											cout << "Takim ortalama performansi: " << i->getOrtalamaPerformans();
											cout << right << setw(53) << "Takim ortalama performansi: " << a->getOrtalamaPerformans() << endl;
											cout << "Takimin kazanma olasiligi: " << "%" << (i->getOrtalamaPerformans() / (i->getOrtalamaPerformans() + a->getOrtalamaPerformans())) * 100;
											cout << right << setw(52) << "Takimin kazanma olasiligi: " << "%" << (a->getOrtalamaPerformans() / (i->getOrtalamaPerformans() + a->getOrtalamaPerformans())) * 100 << endl << endl;
											cout << left << setw(20) << "ISIM" << left << setw(20) << "SOYISIM" << left << setw(20) << "MEVKI";
											cout << left << setw(20) << "ISIM" << left << setw(20) << "SOYISIM" << left << setw(20) << "MEVKI" << endl;
											cout << "------------------------------------------------------" << "      " << "------------------------------------------------------" << endl;
											Futbolcu* futbolcu_i[11] = { &(i->f1),&(i->f2),&(i->f3),&(i->f4),&(i->f5),&(i->f6),&(i->f7),&(i->f8),&(i->f9),&(i->f10),&(i->f11) };
											Futbolcu* futbolcu_a[11] = { &(a->f1),&(a->f2),&(a->f3),&(a->f4),&(a->f5),&(a->f6),&(a->f7),&(a->f8),&(a->f9),&(a->f10),&(a->f11) };
											for (int j = 0; j < 11; j++)
											{
												cout << left << setw(20) << futbolcu_i[j]->get_isim() << left << setw(20) << futbolcu_i[j]->get_soyisim() << left << setw(20) << futbolcu_i[j]->getMevki();
												cout << left << setw(20) << futbolcu_a[j]->get_isim() << left << setw(20) << futbolcu_a[j]->get_soyisim() << left << setw(20) << futbolcu_a[j]->getMevki() << endl;
											}
										}
										a++;
									}
								}
								i++;
							}
							cout << endl;
							cout << endl;
							goto dongu;
						}
						p++;
					}
					i++;
				}
			}
			goto don;
		}
		else if (sec == "2")
		{
			system("cls");
			i = takimlar.begin();
			int a = 0;
			while (true)
			{
				string def;
				while (a < 1)
				{
					cin.ignore();
					a++;
				}
				cout << "Fiksturunu gormek istediginiz takimin adini buyuk harfle giriniz(Cikmak icin 0):";
				getline(cin, def);
				if (def == "0")
				{
					system("cls");
					goto don;
				}
				while (i != takimlar.end()) //tek takima ait fikstur bilgileri
				{
					if (i->getTakimAdi() == def) {
						vector<Fikstur>* takim_maclar = i->getFikstur();
						vector<Fikstur>::iterator c = takim_maclar->begin();
						while (c != takim_maclar->end()) {
							c->displayMessage();
							c++;
						}
					}
					i++;
				}
				i = takimlar.begin();
			}
			goto don;
		}
		else if (sec == "3")
		{
			system("cls");
			int a = 0;
			while (true) {
				cout << "Skorlariyla beraber fiksturunu gormek istediginiz takimin adini buyuk harfle yaziniz(Cikmak icin 0):";
				while (a < 1)
				{
					cin.ignore();
					a++;
				}
				string a;
				getline(cin, a);
				if (a == "0")
				{
					system("cls");
					goto don;
				}
				i = takimlar.begin();
				while (i != takimlar.end()) {
					if (i->getTakimAdi() == a) {
						vector<Fikstur>* takim_maclar = i->getFikstur();
						vector<Fikstur>::iterator c = takim_maclar->begin();
						while (c != takim_maclar->end()) {
							cout << "macID:" << c->getmacID() << endl << "Hafta:" << c->getHafta() << endl << c->getTakim1() << " " << c->getScore1() << " " << "-" <<
								" " << c->getScore2() << " " << c->getTakim2() << endl;
							cout << "\n";
							c++;
						}
					}
					i++;
				}
			}
		}
		else if (sec == "4") {
			vector<Fikstur>::iterator p = fikstur.begin();
			int a = 1;
			while (p != fikstur.end()) {

				cout << "Hafta: " << a << endl;
				while (p->getHafta() == a) {
					cout << p->getmacID() << ")" << p->getTakim1() << " vs " << p->getTakim2() << endl << endl;
					p++;
					if (p == fikstur.end()) break;
				}
				a++;

			}
			goto don;
		}
		else if (sec == "5")
		{
			vector<Fikstur>::iterator p = fikstur.begin();
			int a = 1;
			while (p != fikstur.end()) {

				cout << "Hafta: " << a << endl;
				while (p->getHafta() == a) {
					cout << p->getmacID() << ")" << p->getTakim1() << " " << p->getScore1() << "-" << p->getScore2() << " " << p->getTakim2() << endl << endl;
					p++;
					if (p == fikstur.end()) break;
				}
				a++;

			}
			goto don;
		}
		else if (sec == "6")
		{
			i = takimlar.begin();
			cout << left << setw(23) << "Takim adi" << left << setw(5) << "|Mac sayisi|" << left << setw(5) << "Galibiyet|" << left << setw(5) << "Beraberlik|" << left << setw(5) << "Maglubiyet|" << left << setw(5) << "Atilan Gol|" << left << setw(5) << "Yenilen Gol|" << left << setw(5) << "Averaj|" << left << setw(5) << "Puan |" << endl;
			cout << "--------------------------------------------------------------------------------------------------------\n";
			while (i != takimlar.end())
			{
				vector<Fikstur>* takim_maclar = i->getFikstur();
				vector<Fikstur>::iterator c = takim_maclar->begin();
				int puan = 0;
				int galibiyet_sayisi = 0;
				int maglubiyet_sayisi = 0;
				int beraberlik_sayisi = 0;
				int atilan_gol = 0;
				int yenilen_gol = 0;
				int averaj = 0;
				while (c != takim_maclar->end())
				{
					if (c->getTakim1() == i->getTakimAdi())
					{
						if (c->getScore1() > c->getScore2()) {
							puan += 3;
							galibiyet_sayisi += 1;
							atilan_gol += c->getScore1();
							yenilen_gol += c->getScore2();
						}
						else if (c->getScore1() == c->getScore2()) {
							puan += 1;
							beraberlik_sayisi += 1;
							atilan_gol += c->getScore1();
							yenilen_gol += c->getScore2();
						}
						else if (c->getScore1() < c->getScore2()) {
							maglubiyet_sayisi += 1;
							atilan_gol += c->getScore1();
							yenilen_gol += c->getScore2();
						}
					}
					if (c->getTakim2() == i->getTakimAdi())
					{
						if (c->getScore2() > c->getScore1()) {
							puan += 3;
							galibiyet_sayisi += 1;
							atilan_gol += c->getScore2();
							yenilen_gol += c->getScore1();
						}
						else if (c->getScore2() < c->getScore1())
						{
							maglubiyet_sayisi += 1;
							atilan_gol += c->getScore2();
							yenilen_gol += c->getScore1();
						}
						else if (c->getScore2() == c->getScore1())
						{
							beraberlik_sayisi += 1;
							atilan_gol += c->getScore2();
							yenilen_gol += c->getScore1();
						}
					}
					c++;
				}
				i->setPuan(puan);
				i->setGalibiyetSayisi(galibiyet_sayisi);
				i->setMaglubiyetSayisi(maglubiyet_sayisi);
				i->setBeraberlikSayisi(beraberlik_sayisi);
				i->setAtilanGol(atilan_gol);
				i->setYenilenGol(yenilen_gol);
				averaj = atilan_gol - yenilen_gol;
				i->setAveraj(averaj);
				i++;
			}
			vector<Takim> takim_puan_durumu;
			takim_puan_durumu.insert(takim_puan_durumu.begin(), takimlar.begin(), takimlar.end());
			bubbleSort(takim_puan_durumu);
			vector<Takim>::iterator a = takim_puan_durumu.begin();
			int siralama = 01;
			while (a != takim_puan_durumu.end())
			{
				cout << setfill(' ') << setw(2) << siralama << ")";
				cout << left << setw(20) << a->getTakimAdi() << setw(5) << "|" << setw(6) << a->getFikstur()->size() << setw(5) << "|" << left << setw(5) << a->getGalibiyetSayisi() << setw(5) << "|" << left << setw(6) << a->getBeraberlikSayisi() << setw(6) << "|" << left << setw(5) << a->getMaglubiyetSayisi();
				cout << setw(6) << "|" << left << setw(5) << a->getAtilanGol() << setw(7) << "|" << left << setw(5) << a->getYenilenGol() << setw(2) << "|" << left << setw(5) << a->getAveraj() << setw(3) << "|" << left << setw(3) << a->getPuan() << setw(5) << "|" << endl;
				cout << "---------------------------------------------------------------------------------------------------------\n";
				siralama++;
				a++;
			}
			goto don;

		}
		else if (sec == "0")
		{
			cout << "Program sonlandi.";
			exit(0);
		}
		else {
			system("cls");
			cout << "Gecerli sayi giriniz.";
			goto don;
		}
	}
	else if (secim == "0")
	{
		cout << "Program sonlandi.";
		exit(0);
	}
	else if (secim == "8")
	{
		i = takimlar.begin();
		while (i != takimlar.end())
		{
			Futbolcu* futbolcu[11] = { &(i->f1),&(i->f2),&(i->f3),&(i->f4),&(i->f5),&(i->f6),&(i->f7),&(i->f8),&(i->f9),&(i->f10),&(i->f11) };
			for (int j = 0; j < 11; j++)
			{
				if (futbolcu[j]->getMevki() == "DEFANS")
				{
					futbolcu[j]->setPerformans(50);
				}
			}
			i++;
		}

		goto secim;
	}
	else {
		system("cls");
		cout << "Gecerli bir sayi giriniz!" << endl;
		goto secim;
	}

}
