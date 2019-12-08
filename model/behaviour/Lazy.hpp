
#ifndef _CLazy
#define _CLazy
#include"./Behaviour.hpp"
class Lazy:public Behaviour{
  pair<pair< int, int >, pair< int, int >> move(int index, pair< int, int > posActual, pair< int, int > dirActual, vector< Beast*> listBeast){
    int count =0;

    for(auto ptr=listBeast.begin(); ptr!=listBeast.end(); ptr++){

      pair<int, int> posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>

      //To verify the beast is next to this beast or not and the range of detection is 30, variable count will count the number of beast in the range of detection
      if(sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second))< 30) {
        count +=1;
		}
    }
    //Set the alert number equals to 3(3+1(himself)), if the number of beast around is bigger than this value, the beast will change the direction to the opposite one.
    if(count<4){

    }else{
      dirActual.first = -dirActual.first;
      dirActual.second = -dirActual.second;
    }
    // change the position
    posActual.first+=dirActual.first;
    posActual.second+=dirActual.second;
    return pair<pair< int, int >, pair< int, int >>(posActual, dirActual);


	}
};
#endif