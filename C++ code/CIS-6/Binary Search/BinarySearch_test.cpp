#include "BinarySearch.h"

int main()
{
	int val, cnt = 0;

	// gets size of file
	streampos size;

	// character pointer 
	char* memblock;

	// opens file in binary mode and sets get position to end
	ifstream file;
	file.open("dataarray.bin", ios::in | ios::binary | ios::ate);

	// checks if the file has successfully opened
	if (file.is_open())
	{
		// accumilator for number of 3s
		int count3 = 0;

		// size of file
		size = file.tellg();

		// creates a space with the size of the file
		memblock = new char[size];

		// get position set to beginning
		file.seekg(0, ios::beg);

		// reads file and puts data into memblock
		file.read(memblock, size);

		// close file
		file.close();

		// converts characters into integers
		int* nums = (int*)memblock;

		mergeSort(nums, 0, size/4 - 1);
        
        // desired value
		cout << "input value" << endl;
		cin >> val;
        
        // stores possible -1 return value
		int* result = new int[2];

        *result = recursiveBinarySearch(nums, 0, size / 4 - 1, val, cnt);

        int out = *result;

        if (result[0] == -1)
	        int out = result[1];
        
        // outputs number of recursions and value
        string output = to_string(out) + ":" + to_string(val);

        cout << output << endl;

		return 0;
	}
	else
		cout << "file not open" << endl;
}
