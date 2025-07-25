#include <iostream>
#include <vector>
#include <string>
#include <cmath>

auto matriseYazdir(std::string girilenMetin, bool cozumModu) -> std::vector<std::vector<char>>;
auto matrisiTersYazdir(std::vector<std::vector<char>> vektor, bool cozumModu) -> std::string;

int main()
{
    int modSecim;
    int sayac = 0;
    std::string girilenMetin;
    
    std::cout << "Mod Seciniz (1: Sifreleme 2: Sifre Cozme): ";
    std::cin >> modSecim;
    
    std::cout << "Matris yontemiyle sifrelemek / sifresini cozmek istediginiz metni BUYUK HARFLERLE giriniz:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, girilenMetin);

    if (modSecim == 1)
        std::cout << "Sifreli metin: " << std::endl << matrisiTersYazdir(matriseYazdir(girilenMetin, false), false) << std::endl;
    else if (modSecim == 2)
        std::cout << "Sifresi cozulmus metin (Sondaki X'leri goz ardi edebilirsiniz.): " << std::endl << matrisiTersYazdir(matriseYazdir(girilenMetin, true), true) << std::endl;
}

auto matriseYazdir(std::string girilenMetin, bool cozmeModu) -> std::vector<std::vector<char>>
{
    int vektorKenar = ceil(sqrt(girilenMetin.size()));
    
    std::vector<std::vector<char>> vektor(vektorKenar, std::vector<char>(vektorKenar, 'X'));

    int sayac = 0;
    
    if (!cozmeModu)
    {
        for (int i = 0; i < vektorKenar; ++i)
        {
            for (int j = 0; j < vektorKenar; ++j)
            {
                if (girilenMetin.length() > sayac)
                {
                    vektor.at(i).at(j) = girilenMetin.at(sayac);
                    ++sayac;
                }
            }
        }
    }
    else 
    {
        for (int i = 0; i < vektorKenar; ++i)
        {
            for (int j = 0; j < vektorKenar; ++j)
            {
                if (girilenMetin.length() > sayac)
                {
                    vektor.at(j).at(i) = girilenMetin.at(sayac);
                    ++sayac;
                }
            }
        }
    }
    return vektor;
}

auto matrisiTersYazdir(std::vector<std::vector<char>> vektor, bool cozmeModu) -> std::string
{
    int vektorSatirSayisi = vektor.size();
    int vektorSutunSayisi = vektor.at(0).size();

    std::string metin;

    if (!cozmeModu)
    {
        for (int i = 0; i < vektorSutunSayisi; ++i)
        {
            for(int j = 0; j < vektorSatirSayisi; ++j)
            {
                metin.push_back(vektor.at(j).at(i));
            }
        }
    }

    else
    {
        for (int i = 0; i < vektorSutunSayisi; ++i)
        {
            for(int j = 0; j < vektorSatirSayisi; ++j)
            {
                metin.push_back(vektor.at(i).at(j));
            }
        }
    }
    return metin;
}
