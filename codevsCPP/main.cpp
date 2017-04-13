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

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";

    p1014b();
    cout<<endl;

    return 0;
}

