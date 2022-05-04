#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

void Citeste_Fisier(string& sir) {
    FILE* fisier = fopen("D:\\facultate\\POO\\oop-2022\\Laboratorul-8\\fisier.txt", "r");
    if (fisier == nullptr) {
        printf("Eroare deschidere fisier. \n");
        exit(1);
    }
    char subsir[4096];
    while (!feof(fisier)) {
        auto text = fread(subsir, 1, sizeof(subsir), fisier);
        sir.append(subsir, text);
    }
    fclose(fisier);
    for (int i=0;i<sir.size();i++) {
        sir[i] = tolower(sir[i]);
    }
}

void Impartire_Cuvinte(string sir,map<string,int>& lista) {
    int pos = 0;
    int start_word = 0;
    auto pozitie = sir.find_first_of(" ,?!.", pos);
    while (pozitie!=string::npos) {
        auto ceva = sir.substr(start_word, pozitie - start_word);
        lista[ceva]++;
        pos = pozitie+1;
        start_word = sir.find_first_not_of(" ,?!.",pos);
        pos = start_word;
        pozitie = sir.find_first_of(" ,?!.", pos);
    }
    if (sir.find_first_not_of(" ,?!.", pos) != string::npos) {
        auto ceva = sir.substr(sir.find_first_not_of(" ,?!.", pos), sir.size() - sir.find_first_not_of(" ,?!.", pos));
        lista[ceva]++;
    }
}

bool Comparare(pair<string,int>& stanga,pair<string,int>& dreapta) {
    if (stanga.second != dreapta.second)
        return stanga.second < dreapta.second;
    else {
        return stanga.first.compare(dreapta.first) > 0;
    }
}

int main() {
    string sir;
    Citeste_Fisier(sir);

    map<string, int> lista;
    Impartire_Cuvinte(sir, lista);
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&Comparare)> q(Comparare);
    
    map<string,int>::iterator it=lista.begin();
    while (it != lista.end())
    {
        pair<string,int> pereche;
        pereche.first = it->first;
        pereche.second = it->second;
        q.push(pereche);
        it++;
    }

    while (!q.empty()) {
        cout << q.top().first << " => " << q.top().second<<"\n";
        q.pop();
    }

	return 0;
}