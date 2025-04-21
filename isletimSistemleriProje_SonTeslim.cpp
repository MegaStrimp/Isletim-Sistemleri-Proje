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
    int calismaZamani;
    int gcZamani;
    int durum = hazir;
    
    surec(int _ID,int _girisZamani,int _calismaZamani)
    {
        ID = _ID;
        girisZamani = _girisZamani;
        calismaZamani = _calismaZamani;
        gcZamani = 1 + rand() % calismaZamani;
    }
};

class kontrolcu
{
    public:
    int zaman = 0;
    int calisanSurecID = -1;
    vector<surec> surecler;

    void rastgeleSurecOlustur(int adet)
    {
        for (int i = 0; i < adet; ++i)
        {
            surec surec(i,1 + rand() % 101,1 + rand() % 15);
            surecler.push_back(surec);
        }
    }

    void surecleriIsle()
    {
        while (!surecler.empty())
        {
            for (auto i = surecler.begin(); i != surecler.end();)
            {
                if (i->girisZamani == zaman)
                {
                    cout<<"zaman: "<<zaman<<" s: Surec "<<i->ID<<" calismaya basladi"<<endl;
                    i = surecler.erase(i);
                }
                else
                {
                    ++i;
                }
            }
            
            zaman++;
        }
    }

    void surecGeldi(int ID)
    {
        
    }

    void surecCikti(int ID)
    {
        
    }

    void surecCalismayaBasladi(int ID)
    {
        
    }

    void surecCalismayiBirakti(int ID)
    {
        
    }

    void surecGcIstedi(int ID)
    {
        
    }

    void gcBitti(int ID)
    {
        
    }
};

int main()
{
    cout<<"Isletim Sistemleri Proje - Son Teslim"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Anil Berk Bakir"<<endl;
    cout<<"Adviye Yilmazer"<<endl;
    cout<<"Yusuf Maytalman"<<endl;
    cout<<"Yusuf Diyar Kayir"<<endl<<endl;

    /*
    VSCode ile çalıştırmak için;
    * C/C++ extension indirin
    * Bu dosyayı terminalde açın
    * Terminale "g++ -std=c++11 -o main isletimSistemleriProje_SonTeslim.cpp" komutunu girin
    * Oluşan main.exe dosyasını açın
    */

    srand(time(0));
    
    kontrolcu kontrolcu;

    kontrolcu.rastgeleSurecOlustur(12);
    kontrolcu.surecleriIsle();

    cout<<endl;
    cout<<"Cikmak Icin Enter'a Basin"<<endl;
    cin.ignore();
    
    return 0;
}