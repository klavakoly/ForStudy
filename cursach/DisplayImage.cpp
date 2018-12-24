#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void binar(Mat image);
Mat poleWithPlaceForCount(Mat& image2);
void drewPoleLines(Mat& last, Mat& imagePicture, int masshtab, int lineBright, int darkLineBright);
void Reducing(Mat& image);


int main(int argc, char* argv[])
{
  const int darkLineBright{ 150 };
  const int lineBright{ 200 };
  const int masshtab{ 25 };
  int weight{ 0 };
  int hight{ 0 };
  int weight_{ 0 };
  int hight_{ 0 };
  string path{ "" };
  const int maxValue{ 80 };
  const int minValue{ 10 };
  string name_{ "" };
  Mat image;

  if (argc > 1)
  {
    name_ = argv[1];
    image = imread(name_, IMREAD_GRAYSCALE);
  }
  else
  {
    std::cout << "Get name of picture" << endl;
    std::cin >> name_;
    image = imread(name_, IMREAD_GRAYSCALE);

    while (image.empty())
    {
      std::cout << "Could not open or find the image" << endl;
      std::cout << "Try again. Get name of picture" << endl;
      std::cin >> name_;
      image = imread(name_, IMREAD_GRAYSCALE);
    }
  }

  binar(image);

  Reducing(image);

  weight_ = image.size[1];
  hight_ = image.size[0];
  if (argc < 2)
  {
    std::cout << "Number of lines: " << weight_ << endl;
    std::cout << "Number of columns: " << hight_ << endl;
  }

  if (argc > 2)
  {
    weight = atoi(argv[2]);
  }
  else
  {
    std::cout << "Get weight" << endl;
    std::cin >> weight;
  }

  while ((weight > maxValue) || (weight < minValue))
  {

    std::cout << "Uncorrect value. Try again." << endl;//not number: check
    std::cin >> weight;
  }

  if (argc > 3)
  {
    hight = atoi(argv[3]);
  }
  else
  {
    std::cout << "Get hight" << endl;
    std::cin >> hight;
  }
  while ((hight > maxValue) || (hight < minValue))
  {
    std::cout << "Uncorrect value. Try again." << endl;
    std::cin >> hight;
  }

  String windowName2 = "resize";
  String windowName3 = "first";
  String windowName4 = "last";
  String windowName5 = "Pole";

  cv::resize(image, image, { weight , hight });//масштабирование картинки к размерам weight*hight

  binar(image);//бинаризация картинки(приведение пикселей либо к черному цвету либо к белому, без интенсивности)

  Mat image2;
  cv::resize(image, image2, { weight * masshtab, hight * masshtab }, 0.0, 0.0, INTER_NEAREST);//масштабирование картинки в более читаемые размеры

  binar(image2);

  Mat last = poleWithPlaceForCount(image2);//добавление к изображению слева и сверху поля для чисел

  drewPoleLines(last, image2, masshtab, lineBright, darkLineBright);//вырисовование линий для кроссворда

  int maxPointRows{ 0 };
  int maxPointCols{ 0 };
  for (int i = 0; i < image.rows; i++)
  {
    string countString{ "" };

    int count{ 0 };
    int point{ 0 };
    for (int j = image.cols - 1; j >= 0; j--)
    {

      if (image.at<uchar>(i, j) == 0)
      {
        count++;

      }
      else
      {
        if (count != 0)
        {
          point++;
          countString = to_string(count);
          if (count > 9)
          {
            putText(last,
              countString,
              Point(
                last.cols - image2.cols - point * masshtab + 0.1*masshtab,
                masshtab*0.7 + i * masshtab + (last.rows - image2.rows)),
              masshtab*0.02,
              masshtab*0.02,
              Scalar(0));

          }
          else
          {
            putText(last,
              countString,
              Point(
                last.cols - image2.cols - point * masshtab + masshtab * 0.3,
                masshtab*0.7 + i * masshtab + (last.rows - image2.rows)),
              masshtab*0.02,
              masshtab*0.02,
              Scalar(0));
          }
          count = 0;
        }
      }
    }
    if (count != 0)
    {
      point++;
      countString = to_string(count);
      if (count > 9)
      {
        putText(last,
          countString,
          Point(
            last.cols - image2.cols - point * masshtab + 0.1*masshtab,
            masshtab*0.7 + i * masshtab + (last.rows - image2.rows)),
          masshtab*0.02,
          masshtab*0.02,
          Scalar(0));
      }
      else
      {
        putText(last,
          countString,
          Point(
            last.cols - image2.cols - point * masshtab + masshtab * 0.3,
            masshtab*0.7 + i * masshtab + (last.rows - image2.rows)),
          masshtab*0.02,
          masshtab*0.02,
          Scalar(0));
      }
    }
    if (point > maxPointCols)
      maxPointCols = point;
    point = 0;
    std::cout << endl;
  }

  for (int i = 0; i < image.cols; i++)
  {
    string countString{ "" };

    int count{ 0 };
    int point{ 0 };
    for (int j = image.rows - 1; j >= 0; j--)
    {

      if (image.at<uchar>(j, i) == 0)
      {
        count++;
      }
      else
      {
        if (count != 0)
        {
          countString = to_string(count);
          if (count > 9)
          {
            putText(last,
              countString,
              Point(
                masshtab*0.1 + i * masshtab + (last.cols - image2.cols),
                last.rows - image2.rows - point * masshtab - 0.25*masshtab),
              masshtab*0.02,
              masshtab*0.02,
              Scalar(0));

          }
          else
          {
            putText(last,
              countString,
              Point(
                masshtab*0.25 + i * masshtab + (last.cols - image2.cols),
                last.rows - image2.rows - point * masshtab - 0.25*masshtab),
              masshtab*0.02,
              masshtab*0.02,
              Scalar(0));
          }
          point++;
          count = 0;
        }
      }
    }
    if (count != 0)
    {
      countString = to_string(count);
      if (count > 9)
      {
        putText(last,
          countString,
          Point(
            masshtab*0.1 + i * masshtab + (last.cols - image2.cols),
            last.rows - image2.rows - point * masshtab - 0.25*masshtab),
          masshtab*0.02,
          masshtab*0.02,
          Scalar(0));
      }
      else
      {
        putText(last,
          countString,
          Point(
            masshtab*0.25 + i * masshtab + (last.cols - image2.cols),
            last.rows - image2.rows - point * masshtab - 0.25*masshtab),
          masshtab*0.02,
          masshtab*0.02,
          Scalar(0));
      }
      point++;
    }
    if (point > maxPointRows)
      maxPointRows = point;
    point = 0;
    std::cout << endl;
  }

  Rect r(
    last.cols - image2.cols - maxPointCols * masshtab,
    last.rows - image2.rows - maxPointRows * masshtab,
    last.cols - (last.cols - image2.cols - maxPointCols * masshtab),
    last.rows - (last.rows - image2.rows - maxPointRows * masshtab));
  last = Mat(last, r).clone();
  if (argc < 2)
  {
    cv::namedWindow(windowName4, WINDOW_AUTOSIZE);
    cv::imshow(windowName4, last);
  }
  cv::imwrite("pole_" + name_, last);
  cv::Rect roi(cv::Rect(last.cols - image2.cols, last.rows - image2.rows, image2.cols, image2.rows));
  cv::Mat targetROI = last(roi);
  image2.copyTo(targetROI);
  drewPoleLines(last, image2, masshtab, lineBright, darkLineBright);
  cv::imwrite("result_" + name_, last);
  if (argc < 2)
  {

    cv::namedWindow(windowName5, WINDOW_AUTOSIZE);
    cv::imshow(windowName5, last);
  }
  //cv::namedWindow(windowName2, WINDOW_AUTOSIZE);
  //cv::imshow(windowName2, image2);

  cv::waitKey(0);
  return 0;
}



