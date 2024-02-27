#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::unordered_map<std::string, std::vector<std::string>> kartlar = {
    {"1", {"maca 1", "kupa 1", "karo 1", "sinek 1"}},
    {"2", {"maca 2", "kupa 2", "karo 2", "sinek 2"}},
    {"3", {"maca 3", "kupa 3", "karo 3", "sinek 3"}},
    {"4", {"maca 4", "kupa 4", "karo 4", "sinek 4"}},
    {"5", {"maca 5", "kupa 5", "karo 5", "sinek 5"}},
    {"6", {"maca 6", "kupa 6", "karo 6", "sinek 6"}},
    {"7", {"maca 7", "kupa 7", "karo 7", "sinek 7"}},
    {"8", {"maca 8", "kupa 8", "karo 8", "sinek 8"}},
    {"9", {"maca 9", "kupa 9", "karo 9", "sinek 9"}},
    {"10", {"maca 10", "kupa 10", "karo 10", "sinek 10"}},
    {"as", {"maca as", "kupa as", "karo as", "sinek as"}},
    {"papaz", {"maca papaz", "kupa papaz", "karo papaz", "sinek papaz"}},
    {"kız", {"maca kız", "kupa kız", "karo kız", "sinek kız"}},
    {"joker", {"maca joker", "kupa joker", "karo joker", "sinek joker"}}
};

std::vector<std::string> oyuncuDeste;
std::vector<std::string> yapayZekaDeste;
std::vector<std::string> ortadakikagitlar;
std::vector<std::string> oyuncununKazandigiKartlar;
std::vector<std::string> yzninKazandigiKartlar;
int sonKazanan;
void kartDagit() {
    // Rastgele bir tür seç
    if (kartlar.empty()) {
        std::cout << "Tüm kartlar tükendi!" << std::endl;
        return;
    }

    auto it = kartlar.begin();
    std::advance(it, rand() % kartlar.size());
    std::string anahtar = it->first;

    while (kartlar[anahtar].empty()) {
        // Yeni bir tür seç
        it = kartlar.begin();
        std::advance(it, rand() % kartlar.size());
        anahtar = it->first;
    }

    // Seçilen türden rastgele bir kart seç
    int kartIndex = rand() % kartlar[anahtar].size();
    std::string secilenEleman = kartlar[anahtar][kartIndex];

    // Kartı oyuncunun desteğine ekle
    oyuncuDeste.push_back(secilenEleman);

    // Seçilen kartı kartlar listesinden çıkar
    kartlar[anahtar].erase(kartlar[anahtar].begin() + kartIndex);

}

void kartDagitYZ() {
    // Rastgele bir tür seç
    auto it = kartlar.begin();
    std::advance(it, rand() % kartlar.size());
    std::string anahtar = it->first;

    while (kartlar[anahtar].empty()) {
    // Yeni bir tür seç
    it = kartlar.begin();
    std::advance(it, rand() % kartlar.size());
    anahtar = it->first;
}

    // Seçilen türden rastgele bir kart seç
    int kartIndex = rand() % kartlar[anahtar].size();
    std::string secilenEleman = kartlar[anahtar][kartIndex];

    // Kartı yapay zekanın desteğine ekle
    yapayZekaDeste.push_back(secilenEleman);

    // Seçilen kartı kartlar listesinden çıkar
    kartlar[anahtar].erase(kartlar[anahtar].begin() + kartIndex);
}

void ortayakapalikartlarikoy() {
    // Rastgele bir tür seç
    auto it = kartlar.begin();
    std::advance(it, rand() % kartlar.size());
    std::string anahtar = it->first;

    // Seçilen türden rastgele bir kart seç
    int kartIndex = rand() % kartlar[anahtar].size();
    std::string secilenEleman = kartlar[anahtar][kartIndex];

    // Kartı ortadaki kartlar listesine ekle
    ortadakikagitlar.push_back(secilenEleman);

    // Seçilen kartı kartlar listesinden çıkar
    kartlar[anahtar].erase(kartlar[anahtar].begin() + kartIndex);
}

void acikkartkoy() {
    // Rastgele bir tür seç
    auto it = kartlar.begin();
    std::advance(it, rand() % kartlar.size());
    std::string anahtar = it->first;

    // Seçilen türden rastgele bir kart seç
    int kartIndex = rand() % kartlar[anahtar].size();
    std::string secilenEleman = kartlar[anahtar][kartIndex];

    // Kartı ortadaki kartlar listesine ekle
    ortadakikagitlar.push_back(secilenEleman);

    // Seçilen kartı kartlar listesinden çıkar
    kartlar[anahtar].erase(kartlar[anahtar].begin() + kartIndex);
}


