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
    int calistigiZaman = 0;
    int gcZamani;
    int gcBitisZamani;
    int durum = hazir;

    surec(int _ID, int _girisZamani, int _calismaZamani)
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
    int kesmeSuresi;

    vector<surec*> surecler;
    vector<surec*> sistemdekiSurecler;
    vector<surec*> siradakiSurecler;
    vector<surec*> blokeSurecler;

    kontrolcu(int _kesmeSuresi)
    {
        kesmeSuresi = _kesmeSuresi;
    }

    void rastgeleSurecOlustur(int adet)
    {
        for (int i = 0; i < adet; ++i)
        {
            surec *yeniSurec = new surec(1 + i, 1 + rand() % 101, kesmeSuresi + rand() % (kesmeSuresi * 10));
            surecler.push_back(yeniSurec);
        }
    }

    void surecleriIsle()
    {
        while (!surecler.empty() || !sistemdekiSurecler.empty() || !blokeSurecler.empty())
        {
            for (auto i = blokeSurecler.begin(); i != blokeSurecler.end();)
            {
                if (zaman >= (*i)->gcBitisZamani)
                {
                    gcBitti(*i);
                    sistemdekiSurecler.push_back(*i);
                    i = blokeSurecler.erase(i);
                }
                else
                {
                    ++i;
                }
            }

            for (auto i = surecler.begin(); i != surecler.end();)
            {
                if ((*i)->girisZamani == zaman)
                {
                    surecGeldi(*i);
                    sistemdekiSurecler.push_back(*i);
                    i = surecler.erase(i);
                }
                else
                {
                    ++i;
                }
            }

            if (((calisanSurecID == -1) && (!sistemdekiSurecler.empty())) || ((sistemdekiSurecler.size() > 1) && (zaman % kesmeSuresi == 0)))
            {
                siradakiSurecler.clear();

                for (auto &i:sistemdekiSurecler)
                {
                    if (i->ID != calisanSurecID)
                        siradakiSurecler.push_back(i);
                }

                if (calisanSurecID != -1)
                {
                    for (auto &i:sistemdekiSurecler)
                    {
                        if (i->ID == calisanSurecID)
                        {
                            surecCalismayiBirakti(i);
                            break;
                        }
                    }
                }

                if (!siradakiSurecler.empty())
                {
                    surec *hedefSurec = siradakiSurecler[rand() % siradakiSurecler.size()];
                    surecCalismayaBasladi(hedefSurec);
                }
                else if (!sistemdekiSurecler.empty())
                {
                    surecCalismayaBasladi(sistemdekiSurecler[0]);
                }
            }

            for (auto i = sistemdekiSurecler.begin(); i != sistemdekiSurecler.end();)
            {
                if ((*i)->ID == calisanSurecID)
                {
                    (*i)->calistigiZaman++;

                    if ((*i)->calistigiZaman == (*i)->gcZamani)
                    {
                        surecGcIstedi(*i);
                        (*i)->gcBitisZamani = zaman + 2 + (rand() % 5);
                        
                        blokeSurecler.push_back(*i);
                        calisanSurecID = -1;
                        i = sistemdekiSurecler.erase(i);
                        continue;
                    }

                    if ((*i)->calistigiZaman >= (*i)->calismaZamani)
                    {
                        surecCalismayiBirakti(*i);
                        surecCikti(*i);
                        calisanSurecID = -1;
                        delete *i;
                        i = sistemdekiSurecler.erase(i);
                        continue;
                    }

                    ++i;
                }
                else
                {
                    ++i;
                }
            }

            zaman++;
        }
    }

    void surecGeldi(surec *hedefSurec)
    {
        cout<<"zaman: "<<zaman<<" s: Surec "<<hedefSurec->ID<<" geldi."<<endl;
    }

    void surecCikti(surec *hedefSurec)
    {
        cout<<"zaman: "<<zaman<<" s: Surec "<<hedefSurec->ID<<" cikti."<<endl;
    }

    void surecCalismayaBasladi(surec *hedefSurec)
    {
        cout<<"zaman: "<<zaman<<" s: Surec "<<hedefSurec->ID<<" calismaya basladi."<<endl;
        calisanSurecID = hedefSurec->ID;
        hedefSurec->durum = calisir;
    }

    void surecCalismayiBirakti(surec *hedefSurec)
    {
        cout<<"zaman: "<<zaman<<" s: Surec "<<hedefSurec->ID<<" calismayi birakti."<<endl;
        hedefSurec->durum = hazir;
    }

    void surecGcIstedi(surec *hedefSurec)
    {
        cout<<"zaman: "<<zaman<<" s: Surec "<<hedefSurec->ID<<" GC istedi."<<endl;
        hedefSurec->durum = bloke;
    }

    void gcBitti(surec *hedefSurec)
    {
        cout<<"zaman: "<<zaman<<" s: Surec "<<hedefSurec->ID<<" GC'yi bitirdi."<<endl;
        hedefSurec->durum = hazir;
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

    kontrolcu kontrolcu(3); //Kesme süresini 3 saniye olarak ayarladık. Sonraki çalışacak süreci rastgele seçiyor

    kontrolcu.rastgeleSurecOlustur(2); //Daha fazla süreç sisteme girebilir ama biz varsayılan olarak 2 yaptık
    kontrolcu.surecleriIsle();

    for (auto *i:kontrolcu.surecler)
    {
        delete i;
    }

    for (auto *i:kontrolcu.sistemdekiSurecler)
    {
        delete i;
    }

    for (auto *i:kontrolcu.siradakiSurecler)
    {
        delete i;
    }

    for (auto *i:kontrolcu.blokeSurecler)
    {
        delete i;
    }

    cout<<endl;
    cout<<"Cikmak Icin Enter'a Basin"<<endl;
    cin.ignore();

    return 0;
}
