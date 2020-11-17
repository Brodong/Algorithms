/***********************************************
#
#      Filename: segmenttree.cpp
#
#        Author: Li Xudong - 757264690@qq.com
#   Description: ---
#        Create: 2020-11-17 18:40:28
# Last Modified: 2020-11-17 18:40:28
#
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// 线段树模板
// bilibili上有一位up讲的非常好
// https://www.bilibili.com/video/BV1cb411t7AM?from=search&seid=13012088169955040692
//


#define maxN 1000

void buildtree(int arr[], int tree[], int node, int start, int end)
{
    if(start==end)
    {
        tree[node]=arr[start];
    }
    else
    {
        int mid = (start+end)/2;
        int leftnode = 2*node + 1;
        int rightnode = 2*node + 2;
        buildtree(arr, tree, leftnode, start, mid);
        buildtree(arr, tree, rightnode, mid+1, end);
        tree[node] = tree[leftnode] + tree[rightnode];
    }
}
// 将a[idx]更新为val
void updatetree(int arr[], int tree[], int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        arr[idx] = val;
        tree[node] = val;
    }
    else{
        int mid = (start+end)/2;
        int leftnode = 2*node + 1;
        int rightnode = 2*node + 2;
        if(idx >=start && idx <=mid)
        {
            updatetree(arr, tree, leftnode, start, mid, idx, val);
        }
        else
        {
            updatetree(arr, tree, leftnode, mid+1, end, idx, val);
        }
        tree[node] = tree[leftnode] + tree[rightnode];
    }
}

// query [L, R]
int querytree(int arr[], int tree[], int node, int start, int end, int L, int R)
{
    if(R<start || L>end) return 0;
    else if(start == end || (start>=L && end<=R)) return tree[node];
    else{
        int mid = (start+end)/2;
        int leftnode = 2*node + 1;
        int rightnode = 2*node + 2;
        int sumleft = querytree(arr, tree, leftnode, start, mid, L, R);
        int sumright = querytree(arr, tree, rightnode, mid+1, end, L, R);
        int sum = sumleft+sumright;    
    }
}
int main()
{
    // 首先输入一个数组
    int a[5]={1,3,9,8,2};
    int tree[maxN];

    memset(tree, 0, sizeof(tree));
    
    buildtree(a, tree, 0, 0, 4);
    
    for(int i=0; i<15; i++)
    {
        printf("tree[%d]=%d\n", i, tree[i]);
    }
    printf("\n");
    printf("sum is %d\n", querytree(a, tree, 0, 0, 4, 2, 4));
    updatetree(a, tree, 0, 0, 4, 4, 6);
    
    for(int i=0; i<15; i++)
    {
        printf("tree[%d]=%d\n", i, tree[i]);
    }
    
    return 0;
}

