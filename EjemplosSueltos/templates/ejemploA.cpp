#include <iostream>
using namespace std;

template <class TYPE>
class Item{
  private:
    TYPE Data;
  public:
    //Item():Data( TYPE() ){}
    Item(){
      Data=0;
    }
    void SetData(TYPE nValue){Data=nValue;}
    TYPE GetData(){return Data;}
    void PrintData(){cout << Data << endl;}
};

//Función que dobla el valor del valor que le pasemos.
template <class TYPE>
void dobla(TYPE valor){
  cout << valor*2 << endl;
}

template <class TYPE>
TYPE triplica(TYPE valor){
  return valor*3;
}

int main(){

  //El compilador no necesita conocer el tipo. Este se le dará en tiempo de ejecución.
  dobla(6.332 );
  cout << triplica(2) << endl;

  Item <int> uno;
  //uno.SetData(45);
  uno.PrintData();

}
