#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <random>
#include<math.h>
#include <cmath>





int main()
{  
    float mean, var;
    
    printf("輸入mean:");
    scanf("%f", &mean);
    printf("輸入variance:");
    scanf("%f", &var);
    
    
    std::random_device rd;
    std::mt19937 generator(rd()); //產生器
    std::normal_distribution<float> norm(mean, sqrt(var)); //設定參數
    float x = norm(generator); // 產生標準常態分布的亂數 

    float X1[100] = { 0 };
    float X2[10000] = { 0 };
    float mean100=0, mean10000=0;
    int heavy70 = 0, heavy70p = 0;
    float Pmore70=0, Pmore70p=0;
    float std100 = 0, std10000 = 0;
    float cdf1 = 0, cdf2 = 0;
    float std1=0, std2=0;
    float C1[100] = { 0 };
    float C2[10000] = { 0 };

    //100次實驗
    for (int i = 0; i < 100; i++)  
    {
        float x = norm(generator);
        X1[i] = x;
        if (x >70)                //超過70公斤人數
            heavy70 += 1;
    }


    for (int j = 0; j < 100; j++)  //100次實驗的mean      
        mean100 = mean100 + X1[j];

    Pmore70 = (float)heavy70 / 100; //大於70公斤的機率

    for (int k = 0; k < 100; k++)  //100次實驗的標準差 
        std100 += (((X1[k] - (mean100 / 100))) * ((X1[k] - (mean100 / 100)))) / 100;
    std1 = sqrt(std100);

    cdf1 = 1 - Pmore70;  //p=70的cdf



    //10000次實驗
    for (int ii = 0; ii < 10000; ii++)  
    {
        float x = norm(generator);
        X2[ii] = x;
        if (x > 70)                //超過70公斤人數
            heavy70p += 1;  
    }

    for (int jj = 0; jj < 10000; jj++)  //10000次實驗的mean      
        mean10000 = mean10000 + X2[jj];

    Pmore70p = (float)heavy70p / 10000; //大於70公斤的機率

    for (int kk = 0; kk < 10000; kk++)  //10000次實驗的標準差 
        std10000 +=  (((X2[kk] - (mean10000/10000)))* ((X2[kk] - (mean10000/10000))))/10000;
    std2 = sqrt(std10000 );

    cdf2 = 1 - Pmore70p;  //p=70的cdf


  //P(X>70)理論值:大於平均值2標準差 = 𝑃𝑟(𝜇 − 2𝜎 ≤ 𝑋 ≤ 𝜇 + 2𝜎)/2 + 0.5
    float cdf = 0.954499736103642 / 2 + 0.5;
    float theopdf = 1 - cdf;
       

    //作業b

    printf("\n                          experiental results             theoretical results\n");
    printf("                          (n=100)     (n=10000)     (平均值=50 標準差=10 之 Normal distribution)  \n");
    printf("mean =                     %2f      %2f        50.00000 \n",mean100/100,mean10000/10000);
    printf("standard deviation =       %2f       %2f         10.00000 \n", std1, std2,sqrt(var));
    printf("P(X>=70) =                 %2f       %2f         %2f\n", Pmore70, Pmore70p,theopdf);
    printf("CDF:F(X=70) =              %2f       %2f         %2f\n", cdf1, cdf2,cdf);


    //作業a
    //matlab畫cdf圖,X1為x軸，C1為y軸

    for (int Q = 0; Q < 100 - 1; Q++)   //氣泡排序
    {
        for (int QQ = 0; QQ < 100 - Q - 1; QQ++)
        {
            if (X1[QQ] > X1[QQ + 1])
            {
                float temp = X1[QQ];
                X1[QQ] = X1[QQ + 1];
                X1[QQ + 1] = temp;
            }
        }
    }

    for (int q = 0; q < 100; q++)
    {
        if (q == 0)
            C1[q] = 0.01;
        else
            C1[q] = C1[q - 1] + 0.01;
    }

    FILE* pfile;
    pfile = fopen("CDF_x_3.a.txt", "w");
    if (pfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < 100; h++)
            fprintf(pfile, " %f\n", X1[h]);
    }
    fclose(pfile);
    

    FILE* qfile;
    qfile = fopen("CDF_y_3.a.txt", "w");
    if (qfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < 100; h++)
            fprintf(qfile, " %f\n", C1[h]);
    }
    fclose(qfile);


    //作業a
    //matlab畫cdf圖,X2為x軸，C2為y軸

    for (int U = 0; U < 10000 - 1; U++)   //氣泡排序
    {
        for (int UU = 0; UU < 10000 - U - 1; UU++)
        {
            if (X2[UU] > X2[UU + 1])
            {
                float temp = X2[UU];
                X2[UU] = X2[UU + 1];
                X2[UU + 1] = temp;
            }
        }
    }

    for (int u = 0; u < 10000; u++)
    {
        if (u == 0)
            C2[u] = 0.0001;
        else
            C2[u] = C2[u - 1] + 0.0001;
    }


    FILE* rfile;
    rfile = fopen("CDF2_x_3.a.txt", "w");
    if (rfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < 10000; h++)
            fprintf(rfile, " %f\n", X2[h]);
    }
    fclose(rfile);

    FILE* sfile;
    sfile = fopen("CDF2_y_3.a.txt", "w");
    if (sfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < 10000; h++)
            fprintf(sfile, " %f\n", C2[h]);
    }
    fclose(sfile);


   

    //作業c

    /*該公司內有一電梯，其最大負重為850公斤。假設在電梯已負重800公斤之情況下，有一員工進入電梯造
      成電梯超重，請各對100筆與10000筆資料，計算並繪製「在電梯超重之情況下，員工體重之條件PDF */
      
    // P(體重>50的機率)

    int da1 = 0,da2=0 ;
    float p1[100] = { 0};
    float p2[10000] = { 0 };
    float c1[100] = { 0 };
    float c2[10000] = { 0 };
    float pdf1[100] = { 0 };
    float pdf2[10000] = { 0 };
    float matlabpdf1[100] = { 0 };
    float matlabpdf2[10000] = { 0 };
    


    for (int m = 0; m < 100;m++)  //100次實驗
    {
        float x = norm(generator);
        if (x >= 50)
        {      
            p1[da1] = x;  //0不要取    //刪除陣列裡面0的部分
            da1 += 1;
        }
        else
            continue;
    }


    
    for (int c = 0; c < da1 - 1; c++)   //氣泡排序
    {
        for (int d = 0; d < da1 - c - 1; d++)
        {
            if (p1[d] > p1[d + 1]) 
            {
                float swap = p1[d];
                p1[d] = p1[d + 1];
                p1[d + 1] = swap;
            }
        }
    }



    for (int z = 0; z < da1; z++)     //PDF
    {
        static const float pi = 3.14159265;
        pdf1[z] = exp(-1 * (p1[z] - mean) * (p1[z] - mean) / (2 * sqrt(var) * sqrt(var))) / (sqrt(var) * sqrt(2 * pi));
    }
    

    //for (int v = 0; v < da1; v++)                                 //ensure
    //    printf("%f   %f\n", p1[v], (float)100 * pdf1[v] /da1 );
    //

                                                                //求條件pdf
    for (int v = 0; v < da1; v++)                               //100次實驗之pdf陣列
      matlabpdf1[v] = (float)100 * pdf1[v] / da1;              //之後存檔load到matlab x軸為p1 y軸為matlabpdf1


    //MATLAB
    FILE* tfile;
    tfile = fopen("PDF_x_3.c.txt", "w");
    if (tfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < da1; h++)
            fprintf(tfile, " %f\n", p1[h]);
    }
    fclose(tfile);


    FILE* ufile;
    ufile = fopen("PDF_y_3.c.txt", "w");
    if (ufile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < da1; h++)
            fprintf(ufile, " %f\n", matlabpdf1[h]);
    }
    fclose(ufile);





    //10000次實驗



    for (int n = 0; n < 10000; n++)  //100次實驗
    {
        float x = norm(generator);
        if (x >= 50)
        {

            p2[da2] = x;  //0不要取    //刪除陣列裡面0的部分
            da2 += 1;
        }
        else
            continue;
    }



    for (int e = 0; e < da2 - 1; e++)   //氣泡排序
    {
        for (int f = 0; f < da2 - e - 1; f++)
        {
            if (p2[f] > p2[f + 1])
            {
                float temp = p2[f];
                p2[f] = p2[f + 1];
                p2[f + 1] = temp;
            }
        }
    }


    for (int u = 0; u < da2; u++)     //求PDF
    {
        static const float pi = 3.14159265;
        pdf2[u] = exp(-1 * (p2[u] - mean) * (p2[u] - mean) / (2 * sqrt(var) * sqrt(var))) / (sqrt(var) * sqrt(2 * pi));
    }
    
   //for (int w = 0; w < da2; w++)    //之後存檔load到matlab                           
   //     printf("%f   %f\n", p2[w], (float)100 * pdf2[w] / da2);
   // 

                                                       //求條件pdf
    for (int w = 0; w < da2; w++)                     //100次實驗之pdf陣列
        matlabpdf2[w] = (float)100 * pdf2[w] / da2;    //之後存檔load到matlab x軸為p2 y軸為matlabpdf2


    //MATLAB
    FILE* wfile;
    wfile = fopen("PDF2_x_3.c.txt", "w");
    if (wfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < da2; h++)
            fprintf(wfile, " %f\n", p2[h]);
    }
    fclose(wfile);

    FILE* xfile;
    xfile = fopen("PDF2_y_3.c.txt", "w");
    if (xfile == NULL)
        printf("open failure");
    else
    {
        for (int h = 0; h < da2; h++)
            fprintf(xfile, " %f\n", matlabpdf2[h]);
    }
    fclose(xfile);


    printf("\n\n\n\n\n\n");

    system("pause");
    return 0;
}