#ifndef POSICION_H
#define POSICION_H

//inicio clase posicion
class Posicion
{
   private:
      int x,y;//variables privadas enteras
   public:
      Posicion(int = 0,int = 0) ;//contstructor de la clase posicion
      int getX();//devuelve el valor de variable privada X
      int getY();//devuelve el valor de variable privada Y
};//fin clase posicion

#endif
