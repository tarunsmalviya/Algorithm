#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 20

void display(int);
void sort(int, int);
void merge(int, int, int);

int arr[SIZE];

int main() {
	int size = 0;
	
	cout<<"Enter size of array(max 20):";
	cin>>size;
	
	if (size > SIZE)
	{
	    cout<<endl<<"Invalid size!";
	    return 1;
	}
	
	for (int i = 0; i < size; i++) 
	{
	    cout<<"Enter element at index "<<i + 1<<":";
	    cin>>arr[i];
	}
	
	display(size);
	sort(0, size - 1);
	display(size);
	
	
	return 0;
}

void display(int size)
{
    cout<<endl<<"Array:-"<<endl;
    for (int i = 0; i < size; i++) 
    {
        cout<<"    "<<arr[i];
    }
    cout<<endl;
}

void sort(int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        sort(p, q);
        sort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    
    int i = 0;
    int j = 0;
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
        
    for (i = 0; i < n2; i++)
        R[i] = arr[q + 1 + i];
    
    L[n1] = INFINITY;
    R[n2] = INFINITY;
        
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++) 
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}