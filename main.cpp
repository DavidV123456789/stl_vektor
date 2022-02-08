#include <iostream>
#include <vector>//ak chceme pracovat s vektorom
#include <iterator>//pre pouzitie iteratorov
#include <algorithm>//pre pouzitie algoritmov

using std::cout;
using std::endl;
using std::vector;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::vector<int> intCisla {10,9,8,7,6,5};//prazdny vektor //{10,9,8,7,6,5} ked pridame toto tak bude iniciolizovany hodnotami
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
    std::copy(intCisla.begin(),intCisla.end(),std::ostream_iterator<int>(cout," "));

    return 0;
}