std::string acikKart;
int baslangicdagitmasi = 0;
void oyuncuKartlari() {
  std::cout << "Oyuncu: \n";
  int a = 1;
  for (const std::string& str : oyuncuDeste) {
      std::cout << "("<< a << ") "<< str << std::endl;
      a+=1;
  }
}
void oyun() {

    srand(time(nullptr));
    for(int i=0; i<4; i++){
        kartDagit();
        kartDagitYZ();
    }
    if(baslangicdagitmasi < 1) {
        for(int i=0; i<3; i++){
            ortayakapalikartlarikoy();
        }
        acikkartkoy();

        baslangicdagitmasi+=1;
    }

    // Acik karti belirleme
    if(ortadakikagitlar.size() > 0) {
      acikKart = ortadakikagitlar.back();

      std::cout << "ortadakikagitlar: \n";
      for (const std::string& str : ortadakikagitlar) {
          std::cout << str << std::endl;
      }

      std::cout << "Acik kart \n";
      std::cout << acikKart << std::endl;
  }
    }


void yapayZekaOyna() {
    int elKontrol;
    int acikKartNe;
    int kartNe;
    if(isAs(yapayZekaDeste[t])) kartNe=11;
    if(isKiz(yapayZekaDeste[t])) kartNe=12;
    if(isPapaz(oyuncuDeste[t])) kartNe=13;
    if(isJoker(yapayZekaDeste[t])) kartNe=14;
    if(isBir(yapayZekaDeste[t])) kartNe=1;
    if(isIki(yapayZekaDeste[t])) kartNe=2;
    if(isUc(yapayZekaDeste[t])) kartNe=3;
    if(isDort(yapayZekaDeste[t])) kartNe=4;
    if(isBes(yapayZekaDeste[t])) kartNe=5;
    if(isAlti(yapayZekaDeste[t)) kartNe=6;
    if(isYedi(yapayZekaDeste[t])) kartNe=7;
    if(isSekiz(yapayZekaDeste[t])) kartNe=8;
    if(isDokuz(yapayZekaDeste[t])) kartNe=9;
    if(isOn(yapayZekaDeste[t)) kartNe=10;

    if(isAs(acikKart)) acikKartNe=11;
    if(isKiz(acikKart)) acikKartNe=12;
    if(isPapaz(acikKart)) acikKartNe=13;
    if(isJoker(acikKart[secim-1])) kartNe=14;
    if(isBir(acikKart)) acikKartNe=1;
    if(isIki(acikKart)) acikKartNe=2;
    if(isUc(acikKart)) acikKartNe=3;
    if(isDort(acikKart)) acikKartNe=4;
    if(isBes(acikKart)) acikKartNe=5;
    if(isAlti(acikKart)) acikKartNe=6;
    if(isYedi(acikKart)) acikKartNe=7;
    if(isSekiz(acikKart)) acikKartNe=8;
    if(isDokuz(acikKart)) acikKartNe=9;
    if(isOn(acikKart)) acikKartNe=10;

    for(int t = 0; t < 4; t++) {
        if(kartNe == acikKartNe || isJoker(yapayZekaDeste[t])) {
            yzninKazandigiKartlar.insert(yzninKazandigiKartlar.end(), ortadakikagitlar.begin(), ortadakikagitlar.end());
            ortadakikagitlar.clear();

            std::string toRemove = yapayZekaDeste[t];
            yapayZekaDeste.erase(std::remove(yapayZekaDeste.begin(), yapayZekaDeste.end(), toRemove), yapayZekaDeste.end());

            elKontrol++;
            t=5;
            sonKazanan=0;
        }
        if(t == 3) {
          int indeks = rand() % yapayZekaDeste.size();
          std::string secilenEleman = yapayZekaDeste[indeks];
          yapayZekaDeste.erase(yapayZekaDeste.begin() + indeks);
          ortadakikagitlar.push_back(secilenEleman);
          std::cout << "Rakibin bu karti atti: " << secilenEleman << std::endl;
        }

    }
}
bool isJoker(const std::string& kart) {
    return kart.find("joker") != std::string::npos;
}
bool isAs(const std::string& kart) {
  return kart.find("as") != std::string::npos;
}
bool isBir(const std::string& kart) {
  return kart.find("1") != std::string::npos;
}
bool isIki(const std::string& kart) {
  return kart.find("2") != std::string::npos;
}
bool isUc(const std::string& kart) {
  return kart.find("3") != std::string::npos;
}
bool isDort(const std::string& kart) {
  return kart.find("4") != std::string::npos;
}
bool isBes(const std::string& kart) {
  return kart.find("5") != std::string::npos;
}
bool isAlti(const std::string& kart) {
  return kart.find("6") != std::string::npos;
}
bool isYedi(const std::string& kart) {
  return kart.find("7") != std::string::npos;
}
bool isSekiz(const std::string& kart) {
  return kart.find("8") != std::string::npos;
}
bool isDokuz(const std::string& kart) {
  return kart.find("9") != std::string::npos;
}
bool isOn(const std::string& kart) {
  return kart.find("10") != std::string::npos;
}
bool isPapaz(const std::string& kart) {
  return kart.find("papaz") != std::string::npos;
}
bool isKiz(const std::string& kart) {
  return kart.find("kız") != std::string::npos;
}

int main() {
  int ij = 0;
  int cardC=0;
  while(ij < 1) {

    oyun();

    int w = 0;
    int secim;
    while(w < 4) {
      std::cout << "Oyuncu: \n";
      int a = 1;
      for (const std::string& str : oyuncuDeste) {
          std::cout << "("<< a << ") "<< str << std::endl;
          a+=1;
      }
        std::cout<<"Hangi numaralı karti oynayacaksiniz? (1/2/3/4)\n\n>>> ";
        std::cin >> secim;
        if(secim != 1 && secim != 2 && secim != 3 && secim != 4) {
            int errOne = 0;
            while(errOne < 1) {
                std::cout<<"Hatali secim. Tekrar dene!";
                std::cin >> secim;
                if(secim == 1 || secim == 2 || secim == 3 || secim == 4) errOne+=1;
            }
        }
        int kartNe;
        int acikKartNe;

            if(isAs(oyuncuDeste[secim-1])) kartNe=11;
            if(isKiz(oyuncuDeste[secim-1])) kartNe=12;
            if(isPapaz(oyuncuDeste[secim-1])) kartNe=13;
            if(isJoker(oyuncuDeste[secim-1])) kartNe=14;
            if(isBir(oyuncuDeste[secim-1])) kartNe=1;
            if(isIki(oyuncuDeste[secim-1])) kartNe=2;
            if(isUc(oyuncuDeste[secim-1])) kartNe=3;
            if(isDort(oyuncuDeste[secim-1])) kartNe=4;
            if(isBes(oyuncuDeste[secim-1])) kartNe=5;
            if(isAlti(oyuncuDeste[secim-1])) kartNe=6;
            if(isYedi(oyuncuDeste[secim-1])) kartNe=7;
            if(isSekiz(oyuncuDeste[secim-1])) kartNe=8;
            if(isDokuz(oyuncuDeste[secim-1])) kartNe=9;
            if(isOn(oyuncuDeste[secim-1])) kartNe=10;

            if(isAs(acikKart)) acikKartNe=11;
            if(isKiz(acikKart)) acikKartNe=12;
            if(isPapaz(acikKart)) acikKartNe=13;
            if(isJoker(acikKart[secim-1])) kartNe=14;
            if(isBir(acikKart)) acikKartNe=1;
            if(isIki(acikKart)) acikKartNe=2;
            if(isUc(acikKart)) acikKartNe=3;
            if(isDort(acikKart)) acikKartNe=4;
            if(isBes(acikKart)) acikKartNe=5;
            if(isAlti(acikKart)) acikKartNe=6;
            if(isYedi(acikKart)) acikKartNe=7;
            if(isSekiz(acikKart)) acikKartNe=8;
            if(isDokuz(acikKart)) acikKartNe=9;
            if(isOn(acikKart)) acikKartNe=10;

        if(kartNe == acikKartNe || isJoker(oyuncuDeste[secim-1])) {
            oyuncununKazandigiKartlar.insert(oyuncununKazandigiKartlar.end(), ortadakikagitlar.begin(), ortadakikagitlar.end());
            ortadakikagitlar.clear();
            std::cout<<"kartlari aldin!";
            sonKazanan=1;
        }
        std::string toRemove = oyuncuDeste[secim-1];
        oyuncuDeste.erase(std::remove(oyuncuDeste.begin(), oyuncuDeste.end(), toRemove), oyuncuDeste.end());
        yapayZekaOyna();
        w++;
    }
    cardC+=4;
    int oyuncuPuan=0;

    if(cardC>20) {
      std::cout<<"OYUN BITTI.";
      if(ortadakikagitlar.size() > 0) {
        if(sonKazanan>0) {
          oyuncununKazandigiKartlar.insert(oyuncununKazandigiKartlar.end(), ortadakikagitlar.begin(), ortadakikagitlar.end());
          ortadakikagitlar.clear();
        }
        else {
          yzninKazandigiKartlar.insert(yzninKazandigiKartlar.end(), ortadakikagitlar.begin(), ortadakikagitlar.end());
          ortadakikagitlar.clear();
        }
      }
      for (const std::string& str : oyuncununKazandigiKartlar) {
        if(isAs(str)) oyuncuPuan++;
        if(isJoker(str)) oyuncuPuan++;
        if(str=="karo 10") oyuncuPuan+=3;
        if(str=="sinek 2") oyuncuPuan+=2;
          std::cout << str << std::endl;
      }
      std::cout<<oyuncuPuan<<std::endl;

      exit(0);
    }

}

    return 0;
}
