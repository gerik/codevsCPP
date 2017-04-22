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
#include <unordered_map>
#include <array>
//#include <stdio.h>

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

    int l    = (int) m;

    if(m - l > 0.0) l++;


    int lMax = (l * l + l)/2;

    int k    = lMax - n;

    int o    = l - k;

    if(l % 2 == 1)
        cout << l + 1 - o <<"/" << o <<endl;
    else
        cout << o <<"/" << l + 1 - o  <<endl;

    return 0;
}
int p1160(){

    int n;
    cin >> n;
    int num = n * n;
    int x   = n - 1;
    int y   = n;
    int a[n][n];
    int k = 0,i,j;
    while(num != 0){
        for(i = n-k; i > 0 && num != 0; i--){
            y--;
            a[x][y] = num;
            num--;
        }
        k++;
        for(j = n-k;j > 0 && num != 0; j--){
            x--;
            a[x][y] = num;
            num--;
        }
        for(i = n-k;i > 0 && num != 0; i--){
            y++;
            a[x][y] = num;
            num--;
        }
        k++;
        for(j = n-k;j > 0 && num != 0; j--){
            x++;
            a[x][y] = num;
            num--;
        }
    }
    
    int plus = 0;
    for(x = 0; x < n; x++){
        for(y = 0; y < n; y++){
            cout << a[x][y] << " ";
            if(x == y || x + y == n-1)
                plus +=a[x][y];
        }
        cout << endl;
    }
    
    cout << plus <<endl;
    
    return 1160;
}

int p1012(){
    int x, y;
    cin >> x >> y;
    if(y % x != 0)
        cout << "0" <<endl;
    else{
        int z = y / x;
        int k = 0;
        for(int i = 2; i <= z; i++){
            if(z % i == 0){
                ++ k;
                while(z % i == 0)
                    z = z / i;
            }
        }
        cout << (int)pow(2, k);
    }
    return 1012;
}

int p1212(){
    int A, B;
    cin >> A >> B;
    if(A == 1 || B == 1)  {
        cout << 1;
        return 1212;
    }
    if(A > B) swap(A, B);
    int a = A;
    for(int i = 2;i <= a; i++){
        while(a % i == 0 && B % i == 0){
            a /= i;
            B /= i;
           // cout << "a = " << a <<endl;
        }
       // cout << "B = " << B <<endl;
    }
    cout << A / a << endl;
    
    return 1212;
}

int p1430(){
//    int n;
//    cin >> n;
//    int a[30001] = {0};
//    for(int i = 2; i <= n; i++){
//        if(a[i] == 1)
//            continue;
//        int j = 2;
//        while(i * j <= n){
//            a[i * j] = 1;
//            j++;
//        }
//        if (a[n] == 1){
//            cout << "\\n" <<endl;
//            return 1430;
//        }
//    }
//    if (a[n] == 1){
//        cout << "\\n";
//        return 1430;
//    }
//    else{
//        cout << "\\t";
//    }
//    cout << endl;
//    
//    return 1430;
    int n,a;
    
    cin>>n;
    
    if(n==1){cout<<"\\n"<<endl;return 0;}
    
    a=sqrt(n);
    
    int i;
    
    for(i=2;i<=a;i++)
        
    {
        
        if(n%i==0) {cout<<"\\n"<<endl;return 0;}
        
    }
    
    if(i>1)cout<<"\\t"<<endl;
    
    return 0;
}

//题目描述 Description
//将十进制数n转换成m进制数 m<=16
//
//n<=100
//
//输入描述 Input Description
//共一行
//
//n和m
//
//输出描述 Output Description
//共一个数
//
//表示n的m进制
//
//样例输入 Sample Input
//样例1：10 2
//
//样例2:100 15
//
//样例输出 Sample Output
//样例1：1010
//
//样例2:6A

