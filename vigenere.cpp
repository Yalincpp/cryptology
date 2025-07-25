#include <iostream>
#include <string>

using namespace std;

auto kaydirmaSayisiGecerliMi(int kaydirmaSayisi) -> bool;
auto harfiKaydir(char harf, string kaydirmaAnahtari, int i) -> char;
auto harfiTersKaydir(char harf, string kaydirmaAnahtari, int i) -> char;

int main()
{
    string metin, cevrilmisMetin, kaydirmaAnahtari;
    int secim;

    cout << "Mod seciniz (1: Metin sifreleme 2: Sifre cozme): ";
    cin >> secim;

    cin.ignore();
    cout << "Sifrelemek / sifresini cozmek istediginiz metni BÜYÜK HARFLERLE giriniz: " << endl;
    getline(cin, metin);
    
    int sayac = 0;
    sayac++;
    cout << "Kaydirma anahtari giriniz (Tek kelime): " << endl;
    cin >> kaydirmaAnahtari;

    cevrilmisMetin.clear();
    if(secim == 1)
    {
        int i = 1;
        for(char karakter : metin)
        {
            cevrilmisMetin.push_back(harfiKaydir(karakter, kaydirmaAnahtari, i));
            i++;
        }
    } 
    else if (secim == 2)
    {
        int i = 1;
        for(char karakter : metin)
        {
            cevrilmisMetin.push_back(harfiTersKaydir(karakter, kaydirmaAnahtari, i));
            i++;
        }
    }
    cout << endl << "Sifrelenmis / sifresi cozulmus metin:" << endl << cevrilmisMetin << endl;
    system("pause");

    
}

auto harfiKaydir(char harf, string anahtar, int i) -> char
{
    if(harf == ' ')
        return ' ';

    int anahtarIndex = i % anahtar.size();
    int kaydirmaMiktari = anahtar[anahtarIndex - 1] - 'A';

    return 'A' + (harf - 'A' + kaydirmaMiktari) % 26;
}

auto harfiTersKaydir(char harf, string anahtar, int i) -> char
{
    if(harf == ' ')
        return ' ';

    int anahtarIndex = i % anahtar.size();
    int kaydirmaMiktari = anahtar[anahtarIndex - 1] - 'A';

    return 'A' + (harf - 'A' - kaydirmaMiktari + 26) % 26;
}