void binar(Mat image)
{
  for (int i = 0; i < image.rows; i++)
  {
    for (int j = 0; j < image.cols; j++)
    {
      if (image.at<uchar>(i, j) < 60)
        image.at<uchar>(i, j) = 0;
      else
        image.at<uchar>(i, j) = 255;
    }
  }
}



Mat poleWithPlaceForCount(Mat& image2)
{
  int weight = image2.cols;
  int hight = image2.rows;
  int weight_{ 0 };
  int hight_{ 0 };
  if (weight % 2 == 0)
  {
    weight_ = weight * 1.5;
  }
  else
  {
    weight_ = (weight - 1) * 1.5 + 1;
  }
  if (hight % 2 == 0)
  {
    hight_ = hight * 1.5;
  }
  else
  {
    hight_ = (hight - 1) * 1.5 + 1;
  }

  cv::Mat last = cv::Mat(hight_, weight_, IMREAD_GRAYSCALE, cv::Scalar(255));
  return last;
}



void drewPoleLines(Mat& last, Mat& imagePicture, int masshtab, int lineBright, int darkLineBright)
{
  int hight_ = last.rows;
  int weight_ = last.cols;
  for (int y = 0; y < hight_; y = y + masshtab)
  {
    line(last, Point(0, y), Point(weight_, y), cv::Scalar(lineBright));
    line(last, Point(0, y + masshtab - 1), Point(weight_, y + masshtab - 1), cv::Scalar(lineBright));
  }

  for (int x = 0; x < weight_; x = x + masshtab)
  {
    line(last, Point(x, 0), Point(x, hight_), cv::Scalar(lineBright));
    line(last, Point(x + masshtab - 1, 0), Point(x + masshtab - 1, hight_), cv::Scalar(lineBright));
  }

  for (int y = last.rows - imagePicture.rows; y < hight_; y = y + masshtab * 5)
  {
    line(last, Point(0, y), Point(weight_, y), cv::Scalar(darkLineBright));
    line(last, Point(0, y + masshtab * 5 - 1), Point(weight_, y + masshtab * 5 - 1), cv::Scalar(darkLineBright));
  }

  for (int x = last.cols - imagePicture.cols; x < weight_; x = x + masshtab * 5)
  {
    line(last, Point(x, 0), Point(x, hight_), cv::Scalar(darkLineBright));
    line(last, Point(x + masshtab * 5 - 1, 0), Point(x + masshtab * 5 - 1, hight_), cv::Scalar(darkLineBright));
  }

  for (int y = 0; y < hight_ - imagePicture.rows - 1; y++)
  {
    line(last, Point(0, y), Point(weight_ - imagePicture.cols - 1, y), cv::Scalar(lineBright));
  }

  for (int x = 0; x < weight_ - imagePicture.cols - 1; x++)
  {
    line(last, Point(x, 0), Point(x, hight_ - imagePicture.rows - 1), cv::Scalar(lineBright));
  }

  line(last, Point(0, hight_ - imagePicture.rows - 1), Point(weight_, hight_ - imagePicture.rows - 1), cv::Scalar(0));
  line(last, Point(weight_ - imagePicture.cols - 1, 0), Point(weight_ - imagePicture.cols - 1, hight_), cv::Scalar(0));
}



void Reducing(Mat& image)
{
  int weight_ = image.size[1];
  int hight_ = image.size[0];

  int * reduce = new int[4]; //l_x r_x top_y bot_y
  bool * check = new bool[4];
  for (int i = 0; i < 4; i++) { check[i] = true; reduce[i] = 0; }
  reduce[0] = weight_;

  for (int i = 0; i < image.rows; i++)
  {

    for (int j = 0; j < image.cols; j++)
    {
      if (image.at<uchar>(i, j) != 255)
      {
        check[2] = false;
        check[3] = false;
        if (reduce[0] > j) reduce[0] = j;
        if (reduce[1] < j)reduce[1] = j;
      }
    }
    if (check[2]) reduce[2]++;
    if (check[3])
    {
      reduce[3]++;
    }
    else
    {
      reduce[3] = 0;
      check[3] = true;
    }
  }
  reduce[1] = weight_ - reduce[1] - 1;
  reduce[0] += 1;
  if (reduce[0] == weight_ + 1) reduce[0] = 0;

  Rect r(reduce[0], reduce[2], weight_ - reduce[0] - reduce[1], hight_ - reduce[2] - reduce[3]);
  image = Mat(image, r).clone();
}