int p1474(){
    int n, m;
    char a[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char s[10] = {0};
    cin >> n >> m;
    if(m < 2)
        return 0;
    int i = 0;
    while(n > 0){
        s[i++] = a[n % m];
        n /= m;
    }
    while(--i>=0){
        cout << s[i];
    }
    return 1474;
}

int p1475(){
    char n[10] ={'\0'};
    int m;
    cin >> n;
    cin >> m;
    int res = 0;
    for(int i = 0; n[i]!= '\0'; i++){
        if(n[i] >= 'A')
        res = (n[i] - 'A' + 10) + res * m;
        else
        res = (n[i] - '0') + res * m;
    }
    cout << res << endl;
    return 1475;
}

int p1011(){
    int n;
    int f[1001];
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        f[i] = 1;
        for(int j = 1; j <= i/2; j++){
            f[i] += f[j];
        }
    }
    cout << f[n] << endl;
    return 1011;
}

int p1978(){
    int n, dp[40];
    cin >> n;
    dp[1] = dp[2] = 1;
    for(int i = 3; i <=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    
    return 1978;
}

//int p1501(){
//    int n;
//    cin >> n;
//    int a[30] = {0};
//    int w = 1,h = 1;
//    for (int i = 0; i < n * 2; i++) {
//        cin >> a[i];
//    }
//    int k = 1;
//    int nn = n;
//    while (nn > (1 << k) - 1) {
//        k++;
//        nn = (1 << k) - 1;
//    };
//    int m = 0;
//    for (int i = 1; m < nn * 2 ; i++) {
//        int tw = 0;
//        bool th = false;
//        for (int j = 0; j < 1 << i; j++ ) {
//            if (a[j + m] != 0) {
//                tw++;
//                th = true;
//            }
//        }
//        m = m + (1 << i);
//        if (th) h++;
//        if (tw > w) w = tw;
//    }
//    cout << w << " " << h;
//    return 1501;
//}

void p1501helper(int x, int y, int a[], int b[], int w[], int *maxx, int *y1) {
    if (a[x] >0) {
        w[y]++;
        p1501helper(a[x], y + 1,a, b, w, maxx, y1);
    }
    if (b[x] > 0) {
        w[y]++;
        p1501helper(b[x], y + 1,a, b, w, maxx, y1);
    }
        *y1 = (int)max(y, *y1);
}

int p1501() {
    
    int n;
    int a[16] = {0}, b[16] = {0}, w[16] = {0}, maxx = -1, y1 = -1;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    
    if (n == 1){
        cout << "1" << " " << "1";
        return 0;
    }
    
    p1501helper(1, 1, a, b, w, &maxx, &y1);
    
    for (int i = 1; i <= y1; i++) {
        maxx = max(maxx,w[i]);
    }
    cout << maxx << " " << y1;
    
    return 1501;
}

int p1842helper(int x) {
    if(x >= 0 ) {
        return 5;
    }
    else{
        return p1842helper(x + 1) + p1842helper(x + 2) + 1;
    }
}
int p1842() {
    int x;
    cin >> x;
    
    cout << p1842helper(x);
    
    return 1842;
}

int p3038helper(int n, int s) {
    if (1 == n) return s;
    if (n >= INT_MAX || n <= 0) return -1;
    if (n % 2 == 1) {
        s++;
        return p3038helper(3 * n + 1, s);
    }
    else {
        s++;
        return p3038helper(n / 2, s);
    }
}

int p3038() {
    int T, n, s = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << p3038helper(n,s) <<endl;
    }
    return 3038;
}


int pre_order(int i, int L[], int R[]){
    if (i == 0) {
        return 0;
    }
    cout << i << " ";
    pre_order(L[i], L, R);
    pre_order(R[i], L, R);
    return 0;
}

int in_order(int i, int L[], int R[]){
    if (i == 0) {
        return 0;
    }

    in_order(L[i], L, R);
    cout << i << " ";
    in_order(R[i], L, R);
    return 0;
}

int post_order(int i, int L[], int R[]){
    if (i == 0) {
        return 0;
    }
    
    post_order(L[i], L, R);
    post_order(R[i], L, R);
    cout << i << " ";
    return 0;
}

int p3143() {
    int n;
    int L[17] = {0}, R[17] = {0};
    L[0] = 1;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> L[i] >> R[i];
    }

    pre_order(L[0], L, R);
    cout << endl;
    in_order(L[0], L, R);
    cout << endl;
    post_order(L[0], L, R);
    return 3143;
}

