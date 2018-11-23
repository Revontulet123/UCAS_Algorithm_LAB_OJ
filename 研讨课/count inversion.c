#include <stdio.h>
#include <string.h>
 
int* arr;
int* temp;
 

int merge(int low, int middle, int high)
{
    int i = low, j = middle + 1, k = low;
    
    while ((i <= middle) && (j <= high)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    
    int q = 0;
    if (i > middle) {
        for (q = j; q <= high; q++) {
            temp[k++] = arr[q];
        }
    }else{
        for (q = i; q <= high; q++) {
            temp[k++] = arr[q];
        }
    }

  
    int count = 0;
    
    int left = low;
    int right = middle + 1;
    
    while (left <= middle && right <= high) {
        if (arr[left] > 3*arr[right]) {
            
            count += middle + 1 - left;
            
            right++;
        }else{
            
            left++;
        }
    }
    
    

    for (int t = low; t <= high; t++) {
        
        arr[t] = temp[t];
    }
    
    return count;
}
 

int count_inversion(int low, int high)
{
    int count = 0, middle;
    if(low < high)
    {
        middle = low + (high - low) / 2;
        count += count_inversion(low, middle);        
        count += count_inversion(middle + 1, high);   
        count += merge(low, middle, high);   
    }
    
    if (count > 0) {
                
        return count;
    }
    
    return 0;
}

int main()
{
    int n;
    cin >> n;
    arr = new int[n];
    temp = new int[n];
    
    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << count_inversion(0, n-1);
    
    cout << endl;
    return 0;
}
