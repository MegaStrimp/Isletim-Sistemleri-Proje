/*
İşletim Sistemleri Proje
------------------------
Anıl Berk Bakır
Adviye Yılmazer
Yusuf Maytalman
Yusuf Diyar Kayır
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum surecDurumlari
{
    hazir,
    calisir,
    bloke
};

class surec
{
    public:
    int ID;
    int girisZamani;
    int kalanZaman;
    int durum = hazir;
    
    surec(int _ID,int _girisZamani,int _kalanZaman)
    {
        ID = _ID;
        girisZamani = _girisZamani;
        kalanZaman = _kalanZaman;
    }
};

class kontrolcu
{
    public:
    int zaman = 0;
    vector<surec> surecler;

    void rastgeleSurecOlustur(int adet)
    {
        for (int i = 0; i < adet; ++i) {
            surec surec(i,rand() % 21,1 + rand() % 10);
            surecler.push_back(surec);
        }
    }

    void surecleriIsle()
    {
        while (!surecler.empty())
        {
            for (auto& secilenSurec:surecler)
            {
                if (secilenSurec.girisZamani == zaman)
                {
                    cout <<"zaman: "<<zaman<<" s: olay oldu."<<endl;
                }
            }
            
            zaman++;
        }
    }
};

int main()
{
    srand(time(0));
    
    kontrolcu kontrolcu;

    kontrolcu.rastgeleSurecOlustur(12);
    kontrolcu.surecleriIsle();

    cout<<"Cikmak Icin Enter'a Basin"<<endl;
    cin.ignore();

    return 0;
}