void hanoi(int n,char a,char b,char c)
{
    if(n==1)
        cout<<n<<" from "<<a<<" to "<<c<<endl;
    else
    {
        hanoi(n-1,a,c,b);
        cout<<n<<" from "<<a<<" to "<<c<<endl;
        hanoi(n-1,b,a,c);
    }
}


int p3145() {
    int n;
    cin >> n;
    cout << (1<<n) - 1 <<endl;
    hanoi(n, 'A' ,'B', 'C');
    return 3145;
}

int p1098() {
    int N, ans = 0;
    cin >> N;
    int A[N];
    int n = 0, sum = 0;
    while (n < N) {
        cin >> A[n];
        sum +=  A[n];
        n++;
    }
    int avg = sum / N;

    for (int i = 0; i < N; i++) {
        if (A[i] == avg) continue;
        if (A[i] != avg) {
            A[i + 1] += A[i] - avg;
           // cout << A[i + 1] <<endl;
            ans++;
        }
    }
    cout << ans;
    return 1098;
}

struct line {
    int left, right;
};

bool cmp(line a, line b){
    return a.right < b.right;
}

int p1214() {
    int n;
    cin >> n;
    line a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].left >> a[i].right;
        if (a[i].left > a[i].right) {
            swap(a[i].left, a[i].right);
        }
    }
    sort(a, a + n, cmp);
    
    int max_right = a[0].right, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].left >= max_right) {
            max_right = a[i].right;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 1214;
}


int p3115(){
    string A, B;
    bool minus = false;
    cin >> A >> B;
    if (A.size() < B.size()) {
        swap(A, B);
        minus = true;
    }
    
    for (long i = B.size(); i < A.size(); i++) {
        B = "0" + B;
    }
    
    for (long i = 0; i < A.size(); i++) {
        if (A[i] > B[i]) {
            break;
        }
        else if (A[i] == B[i]) continue;
        else {
            swap(A, B);
            minus = true;
            break;
        }
    }
    
    for (long i = A.size() - 1; i >= 0; i--) {
        if(A[i] < '0' || A[i] < B[i]) {
            A[i - 1] -= 1;
            A[i] += 10;
        }
            A[i] = '0' + A[i] - B[i];
    }

    long i = 0;
    while (i < A.size()) {
        if (A[i] == '0'){
            i++;
        }
        else
            break;
    }
    if (i == A.size()) {
        i--;
    }
    if (minus) {
        cout << "-";
    }
    while (i < A.size()) {
        cout <<A[i];
        i++;
    }
    
    return 3115;
    
}

int p3116(){
    string A, B;
    cin >> A >> B;
    if (A.size() < B.size()) {
        swap(A, B);
    }
    
    for (long i = B.size(); i < A.size(); i++) {
        B = "0" + B;
    }
    
    for (long i = 0; i < A.size(); i++) {
        if (A[i] > B[i]) {
            break;
        }
        else if (A[i] == B[i]) continue;
        else {
            swap(A, B);
            break;
        }
    }
    
    
    int carry = 0;
    for (long i = A.size() - 1; i >= 0; i--) {
        int temp = A[i] - '0' + B[i] -'0' + carry;
        if(temp > 9) {
            A[i] = temp - 10 + '0';
            carry = 1;
        }
        else{
            A[i] = temp + '0';
            carry = 0;
        }
    }
    
    if (1 == carry) {
        A = "1" + A;
    }
    
    long i = 0;
    while (i < A.size()) {
        cout <<A[i];
        i++;
    }
    
    return 3116;
    
}

string p3116(string A, string B){

    if (B == "0") {
        return "0";
    }
    
    if (A.size() < B.size()) {
        swap(A, B);
    }
    
    for (long i = B.size(); i < A.size(); i++) {
        B = "0" + B;
    }
    
    for (long i = 0; i < A.size(); i++) {
        if (A[i] > B[i]) {
            break;
        }
        else if (A[i] == B[i]) continue;
        else {
            swap(A, B);
            break;
        }
    }
    
    
    int carry = 0;
    for (long i = A.size() - 1; i >= 0; i--) {
        int temp = A[i] - '0' + B[i] -'0' + carry;
        if(temp > 9) {
            A[i] = temp - 10 + '0';
            carry = 1;
        }
        else{
            A[i] = temp + '0';
            carry = 0;
        }
    }
    
    if (1 == carry) {
        A = "1" + A;
    }
    
    return A;
    
}

