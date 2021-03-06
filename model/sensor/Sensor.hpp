#ifndef _CSensor
#define _CSensor

#include<random>
#include<iostream>

using namespace std;

/**
 * Implementation of Sensor
 *
 * For different kinds of sensor, they have somme common caracter likes
 * "distance", "degree" and capacity of "detection".
 *
 *
 */
class Sensor{
private:
	double distance;
	double degree;
	double detection;
public:
  virtual ~Sensor(){};
	Sensor(double dis, double det, double degr){
		this->distance= dis;
		this->detection= det;
		this->degree= degr;
	}
	double getDistance() const{
		return this->distance;
	}
	double getDegree() const{
		return this->degree;
	}
	double getDetection() const{
		return this->detection;
	}
};
#endif
