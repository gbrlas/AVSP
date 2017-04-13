#include <iostream.h>

#define for(i,n) for(int i=0; i<n; i++)

int PowerOf2[31] = {1 ,2 ,4 ,8 ,16 ,32 ,64 ,128 ,256 ,512 ,1024 ,2048 ,4096 ,8192 ,16384 ,32768 ,65536 ,131072 ,262144 ,524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

// bool result = true: light bulb is on
bool resovle(int n, int k)
{
    if ((k + 1) % PowerOf2[n] == 0)
		return true;
	return false;
}

int main()
{
    int t, n, k;

    cin >> t;
    for(i,t){
        bool isOn = false;

        cin >> n >> k;
        isOn = resovle(n, k);
        cout << "Case #" << i + 1 << ": " << (isOn ? "ON" : "OFF") << endl;
    }
    return 0;

}
