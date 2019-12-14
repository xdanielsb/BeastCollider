#ifndef _CAnimal
#define _CAnimal
#include"../../logic/util/Random.hpp"
class Animal{
private:
  int id;
  ii pos;
  ii dir;
  int age;
  int maxAge;
  bool hasMultipleBehaviours;
  unsigned char               * color;
  const double      AFF_SIZE = 8.;
  const double      MAX_VITESSE = 10.;
  const double      LIMITE_VUE = 30.;

public:

  Animal(){}
  /**
  * Initer an instance of animal.
  *
  * @param _id int the id of the animal
  * @param _pos pair<float, float> the position of the animal
  * @param _dir pair<float, float> the moving direction of the animal
  */
  Animal(int _id, ii _pos, ii _dir): id(_id), pos(_pos), dir(_dir){
    this->age = 0;
    color = Random::getInstance()->getDarkColor();
  }
  virtual ~Animal(){};
  /// Get the position of animal
  ii getPosition() {
    return this->pos;
  }
  /// Get the X position of animal
  float getPosX() const{
    return this->pos.X;
  }
  /// Get the Y position of animal
  float getPosY() const{
    return this->pos.Y;
  }
  /// Get the X direction of animal
  float getDirX() const{
    return this->dir.X;
  }
  /// Get the Y direction of animal
  float getDirY() const{
    return this->dir.Y;
  }
  /// Set the X position of animal
  void setPosX(float posX){
    this->pos.X = posX;
  }
  /// Set the Y position of animal
  void setPosY(float posY){
    this->pos.Y = posY;
  }
  /// Set the X direction of animal
  void setDirX(float dirX){
    this->dir.X = dirX;
  }
  /// Set the Y direction of animal
  void setDirY(float dirY){
    this->dir.Y = dirY;
  }
  /// Get the actual age of animal
  int getAge() const {
    return this->age;
  }
  /// Animal gets one year older
  void getOlder(){
    this->age++;
  }
  /// Set animal's max age
  void setMaxAge( int m){
    this->maxAge = m;
  }
  /// Get animal's max age
  int getMaxAge( ) const{
    return this->maxAge;
  }
  /// Get the direction of animal
  ii getDirection(){
    return this->dir;
  }
  /// Get the ID of animal
  int getId() {
    return this->id;
  }
  /// Change the direction of the actual animal to the opposite direction
  void invertDirection(){
    this->dir.X *= -1;
    this->dir.Y *= -1;
  }
  /// Calculate the euclidiean distance between two pair
  double getDistance(const ii &a2){
      return hypot( this->pos.X - a2.X , this->pos.Y - a2.Y );
  }
  virtual void move(vector<Animal*> &neighbors) = 0;
  /// Set the behaviour of the animal
  virtual void setBehavior( int type) = 0;

  virtual Animal* clone() = 0;

  /// Set the animal whether it's multiplebehaviour or not
  void sethasMultipleBehaviours( bool flag ){
    this->hasMultipleBehaviours = flag;
  }
  /// Get the info about the animal whether it's multiplebehaviour or not
  bool gethasMultipleBehaviours() const {
    return this->hasMultipleBehaviours;
  }

  /// Draw the animal in the graphique interface
  void draw( CImg<unsigned char> &u ){
   double orientation = this->getDirX() != 0 ? atan(-this->getDirY()/this->getDirX()): .0;
   double xt = this->getPosX() + cos( orientation )*AFF_SIZE/2.1;
   double yt = this->getPosY() - sin( orientation )*AFF_SIZE/2.1;
   u.draw_ellipse( this->getPosX(), this->getPosY(), AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., this->color );
   u.draw_circle(  this->getPosX(), this->getPosY(), 4, this->color );

   u.draw_text( this->getPosX(), this->getPosY() + 5 , "c", this->color );
  }
  /**
  * Print the info of the animal, ID and position actual
  *
  * @param b a pointer of animal
  */
  friend ostream& operator << (ostream &out, Animal *b) {
   out << "Animal #"<< b->getId()
       << " = { "<< b->getPosition().X
       << ", " << b->getPosition().Y
       << "}"<< endl;
   return out;
 }
};
#endif
