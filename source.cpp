#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

void setAdata();
void sentense();
void Data();

std::string Adata;
std::vector<std::string> data;
std::vector<std::string> Avector;
std::vector<std::string> Bvector;
std::vector<std::string> Sword;
std::vector<std::string> s_count;
std::vector<int> count;
std::string word;
std::string output;
std::string Aword;

int main()
{   
    setAdata();
    sentense();
    Data();
    std::string source;
    std::cout << "입력: ";
    std::cin >> source;
    Aword = source;
    int j = 0;
    while (1) { ///////////////////       조건만 하면 완성??   
        Sword.clear();
        s_count.clear();
        count.clear();
        if (j > 1)
            source = output;
        if (j == 0) {
            std::cout <<"\n출력: "<< Aword << " "; //source다음 어절이 output 전 output과 후 output이 같으면 됨
            j++;
            continue;
        }
        for (int i = 0;i < Avector.size();i++) { //Sword에 source다음 어절 넣음
            if (source == Avector[i]) {
                Sword.push_back(Bvector[i]);
            }
        }
        for (int i = 0;i < Sword.size();i++) { //Sword(source다음어절)에 각 어절이 몇개 있는지 저장
            s_count.push_back(Sword[i]);
            count.push_back(std::count(Sword.begin(), Sword.end(), Sword[i]));
        }
        auto max = std::max_element(count.begin(), count.end());
        for (int i = 0;i < count.size();i++) { //max비교로 가장 많이 나온 어절 찾아 output에 저장 
            if (count[i] == *max) {
                output = s_count[i];
            }
        }
        if (source == output) {
            std::cout << "\n\n입력: ";
                std::cin >> source;
            j=0;
            Aword = source;
            continue;
        }
            std::cout << output << " ";
            j++;
    }
}
void Data() {
    int b = 0, num = 0;
    std::string tmp;
    for (int i = 0;i < data.size();i++) {
        b = 0;
        num = 0;
        std::istringstream iss(data[i]);
        std::istringstream a(data[i]);
        while (a >> tmp) {
            num++;
        }
        iss >> word;
        while (1) {
            Avector.push_back(word);
            iss >> word;
            Bvector.push_back(word);
            b++;
            if (num == b + 1)
                break;
        }
    }
}
void sentense() {
   int i = 0;
   std::string tmp;
   for (;;) {
       if (Adata[i] != '/') {
           tmp += Adata[i];
       } else {
           data.push_back(tmp);
           tmp.clear();
       }
       i++;
       if (Adata[i] == '\0') {
           break;
       }
   }
}
void setAdata() {
    Adata = "i ate pizza/i love dog/i love cat/i eat slad/she is running/running shoese/";
}
