#include <iostream>
#include "hip/hip_runtime.h"
using namespace std;

void DumpDcuDeviceInfo();

int main( int argc, char **argv )
{
	DumpDcuDeviceInfo();
	return 0;
}

void DumpDcuDeviceInfo()
{
    int num_gpus = -1;
	hipGetDeviceCount( &num_gpus );
	cout << " number of gpu = " << num_gpus << "\n";
}
