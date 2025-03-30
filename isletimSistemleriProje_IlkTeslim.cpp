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

class surec
{
    public:
    int ID;
    int girisZamani;
    
    surec(int _ID,int _girisZamani)
    {
        ID = _ID;
        girisZamani = _girisZamani;
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
            surec surec(i,1 + rand() % 21);
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
