//
// Created by sunguoyan on 16/4/5.
//

#include "Lapulasi.h"
using namespace cv;

/**
 * ���ܣ�ʹ��ģ��ԻҶ�ͼ��������д���
 * ������srcΪĿ��ͼ��tmpltΪģ�壬twΪ�����С��x,yΪҪȡ�����ص�����
 */
int Lapulasi::TempltExcute(Mat &src,int *tmplt,int tw,int x,int y){
    int i,j,py,px;
    int sum = 0;
    for(i=0;i<tw;i++){
        for(j=0;j<tw;j++){
            py = y-tw/2+i;
            px = x-tw/2+j;
            sum+=src.at<ty>(py,px)*tmplt[i*tw+j];
        }
    }
    return sum;
}

/*
 * ���ܣ��Ҷ�ͼ���������˹�񻯴���
 * ������srcΪԭʼͼ��dstΪ�񻯽��
 */
void Lapulasi::SharpLapulasi(Mat &src,Mat&dst){
    int tmplt[9] = {-1,-1,-1,-1,8,-1,-1,-1,-1};
    int h,w;
    int scale;
    int tmp;
    scale = 3;
    for(h = 1;h < Y_image-1;h++){
        for(w = 1;w < X_image - 1;w++){
            tmp = TempltExcute(src,tmplt,3,w,h);
            tmp = tmp/scale;
            tmp = tmp +src.at<ty>(h,w);
            tmp = tmp > 255?255:tmp;
            tmp = tmp < 0?0:tmp;
            dst.at<ty>(h,w)=tmp;
        }
    }
}

int main(){
    Mat src,dst;
    string filename = "/Users/sunguoyan/Downloads/picture/heben.jpg";
    src = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
    dst.create(src.size(),src.type());
    Lapulasi p;
    p.X_image = src.cols;
    p.Y_image = src.rows;

    p.SharpLapulasi(src,dst);

    namedWindow("origin");
    namedWindow("result");
    imshow("origin",src);
    imshow("result",dst);
    waitKey(0);
    return 0;
}
