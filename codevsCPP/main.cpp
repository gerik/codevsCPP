//
//  main.cpp
//  codevsCPP
//
//  Created by jiafu on 2017/3/30.
//  Copyright © 2017年 jiafu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

//1075 明明的随机数  2006年NOIP全国联赛普及组
//时间限制: 1 s
//空间限制: 128000 KB
//题目等级 : 白银 Silver
//题解
//题目描述 Description
//明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
//
//输入描述 Input Description
//有2行，第1行为1个正整数，表示所生成的随机数的N个数：
//
//
//
//第2行有N个用空格隔开的正整数，为所产生的随机数
//
//
//
//输出描述 Output Description
//第1行为1个正整数M，表示不相同的随机数的个数。第2行为M个用空格隔开的正整数，为从小
//到大排好序的不相同的随机数。
//样例输入 Sample Input
//10
//
//20 40 32 67 40 20 89 300 400 15
//
//样例输出 Sample Output
//8
//
//15 20 32 40 67 89 300 400

int p1075(){

    int n,c = 0;
        int a[1000] = {0};
        cin >> n;
        int t = 1;
        for (int i = 0; i < n; i++) {
            cin >> t;
            if(0 == a[t - 1]){
                c++;
                a[t - 1] = t;
            }
        }
        
        cout << c << endl;
        
        for (int i = 0; i < 1000; i++) {
            if (0 != a[i]) {
                cout<<a[i]<<" ";
            }
        }
        cout << endl;
        
        return 0;

}


//1076 排序
//时间限制: 1 s
//空间限制: 128000 KB
//题目等级 : 白银 Silver
//题解
//题目描述 Description
//给出n和n个整数，希望你从小到大给他们排序
//
//输入描述 Input Description
//第一行一个正整数n
//
//
//
//第二行n个用空格隔开的整数
//
//输出描述 Output Description
//输出仅一行，从小到大输出n个用空格隔开的整数
//
//样例输入 Sample Input
//3
//
//3 1 2
//
//样例输出 Sample Output
//1 2 3
//
//数据范围及提示 Data Size & Hint
//1<=n<=100000

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high){
    int privot = a[low];
    while(low < high){
        while(low < high && a[high] >= privot) high--;
        swap(&a[low],&a[high]);
        while(low < high && a[low] <= privot) low++;
        swap(&a[low],&a[high]);
    }
    return low;
}

void qsort_improve(int r[ ],int low,int high, int k){
    if( high -low > k ) {
        int pivot = partition(r, low, high);
        qsort_improve(r, low, pivot - 1,k);
        qsort_improve(r, pivot + 1, high,k);
    }
}
void quickSort(int r[], int n, int k){
    qsort_improve(r,0,n,k);

    for(int i=1; i<=n;i ++){
        int tmp = r[i];
        int j=i-1;
        while(tmp < r[j]){
            r[j+1]=r[j]; j=j-1;
        }
        r[j+1] = tmp;
    }
    
}

//void quickSort(int a[], int low, int high){
//    if(low < high){
//        int privot = partition(a, low, high);
//        quickSort(a, low, privot - 1);
//        quickSort(a, privot + 1, high);
//    }
//}


int p1076(){
    
    int n;
    
    cin >> n;
    
    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    //sort(a,a + n);
    quickSort(a, n, 4);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
    
    return 0;
    
}

int p1083p(){
    
    int in;
    
    cin >> in;
    for(int n = 1;n<in;n++){
    double m = (sqrt(8.0 * n + 1) - 1) / 2;
    
    int l = (int) m;
    
    if(m - l > 0.0) l++;
    
    
    int lMax = (l * l + l)/2;
    
    int k = lMax - n;
    
    int out = l - k;
    
    if(l % 2 == 1)
        cout << l + 1 - out <<"/" << out <<endl;
    else
        cout << out <<"/" << l + 1 - out  <<endl;
    }
    return 0;
}

int p1083(){
    
    int n;
    
    cin >> n;
    
    double m = (sqrt(8.0 * n + 1) - 1) / 2;
    
    int l = (int) m;
    
    if(m - l > 0.0) l++;
    
    
    int lMax = (l * l + l)/2;
    
    int k = lMax - n;
    
    int o = l - k;
    
    if(l % 2 == 1)
        cout << l + 1 - o <<"/" << o <<endl;
    else
        cout << o <<"/" << l + 1 - o  <<endl;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    p1083();
    
    return 0;
}

