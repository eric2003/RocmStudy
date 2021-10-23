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
	cout << " number of gpus = " << num_gpus << "\n";
    for ( int i = 0; i < num_gpus; ++ i )
    {
		hipDeviceProp_t prop;
		hipGetDeviceProperties( &prop, i );
        cout << " --- General Information for device " << i << " ---" << endl;
        cout << "Name: " << prop.name << endl;
        cout << "Compute capability: " << prop.major << "." <<  prop.minor << endl;
        cout << "Clock rate: " << prop.clockRate << endl;
		/*
        cout << "Device copy overlap: ";
        if ( prop.deviceOverlap )
		{
            cout << "Enabled\n";
		}
        else
		{
			cout << "Disabled\n";
		}
        cout << "Kernel execition timeout : ";
        if ( prop.kernelExecTimeoutEnabled )
		{
            cout << "Enabled\n";
		}
        else
		{
			cout << "Disabled\n";
		}
		*/
        cout << " --- Memory Information for device " << i << " ---\n";
        cout << "Total global mem: " << prop.totalGlobalMem << endl;
        cout << "Total constant Mem: " << prop.totalConstMem << endl;
        //cout << "Max mem pitch: " << prop.memPitch << endl;
        //cout << "Texture Alignment: " << prop.textureAlignment << endl;
        cout << " --- MP Information for device " << i << " ---\n";
        cout << "Multiprocessor count: " << prop.multiProcessorCount << endl;
        cout << "Shared mem per mp: " << prop.sharedMemPerBlock << endl;
        cout << "Registers per mp: " << prop.regsPerBlock << endl;
        cout << "Threads in warp: " << prop.warpSize << endl;
        cout << "Max threads per block: " << prop.maxThreadsPerBlock << endl;
        cout << "Max thread dimensions: (" <<
            prop.maxThreadsDim[0] << "," << prop.maxThreadsDim[1] << "," <<
            prop.maxThreadsDim[2] << ")" << endl;
        cout << "Max grid dimensions: (" <<
            prop.maxGridSize[0] << "," << prop.maxGridSize[1] << "," <<
            prop.maxGridSize[2] << ")" << endl;
        cout << endl;
	}
	cout << "Hip Device prop succeeded " << endl;
}
