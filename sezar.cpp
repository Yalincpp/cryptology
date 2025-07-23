#include <iostream>
#include <string>

using namespace std;

auto kaydirmaSayisiGecerliMi(int kaydirmaSayisi) -> bool;
auto harfiKaydir(char harf, int kaydirmaSayisi) -> char;
auto harfiTersKaydir(char harf, int kaydirmaSayisi) -> char;

int main()
{
    string metin, cevrilmisMetin;
    int kaydirmaSayisi, secim;

    cout << "Mod seciniz (1: Metin sifreleme 2: Sifre cozme): ";
    cin >> secim;

    cin.ignore();
    cout << "Sifrelemek / sifresini cozmek istediginiz metni BÜYÜK HARFLERLE giriniz: " << endl;
    getline(cin, metin);
    
    int sayac = 0;
    do {
    sayac++;
    cout << "Kaydirma sayisi giriniz: " << endl;
    cin >> kaydirmaSayisi;
    if(sayac >= 1)
    {
        cout << "Girdiginiz kaydirma sayisi gecersizdir. Lutfen farkli bir sayiyla tekrar deneyiniz." << endl;
        continue;
    }
    } while(!kaydirmaSayisiGecerliMi(kaydirmaSayisi));

    cevrilmisMetin.clear();
    if(secim == 1)
    {
        for(char karakter : metin)
        {
            cevrilmisMetin.push_back(harfiKaydir(karakter, kaydirmaSayisi));
        }
    } 
    else if (secim == 2)
    {
        for(char karakter : metin)
        {
            cevrilmisMetin.push_back(harfiTersKaydir(karakter, kaydirmaSayisi));
        }
    }
    cout << endl << "Sifrelenmis / sifresi cozulmus metin:" << endl << cevrilmisMetin << endl;

    
}

auto kaydirmaSayisiGecerliMi(int kaydirmaSayisi) -> bool
{
    if(kaydirmaSayisi < 1 || kaydirmaSayisi > 26)
    {
        return false;
    }
    return true;
}

auto harfiKaydir(char harf, int kaydirmaSayisi) -> char
{ 
    int harfAscii = harf;
    if((harfAscii + kaydirmaSayisi) > 'Z')
    {
        kaydirmaSayisi = kaydirmaSayisi - (('Z' - 'A') + 1);
    }

    if(harf == ' ')
    {
        return ' ';
    }

    harfAscii = harfAscii + kaydirmaSayisi;
    return harfAscii;
}

auto harfiTersKaydir(char harf, int kaydirmaSayisi) -> char
{
    int harfAscii = harf;
    if((harfAscii - kaydirmaSayisi) < 'A')
    {
        kaydirmaSayisi = kaydirmaSayisi + (('A' - 'Z') - 1);
    }

    if(harf == ' ')
    {
        return ' ';
    }

    harfAscii = harfAscii - kaydirmaSayisi;
    return harfAscii;
}
