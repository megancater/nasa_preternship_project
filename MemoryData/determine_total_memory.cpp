#include <iostream>
#include <cstdlib>

long unsigned int determine_total_memory(int count, int data_structure, int number_buckets) 
{

	long unsigned int key = sizeof(float);
	long unsigned int value = sizeof(int);

	long unsigned int head = 8;
	long unsigned int tail = 8;
	long unsigned int prev = 8;
	long unsigned int next = 8;

	if(data_structure == hashmap)
	{
		return ((sizeof(key) + sizeof(value))*number_buckets);
	}

	else if(data_structure == dllist)
	{
		return (head + tail + (sizeof(float) + prev + next)*count;
	}

	else if(data_structure == array)
	{
		return (sizeof(float)*count);
	}
}
