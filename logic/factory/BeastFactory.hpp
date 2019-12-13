#ifndef _CBeastFactory
#define _CBeastFactory
#include"../../model/beast/Animal.hpp"
#include"../../model/beast/Beast.hpp"
#include"../util/Random.hpp"
#include"./BehaviourFactory.hpp"

class BeastFactory{
  private:
    Random *rnd;
    const int NUM_BEHAVIOURS = 5;
    BehaviourFactory* behaviourFactory;
  public:
    BeastFactory() {
      rnd = new Random();
      behaviourFactory = new BehaviourFactory();
    }
    Beast* newRandomBeast(int id, int type){
      return new Beast(id, {this->rnd->getInt(1, WIDTH_WINDOW),
                            this->rnd->getInt(1, HEIGHT_WINDOW)},
                            {this->rnd->getInt(-1, 1),
                            this->rnd->getInt(-1, 1)},
                            behaviourFactory->getComportement(type)
                      );
    }
    // TODO: put a limit of the maximun number of elements in the population
    vector<Animal*> newRandomPopulation( int n ){
      vector<Animal*> list;
      vector< float > pseudoRandomDistribution = rnd->getVector(  NUM_BEHAVIOURS );
      for( int i = 0, id = 1; i < NUM_BEHAVIOURS; i++){
        int totali = round(pseudoRandomDistribution[ i ] * n);
        printf("\tNumber of beast with behaviour %d = %d \n", i,  totali);
        for( int j = 0; j < totali; j++, id++){
            list.push_back( this->newRandomBeast( id, i ) );
        }
      }
      return list;
    }
};
#endif
