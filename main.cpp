#include <iostream>
#include <vector>//ak chceme pracovat s vektorom
#include <iterator>//pre pouzitie iteratorov
#include <algorithm>//pre pouzitie algoritmov
#include "stlVector.h"
#include <fstream>
#include <string.h>
using std::cout;
using std::endl;
using std::vector;

template<typename  T>
void  print(const T &kontajner, const char *sprava)
{

    cout<<sprava<<": ";
    typename  T::const_iterator pos;
    for(pos=kontajner.begin();pos!=kontajner.end();pos++)
    {
        cout<<*pos<<" ";
    }
    cout<<endl;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> intCisla {10,9,8,7,6,5,0};//prazdny vektor //{10,9,8,7,6,5} ked pridame toto tak bude iniciolizovany hodnotami
    intCisla.push_back(1);//prida novy prvok na koniec
    intCisla.push_back(2);
    intCisla.push_back(3);
    intCisla.push_back(4);
    intCisla.push_back(5);

    std::cout<<intCisla.size()<<endl;//vraati pocet prvkov vektora
    cout<<intCisla.max_size()<<std::endl;//maximalny pocet prvkov
    cout<<intCisla.capacity()<<endl;//maximalny pocet prvkov bez novej alokacie

    //vypis prvkov vektora pomocou iteratora: //
     /*
    vector<int>::const_iterator pos; //vytvorim konstantny iterator
    for(pos=intCisla.begin();pos!=intCisla.end();pos++)//begin() je iterator ukazujuci na zaciatok, end() je iterator ukazujuci ta koniec
    {
        cout<<*pos<<" ";
    }
    Druha moznost len v c++
    //skratena verzia bez(vector<int>::const_iterator pos;), automaticke odvodenie typu
    for(auto iter=intCisla.begin();iter!=intCisla.end();iter++)//begin() je iterator ukazujuci na zaciatok, end() je iterator ukazujuci ta koniec
    {
        cout<<*iter<<" ";//iterator je pinterm preto musi byt definovany hviezdickou
    }
    */

    //vypis prvkov vektora pomocou for: //
    /*
    for(auto i:intCisla)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    */

    //vypis prvkov vektora pomocou  algoritmu: //
    //auto kam=std::ostream_iterator<int>(cout," ");//mozeme nahradit: std::copy(intCisla.begin(),intCisla.end(),kam);//rovnako aj z ostatnymi dvomi
    auto kam=std::ostream_iterator<int>(cout," ");
    //
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    //tredenie:
    std::sort(intCisla.begin(), intCisla.end());//algoritmus na tredenie
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    //funkcie, ktoré sú pomalé preto je lepšie sa im vyhýbať:
    intCisla.erase(intCisla.begin()+2,intCisla.begin()+4);//mazanie
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    intCisla.insert(intCisla.begin()+1,50);//pridanie prvku
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    std::sort(intCisla.begin(), intCisla.end(),Tried());//tým tried určujeme ako má triediť, (tried) máš v záhlavnom
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    //landa funkcia: [](odovzdane parametre)->auto{return prikazy;}
    // auto nie je povinne tam pisat
    // return tiez nie ak nepozadujeme navratovu hodnotu
    // odovzdane prametre mozu byt auto
    //[] su tu premenne, ktore lambda funkcia z okoliteho bloku
    //ak su uvedene = preberaju sa hodnotou a nedaju sa v labda zmenit
    //ak su uvedene & preberaju sa odkazom a su menitele
    std::sort(intCisla.begin(), intCisla.end(),[](auto i, auto j){return  i<j;});//algoritmus na tredenie
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    std::sort(intCisla.begin(),intCisla.end(),[](auto i, auto j)->auto {return i>j;});
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    cout<<std::count(intCisla.begin(),intCisla.end(),5);//kolkokrat sa tam nachadza urcita hodnota
    cout<<endl;
    cout<<std::count_if(intCisla.begin(),intCisla.end(),[](auto i){return i>=10;});
    cout<<endl;
    cout<<std::count_if(intCisla.begin(),intCisla.end(),[](auto i){return i%2==0 && i!=0;});
    cout<<endl;
    int delitel=3;
    cout<<std::count_if(intCisla.begin(),intCisla.end(),[delitel](auto i){return i%delitel==0 && i!=0;});//premenne musi zachytavat do []
    cout<<endl;
/*
    auto koniec=std::remove(intCisla.begin(),intCisla.end(),5);//musi sa zmenit koniec ak odstranujem priamo hodnoty
    std::copy(intCisla.begin(),koniec,std::ostream_iterator<int>(cout," "));
    cout<<endl;

    koniec=std::remove_if(intCisla.begin(),koniec,[](auto i){return i*i>5;});
    std::copy(intCisla.begin(),koniec,std::ostream_iterator<int>(cout," "));
    cout<<endl;

    intCisla.erase(koniec,intCisla.end());//uplnne vymaze premenne od konca do praveho konca
*/

    std::copy_if(intCisla.begin(),intCisla.end(),kam,[](auto i)->bool{return i%2;});
    cout<<endl;
    std::remove_copy_if(intCisla.begin(),intCisla.end(),kam,[](auto i)->bool{return i%2;});
    cout<<endl;
    std::replace_copy_if(intCisla.begin(),intCisla.end(),kam,[](auto i)->bool{return i%2;},10);
    cout<<endl;
    std::replace(intCisla.begin(),intCisla.end(),8,88);
    cout<<endl;
    auto isPrvocislo=[](int cislo){int i=2;if(cislo==2){return 1;};for(i;i<=cislo/2;i++){if(cislo%i==0){return 0;}};return 1;};
    std::copy_if(intCisla.begin(),intCisla.end(),kam,isPrvocislo);

    std::for_each(intCisla.begin(),intCisla.end(),[](auto &i){i+=5;});
    print(intCisla,"Vypis:");

    std::vector<int>novy;
    std::copy_if(intCisla.begin(),intCisla.end(),std::back_inserter(novy),[](auto i){return i>=15;});
    print(novy,"Vypis:");

    std::ofstream fout("zapis.txt");
    std::copy_if(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(fout," "),[](auto i)->bool{return i%2;});
    std::ifstream fin("citaj.txt");
    std::copy(std::istream_iterator<int>(fin),std::istream_iterator<int>(),std::ostream_iterator<int>(cout," "));//KAM TO POSLAŤ -> RESULT

    cout<<endl;
    std::string meno="David";
    std::string priezvisko="Vdoviak";
    cout<<meno+" "+priezvisko+" - "+meno[0]+priezvisko[0]<<endl;
    std::vector<std::string>slova;
    fin.close();
    fin.open("veta.txt");
    cout<<endl;
    std::copy(std::istream_iterator<std::string>(fin),std::istream_iterator<std::string>(),std::ostream_iterator<std::string>(cout,"\n"));
    cout<<endl;

    fin.close();
    fin.open("veta.txt");
    std::copy(std::istream_iterator<std::string>(fin),std::istream_iterator<std::string>(),std::back_inserter(slova));
    print(slova,"Slova");

    auto cmp=[](auto i, auto j){
            i[0]=std::tolower(i[0]);
            j[0]=std::tolower(j[0]);
            return i<j;
    };
    sort(slova.begin(),slova.end(),cmp);
    print(slova,"Triedenie");
    sort(slova.begin(),slova.end(),[](auto i, auto j){return i.length()<j.length();});
    print(slova,"Triedenie");

    return 0;
}