string p3117helper_map(string A, char b){
    unordered_map <int, string> map;
    int ib = b - '0';
    if(map.find(ib) == map.end()){
        int carry = 0;
        int temp = 0;
        for (long i = A.size() - 1; i >= 0; i--) {
            temp = (A[i] - '0') * ib + carry;
            if(temp > 9) {
                carry = temp / 10;
                A[i] = temp % 10 + '0';
            }
            else {
                A[i] = temp + '0';
                carry = 0;
            }
        }
        if (carry > 0) {
            char c ='0' + carry;
            A = c + A;
        }
        map[ib] = A;
        return A;
    }
    else{
        return map[ib];
    }
    return A;
}

string p3117helper_m(string M[], string A, char b){
    int ib = b - '0';
    if(M[ib] == ""){
        int carry = 0;
        int temp = 0;
        for (long i = A.size() - 1; i >= 0; i--) {
            temp = (A[i] - '0') * ib + carry;
            if(temp > 9) {
                carry = temp / 10;
                A[i] = temp % 10 + '0';
            }
            else {
                A[i] = temp + '0';
                carry = 0;
            }
        }
        if (carry > 0) {
            char c ='0' + carry;
            A = c + A;
        }
        M[ib] = A;
        return A;
    }
    else{
        return M[ib];
    }
    return A;
}


string p3117helper(string A, char b){
    int ib = b - '0';
    int carry = 0;
    int temp = 0;
    for (long i = A.size() - 1; i >= 0; i--) {
        temp = (A[i] - '0') * ib + carry;
        if(temp > 9) {
            carry = temp / 10;
            A[i] = temp % 10 + '0';
        }
        else {
            A[i] = temp + '0';
            carry = 0;
        }
    }
    if (carry > 0) {
        char c ='0' + carry;
        A = c + A;
    }
    return A;
}

int p3117(){
    string A, B;
    string M[10] = {""};
    cin >> A >> B;
    
    if (A == "0" || B == "0") {
        cout << "0";
        return 0;
    }
    
    if (A.size() < B.size()) {
        swap(A, B);
    }
    string ans = "0";
    string zero = "";
    for (long j = B.size() - 1; j >= 0; j--) {
        string temp = p3117helper_m(M, A, B[j]) + zero;
        ans = p3116(ans, temp);
        zero += "0";
    }
    
    cout << ans;
    
    return 3116;
}

//1014 装箱问题  2001年NOIP全国联赛普及组
//时间限制: 1 s
//空间限制: 128000 KB
//题目等级 : 黄金 Gold
//题解
//题目描述 Description
//有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
//
//要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
//
//输入描述 Input Description
//一个整数v，表示箱子容量
//
//一个整数n，表示有n个物品
//
//接下来n个整数，分别表示这n 个物品的各自体积
//
//输出描述 Output Description
//一个整数，表示箱子剩余空间。

int p1014() {

    int n, v, thing, f[20001];
    
    cin >> v >> n;
    
    memset(f, 0,  sizeof(f));
    
    for(int i=1; i<=n; ++i){
        cin >> thing;
        for(int j=v; j>=thing; j--){
            f[j] = max(f[j-thing]+thing, f[j]);
        }
    }
    cout << v-f[v];
    return 0;
}

int p1014b() {
   
    int w[35];
    
    int f[20005];
    
    int n,v;
    memset(f, 0, sizeof(f));
    scanf("%d%d",&v,&n);
    
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);
    for (int i=1;i<=n;i++){
        
        for (int j=v;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    }
    
    printf("%d",v-f[v]);
    
    return 0;
}

