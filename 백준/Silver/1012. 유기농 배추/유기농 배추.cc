#include <stdio.h>

int beachu[50][50];

void oversearch(int i, int j, int m, int n)
{   
    if(i < m - 1){
        if(beachu[i + 1][j] == 1){
            beachu[i + 1][j] = 2;
            oversearch(i + 1, j, m, n);
        }    
    }
    
    if(j < n - 1){
        if(beachu[i][j + 1] == 1){
            beachu[i][j + 1] = 2;
            oversearch(i, j + 1, m, n);
        }    
    }
    
    if(j > 0){
        if(beachu[i][j - 1] == 1){
            beachu[i][j - 1] = 2;
            oversearch(i, j - 1, m, n);
        }
    }
    
    if(i > 0){
        if(beachu[i - 1][j] == 1){
            beachu[i - 1][j] = 2;
            oversearch(i - 1, j, m, n);
        }    
    }
}

int search(int m, int n)
{
    int worm = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(beachu[i][j] == 1){
                worm++;
                beachu[i][j] = 2;
                oversearch(i, j, m, n);
            }
        }
    }
    return worm;
}


int main()
{
  int m, n, k;
  int testcase, vertical, horizontal;

  scanf("%d", &testcase);

  for(int i = 0; i < testcase; i++){
      scanf ("%d %d %d", &m, &n, &k);
        for(vertical = 0; vertical < m; vertical++){
            for(horizontal = 0; horizontal < n; horizontal++){
                beachu[vertical][horizontal] = 0;
            }
        }
        for(int count = 0; count < k; count++){
            scanf("%d %d", &vertical, &horizontal);
            beachu[vertical][horizontal] = 1;
        }
        printf("%d\n", search(m, n));
        for(vertical = 0; vertical < m; vertical++){
            for(horizontal = 0; horizontal < n; horizontal++){
                beachu[vertical][horizontal] = 0;
            }
        }        
    }
  return 0;
}