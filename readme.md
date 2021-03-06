# Beast Collider

This is a simulation of a game in c++, in which each beast can have Possible  Behaviours,
accessories and sensors.

#### Views

<img src="assets/img/view1.png"/>
<img src="assets/img/view2.png"/>

### Run - Test - Debug

#### How to run?
```sh
  $ make linux  #run this if your computer has gnu-linux
  $ make macosx #run this if your computer has macosx
```
#### How to run the tests?
```sh
  $ make test-code
```

### How to simulate in Command Line Interface (CLI)
```sh
  $ make linux CLI=1 #run this if your computer has gnu-linux
  $ make macosx CLI=1 #run this if your computer has macosx
```
### Dependencies

* g++
* c++17
* lm
* -lX11
* -lpthread

### Model

<img src="diagrams/static/model.png"/>

#### Types
```c++
enum BEHAVIOURS{
  FARSIGTHED         = 0,
  GREGARIU           = 1,
  KAMIKAZE           = 2,
  LAZY               = 3,
  MULTIPLEBEHAVIOUR  = 4
};
enum ACCESSORY{
  CAMOUFLAGE  = 0,
  FIN         = 1,
  SHELL       = 2,
};
enum SENSOR{
  EAR = 0,
  EYE = 1,
};
```
