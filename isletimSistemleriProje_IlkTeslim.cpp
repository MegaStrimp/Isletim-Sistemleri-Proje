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
        for (int i = 0; i < adet; ++i)
        {
            surec surec(i,1 + rand() % 101);
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
                    cout<<"zaman: "<<zaman<<" s: olay oldu."<<endl;
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
};

int main()
{
    cout<<"Isletim Sistemleri Proje - 1. Teslim"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Anil Berk Bakir"<<endl;
    cout<<"Adviye Yilmazer"<<endl;
    cout<<"Yusuf Maytalman"<<endl;
    cout<<"Yusuf Diyar Kayir"<<endl<<endl;

    srand(time(0));
    
    kontrolcu kontrolcu;

    kontrolcu.rastgeleSurecOlustur(12);
    kontrolcu.surecleriIsle();

    cout<<endl;
    cout<<"Cikmak Icin Enter'a Basin"<<endl;
    cin.ignore();
    
    return 0;
}