//1068 乌龟棋  2010年NOIP全国联赛提高组
//时间限制: 1 s
//空间限制: 128000 KB
//题目等级 : 钻石 Diamond
//题解
//题目描述 Description
//小明过生日的时候，爸爸送给他一副乌龟棋当作礼物。 乌龟棋的棋盘是一行N个格子，每个格子上一个分数（非负整数）。棋盘第1格是唯一 的起点，第N格是终点，游戏要求玩家控制一个乌龟棋子从起点出发走到终点。
//
//…… 1 2 3 4 5 ……N 乌龟棋中M张爬行卡片，分成4种不同的类型（M张卡片中不一定包含所有4种类型 的卡片，见样例），每种类型的卡片上分别标有1、2、3、4四个数字之一，表示使用这种卡 片后，乌龟棋子将向前爬行相应的格子数。游戏中，玩家每次需要从所有的爬行卡片中选择 一张之前没有使用过的爬行卡片，控制乌龟棋子前进相应的格子数，每张卡片只能使用一次。 游戏中，乌龟棋子自动获得起点格子的分数，并且在后续的爬行中每到达一个格子，就得到 该格子相应的分数。玩家最终游戏得分就是乌龟棋子从起点到终点过程中到过的所有格子的 分数总和。 很明显，用不同的爬行卡片使用顺序会使得最终游戏的得分不同，小明想要找到一种卡 片使用顺序使得最终游戏得分最多。 现在，告诉你棋盘上每个格子的分数和所有的爬行卡片，你能告诉小明，他最多能得到 多少分吗？
//
//输入描述 Input Description
//输入的每行中两个数之间用一个空格隔开。 第1行2个正整数N和M，分别表示棋盘格子数和爬行卡片数。 第2行N个非负整数，a1a2……aN
//
//，其中ai表示棋盘第i个格子上的分数。 第3行M个整数，b1b2……bM
//
//，表示M张爬行卡片上的数字。 输入数据保证到达终点时刚好用光M张爬行卡片，即N - 1=∑(1->M) bi
//
//输出描述 Output Description
//输出一行一个整数
//
//样例输入 Sample Input
//13 8
//
//4 96 10 64 55 13 94 53 5 24 89 8 30
//
//1 1 1 1 1 2 4 1
//
//样例输出 Sample Output
//455
//
//数据范围及提示 Data Size & Hint
//【数据范围】
//
//对于30%的数据有1 ≤ N≤ 30，1 ≤M≤ 12。
//
//对于50%的数据有1 ≤ N≤ 120，1 ≤M≤ 50，且4 种爬行卡片，每种卡片的张数不会超
//
//过20。
//
//对于100%的数据有1 ≤ N≤ 350，1 ≤M≤ 120，且4 种爬行卡片，每种卡片的张数不会
//
//超过40；0 ≤ ai ≤ 100，1 ≤ i ≤ N；1 ≤ bi ≤ 4，1 ≤ i ≤M。输入数据保证N−1=ΣM
//
//i b
//
//1

int p1068() {
    int n, m;
    int s[400];
    int a = 0, b = 0, c = 0, d = 0;
    static int f[41][41][41][41] = {0};
    //static array<array<array<array<int,50>,50>,50>,17> f;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int x,j = 1; j <=m; j++) {
        cin >> x;
        switch (x) {
            case 1:
                a++;
                break;
            case 2:
                b++;
                break;
            case 3:
                c++;
                break;
            default:
                d++;
                break;
        }
    }
    for (int i = 1; i <= a + 1; i++) {
        for (int j = 1; j <= b + 1; j++) {
            for (int k = 1; k <= c + 1; k++) {
                for (int l = 1 ; l <= d + 1; l++) {
                    f[i][j][k][l] = max(max(f[i-1][j][k][l], f[i][j-1][k][l]),max(f[i][j][k-1][l],f[i][j][k][l-1]))
                    +s[(i-1)+(j-1)*2+(k-1)*3+(l-1)*4];
                }
            }
        }
    }
    cout << f[a + 1][b + 1][c + 1][d + 1];
    return 1068;
}

//1044 拦截导弹  1999年NOIP全国联赛提高组
//时间限制: 1 s
//空间限制: 128000 KB
//题目等级 : 黄金 Gold
//题解
//题目描述 Description
//某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
//
//
//
//输入描述 Input Description
//输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）
//
//
//
//输出描述 Output Description
//输出这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
//
//样例输入 Sample Input
//8 389 207 155 300 299 170 158 65
//
//样例输出 Sample Output
//6
//
//2
//
//数据范围及提示 Data Size & Hint
//导弹的高度<=30000，导弹个数<=20

