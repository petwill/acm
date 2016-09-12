    /* 
     * Author: Gatevin 
     * Created Time:  2015/8/28 14:00:42 
     * File Name: Iki_Hiyori.cpp 
     */  
    #include<iostream>  
    #include<sstream>  
    #include<fstream>  
    #include<vector>  
    #include<list>  
    #include<deque>  
    #include<queue>  
    #include<stack>  
    #include<map>  
    #include<set>  
    #include<bitset>  
    #include<algorithm>  
    #include<cstdio>  
    #include<cstdlib>  
    #include<cstring>  
    #include<cctype>  
    #include<cmath>  
    #include<ctime>  
    #include<iomanip>  
    using namespace std;  
    const double eps(1e-8);  
    typedef long long lint;  
      
    /* 
     * Matrix-Tree定理(Kirchhoff矩阵-树定理) 
     * 图G的所有不同的生成树的个数等于其Kirchhoff矩阵C[G]任何一个n - 1阶主子式的行列式的绝对值 
     * 相关概念： 
     * 定义一个如G的Kirchhoff矩阵C[G]为G的度数矩阵D[G]与邻接矩阵A[G]的差 
     * 即C[G] = D[G] - A[G] 
     * G的度数矩阵D[G]: 是一个n*n的矩阵, 满足当i != j 时d[ij] = 0, 当i == j时d[ij] = (v[i]的度数) 
     * G的邻接矩阵A[G]: 是一个n*n的矩阵, 满足如果v[i]与v[j]之间有边相连则a[ij] = 1否则a[ij] = 0 (但是经过其他题的验证这里a[ij]应该是v[i]和v[j]之间的边数) 
     * n - 1阶主子式: 即矩阵去掉第i行和i列的所有元素之后得到的矩阵(1 <= i <= n) 
     */  
      
    const int sz = 20;  
      
    struct Matrix  
    {  
        double a[sz][sz];  
        Matrix()  
        {  
            for(int i = 0; i < sz; i++)  
                for(int j = 0; j < sz; j++)  
                    a[i][j] == (i == j);  
        }  
        void clear()  
        {  
            memset(a, 0, sizeof(a));  
        }  
        double* operator [] (int x)  
        {  
            return a[x];  
        }  
        double det(int n)//return determinant  
        {  
            double ret = 1;  
            for(int i = 1; i < n; i++)  
            {  
                for(int j = i + 1; j < n; j++)  
                    while(fabs(a[j][i]) > eps)  
                    {  
                        double t = a[i][i] / a[j][i];  
                        for(int k = i; k < n; k++)  
                            a[i][k] -= a[j][k]*t;  
                        for(int k = i; k < n; k++)  
                            swap(a[i][k], a[j][k]);  
                        ret *= -1;  
                    }  
                if(fabs(a[i][i]) < eps)  
                    return 0;  
                ret = ret*a[i][i];  
            }  
            return ret;  
        }  
    };  
      
    Matrix operator - (const Matrix &m1, const Matrix &m2)  
    {  
        Matrix ret;  
        for(int i = 0; i < sz; i++)  
            for(int j = 0; j < sz; j++)  
                ret[i][j] = m1.a[i][j] - m2.a[i][j];  
        return ret;  
    }  
      
    Matrix C, D, A;  
      
    int main()  
    {  
        int T;  
        scanf("%d", &T);  
        while(T--)  
        {  
            int n, m;  
            scanf("%d %d", &n, &m);  
            D.clear(), A.clear();  
            int u, v;  
            while(m--)  
            {  
                scanf("%d %d", &u, &v);  
                A[u][v] = A[v][u] = 1;//此题没有重边  
                D[u][u] += 1;  
                D[v][v] += 1;  
            }  
            C = D - A;  
            printf("%.0f\n", C.det(n));  
        }  
        return 0;  
    }  
