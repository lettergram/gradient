#include <stdio.h>
#include <iostream>
#include <math.h>

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>


/**
 * Description:
 *Finds the gradient between two images, searches the Red channel in RGB
 *  
 * @param: img - image to find gradient on
 * @param: prune - the cut off for the pruning (difference between two steps
 * @param: step - How many pixels apart to check
 * @Return: Mat grad - the image with gradients colored
 **/
Mat findGradient(Mat &img, unsigned int prune, unsigned int step){
  
  Mat grad(img);
  unsigned char prev_horizontal = (*grad.ptr<Point3_<uchar> >(0,0)).x;
  int vsize =  grad.cols;
  unsigned char prev_vertical[vsize];

  for(int i = 0; i < vsize; i ++)
    prev_vertical[i] = (*grad.ptr<Point3_<uchar> >(0,0)).x;
  
  for(int i = step; i < grad.rows - step; i +=step){
    for(int j = step; j < grad.cols - step; j += step){
      /* Horizontal line checking and drawing */
      if(abs((*grad.ptr<Point3_<uchar> >(i, j)).x - prev_horizontal) > prune){
        for(int x = i; x < i + step; x++){
          if( x > grad.rows - 1){ break; }
          for(int y = j - step; y < j - step + 5; y++){
            if(y > grad.cols - 1){ break; }
            (*grad.ptr<Point3_<uchar> >(x, y)).y = 125;
            (*grad.ptr<Point3_<uchar> >(x, y)).z = 254;
          }
        }
      }
      prev_horizontal = (*grad.ptr<Point3_<uchar> >(i, j)).x;

      /* Vetical Line checking and drawing */
      if(abs((*grad.ptr<Point3_<uchar> >(i, j)).x - prev_vertical[j]) > prune){
        for(int y = j; y < j + step; y++){
          if( y > grad.rows - 1){ break; }
          for(int x = i - step; x < i - step + 5; x++){
            if(x > grad.cols - 1){ break; }
            (*grad.ptr<Point3_<uchar> >(x, y)).y = 125;
            (*grad.ptr<Point3_<uchar> >(x, y)).z = 254;
          }
        }
      }
      prev_vertical[j] = (*grad.ptr<Point3_<uchar> >(i, j)).x; // each column
    }
  }
  return grad;
}

int main(argc, const char* argv[]){

  Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  
  char filename[60];
  unsigned int prune = 20;
  unsigned int step = (prune/5);

  sprintf(filename, grad-%s, argv[1]);

  return 0;
}
