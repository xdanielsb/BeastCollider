#ifndef _CDialog
#define _CDialog
class Dialog{
private:
  const int WIDTH = 100;
  const int HEIGHT = 100;
public:
  Dialog(){}
  ~Dialog(){}
  void create(int argc,char **argv ){
    CImg<unsigned char> src(cimg_option("-i","assets/img/beast.ppm","Input image"));
    if (cimg::dialog(cimg::basename("Hi there, xD"),
                  "Authors : \n"
                  "----------------\n\n"
                  "(-) Daniel Santos.\n\n"
                  "(-) Zheng LI .\n\n"
                  "(-) Andy Meri.\n\n"
                  "(-) Gonza Quintana.\n\n"
                  "(-) Xue Wang.\n\n"
                  "(-) Lei Zan .\n\n"
                  "Code: \n"
                  "(-) https://github.com/xdanielsb/BeastCollider.\n\n"
                  "Instructions \n"
                  "1 - Click on the environment to create a random beast\n\n"
                  "2 - Click on a beast to see detail of this beast\n\n"

                  "Look the readme.md for more details","Start !","Quit",0,0,0,0,
                  src.get_resize(this->WIDTH,this->HEIGHT,1,3),true)) std::exit(0);
  }
};
#endif