//int p1044() {
//    int height[30], size = 1;
////    while (cin >> height[size]) size++;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> height[size];
//        size++;
//    }
////    for (int i = 0; i <= n; i++) {
////        cout << height[i] <<endl;
////    }
//    int a[size], dp[size], result = 0, m = 0;
//    memset(a, 0, sizeof(a));
//    memset(dp, 0, sizeof(dp));
//    
//    for (int i = 0; i < size; i++) {
//        dp[i] = 1;
//        for (int j = 0; j < i; j++) {
//            if (height[j] >= height[i]) {
//                dp[i] = max(dp[i], dp[j] + 1);
//            }
//            m = max(m, dp[i]);
//        }
//
//    }
//    
//    a[result] = height[1];
//    for (int i = 1; i < size; i++) {
//        int tmp = 0;
//        for (int j = 1; j <= result; j++) {
//            if (a[j] >= height[i] && (tmp == 0 || a[j] < a[tmp])) {
//                tmp = j;
//            }
//        }
//        if (tmp == 0) {
//            result++;
//            a[result] = height[i];
//        }
//        else{
//            a[tmp] = height[i];
//        }
//    }
//    cout << m << endl << result << endl;
//    return 1044;
//}
int p1044() {//7 300 250 275 252 200 138 245
    int height[30], size = 1;
    //while (cin >> height[size]) size++;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> height[size];
            size++;
        }
    int a[size], dp[size], result = 0, m = 0;
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < size; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (height[j] >= height[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            m = max(m, dp[i]);
        }
        
    }
    
    a[result] = height[1];
    for (int i = 1; i < size; i++) {
        int tmp = 0;
        for (int j = 1; j <= result; j++) {
            if (a[j] >= height[i] && (tmp == 0 || a[j] < a[tmp])) {
                tmp = j;
            }
        }
        if (tmp == 0) {
            result++;
            a[result] = height[i];
        }
        else{
            a[tmp] = height[i];
        }
    }
    cout << m << endl << result << endl;
    return 1576;
}

int p1576() {
    int height[50010];
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> height[i];
    }

    int dp[n], m = 0;
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (height[j] < height[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            m = max(m, dp[i]);
            //cout << m <<endl;
        }
    }
    
    cout << m << endl;
    return 1576;
}

//3027 线段覆盖 2
//时间限制: 1 s
//空间限制: 128000 KB
//题目等级 : 黄金 Gold
//题解
//题目描述 Description
//数轴上有n条线段，线段的两端都是整数坐标，坐标范围在0~1000000，每条线段有一个价值，请从n条线段中挑出若干条线段，使得这些线段两两不覆盖（端点可以重合）且线段价值之和最大。
//
//n<=1000
//
//输入描述 Input Description
//第一行一个整数n，表示有多少条线段。
//
//接下来n行每行三个整数, ai bi ci，分别代表第i条线段的左端点ai，右端点bi（保证左端点<右端点）和价值ci。
//
//输出描述 Output Description
//输出能够获得的最大价值
//样例输入 Sample Input
//3
//
//1 2 1
//
//2 3 2
//
//1 3 4
//
//样例输出 Sample Output
//4
//
//数据范围及提示 Data Size & Hint
//数据范围
//
//对于40%的数据，n≤10；
//
//对于100%的数据，n≤1000；
//
//0<=ai,bi<=1000000
//
//0<=ci<=1000000

struct Line3027{
    int a;
    int b;
    int c;
};

bool cmp3027(Line3027 a, Line3027 b){
    return a.a < b.a;
}


int p3027() {
    int n;
    cin >> n;
    int dp[1010];
    int res = 0;
    memset(dp, 0, sizeof(dp));

    struct Line3027 m[n];
    for (int i = 0; i < n; i++) {
        cin >> m[i].a >> m[i].b >> m[i].c;
    }
    sort(m, m + n, cmp3027);

    for (int i = 0; i < n; i++) {
        dp[i] = m[i].c;
        for (int j = 0; j < i; j++) {
            if (m[i].a >= m[j].b ) {
                dp[i] = max(dp[j] + m[i].c, dp[i]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 3027;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    p3027();
    cout<<endl;

    return 0;
}
