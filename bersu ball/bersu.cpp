#include <bits/stdc++.h>


using namespace std;


int tab[109];
int tab2[109];


int main()
{
    int n, m, wyn = 0;
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
      scanf("%d", &tab[i]);
    
    cin>>m;
    
    for(int i = 0; i < m; i++)
      scanf("%d", &tab2[i]);
    
    sort(tab, tab + n);
    sort(tab2, tab2 + m);
    
    int wsk = 0;
    
    for(int i = 0; i < n; i++)
      {
          while((wsk < m) && (tab2[wsk] < tab[i] - 1))
            wsk++;
          
          if((wsk < m) && ((tab[i] - 1 <= tab2[wsk]) && (tab[i] + 1 >= tab2[wsk])))
            {
                wsk++;
                wyn++;
            }
      }
    
    cout<<wyn<<endl;
    

    return 0;
} 
