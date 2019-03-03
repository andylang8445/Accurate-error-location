//
//  main.cpp
//  Sudoku Answer checking program
//
//  Created by HongjunYun on 2019-03-02.
//  Copyright © 2019 HongjunYun. All rights reserved.
//

#include <stdio.h>
#define N 9

struct structure{
    int x_coordinate;
    int y_coordinate;
    int value;
};
structure cpy[N];
structure map[N][N];
int line_test();
int box_test();
bool error_count[N][N];

int main()
{
    int vertical_error=0;
    int horizontal_error=0;
    int box_error=0;
    int cpy_cnt=0;
    
    printf("TEST\n");
    for(int i=0;i<N*N;i++)
        for(int j=0;j<2;j++)
            error_count[i][j]=false;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&map[i][j].value);
            map[i][j].x_coordinate=j+1;
            map[i][j].y_coordinate=i+1;
            cpy[j]=map[i][j];
        }
        horizontal_error+=line_test();
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cpy[j]=map[j][i];
        }
        vertical_error+=line_test();
    }
    for(int i=0;i<=6;i+=3)
    {
        for(int j=0;j<=6;j+=3)
        {
            for(int x=i;x<i+3;x++)
                for(int y=j;y<j+3;y++)
                    cpy[cpy_cnt++]=map[x][y];
            cpy_cnt=0;
            box_error+=line_test();
        }
    }
    printf("Vertical error: %d\nHorizontal error: %d\nBox error: %d\n----------------\nTotal error count: %d\n",vertical_error,horizontal_error,box_error,(vertical_error+horizontal_error+box_error));
    printf("\n\n\tERROR LOCATION\n-------------------------\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(error_count[i][j]==true)
            {
                printf("\t(%d, %d)\n",j+1,i+1);
            }
        }
    }
    return 0;
}

int line_test()
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(cpy[i].value>cpy[j].value)
            {
                structure tmp=cpy[i];
                cpy[i]=cpy[j];
                cpy[j]=tmp;
                return 1;
            }
        }
    }
    for(int j=0;j<N;j++)
        if(cpy[j].value!=j+1)
            error_count[cpy[j].x_coordinate][cpy[j].y_coordinate]=true;
    return 0;
}

